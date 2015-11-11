using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace LLVM.Collections {
    class NoElementAccessListAbstraction<T> : IList<T> {
        private ListAbstraction<T> _underlying;
        private Action<T[]> _setAllFunction;
        private Func<T[]> _getAllFunction;
 
        public NoElementAccessListAbstraction(Func<T[]> getAllFunction, Action<T[]> setAllFunction) {
            _setAllFunction = setAllFunction;
            _getAllFunction = getAllFunction;

            _underlying = new ListAbstraction<T>(
                index => getAllFunction()[index],
                (value, index) => {
                    var temp = getAllFunction();
                    temp[index] = value;
                    setAllFunction(temp);
                },
                value => {
                    var temp = getAllFunction().ToList();
                    temp.Add(value);
                    setAllFunction(temp.ToArray());
                },
                index => {
                    var temp = getAllFunction().ToList();
                    temp.RemoveAt(index);
                    setAllFunction(temp.ToArray());
                },
                (value, index) => {
                    var temp = getAllFunction().ToList();
                    temp.Insert(index, value);
                    setAllFunction(temp.ToArray());
                },
                () => getAllFunction().Length
            );

        }

        public IEnumerator<T> GetEnumerator() {
            return _underlying.GetEnumerator();
        }

        IEnumerator IEnumerable.GetEnumerator() {
            return _underlying.GetEnumerator();
        }

        public void Add(T item) {
            _underlying.Add(item);
        }

        public void Clear() {
            _setAllFunction(new T[0]);
        }

        public bool Contains(T item) {
            return _getAllFunction().Contains(item);
        }

        public void CopyTo(T[] array, int arrayIndex) {
            var temp = _getAllFunction();
            Array.Copy(temp, 0, array, arrayIndex, temp.Length);
        }

        public bool Remove(T item) {
            var temp = _getAllFunction().ToList();
            var result = temp.Remove(item);
            _setAllFunction(temp.ToArray());
            return result;
        }

        public int Count { get { return _getAllFunction().Length; } }
        public bool IsReadOnly { get { return false; } }
        public int IndexOf(T item) {
            var temp = _getAllFunction();
            for (int index = 0; index < temp.Length; index++) {
                if (temp[index].Equals(item)) {
                    return index;
                }
            }
            return -1;
        }

        public void Insert(int index, T item) {
            _underlying.Insert(index, item);
        }

        public void RemoveAt(int index) {
            _underlying.RemoveAt(index);
        }

        public T this[int index] {
            get { return _underlying[index]; }
            set { _underlying[index] = value; }
        }
    }
}
