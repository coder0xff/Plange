using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using LLVMSharp;

namespace LLVM {
    class FloatingPointType : Type {
        internal FloatingPointType(LLVMTypeRef underlying) : base(underlying) { }

        public static Type Half = new FloatingPointType(LLVMSharp.LLVM.HalfType());
        public static Type Float = new FloatingPointType(LLVMSharp.LLVM.FloatType());
        public static Type Double = new FloatingPointType(LLVMSharp.LLVM.DoubleType());
        public static Type X86FP80 = new FloatingPointType(LLVMSharp.LLVM.X86FP80Type());
        public static Type FP128 = new FloatingPointType(LLVMSharp.LLVM.FP128Type());
        public static Type PPCFP128 = new FloatingPointType(LLVMSharp.LLVM.PPCFP128Type());

        private static Type HalfInContext(Context context) {
            return new Type(LLVMSharp.LLVM.HalfTypeInContext(context.Underlying));
        }

        private static Type FloatInContext(Context context) {
            return new Type(LLVMSharp.LLVM.FloatTypeInContext(context.Underlying));
        }

        private static Type DoubleInContext(Context context) {
            return new Type(LLVMSharp.LLVM.DoubleTypeInContext(context.Underlying));
        }

        private static Type X86FP80InContext(Context context) {
            return new Type(LLVMSharp.LLVM.X86FP80TypeInContext(context.Underlying));
        }

        private static Type FP128InContext(Context context) {
            return new Type(LLVMSharp.LLVM.FP128TypeInContext(context.Underlying));
        }

        private static Type PPCFP128InContext(Context context) {
            return new Type(LLVMSharp.LLVM.PPCFP128TypeInContext(context.Underlying));
        }
    }
}
