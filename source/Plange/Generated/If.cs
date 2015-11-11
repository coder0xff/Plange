using Parlex;

namespace Generated {
	public partial class If : Production {
		public If() : base("If", false) { }
		public override void Start() {
			State2();
		}

		void State2() {
			Transition("if", State1);
		}

		void State5() {
			Transition<BlockLiteral>(State11);
		}

		void State4() {
			Transition(")", State6);
		}

		void State7() {
			Transition("(", State8);
		}

		void State11() {
			Accept();
			Transition<ElseSuffix>(State9);
		}

		void State6() {
			Transition<Ws>(State5);
		}

		void State1() {
			Transition<Ws>(State7);
		}

		void State10() {
			Transition<Expression>(State3);
		}

		void State9() {
			Accept();
		}

		void State3() {
			Transition<Ws>(State4);
		}

		void State8() {
			Transition<Ws>(State10);
		}

	}
}
