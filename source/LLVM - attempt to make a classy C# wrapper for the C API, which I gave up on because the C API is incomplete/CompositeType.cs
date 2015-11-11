using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace LLVM {
    abstract class CompositeType : Type {
        internal CompositeType(LLVMSharp.LLVMTypeRef underlying) : base(underlying) { }

        public Type GetTypeAtIndex(Value value) {
            throw new NotImplementedException();
        }

        abstract public Type GetTypeAtIndex(UInt32 index);

        public bool IndexValid(Value value) {
            throw new NotImplementedException();
        }

        public abstract bool IndexValid(UInt32 index);
    }
}
