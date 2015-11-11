using Parlex;

namespace Generated {
	public partial class FloatLiteral0 : Production {
		public FloatLiteral0() : base("FloatLiteral0", false) { }
		public override void Start() {
			State4();
			State1();
		}

		void State3() {
			Transition<FloatE>(State2);
			Transition(StandardSymbols.DecimalDigit, State3);
		}

		void State5() {
			Accept();
			Transition(".", State3);
			Transition(StandardSymbols.DecimalDigit, State5);
		}

		void State1() {
			Transition(StandardSymbols.DecimalDigit, State5);
		}

		void State4() {
			Transition("-", State1);
		}

		void State2() {
			Accept();
		}

	}
}
