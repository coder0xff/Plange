using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace LLVM.Collections {
    class ReadOnlyIterationListAbstraction<T> : IReadOnlyList<T> {
        public class Context {
            public Object userData;
        }
        private readonly Func<Context, T> _getFirstFunction;
        private readonly Func<Context, T> _getNextFunction;

        public ReadOnlyIterationListAbstraction(Func<Context, T> getFirstFunction, Func<Context, T> getNextFunction) {
            _getFirstFunction = getFirstFunction;
            _getNextFunction = getNextFunction;
        }
        public IEnumerator<T> GetEnumerator() {
            var context = new Context();
            T current = _getFirstFunction(context);
            while (current != null) {
                yield return current;
                current = _getNextFunction(context);
            }
        }

        IEnumerator IEnumerable.GetEnumerator() {
            return GetEnumerator();
        }

        public bool Contains(T item) {
            return Enumerable.Contains(this, item);
        }

        public void CopyTo(T[] array, int arrayIndex) {
            foreach (var item in this) {
                array[arrayIndex++] = item;
            }
        }

        public int Count {
            get {
                var result = 0;
                // ReSharper disable once LoopCanBeConvertedToQuery
                foreach (var item in this) {
                    result++;
                }
                return result;
            }
        }

        public bool IsReadOnly { get { return false; } }

        public int IndexOf(T item) {
            var index = 0;
            foreach (var search in this) {
                if (search.Equals(item)) {
                    return index;
                }
                index++;
            }
            return -1;
        }

        public T this[int index] {
            get { return this.Skip(index).FirstOrDefault(); }
        }
    }
}
