using Parlex;

namespace Generated {
	public partial class TypeofExpression : Production {
		public TypeofExpression() : base("TypeofExpression", false) { }
		public override void Start() {
			State3();
		}

		void State1() {
			Transition<Expression>(State2);
		}

		void State4() {
			Transition<Ws>(State1);
		}

		void State2() {
			Transition<Ws>(State6);
		}

		void State5() {
			Accept();
		}

		void State3() {
			Transition("typeof(", State4);
		}

		void State6() {
			Transition(")", State5);
		}

	}
}
