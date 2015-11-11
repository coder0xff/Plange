using Parlex;

namespace Generated {
	public partial class ExplicitDerivativeExpression : Production {
		public ExplicitDerivativeExpression() : base("ExplicitDerivativeExpression", false) { }
		public override void Start() {
			State5();
		}

		void State4() {
			Transition("d/d", State3);
		}

		void State3() {
			Transition<Expression>(State2);
		}

		void State1() {
			Transition<Ws>(State4);
		}

		void State5() {
			Transition<Expression>(State1);
		}

		void State2() {
			Accept();
		}

	}
}
