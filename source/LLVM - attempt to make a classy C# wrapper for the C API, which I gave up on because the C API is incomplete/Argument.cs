using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using LLVMSharp;

namespace LLVM {
    public class Argument : Value {
        protected Argument(LLVMValueRef underlying) : base(underlying) {}
    }
}
