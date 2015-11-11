using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Plange.Runtime {
    public class Type {
        public String Name { get { throw new NotImplementedException(); } }
        public IReadOnlyList<Method> InstanceMethods { get { throw new NotImplementedException(); } }
        public IReadOnlyList<Method> StaticMethods { get { throw new NotImplementedException(); } }
        public IReadOnlyList<Property> InstanceProperties { get { throw new NotImplementedException(); } }
        public IReadOnlyList<Property> StaticProperties { get { throw new NotImplementedException(); } }
        public IReadOnlyList<Field> InstanceFields { get { throw new NotImplementedException(); } }
        public IReadOnlyList<Field> StaticFields { get { throw new NotImplementedException(); } }
    }
}
