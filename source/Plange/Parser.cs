using System;
using Parlex;

namespace Plange {
    public static class Parser {
        static public AbstractSyntaxGraph Parse(String text) {
            var engine = ParseEngine.FromType<Generated.Syntax>(text);
            engine.Join();
            return engine.AbstractSyntaxGraph;
        }
    }
}
