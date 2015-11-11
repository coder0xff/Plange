using Parlex;

namespace Generated {
	public partial class ContinueStatement : Production {
		public ContinueStatement() : base("ContinueStatement", false) { }
		public override void Start() {
			State3();
		}

		void State4() {
			Transition(";", State2);
		}

		void State2() {
			Accept();
		}

		void State1() {
			Transition<Ws>(State4);
		}

		void State3() {
			Transition("continue", State1);
		}

	}
}
