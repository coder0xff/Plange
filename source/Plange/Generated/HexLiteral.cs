using Parlex;

namespace Generated {
	public partial class HexLiteral : Production {
		public HexLiteral() : base("HexLiteral", false) { }
		public override void Start() {
			State2();
		}

		void State3() {
			Accept();
			Transition(StandardSymbols.HexDigit, State3);
			Transition(StandardSymbols.HexDigit, State1);
		}

		void State2() {
			Transition("0x", State1);
		}

		void State1() {
			Transition(StandardSymbols.HexDigit, State3);
			Transition(StandardSymbols.HexDigit, State1);
		}

	}
}
