using System;

namespace LLVM {
    public class LLVMException : Exception {
        public LLVMException(string errorMessage) : base(errorMessage) { }
    }
}