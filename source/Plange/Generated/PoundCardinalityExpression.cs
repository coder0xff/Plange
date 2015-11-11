using Parlex;

namespace Generated {
	public partial class PoundCardinalityExpression : Production {
		public PoundCardinalityExpression() : base("PoundCardinalityExpression", false) { }
		public override void Start() {
			State2();
		}

		void State4() {
			Transition<Expression>(State3);
		}

		void State1() {
			Transition<Ws>(State4);
		}

		void State2() {
			Transition("#", State1);
		}

		void State3() {
			Accept();
		}

	}
}
