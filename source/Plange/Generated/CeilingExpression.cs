using Parlex;

namespace Generated {
	public partial class CeilingExpression : Production {
		public CeilingExpression() : base("CeilingExpression", false) { }
		public override void Start() {
			State4();
		}

		void State6() {
			Transition("⌉", State1);
		}

		void State3() {
			Transition<Ws>(State5);
		}

		void State5() {
			Transition<Expression>(State2);
		}

		void State1() {
			Accept();
		}

		void State2() {
			Transition<Ws>(State6);
		}

		void State4() {
			Transition("⌈", State3);
		}

	}
}
