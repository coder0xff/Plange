using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace LLVM {
    public class Function : GlobalObject {
        //used by the (String, FunctionType) constructor
        //The only way to get an LLVMValueRef for a function
        //is to call the module's AddFunction(module, name, type)
        //method. These hold on to the needed values until
        //the time comes that AddFunction is called;
        private String _forwardingName;
        private FunctionType _forwardingType;

        internal Function(LLVMSharp.LLVMValueRef underlying) : base(underlying) {}

        public Function(String name, FunctionType type) : base(new LLVMSharp.LLVMValueRef(IntPtr.Zero)){
            _forwardingName = name;
            _forwardingType = type;
        }

        public String Name {
            get {
                if (Underlying.Pointer == IntPtr.Zero) {
                    return _forwardingName;
                }
                return base.Name;
            }
            set {
                if (Underlying.Pointer == IntPtr.Zero) {
                    _forwardingName = value;
                } else {
                    base.Name = value;
                }
            }
        }

    }
}
