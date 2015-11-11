using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace LLVM {
    class ListAbstraction<T> : IList<T> {
        private Func<int, T> _getElementFunction;
        private Action<T, int> _setElementFunction;
        private Action<T> _addFunction;
        private Action<int> _removeAtFunction;
        private Action<T, int> _insertFunction;
        private Func<int> _lenthFunction;
 
        public ListAbstraction(
            Func<int, T> getElementFunction,
            Action<T, int> setElementFunction,
            Action<T> addFunction,
            Action<int> removeAtFunction,
            Action<T, int> insertFunction,
            Func<int> lengthFunction) {
            _getElementFunction = getElementFunction;
            _setElementFunction = setElementFunction;
            _addFunction = addFunction;
            _removeAtFunction = removeAtFunction;
            _insertFunction = insertFunction;
            _lenthFunction = lengthFunction;
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

        public void Clear() {
            while (Count > 0) {
                _removeAtFunction(0);
            }
        }

        public bool Contains(T item) {
            return IndexOf(item) >= 0;
        }

        public void CopyTo(T[] array, int arrayIndex) {
            foreach (var item in this) {
                array[arrayIndex++] = item;
            }
        }

        public bool Remove(T item) {
            int index = IndexOf(item);
            if (index < 0) {
                return false;
            }
            RemoveAt(index);
            return true;
        }

        public int Count { get { return _lenthFunction(); } }
        public bool IsReadOnly { get { return false; } }
        public int IndexOf(T item) {
            for (int index = 0; index < Count; index++) {
                if (this[index].Equals(item)) {
                    return index;
                }
            }
            return -1;
        }

        public void Insert(int index, T item) {
            _insertFunction(item, index);
        }

        public void RemoveAt(int index) {
            _removeAtFunction(index);
        }

        public T this[int index] {
            get { return _getElementFunction(index); }
            set { _setElementFunction(value, index); }
        }
    }
}
