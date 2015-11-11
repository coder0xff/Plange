using System;
using System.Collections;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.Collections.Specialized;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace LLVM {
    class ObservableList<T> : IList<T> {
        private readonly ObservableCollection<T> _underlying = new ObservableCollection<T>();

        public event NotifyCollectionChangedEventHandler CollectionChanged = (sender, args) => { }; 
        public ObservableList() {
            _underlying.CollectionChanged += UnderlyingOnCollectionChanged;
        }

        private void UnderlyingOnCollectionChanged(object sender, NotifyCollectionChangedEventArgs notifyCollectionChangedEventArgs) {
            CollectionChanged(this, notifyCollectionChangedEventArgs);
        }

        public IEnumerator<T> GetEnumerator() {
            return _underlying.GetEnumerator();
        }

        IEnumerator IEnumerable.GetEnumerator() {
            return GetEnumerator();
        }

        public void Add(T item) {
            _underlying.Add(item);
        }

        public void Clear() {
            _underlying.Clear();
        }

        public bool Contains(T item) {
            return _underlying.Contains(item);
        }

        public void CopyTo(T[] array, int arrayIndex) {
            _underlying.CopyTo(array, arrayIndex);
        }

        public bool Remove(T item) {
            return _underlying.Remove(item);
        }

        public int Count { get { return _underlying.Count; } }
        public bool IsReadOnly { get { return false; } }
        public int IndexOf(T item) {
            return _underlying.IndexOf(item);
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
