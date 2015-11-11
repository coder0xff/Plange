using Parlex;

namespace Generated {
	public partial class Ws : Production {
		public Ws() : base("Ws", false) { }
		public override void Start() {
			State1();
		}

		void State2() {
			Accept();
		}

		void State1() {
			Accept();
			Transition(StandardSymbols.WhiteSpaces, State2);
		}

	}
}
