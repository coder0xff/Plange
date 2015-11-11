using Parlex;

namespace Generated {
	public partial class CatchBlock : Production {
		public CatchBlock() : base("CatchBlock", false) { }
		public override void Start() {
			State7();
		}

		void State6() {
			Transition<Ws>(State1);
		}

		void State9() {
			Transition<Ws>(State3);
		}

		void State7() {
			Transition("catch", State6);
		}

		void State4() {
			Transition<Ws>(State10);
		}

		void State10() {
			Transition(")", State9);
		}

		void State3() {
			Transition<BlockLiteral>(State5);
		}

		void State1() {
			Transition("(", State2);
		}

		void State2() {
			Transition<Ws>(State8);
		}

		void State5() {
			Accept();
		}

		void State8() {
			Transition<Expression>(State4);
		}

	}
}
