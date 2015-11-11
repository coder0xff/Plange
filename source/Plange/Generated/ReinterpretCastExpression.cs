using Parlex;

namespace Generated {
	public partial class ReinterpretCastExpression : Production {
		public ReinterpretCastExpression() : base("ReinterpretCastExpression", false) { }
		public override void Start() {
			State1();
		}

		void State2() {
			Transition<Expression>(State7);
		}

		void State6() {
			Transition<Ws>(State4);
		}

		void State3() {
			Accept();
		}

		void State1() {
			Transition("reinterpret_cast", State6);
		}

		void State5() {
			Transition("(", State2);
		}

		void State4() {
			Transition<ExplicitTypeDereference>(State8);
		}

		void State8() {
			Transition<Ws>(State5);
		}

		void State7() {
			Transition(")", State3);
		}

	}
}
