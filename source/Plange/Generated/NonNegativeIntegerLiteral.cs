using Parlex;

namespace Generated {
	public partial class NonNegativeIntegerLiteral : Production {
		public NonNegativeIntegerLiteral() : base("NonNegativeIntegerLiteral", false) { }
		public override void Start() {
			State1();
		}

		void State1() {
			Transition(StandardSymbols.Number, State2);
		}

		void State2() {
			Accept();
			Transition(StandardSymbols.Number, State2);
		}

	}
}
