using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace LLVM {
    class PointerType : SequentialType {
        internal PointerType(LLVMSharp.LLVMTypeRef underlying) : base(underlying) {}

        public PointerType(Type elementType, UInt32 addressSpace) :
            base(LLVMSharp.LLVM.PointerType(elementType.Underlying, addressSpace)) {}

        public UInt32 AddressSpace {
            get { return LLVMSharp.LLVM.GetPointerAddressSpace(Underlying); }
        }
    }
}
