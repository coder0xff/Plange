using Parlex;

namespace Generated {
	public partial class SurfaceIntegralExpression : Production {
		public SurfaceIntegralExpression() : base("SurfaceIntegralExpression", false) { }
		public override void Start() {
			State11();
		}

		void State5() {
			Transition<Expression>(State12);
		}

		void State11() {
			Transition("∫∫(", State1);
		}

		void State10() {
			Transition<Expression>(State13);
		}

		void State13() {
			Transition<Ws>(State7);
		}

		void State8() {
			Transition<Ws>(State9);
		}

		void State4() {
			Transition(",", State14);
			Transition(")", State3);
		}

		void State9() {
			Transition<Expression>(State6);
		}

		void State6() {
			Transition<Ws>(State4);
		}

		void State12() {
			Transition<Ws>(State2);
		}

		void State3() {
			Accept();
		}

		void State2() {
			Transition(",", State8);
			Transition(")", State3);
		}

		void State1() {
			Transition<Ws>(State5);
		}

		void State14() {
			Transition<Ws>(State10);
		}

		void State7() {
			Transition(")", State3);
		}

	}
}
