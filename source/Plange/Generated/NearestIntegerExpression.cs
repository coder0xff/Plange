using Parlex;

namespace Generated {
	public partial class NearestIntegerExpression : Production {
		public NearestIntegerExpression() : base("NearestIntegerExpression", false) { }
		public override void Start() {
			State2();
		}

		void State7() {
			Transition<Expression>(State3);
		}

		void State6() {
			Transition<Ws>(State7);
		}

		void State10() {
			Transition<Ws>(State5);
		}

		void State4() {
			Accept();
		}

		void State5() {
			Transition("||", State4);
		}

		void State1() {
			Transition<Expression>(State10);
		}

		void State9() {
			Transition<Ws>(State1);
		}

		void State2() {
			Transition("||", State9);
			Transition("⌊", State6);
		}

		void State3() {
			Transition<Ws>(State8);
		}

		void State8() {
			Transition("⌉", State4);
		}

	}
}
