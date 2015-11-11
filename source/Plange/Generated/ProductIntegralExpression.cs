using Parlex;

namespace Generated {
	public partial class ProductIntegralExpression : Production {
		public ProductIntegralExpression() : base("ProductIntegralExpression", false) { }
		public override void Start() {
			State11();
		}

		void State8() {
			Transition<Ws>(State5);
		}

		void State7() {
			Transition<Ws>(State13);
		}

		void State6() {
			Transition(",", State1);
			Transition(")", State14);
		}

		void State9() {
			Transition<Ws>(State3);
		}

		void State2() {
			Transition<Ws>(State4);
		}

		void State12() {
			Transition<Ws>(State6);
		}

		void State13() {
			Transition(")", State14);
		}

		void State1() {
			Transition<Ws>(State10);
		}

		void State10() {
			Transition<Expression>(State9);
		}

		void State4() {
			Transition<Expression>(State12);
		}

		void State5() {
			Transition<Expression>(State7);
		}

		void State3() {
			Transition(",", State8);
			Transition(")", State14);
		}

		void State11() {
			Transition("∏(", State2);
		}

		void State14() {
			Accept();
		}

	}
}
