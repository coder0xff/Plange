using Parlex;

namespace Generated {
	public partial class IntervalExpression : Production {
		public IntervalExpression() : base("IntervalExpression", false) { }
		public override void Start() {
			State2();
		}

		void State9() {
			Transition<Ws>(State6);
		}

		void State2() {
			Transition("(", State5);
			Transition("[", State5);
		}

		void State7() {
			Transition(")", State8);
			Transition("]", State8);
		}

		void State3() {
			Transition<Expression>(State10);
		}

		void State4() {
			Transition<Ws>(State3);
		}

		void State10() {
			Transition<Ws>(State7);
		}

		void State1() {
			Transition<Expression>(State9);
		}

		void State8() {
			Accept();
		}

		void State5() {
			Transition<Ws>(State1);
		}

		void State6() {
			Transition("to", State4);
		}

	}
}
