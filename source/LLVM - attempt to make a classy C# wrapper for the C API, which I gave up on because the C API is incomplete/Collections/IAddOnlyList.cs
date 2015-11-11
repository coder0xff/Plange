using System.Collections.Generic;

namespace LLVM {
    public interface IAddOnlyList<T> : IEnumerable<T> {
        void Add(T item);
        bool Contains(T item);
        void CopyTo(T[] array, int arrayIndex);
        int Count { get; }
        bool IsReadOnly { get; }
        int IndexOf(T item);
        T this[int index] { get; }
    }
}