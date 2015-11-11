using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace LLVM {
    public interface IReadOnlyArray<T> : IEnumerable<T> {
        T this[int index] { get; }
        int Length { get; }
    }
}
