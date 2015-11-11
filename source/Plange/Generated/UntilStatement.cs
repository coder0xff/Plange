using Parlex;

namespace Generated {
	public partial class UntilStatement : Production {
		public UntilStatement() : base("UntilStatement", false) { }
		public override void Start() {
			State5();
		}

		void State1() {
			Transition<Ws>(State2);
		}

		void State9() {
			Transition<Ws>(State7);
		}

		void State4() {
			Transition<Expression>(State9);
		}

		void State5() {
			Transition("until", State6);
		}

		void State11() {
			Transition<Ws>(State4);
		}

		void State8() {
			Transition("(", State11);
		}

		void State10() {
			Accept();
		}

		void State7() {
			Transition(")", State1);
		}

		void State2() {
			Transition<BlockLiteral>(State3);
		}

		void State6() {
			Transition<Ws>(State8);
		}

		void State3() {
			Accept();
			Transition<ElseSuffix>(State10);
		}

	}
}
