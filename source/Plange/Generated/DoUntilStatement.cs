using Parlex;

namespace Generated {
	public partial class DoUntilStatement : Production {
		public DoUntilStatement() : base("DoUntilStatement", false) { }
		public override void Start() {
			State11();
		}

		void State3() {
			Transition<Expression>(State6);
		}

		void State10() {
			Transition<Ws>(State7);
		}

		void State4() {
			Transition<Ws>(State12);
		}

		void State1() {
			Transition(")", State5);
		}

		void State11() {
			Transition("do", State4);
		}

		void State2() {
			Transition("until", State10);
		}

		void State12() {
			Transition<BlockLiteral>(State9);
		}

		void State7() {
			Transition("(", State8);
		}

		void State6() {
			Transition<Ws>(State1);
		}

		void State8() {
			Transition<Ws>(State3);
		}

		void State5() {
			Accept();
		}

		void State9() {
			Transition<Ws>(State2);
		}

	}
}
