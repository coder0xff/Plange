using Parlex;

namespace Generated {
	public partial class FloatE : Production {
		public FloatE() : base("FloatE", false) { }
		public override void Start() {
			State1();
		}

		void State4() {
			Accept();
			Transition(StandardSymbols.DecimalDigit, State4);
		}

		void State3() {
			Transition(StandardSymbols.DecimalDigit, State4);
		}

		void State1() {
			Transition("E", State2);
		}

		void State2() {
			Transition("-", State3);
			Transition("+", State3);
			Transition(StandardSymbols.DecimalDigit, State4);
		}

	}
}
