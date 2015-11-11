using Parlex;

namespace Generated {
	public partial class SummationExpression : Production {
		public SummationExpression() : base("SummationExpression", false) { }
		public override void Start() {
			State12();
		}

		void State8() {
			Transition(",", State5);
			Transition(")", State4);
		}

		void State11() {
			Transition<Expression>(State13);
		}

		void State12() {
			Transition("Σ(", State6);
		}

		void State14() {
			Transition(",", State10);
			Transition(")", State4);
		}

		void State2() {
			Transition<Ws>(State8);
		}

		void State7() {
			Transition(")", State4);
		}

		void State4() {
			Accept();
		}

		void State10() {
			Transition<Ws>(State11);
		}

		void State9() {
			Transition<Expression>(State2);
		}

		void State6() {
			Transition<Ws>(State9);
		}

		void State3() {
			Transition<Ws>(State14);
		}

		void State13() {
			Transition<Ws>(State7);
		}

		void State5() {
			Transition<Ws>(State1);
		}

		void State1() {
			Transition<Expression>(State3);
		}

	}
}
