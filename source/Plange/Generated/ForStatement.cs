using Parlex;

namespace Generated {
	public partial class ForStatement : Production {
		public ForStatement() : base("ForStatement", false) { }
		public override void Start() {
			State11();
		}

		void State6() {
			Transition<Ws>(State9);
		}

		void State17() {
			Transition<Ws>(State8);
		}

		void State4() {
			Transition(";", State7);
		}

		void State7() {
			Transition<Ws>(State1);
			Transition<Ws>(State17);
		}

		void State9() {
			Transition<BlockLiteral>(State16);
		}

		void State8() {
			Transition(";", State10);
		}

		void State13() {
			Transition<Ws>(State5);
			Transition<Ws>(State12);
		}

		void State2() {
			Transition<Ws>(State14);
		}

		void State5() {
			Transition<Ws>(State4);
			Transition<BlockLiteral>(State12);
			Transition<Expression>(State12);
		}

		void State16() {
			Accept();
		}

		void State15() {
			Transition<Ws>(State18);
		}

		void State14() {
			Transition("(", State13);
		}

		void State1() {
			Transition<BlockLiteral>(State17);
			Transition<Expression>(State17);
		}

		void State12() {
			Transition<Ws>(State4);
		}

		void State3() {
			Transition<Ws>(State18);
			Transition<BlockLiteral>(State15);
			Transition<Expression>(State15);
		}

		void State18() {
			Transition(")", State6);
		}

		void State11() {
			Transition("for", State2);
		}

		void State10() {
			Transition<Ws>(State3);
			Transition<Ws>(State15);
		}

	}
}
