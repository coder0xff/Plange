using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices;
using LLVMSharp;
using Parlex;

namespace Plange {
    public static class Compiler {
        public static void Compile(IEnumerable<String> sourceFiles, String outputFile) {
            //parse each file
            var syntaxGraphs = sourceFiles.Select(fileName => Tuple.Create(fileName, Parser.Parse(System.IO.File.ReadAllText(fileName))));
            var topLevelElements = syntaxGraphs.SelectMany(fileNameAndGraph => fileNameAndGraph.Item2.NodeTable[fileNameAndGraph.Item2.Root].First().Children.Select(child => Tuple.Create(fileNameAndGraph.Item1, child))).ToArray();

        }
    }
}
