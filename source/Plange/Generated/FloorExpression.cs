using Parlex;

namespace Generated {
	public partial class FloorExpression : Production {
		public FloorExpression() : base("FloorExpression", false) { }
		public override void Start() {
			State5();
		}

		void State1() {
			Transition<Expression>(State3);
		}

		void State5() {
			Transition("⌊", State6);
		}

		void State4() {
			Accept();
		}

		void State3() {
			Transition<Ws>(State2);
		}

		void State6() {
			Transition<Ws>(State1);
		}

		void State2() {
			Transition("⌋", State4);
		}

	}
}
