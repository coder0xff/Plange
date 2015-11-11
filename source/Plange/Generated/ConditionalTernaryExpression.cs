using Parlex;

namespace Generated {
	public partial class ConditionalTernaryExpression : Production {
		public ConditionalTernaryExpression() : base("ConditionalTernaryExpression", false) { }
		public override void Start() {
			State1();
		}

		void State8() {
			Transition<Ws>(State2);
		}

		void State4() {
			Transition<Ws>(State9);
		}

		void State5() {
			Transition<Ws>(State10);
		}

		void State2() {
			Transition<Expression>(State6);
		}

		void State6() {
			Accept();
		}

		void State10() {
			Transition(":", State8);
		}

		void State7() {
			Transition<Ws>(State3);
		}

		void State1() {
			Transition<Expression>(State7);
		}

		void State3() {
			Transition("?", State4);
		}

		void State9() {
			Transition<Expression>(State5);
		}

	}
}
