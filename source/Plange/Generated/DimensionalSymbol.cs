using Parlex;

namespace Generated {
	public partial class DimensionalSymbol : Production {
		public DimensionalSymbol() : base("DimensionalSymbol", false) { }
		public override void Start() {
			State2();
		}

		void State1() {
			Transition<IntegerLiteral>(State2);
		}

		void State2() {
			Accept();
			Transition(StandardSymbols.Letter, State2);
			Transition("/", State2);
			Transition("^", State1);
		}

	}
}
