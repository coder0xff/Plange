using Parlex;

namespace Generated {
	public partial class NegationExpression : Production {
		public NegationExpression() : base("NegationExpression", false) { }
		public override void Start() {
			State2();
		}

		void State1() {
			Transition<Expression>(State3);
		}

		void State2() {
			Transition("-", State1);
		}

		void State3() {
			Accept();
		}

	}
}
