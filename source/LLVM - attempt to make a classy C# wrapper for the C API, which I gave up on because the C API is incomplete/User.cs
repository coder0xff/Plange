using System;
using System.Collections;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.Collections.Specialized;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace LLVM {
    public class User : Value {
        private readonly ArrayAbstraction<Value> _operands;
        private readonly ArrayAbstraction<Use> _uses;
 
        protected User(LLVMSharp.LLVMValueRef underlying) : base(underlying) {
            _operands = new ArrayAbstraction<Value>(
                index => Value.FromRef(LLVMSharp.LLVM.GetOperand(Underlying, (uint)index)),
                (value, index) => LLVMSharp.LLVM.SetOperand(Underlying, (uint)index, value.Underlying),
                () => LLVMSharp.LLVM.GetNumOperands(Underlying));

            _uses = new ArrayAbstraction<Use>(
                index => new Use(LLVMSharp.LLVM.GetOperandUse(Underlying, (uint)index)),
                (value, index) => {throw new NotSupportedException();},
                () => LLVMSharp.LLVM.GetNumOperands(Underlying));
        }

        private void OperandsOnCollectionChanged(object sender, NotifyCollectionChangedEventArgs notifyCollectionChangedEventArgs) {
            
        }

        internal static User FromRef(LLVMSharp.LLVMValueRef underlying) {
            throw new NotImplementedException();
        }

        public IArray<Value> Operands {
            get { return _operands; }
        }
    }
}
