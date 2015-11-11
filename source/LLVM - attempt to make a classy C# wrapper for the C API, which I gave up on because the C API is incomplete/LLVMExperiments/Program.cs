using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;
using LLVMSharp;

namespace LLVMExperiments {
    class Program {
        static void Main(string[] args) {
            var module = LLVM.ModuleCreateWithName("module");

            LLVMValueRef puts;
            {
                LLVMTypeRef[] param_types = { LLVM.PointerType(LLVM.Int8Type(), 0) };
                LLVMTypeRef funcType = LLVM.FunctionType(LLVM.Int32Type(), out param_types[0], 2, new LLVMBool(0));
                puts = LLVM.AddFunction(module, "puts", funcType);
            }

            LLVMValueRef main;
            LLVMValueRef helloWorld = LLVM.ConstString("Hello world", 11, new LLVMBool(0));
            {
                LLVMTypeRef[] param_types = { LLVM.VoidType() };
                LLVMTypeRef funcType = LLVM.FunctionType(LLVM.Int32Type(), out param_types[0], 0, new LLVMBool(0));
                main = LLVM.AddFunction(module, "main", funcType);
                LLVMBasicBlockRef entry = LLVM.AppendBasicBlock(main, "entry");
                LLVMBuilderRef builder = LLVM.CreateBuilder();
                LLVM.PositionBuilderAtEnd(builder, entry);
                LLVMValueRef[] parameters = { helloWorld };
                LLVMValueRef tmp = LLVM.BuildCall(builder, puts, out parameters[0], 1, "tmp");
                LLVM.BuildRet(builder, tmp);
            }

            IntPtr error;
            LLVM.VerifyModule(module, LLVMVerifierFailureAction.LLVMAbortProcessAction, out error);
            LLVM.DisposeMessage(error);

            LLVMExecutionEngineRef engine;

            LLVM.LinkInMCJIT();
            LLVM.InitializeX86Target();
            LLVM.InitializeX86TargetInfo();
            LLVM.InitializeX86TargetMC();
            LLVM.InitializeX86AsmPrinter();

            var platform = Environment.OSVersion.Platform;
            if (platform == PlatformID.Win32NT) // On Windows, LLVM currently (3.6) does not support PE/COFF
            {
                LLVM.SetTarget(module, Marshal.PtrToStringAnsi(LLVM.GetDefaultTargetTriple()) + "-elf");
            }

            var options = new LLVMMCJITCompilerOptions();
            var optionsSize = (4 * sizeof(int)) + IntPtr.Size; // LLVMMCJITCompilerOptions has 4 ints and a pointer

            LLVM.InitializeMCJITCompilerOptions(out options, optionsSize);
            LLVM.CreateMCJITCompilerForModule(out engine, module, out options, optionsSize, out error);
        }
    }
}
