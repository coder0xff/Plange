using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace LLVM {
    public class FunctionType : Type {
        internal FunctionType(LLVMSharp.LLVMTypeRef underlying) : base(underlying) { }

        private FunctionType(Type returnType, LLVMSharp.LLVMTypeRef[] paramTypes, bool isVarArg) :
            base(LLVMSharp.LLVM.FunctionType(returnType.Underlying, out paramTypes[0], (uint)paramTypes.Length, new LLVMSharp.LLVMBool(isVarArg ? 1 : 0))) {}

        public FunctionType(Type returnType, Type[] paramTypes, bool isVarArg) : 
            this(returnType, paramTypes.Select(t => t.Underlying).ToArray(), isVarArg) { }

        public bool IsVarArg {
            get { return LLVMSharp.LLVM.IsFunctionVarArg(Underlying).Value != 0; }
        }

        public Type ReturnType {
            get { return Type.FromRef(LLVMSharp.LLVM.GetReturnType(Underlying)); }
        }

        public IReadOnlyCollection<Type> ParameterTypes {
            get {
                var count = LLVMSharp.LLVM.CountParamTypes(Underlying);
                var temp = new LLVMSharp.LLVMTypeRef[count];
                LLVMSharp.LLVM.GetParamTypes(Underlying, out temp[0]);
                return temp.Select(Type.FromRef).ToList();
            }
        }
    }
}
