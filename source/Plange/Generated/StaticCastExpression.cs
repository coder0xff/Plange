using Parlex;

namespace Generated {
	public partial class StaticCastExpression : Production {
		public StaticCastExpression() : base("StaticCastExpression", false) { }
		public override void Start() {
			State5();
		}

		void State3() {
			Transition<Ws>(State7);
		}

		void State6() {
			Transition(")", State4);
		}

		void State5() {
			Transition<ExplicitTypeDereference>(State3);
		}

		void State2() {
			Transition<Ws>(State6);
		}

		void State4() {
			Accept();
		}

		void State8() {
			Transition<Expression>(State2);
		}

		void State1() {
			Transition<Ws>(State8);
		}

		void State7() {
			Transition("(", State1);
		}

	}
}
