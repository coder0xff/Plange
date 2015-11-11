using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace LLVM {
    //http://www.llvm.org/docs/doxygen/html/group__LLVMCCoreInstructionBuilder.html
    partial class Builder : IDisposable {
        internal LLVMSharp.LLVMBuilderRef Underlying;
        public Builder() {
            Underlying = LLVMSharp.LLVM.CreateBuilder();
        }

        public Builder(Context context) {
            Underlying = LLVMSharp.LLVM.CreateBuilderInContext(context.Underlying);
        }


        public void Dispose() {
            LLVMSharp.LLVM.DisposeBuilder(Underlying);
        }

        public MetadataAsValue CurrentDebugLocation {
            get { throw new NotImplementedException(); }
            set { throw new NotImplementedException(); }
        }

        public void SetInstructionDebugLocation(Instruction instruction) {
            LLVMSharp.LLVM.SetInstDebugLocation(Underlying, instruction.Underlying);
        }

        public void Position(BasicBlock basicBlock, Instruction instruction) {
            LLVMSharp.LLVM.PositionBuilder(Underlying, basicBlock.Underlying, instruction.Underlying);
        }

        public void Position(Instruction instruction) {
            LLVMSharp.LLVM.PositionBuilderBefore(Underlying, instruction.Underlying);
        }

        public void PositionAtEnd(BasicBlock basicBlock) {
            LLVMSharp.LLVM.PositionBuilderAtEnd(Underlying, basicBlock.Underlying);
        }

        public BasicBlock InsertionBlock {
            get { return new BasicBlock(LLVMSharp.LLVM.GetInsertBlock(Underlying)); }
        }

        public void ClearInsertionPosition() {
            LLVMSharp.LLVM.ClearInsertionPosition(Underlying);
        }

        public void Insert(Instruction instruction) {
            LLVMSharp.LLVM.InsertIntoBuilder(Underlying, instruction.Underlying);
        }

        public void Insert(Instruction instruction, String name) {
            LLVMSharp.LLVM.InsertIntoBuilderWithName(Underlying, instruction.Underlying, name);
        }
    }
}
