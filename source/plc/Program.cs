using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using BizArk.Core.CmdLine;
using Plange;

namespace plc {
    static class Program {
        public static void Main() {
            ConsoleApplication.RunProgram<CommandLineArguments>(RunMain);
        }

        private static void RunMain(CommandLineArguments args) {
            args.OutputFile = args.OutputFile ?? "a.out";
            if (args.SourceFiles != null) {
                Compiler.Compile(args.SourceFiles, args.OutputFile);
            } else {
                Console.WriteLine(args.GetHelpText(Console.BufferWidth));
            }
            Console.ReadLine();

        }
    }
}
