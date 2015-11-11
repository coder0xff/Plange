using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace LLVM {
    class IntegerType : Type {
        internal IntegerType(LLVMSharp.LLVMTypeRef underlying) : base(underlying) { }

        public static IntegerType Int1 = new IntegerType(LLVMSharp.LLVM.Int1Type());
        public static IntegerType Int8 = new IntegerType(LLVMSharp.LLVM.Int8Type());
        public static IntegerType Int16 = new IntegerType(LLVMSharp.LLVM.Int16Type());
        public static IntegerType Int32 = new IntegerType(LLVMSharp.LLVM.Int32Type());
        public static IntegerType Int64 = new IntegerType(LLVMSharp.LLVM.Int64Type());

        public IntegerType(UInt32 numBits) : base(LLVMSharp.LLVM.IntType(numBits)) { }

        public IntegerType(Context context, UInt32 numBits) : base(LLVMSharp.LLVM.IntTypeInContext(context.Underlying, numBits)) { }
    }
}
