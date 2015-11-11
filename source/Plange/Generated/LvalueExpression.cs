using Parlex;

namespace Generated {
	public partial class LvalueExpression : Production {
		public LvalueExpression() : base("LvalueExpression", false) { }
		public override void Start() {
			State2();
		}

		void State1() {
			Accept();
		}

		void State2() {
			Transition<Expression>(State1);
		}

	}
}
