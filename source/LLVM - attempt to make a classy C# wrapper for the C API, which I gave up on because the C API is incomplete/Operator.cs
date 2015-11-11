using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using LLVMSharp;

namespace LLVM {
    public class Operator : User {
        protected Operator(LLVMValueRef underlying) : base(underlying) {}
    }
}
