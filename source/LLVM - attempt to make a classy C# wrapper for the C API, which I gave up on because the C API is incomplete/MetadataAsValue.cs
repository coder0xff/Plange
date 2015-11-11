using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using LLVMSharp;

namespace LLVM {
    public class MetadataAsValue : Value {
        protected MetadataAsValue(LLVMValueRef underlying) : base(underlying) {}
    }
}
