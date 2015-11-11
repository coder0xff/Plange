using Parlex;

namespace Generated {
	public partial class FloatLiteral1 : Production {
		public FloatLiteral1() : base("FloatLiteral1", false) { }
		public override void Start() {
			State1();
			State4();
		}

		void State1() {
			Transition("-", State4);
		}

		void State5() {
			Accept();
			Transition<FloatE>(State3);
			Transition(StandardSymbols.DecimalDigit, State5);
		}

		void State3() {
			Accept();
		}

		void State2() {
			Transition(StandardSymbols.DecimalDigit, State5);
		}

		void State4() {
			Transition(".", State2);
		}

	}
}
