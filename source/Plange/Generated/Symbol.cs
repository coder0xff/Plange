using Parlex;

namespace Generated {
	public partial class Symbol : Production {
		public Symbol() : base("Symbol", false) { }
		public override void Start() {
			State2();
		}

		void State2() {
			Transition(StandardSymbols.Letter, State1);
		}

		void State1() {
			Accept();
			Transition(StandardSymbols.Alphanumeric, State1);
		}

	}
}
