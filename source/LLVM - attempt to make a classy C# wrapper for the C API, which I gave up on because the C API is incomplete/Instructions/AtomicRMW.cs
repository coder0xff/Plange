namespace LLVM.Instructions {
    public class AtomicRMW : Instruction {
        protected AtomicRMW(LLVMSharp.LLVMValueRef underlying) : base(underlying) {}
    }
}
