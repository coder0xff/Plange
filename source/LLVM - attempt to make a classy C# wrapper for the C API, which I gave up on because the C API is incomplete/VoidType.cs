using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace LLVM {
    class VoidType : Type {
        internal VoidType(LLVMSharp.LLVMTypeRef underlying) : base(underlying) { }
    }
}
