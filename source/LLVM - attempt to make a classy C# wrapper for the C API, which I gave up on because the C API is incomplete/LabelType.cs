using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace LLVM {
    class LabelType : Type {
        internal LabelType(LLVMSharp.LLVMTypeRef underlying) : base(underlying) { }
    }
}
