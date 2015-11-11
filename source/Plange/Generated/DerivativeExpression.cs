using Parlex;

namespace Generated {
	public partial class DerivativeExpression : Production {
		public DerivativeExpression() : base("DerivativeExpression", false) { }
		public override void Start() {
			State2();
		}

		void State2() {
			Transition<ExplicitDerivativeExpression>(State1);
			Transition<ImplicitDerivativeExpression>(State1);
		}

		void State1() {
			Accept();
		}

	}
}
