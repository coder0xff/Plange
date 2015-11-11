using Parlex;

namespace Generated {
	public partial class ElseSuffix : Production {
		public ElseSuffix() : base("ElseSuffix", false) { }
		public override void Start() {
			State1();
		}

		void State2() {
			Transition<Expression>(State5);
		}

		void State3() {
			Transition<BlockLiteral>(State4);
			Transition<BlockLiteral>(State8);
		}

		void State9() {
			Transition<Ws>(State7);
		}

		void State1() {
			Transition("else", State9);
			Transition("elif", State10);
		}

		void State10() {
			Transition<Ws>(State6);
		}

		void State8() {
			Accept();
			Transition<ElseSuffix>(State4);
		}

		void State5() {
			Transition(")", State3);
			Transition(")", State7);
		}

		void State6() {
			Transition("(", State2);
		}

		void State4() {
			Accept();
		}

		void State7() {
			Transition<BlockLiteral>(State4);
		}

	}
}
