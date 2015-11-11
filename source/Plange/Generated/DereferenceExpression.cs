using Parlex;

namespace Generated {
	public partial class DereferenceExpression : Production {
		public DereferenceExpression() : base("DereferenceExpression", false) { }
		public override void Start() {
			State3();
		}

		void State4() {
			Accept();
		}

		void State3() {
			Transition("dereference(", State2);
		}

		void State2() {
			Transition<Expression>(State1);
		}

		void State1() {
			Transition(")", State4);
		}

	}
}
