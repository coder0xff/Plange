using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace LLVM {
    class AddOnlyListAbstraction<T> : IAddOnlyList<T> {
        private Func<int, T> _getItemFunction;
        private Action<T> _addFunction;
        private Func<int> _lengthFunction;

        public AddOnlyListAbstraction(
            Func<int, T> getItemFunction,
            Action<T> addFunction,
            Func<int> lengthFunction) {
            _getItemFunction = getItemFunction;
            _addFunction = addFunction;
            _lengthFunction = lengthFunction;
        }

        public IEnumerator<T> GetEnumerator() {
            for (int index = 0; index < Count; index++) {
                yield return this[index];
            }
        }

        IEnumerator IEnumerable.GetEnumerator() {
            return GetEnumerator();
        }

        public void Add(T item) {
            _addFunction(item);
        }

        public bool Contains(T item) {
            return Enumerable.Contains(this, item);
        }

        public void CopyTo(T[] array, int arrayIndex) {
            foreach (var item in this) {
                array[arrayIndex++] = item;
            }
        }

        public int Count { get { return _lengthFunction(); } }
        public bool IsReadOnly { get { return false; } }
        public int IndexOf(T item) {
            for (int index = 0; index < Count; index++) {
                if (this[index].Equals(item)) {
                    return index;
                }
            }
            return -1;
        }

        public T this[int index] {
            get { return _getItemFunction(index); }
        }
    }
}
