using Parlex;

namespace Generated {
	public partial class IntegralExpression : Production {
		public IntegralExpression() : base("IntegralExpression", false) { }
		public override void Start() {
			State2();
		}

		void State4() {
			Accept();
		}

		void State6() {
			Transition<Expression>(State12);
		}

		void State5() {
			Transition(")", State4);
		}

		void State8() {
			Transition(",", State14);
			Transition(")", State4);
		}

		void State2() {
			Transition("∫(", State10);
		}

		void State13() {
			Transition<Ws>(State6);
		}

		void State9() {
			Transition<Expression>(State1);
		}

		void State12() {
			Transition<Ws>(State8);
		}

		void State1() {
			Transition<Ws>(State5);
		}

		void State11() {
			Transition(",", State13);
			Transition(")", State4);
		}

		void State14() {
			Transition<Ws>(State9);
		}

		void State3() {
			Transition<Expression>(State7);
		}

		void State10() {
			Transition<Ws>(State3);
		}

		void State7() {
			Transition<Ws>(State11);
		}

	}
}
