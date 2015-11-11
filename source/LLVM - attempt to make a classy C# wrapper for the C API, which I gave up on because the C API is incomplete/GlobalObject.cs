using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace LLVM {
    public class GlobalObject : GlobalValue {
        internal GlobalObject(LLVMSharp.LLVMValueRef underlying) : base(underlying) { }
    }
}
