using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace LLVM {
    class Context {
        internal readonly LLVMSharp.LLVMContextRef Underlying;

        internal Context(LLVMSharp.LLVMContextRef underlying) {
            Underlying = underlying;
        }
    }
}
