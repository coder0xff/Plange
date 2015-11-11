using Parlex;

namespace Generated {
	public partial class AssignmentStatement : Production {
		public AssignmentStatement() : base("AssignmentStatement", false) { }
		public override void Start() {
			State1();
		}

		void State1() {
			Transition<LvalueExpression>(State3);
		}

		void State2() {
			Accept();
		}

		void State6() {
			Transition("<-", State4);
		}

		void State5() {
			Transition<Expression>(State7);
		}

		void State4() {
			Transition<Ws>(State5);
		}

		void State3() {
			Transition<Ws>(State6);
		}

		void State8() {
			Transition(";", State2);
		}

		void State7() {
			Transition<Ws>(State8);
		}

	}
}
