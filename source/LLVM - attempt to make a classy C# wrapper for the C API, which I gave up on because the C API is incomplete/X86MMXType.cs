using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace LLVM {
    class X86MMXType : Type {
        internal X86MMXType(LLVMSharp.LLVMTypeRef underlying) : base(underlying) { }
    }
}
