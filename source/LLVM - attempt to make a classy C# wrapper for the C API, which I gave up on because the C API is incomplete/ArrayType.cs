using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace LLVM {
    class ArrayType : SequentialType {
        internal ArrayType(LLVMSharp.LLVMTypeRef underlying) : base(underlying) {}

        public ArrayType(Type elementType, UInt32 count) : 
            base(LLVMSharp.LLVM.ArrayType(elementType.Underlying, count)) {}

        UInt32 Length {
            get { return LLVMSharp.LLVM.GetArrayLength(Underlying); }
        }
    }
}
