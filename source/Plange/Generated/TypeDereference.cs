using Parlex;

namespace Generated {
	public partial class TypeDereference : Production {
		public TypeDereference() : base("TypeDereference", false) { }
		public override void Start() {
			State2();
		}

		void State2() {
			Transition<ExplicitTypeDereference>(State1);
			Transition<DeducedTypeDereference>(State1);
		}

		void State1() {
			Accept();
		}

	}
}
