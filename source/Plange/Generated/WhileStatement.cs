using Parlex;

namespace Generated {
	public partial class WhileStatement : Production {
		public WhileStatement() : base("WhileStatement", false) { }
		public override void Start() {
			State4();
		}

		void State9() {
			Transition(")", State11);
		}

		void State7() {
			Transition<Ws>(State5);
		}

		void State8() {
			Transition<Ws>(State3);
		}

		void State1() {
			Transition<BlockLiteral>(State2);
		}

		void State4() {
			Transition("while", State7);
		}

		void State10() {
			Accept();
		}

		void State6() {
			Transition<Ws>(State9);
		}

		void State3() {
			Transition<Expression>(State6);
		}

		void State5() {
			Transition("(", State8);
		}

		void State11() {
			Transition<Ws>(State1);
		}

		void State2() {
			Accept();
			Transition<ElseSuffix>(State10);
		}

	}
}
