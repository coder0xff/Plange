using Parlex;

namespace Generated {
	public partial class FreeStatement : Production {
		public FreeStatement() : base("FreeStatement", false) { }
		public override void Start() {
			State6();
		}

		void State1() {
			Transition<Ws>(State4);
		}

		void State6() {
			Transition("free", State1);
		}

		void State2() {
			Transition<Ws>(State5);
		}

		void State5() {
			Transition(";", State3);
		}

		void State3() {
			Accept();
		}

		void State4() {
			Transition<Expression>(State2);
		}

	}
}
