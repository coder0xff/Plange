using Parlex;

namespace Generated {
	public partial class PipeParentheticalExpression : Production {
		public PipeParentheticalExpression() : base("PipeParentheticalExpression", false) { }
		public override void Start() {
			State1();
		}

		void State1() {
			Transition("|", State5);
		}

		void State4() {
			Transition<Expression>(State3);
		}

		void State5() {
			Transition<Ws>(State4);
		}

		void State2() {
			Accept();
		}

		void State3() {
			Transition<Ws>(State6);
		}

		void State6() {
			Transition("|", State2);
		}

	}
}
