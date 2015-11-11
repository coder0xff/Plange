using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace LLVM {
    public class GlobalValue : Constant {
        internal GlobalValue(LLVMSharp.LLVMValueRef underlying) : base(underlying) { }
    }
}
