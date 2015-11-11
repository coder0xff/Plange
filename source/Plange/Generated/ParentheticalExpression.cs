using Parlex;

namespace Generated {
	public partial class ParentheticalExpression : Production {
		public ParentheticalExpression() : base("ParentheticalExpression", false) { }
		public override void Start() {
			State5();
		}

		void State5() {
			Transition("(", State4);
		}

		void State3() {
			Transition<Ws>(State2);
		}

		void State2() {
			Transition(")", State1);
		}

		void State6() {
			Transition<Expression>(State3);
		}

		void State1() {
			Accept();
		}

		void State4() {
			Transition<Ws>(State6);
		}

	}
}
