using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;

namespace LLVM {
    public class Value {
        internal LLVMSharp.LLVMValueRef Underlying;

        protected Value(LLVMSharp.LLVMValueRef underlying) {
            Underlying = underlying;
        }

        internal static Value FromRef(LLVMSharp.LLVMValueRef underlying) {
            throw new NotImplementedException();
        }

        internal static Value[] FromRefs(LLVMSharp.LLVMValueRef[] refs) {
            return refs.Select(FromRef).ToArray();
        }

        public Type Type {
            get { return new Type(LLVMSharp.LLVM.TypeOf(Underlying)); }
        }

        public String Name {
            get { return LLVMSharp.LLVM.GetValueName(Underlying); }
            set { LLVMSharp.LLVM.SetValueName(Underlying, value); }
        }

        public void DumpValue() {
            LLVMSharp.LLVM.DumpValue(Underlying);
        }

        public String PrintValueToString() {
            return Marshal.PtrToStringAnsi(LLVMSharp.LLVM.PrintValueToString(Underlying));
        }

        public void ReplaceAllUsesWith(Value newValue) {
            LLVMSharp.LLVM.ReplaceAllUsesWith(Underlying, newValue.Underlying);
        }

        public bool IsConstant {
            get { return LLVMSharp.LLVM.IsConstant(Underlying).Value != 0; }
        }

        public bool IsUndef {
            get { return LLVMSharp.LLVM.IsUndef(Underlying).Value != 0; }
        }

        public Value IsAMDNode {
            get { return Value.FromRef(LLVMSharp.LLVM.IsAMDNode(Underlying)); }
        }

        public Value IsAMDString {
            get { return Value.FromRef(LLVMSharp.LLVM.IsAMDString(Underlying)); }
        }

        public IEnumerable<Use> Uses {
            get {
                var use = LLVMSharp.LLVM.GetFirstUse(Underlying);
                if (use.Pointer == IntPtr.Zero) yield break;
                yield return new Use(use);
                while ((use = LLVMSharp.LLVM.GetNextUse(use)).Pointer != IntPtr.Zero) {
                    yield return new Use(use);
                }
            }
        }

        public IEnumerable<User> Users {
            get { return Uses.Select(use => use.User); }
        }
    }
}
