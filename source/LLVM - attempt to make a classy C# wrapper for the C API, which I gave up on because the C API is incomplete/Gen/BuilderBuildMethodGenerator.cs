using System;
using System.Collections.Generic;
using System.Linq;
using System.Net;
using System.Reflection;
using System.Runtime.CompilerServices;
using System.Text;
using System.Threading.Tasks;

namespace LLVM.Gen {
    public static class BuilderBuildMethodGenerator {
            
        public static String Generate() {
            var result = new StringBuilder();
            var allMethods = typeof(LLVMSharp.LLVM).GetMethods(BindingFlags.Public | BindingFlags.Static);
            var builderMethods = allMethods.Where(method => method.Name.StartsWith("Build")).OrderBy(m => m.Name);
            foreach (var builderMethod in builderMethods) {
                result.Append(GenerateMethod(builderMethod));
                result.Append("\r\n");
            }
            return result.ToString();
        }

        private static Dictionary<System.Type, String> _typeConversionTable = new Dictionary<System.Type, string> {
            { typeof(LLVMSharp.LLVMValueRef), "Value" },
            { typeof(LLVMSharp.LLVMBasicBlockRef), "BasicBlock" },
            { typeof(LLVMSharp.LLVMBuilderRef), "Builder"},
            { typeof(LLVMSharp.LLVMContextRef), "Context"},
            { typeof(LLVMSharp.LLVMTypeRef), "Type"}
        };

        private static Dictionary<String, String> _nameConversionTable = new Dictionary<string, string> {
            { "Val", "value" },
            { "If", "_if"},
            { "Else", "_else"},
            { "Catch", "_catch"},
            { "RHS", "rhs"},
            { "LHS", "lhs"}
        };

        private static String ConvertName(String name) {
            string result;
            if (!_nameConversionTable.TryGetValue(name, out result)) {
                result = char.ToLower(name[0]) + name.Substring(1);
            }            
            return result;
        }

        private static String GenerateMethod(MethodInfo builderMethod) {
            var signature = new StringBuilder();
            var body = new StringBuilder();
            var call = new StringBuilder();
            signature.Append("public Instruction " + builderMethod.Name + "(");
            body.Append("{\r\n");
            call.Append("\treturn Instruction.FromRef(LLVMSharp.LLVM." + builderMethod.Name + "(Underlying");
            var ps = builderMethod.GetParameters().Skip(1).ToArray();
            var firstParam = true;
            for (int index = 0; index < ps.Length; index++) {
                var p = ps[index];
                var pType = p.ParameterType;
                if (pType.HasElementType) {
                    pType = pType.GetElementType();
                }
                var name = ConvertName(p.Name);
                signature.Append(firstParam ? "" : ", ");
                firstParam = false;
                if (pType.Name.EndsWith("Ref")) {
                    if (p.IsOut && index < ps.Length - 1 && ps[index + 1].ParameterType == typeof(uint)) {
                        //an array
                        signature.Append(_typeConversionTable[pType]);
                        signature.Append("[] ");
                        signature.Append(name);

                        body.Append("\tvar ");
                        body.Append(name);
                        body.Append("Proxy = ");
                        body.Append(name);
                        body.AppendLine(".Select(x => x.Underlying).ToArray();");

                        call.Append(", out ");
                        call.Append(name);
                        call.Append("Proxy[0], (uint)");
                        call.Append(name);
                        call.Append("Proxy.Length");
                        index++;
                    } else {
                        signature.Append(_typeConversionTable[pType]);
                        signature.Append(" ");
                        signature.Append(name);

                        call.Append(", ");
                        call.Append(name);
                        call.Append(".Underlying");
                    }
                } else {
                    signature.Append(pType.Name);
                    signature.Append(" ");
                    signature.Append(name);

                    call.Append(", ");
                    call.Append(name);
                }
            }
            signature.Append(")\r\n");
            call.Append("));\r\n");
            body.Append(call);
            body.Append("}\r\n");
            return signature.ToString() + body;
        }

        public static void GenerateFile(String filePathName) {
            System.IO.File.WriteAllText(filePathName, Generate());
        }
    }
}
