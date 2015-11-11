using Parlex;

namespace Generated {
	public partial class BreakStatement : Production {
		public BreakStatement() : base("BreakStatement", false) { }
		public override void Start() {
			State1();
		}

		void State4() {
			Transition<Ws>(State3);
		}

		void State1() {
			Transition("break", State4);
		}

		void State3() {
			Transition(";", State2);
		}

		void State2() {
			Accept();
		}

	}
}
