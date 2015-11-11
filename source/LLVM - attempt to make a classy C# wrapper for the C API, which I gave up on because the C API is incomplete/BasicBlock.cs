using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using LLVM.Collections;
using LLVM.Instructions;
using LLVMSharp;

namespace LLVM {
    public class BasicBlock : Value {
        internal new LLVMSharp.LLVMBasicBlockRef Underlying;
        private readonly ReadOnlyIterationListAbstraction<Instruction> _instructions;

        internal BasicBlock(LLVMSharp.LLVMBasicBlockRef underlying) : base(LLVMSharp.LLVM.BasicBlockAsValue(underlying)) {
            Underlying = underlying;
            _instructions = new ReadOnlyIterationListAbstraction<Instruction>(
                context => {
                    var temp = LLVMSharp.LLVM.GetFirstInstruction(Underlying);
                    context.userData = temp;
                    return Instruction.FromRef(temp);
                },
                context => {
                    var temp = (LLVMSharp.LLVMValueRef)context.userData;
                    temp = LLVMSharp.LLVM.GetNextFunction(temp);
                    return Instruction.FromRef(temp);
                });
            
        }

        public Function Parent {
            get { return new Function(LLVMSharp.LLVM.GetBasicBlockParent(Underlying)); }
        }

        public Terminator Terminator {
            get { return Terminator.FromRef(LLVMSharp.LLVM.GetBasicBlockTerminator(Underlying)); }
        }

        public IReadOnlyList<Instruction> Instructions {
            get { return _instructions; }
        }
    }
}
