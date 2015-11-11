using Parlex;

namespace Generated {
	public partial class PointerToExpression : Production {
		public PointerToExpression() : base("PointerToExpression", false) { }
		public override void Start() {
			State3();
		}

		void State1() {
			Accept();
		}

		void State2() {
			Transition<ExplicitTypeDereference>(State1);
		}

		void State3() {
			Transition("pointer_to", State2);
		}

	}
}
