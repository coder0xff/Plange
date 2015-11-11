using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace LLVM {
    class ArrayAbstraction<T> : IArray<T> {
        private readonly Func<int, T> _getElementFunction;
        private readonly Action<T, int> _setElementFunction;
        private readonly Func<int> _getLengthFunction;
 
        public ArrayAbstraction(Func<int, T> getElementFunction, Action<T, int> setElementFunction, Func<int> getLengthFunction) {
            _getElementFunction = getElementFunction;
            _setElementFunction = setElementFunction;
            _getLengthFunction = getLengthFunction;
        }

        public IEnumerator<T> GetEnumerator() {
            for (int index = 0; index < _getLengthFunction(); index++) {
                yield return this[index];
            }
        }

        IEnumerator IEnumerable.GetEnumerator() {
            return GetEnumerator();
        }

        public T this[int index] {
            get { return _getElementFunction(index); }
            set { _setElementFunction(value, index); }
        }

        public int Length { get { return _getLengthFunction(); } }
    }
}
