using Parlex;

namespace Generated {
	public partial class DoWhileStatement : Production {
		public DoWhileStatement() : base("DoWhileStatement", false) { }
		public override void Start() {
			State4();
		}

		void State3() {
			Transition(")", State12);
		}

		void State4() {
			Transition("do", State2);
		}

		void State10() {
			Transition("while", State6);
		}

		void State12() {
			Accept();
		}

		void State5() {
			Transition("(", State8);
		}

		void State2() {
			Transition<Ws>(State9);
		}

		void State1() {
			Transition<Expression>(State11);
		}

		void State8() {
			Transition<Ws>(State1);
		}

		void State6() {
			Transition<Ws>(State5);
		}

		void State11() {
			Transition<Ws>(State3);
		}

		void State9() {
			Transition<BlockLiteral>(State7);
		}

		void State7() {
			Transition<Ws>(State10);
		}

	}
}
