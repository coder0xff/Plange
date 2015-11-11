using Parlex;

namespace Generated {
	public partial class ReturnStatement : Production {
		public ReturnStatement() : base("ReturnStatement", false) { }
		public override void Start() {
			State5();
		}

		void State2() {
			Accept();
		}

		void State5() {
			Transition("return", State6);
		}

		void State3() {
			Transition(";", State2);
		}

		void State4() {
			Transition<Ws>(State3);
		}

		void State1() {
			Transition(";", State2);
			Transition<Expression>(State4);
		}

		void State6() {
			Transition<Ws>(State1);
		}

	}
}
