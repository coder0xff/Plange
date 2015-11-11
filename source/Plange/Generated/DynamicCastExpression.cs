using Parlex;

namespace Generated {
	public partial class DynamicCastExpression : Production {
		public DynamicCastExpression() : base("DynamicCastExpression", false) { }
		public override void Start() {
			State8();
		}

		void State3() {
			Transition(")", State7);
		}

		void State2() {
			Transition<Ws>(State5);
		}

		void State5() {
			Transition("(", State4);
		}

		void State8() {
			Transition("dynamic_cast", State6);
		}

		void State4() {
			Transition<Expression>(State3);
		}

		void State1() {
			Transition<ExplicitTypeDereference>(State2);
		}

		void State6() {
			Transition<Ws>(State1);
		}

		void State7() {
			Accept();
		}

	}
}
