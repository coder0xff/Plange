using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace LLVM {
    public class Use {
        internal readonly LLVMSharp.LLVMUseRef Underlying;

        internal Use(LLVMSharp.LLVMUseRef underlying) {
            Underlying = underlying;
        }

        public User User {
            get { return User.FromRef(LLVMSharp.LLVM.GetUser(Underlying)); }
        }

        public Value Value {
            get { return Value.FromRef(LLVMSharp.LLVM.GetUsedValue(Underlying)); }
        }
    }
}
