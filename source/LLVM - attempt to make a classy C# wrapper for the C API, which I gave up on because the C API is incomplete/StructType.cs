using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.Collections.Specialized;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using LLVM.Collections;
using LLVMSharp;

namespace LLVM {
    class StructType : CompositeType {
        internal StructType(LLVMSharp.LLVMTypeRef underlying) : base(underlying) {
            Init();
        }

        private StructType(LLVMSharp.LLVMTypeRef[] elementTypes, bool packed) :
            base(LLVMSharp.LLVM.StructType(out elementTypes[0], (uint)elementTypes.Length, new LLVMBool(packed ? 1 : 0))) {
            Init();
        }

        public StructType(Type[] elementTypes, bool packed) : this(elementTypes.Select(t => t.Underlying).ToArray(), packed) { }

        private StructType(Context context, LLVMSharp.LLVMTypeRef[] elementTypes, bool packed) :
            base(LLVMSharp.LLVM.StructTypeInContext(context.Underlying, out elementTypes[0], (uint)elementTypes.Length, new LLVMBool(packed ? 1 : 0))) {
            Init();
        }

        public StructType(Context context, Type[] elementTypes, bool packed) : this(context, elementTypes.Select(t => t.Underlying).ToArray(), packed) { }

        public StructType(Context context, String name) : base(LLVMSharp.LLVM.StructCreateNamed(context.Underlying, name)) {
            Init();
        }

        public String Name {
            get { return LLVMSharp.LLVM.GetStructName(Underlying); }
        }

        private Type[] GetAllElementTypes() {
            var count = LLVMSharp.LLVM.CountStructElementTypes(Underlying);
            var temp = new LLVMSharp.LLVMTypeRef[count];
            LLVMSharp.LLVM.GetStructElementTypes(Underlying, out temp[0]);
            return temp.Select(Type.FromRef).ToArray();
        }

        private void SetAllElementTypes(Type[] elements) {
            var temp = elements.Select(t => t.Underlying).ToArray();
            LLVMSharp.LLVM.StructSetBody(Underlying, out temp[0], (uint)temp.Length, new LLVMBool(IsPacked ? 1 : 0));
        }

        private void Init() {
            _elements = new NoElementAccessListAbstraction<Type>(GetAllElementTypes, SetAllElementTypes);
        }

        private NoElementAccessListAbstraction<Type> _elements; 

        public IList<Type> Elements {
            get { return _elements; }
        }

        public bool IsPacked {
            get { return LLVMSharp.LLVM.IsPackedStruct(Underlying).Value != 0; }
            set {
                var count = LLVMSharp.LLVM.CountStructElementTypes(Underlying);
                var temp = new LLVMSharp.LLVMTypeRef[count];
                LLVMSharp.LLVM.GetStructElementTypes(Underlying, out temp[0]);
                LLVMSharp.LLVM.StructSetBody(Underlying, out temp[0], (uint)temp.Length, new LLVMBool(value ? 1 : 0));
            }
        }

        public bool IsOpaque {
            get { return LLVMSharp.LLVM.IsOpaqueStruct(Underlying).Value != 0; }
        }

        public override Type GetTypeAtIndex(uint index) {
            return Elements[(int)index];
        }

        public override bool IndexValid(uint index) {
            return index < Elements.Count;
        }
    }
}
