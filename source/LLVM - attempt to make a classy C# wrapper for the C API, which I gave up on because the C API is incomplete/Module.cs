using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices;
using System.Runtime.Remoting.Contexts;
using System.Text;
using System.Threading.Tasks;
using LLVM.Collections;
using LLVMSharp;

namespace LLVM {
    class Module : IDisposable {
        internal readonly LLVMSharp.LLVMModuleRef Underlying;

        public Module(String moduleId) {
            Underlying = LLVMSharp.LLVM.ModuleCreateWithName(moduleId);
            Init();
        }

        public Module(String moduleId, Context context) {
            Underlying = LLVMSharp.LLVM.ModuleCreateWithNameInContext(moduleId, context.Underlying);
            Init();
        }

        private void Init() {
            _functions = new AddOnlyIterationListAbstraction<Function>(
                context => {
                    var temp = LLVMSharp.LLVM.GetFirstFunction(Underlying);
                    context.userData = temp;
                    return new Function(temp);
                },
                context => {
                    var temp = LLVMSharp.LLVM.GetNextFunction((LLVMValueRef)context.userData);
                    context.userData = temp;
                    return new Function(temp);
                },
                function => {
                    function.Underlying = LLVMSharp.LLVM.AddFunction(Underlying, function.Name, function.Type.Underlying);
                });
        }

        public void Dispose() {
            LLVMSharp.LLVM.DisposeModule(Underlying);
        }

        public String DataLayout {
            get { return LLVMSharp.LLVM.GetDataLayout(Underlying); }
            set { LLVMSharp.LLVM.SetDataLayout(Underlying, value); }
        }

        public String Target {
            get { return LLVMSharp.LLVM.GetTarget(Underlying); }
            set { LLVMSharp.LLVM.SetTarget(Underlying, value); }
        }

        public void Dump() {
            LLVMSharp.LLVM.DumpModule(Underlying);
        }

        public void PrintToFile(String filename) {
            IntPtr errorMessagePtr;
            var result = LLVMSharp.LLVM.PrintModuleToFile(Underlying, filename, out errorMessagePtr);
            if (result.Value != 0) {
                var errorMessage = Marshal.PtrToStringAnsi(errorMessagePtr);
                throw new LLVMException(errorMessage);
            }
        }

        public override string ToString() {
            IntPtr resultPtr = LLVMSharp.LLVM.PrintModuleToString(Underlying);
            return resultPtr == IntPtr.Zero ? null : Marshal.PtrToStringAnsi(resultPtr);
        }

        public String InlineASM {
            set {
                LLVMSharp.LLVM.SetModuleInlineAsm(Underlying, value);
            }
        }

        public Context Context {
            get {
                return new Context(LLVMSharp.LLVM.GetModuleContext(Underlying));
            }
        }

        public Type GetTypeByName(String name) {
            LLVMSharp.LLVMTypeRef temp = LLVMSharp.LLVM.GetTypeByName(Underlying, name);
            return temp.Pointer == IntPtr.Zero ? null : Type.FromRef(temp);
        }

        public UInt32 GetNamedMetadataNumOperands(String name) {
            return LLVMSharp.LLVM.GetNamedMetadataNumOperands(Underlying, name);
        }

        public Value[] GetNamedMetadataOperands(String name) {
            var temp = new LLVMSharp.LLVMValueRef[GetNamedMetadataNumOperands(name)];
            LLVMSharp.LLVM.GetNamedMetadataOperands(Underlying, name, out temp[0]);
            return Value.FromRefs(temp);
        }

        public void AddNamedMetadataOperand(String name, Value value) {
            LLVMSharp.LLVM.AddNamedMetadataOperand(Underlying, name, value.Underlying);
        }

        private AddOnlyIterationListAbstraction<Function> _functions;
 
        public IAddOnlyList<Function> Functions { get { return _functions; } }

        private AddOnlyListAbstraction<MDNode> _metadataOperands;

        public IAddOnlyList<MDNode> MetadataOperands { get { return _metadataOperands; } }
    }
}
