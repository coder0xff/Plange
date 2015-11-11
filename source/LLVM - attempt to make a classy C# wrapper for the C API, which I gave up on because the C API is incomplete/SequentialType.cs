using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace LLVM {
    class SequentialType : CompositeType {
        internal SequentialType(LLVMSharp.LLVMTypeRef underlying) : base(underlying) { }

        public override Type GetTypeAtIndex(uint index) {
            throw new NotImplementedException();
        }

        public override bool IndexValid(uint index) {
            throw new NotImplementedException();
        }

        public Type ElementType {
            get { return Type.FromRef(LLVMSharp.LLVM.GetElementType(Underlying)); }
        }

    }
}
