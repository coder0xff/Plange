using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using BizArk.Core.CmdLine;

namespace plc {
    [CmdLineOptions(DefaultArgName = "SourceFiles", ArgumentPrefix = "-")]
    class CommandLineArguments : CmdLineObject {
        [CmdLineArg] public String[] SourceFiles { get; set; }

        [CmdLineArg]
        public String OutputFile { get; set; }
    }
}
