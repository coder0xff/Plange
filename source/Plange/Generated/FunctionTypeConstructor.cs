using Parlex;

namespace Generated {
	public partial class FunctionTypeConstructor : Production {
		public FunctionTypeConstructor() : base("FunctionTypeConstructor", false) { }
		public override void Start() {
			State5();
		}

		void State1() {
			Transition<FunctionArrowOp>(State4);
			Transition(",", State3);
		}

		void State7() {
			Transition<Ws>(State1);
		}

		void State5() {
			Transition<Expression>(State7);
		}

		void State4() {
			Transition<Ws>(State6);
		}

		void State6() {
			Transition<Expression>(State2);
		}

		void State2() {
			Accept();
		}

		void State3() {
			Transition<Ws>(State5);
		}

	}
}
