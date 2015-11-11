using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using LLVMSharp;

namespace LLVM {
    public class Instruction : Value {
        protected Instruction(LLVMValueRef underlying) : base(underlying) {}

        public static Instruction FromRef(LLVMValueRef temp) {
            throw new NotImplementedException();
        }
    }
}
