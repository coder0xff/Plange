using System;

namespace LLVM.Instructions {
    public class Terminator : Instruction {
        private Terminator(LLVMSharp.LLVMValueRef underlying) : base(underlying) {
            throw new NotImplementedException();
        }

        internal static Terminator FromRef(LLVMSharp.LLVMValueRef underlying) {
            //see LLVMSharp.LLVMOpcode
            throw new NotImplementedException();
        }
    }
}
