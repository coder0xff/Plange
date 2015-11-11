using Parlex;

namespace Generated {
	public partial class InfixExpression : Production {
		public InfixExpression() : base("InfixExpression", false) { }
		public override void Start() {
			State2();
		}

		void State1() {
			Transition<Ws>(State5);
		}

		void State2() {
			Transition<Expression>(State6);
		}

		void State4() {
			Accept();
		}

		void State6() {
			Transition<Ws>(State3);
		}

		void State5() {
			Transition<Expression>(State4);
		}

		void State3() {
			Transition<BinaryOperator>(State1);
		}

	}
}
