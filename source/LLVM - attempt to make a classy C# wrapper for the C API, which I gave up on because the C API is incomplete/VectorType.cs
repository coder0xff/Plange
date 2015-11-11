using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace LLVM {
    class VectorType : SequentialType {
        internal VectorType(LLVMSharp.LLVMTypeRef underlying) : base(underlying) { }

        public VectorType(Type elementType, UInt32 size) : base(LLVMSharp.LLVM.VectorType(elementType.Underlying, size)) { }

        public UInt32 Size {
            get { return LLVMSharp.LLVM.GetVectorSize(Underlying); }
        }
    }
}
