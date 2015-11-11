using Parlex;

namespace Generated {
	public partial class ImplicitDerivativeExpression : Production {
		public ImplicitDerivativeExpression() : base("ImplicitDerivativeExpression", false) { }
		public override void Start() {
			State3();
		}

		void State2() {
			Accept();
		}

		void State1() {
			Transition("’", State2);
		}

		void State3() {
			Transition<Expression>(State1);
		}

	}
}
