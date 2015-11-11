using Parlex;

namespace Generated {
	public partial class MagnitudeExpression : Production {
		public MagnitudeExpression() : base("MagnitudeExpression", false) { }
		public override void Start() {
			State1();
		}

		void State3() {
			Transition("|", State5);
		}

		void State1() {
			Transition("|", State6);
		}

		void State6() {
			Transition<Ws>(State2);
		}

		void State4() {
			Transition<Ws>(State3);
		}

		void State5() {
			Accept();
		}

		void State2() {
			Transition<Expression>(State4);
		}

	}
}
