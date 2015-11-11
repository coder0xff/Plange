using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace LLVM {
    public interface IArray<T> : IEnumerable<T> {
        T this[int index] { get; set; }
        int Length { get; }
    }
}
