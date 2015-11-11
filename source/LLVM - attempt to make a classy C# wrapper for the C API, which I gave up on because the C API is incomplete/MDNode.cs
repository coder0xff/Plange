using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace LLVM {
    public class MDNode : Value {
        protected MDNode(LLVMSharp.LLVMValueRef underlying) : base(underlying) {}
    }
}
