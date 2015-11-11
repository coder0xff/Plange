namespace LLVM.Instructions {
    public class ShuffleVector : Instruction {
        protected ShuffleVector(LLVMSharp.LLVMValueRef underlying) : base(underlying) {}
    }
}
