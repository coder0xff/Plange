using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace LLVM {
    public class Type {
        internal readonly LLVMSharp.LLVMTypeRef Underlying;

        protected internal Type(LLVMSharp.LLVMTypeRef underlying) {
            Underlying = underlying;
        }

        internal static Type FromRef(LLVMSharp.LLVMTypeRef underlying) {
            switch (LLVMSharp.LLVM.GetTypeKind(underlying)) {
                case LLVMSharp.LLVMTypeKind.LLVMArrayTypeKind:
                    return new ArrayType(underlying);
                case LLVMSharp.LLVMTypeKind.LLVMDoubleTypeKind:
                    return new Type(underlying);
                case LLVMSharp.LLVMTypeKind.LLVMFP128TypeKind:
                    return new Type(underlying);
                case LLVMSharp.LLVMTypeKind.LLVMFloatTypeKind:
                    return new Type(underlying);
                case LLVMSharp.LLVMTypeKind.LLVMFunctionTypeKind:
                    return new FunctionType(underlying);
                case LLVMSharp.LLVMTypeKind.LLVMHalfTypeKind:
                    return new Type(underlying);
                case LLVMSharp.LLVMTypeKind.LLVMIntegerTypeKind:
                    return new Type(underlying);
                case LLVMSharp.LLVMTypeKind.LLVMLabelTypeKind:
                    return new LabelType(underlying);
                case LLVMSharp.LLVMTypeKind.LLVMMetadataTypeKind:
                    return new Type(underlying);
                case LLVMSharp.LLVMTypeKind.LLVMPPC_FP128TypeKind:
                    return new Type(underlying);
                case LLVMSharp.LLVMTypeKind.LLVMPointerTypeKind:
                    return new PointerType(underlying);
                case LLVMSharp.LLVMTypeKind.LLVMStructTypeKind:
                    return new StructType(underlying);
                case LLVMSharp.LLVMTypeKind.LLVMVectorTypeKind:
                    return new VectorType(underlying);
                case LLVMSharp.LLVMTypeKind.LLVMVoidTypeKind:
                    return new VoidType(underlying);
                case LLVMSharp.LLVMTypeKind.LLVMX86_FP80TypeKind:
                    return new Type(underlying);
                case LLVMSharp.LLVMTypeKind.LLVMX86_MMXTypeKind:
                    return new X86MMXType(underlying);
            }
            throw new LLVMException("Invalid type kind");
        }
    }
}
