using Parlex;

namespace Generated {
	public partial class LineIntegralExpression : Production {
		public LineIntegralExpression() : base("LineIntegralExpression", false) { }
		public override void Start() {
			State11();
		}

		void State8() {
			Transition<Expression>(State12);
		}

		void State12() {
			Transition<Ws>(State10);
		}

		void State2() {
			Transition<Ws>(State3);
		}

		void State7() {
			Transition<Ws>(State9);
		}

		void State14() {
			Transition<Ws>(State5);
		}

		void State1() {
			Accept();
		}

		void State3() {
			Transition<Expression>(State13);
		}

		void State11() {
			Transition("∮(", State4);
		}

		void State5() {
			Transition<Expression>(State7);
		}

		void State10() {
			Transition(",", State14);
			Transition(")", State1);
		}

		void State6() {
			Transition(")", State1);
		}

		void State9() {
			Transition(",", State2);
			Transition(")", State1);
		}

		void State4() {
			Transition<Ws>(State8);
		}

		void State13() {
			Transition<Ws>(State6);
		}

	}
}
