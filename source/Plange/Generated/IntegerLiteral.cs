using Parlex;

namespace Generated {
	public partial class IntegerLiteral : Production {
		public IntegerLiteral() : base("IntegerLiteral", false) { }
		public override void Start() {
			State1();
		}

		void State1() {
			Transition("-", State3);
			Transition<NonNegativeIntegerLiteral>(State2);
		}

		void State2() {
			Accept();
		}

		void State3() {
			Transition<NonNegativeIntegerLiteral>(State2);
		}

	}
}
