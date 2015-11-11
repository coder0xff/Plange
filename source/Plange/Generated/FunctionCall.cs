using Parlex;

namespace Generated {
	public partial class FunctionCall : Production {
		public FunctionCall() : base("FunctionCall", false) { }
		public override void Start() {
			State2();
		}

		void State8() {
			Transition<Ws>(State7);
		}

		void State3() {
			Transition(")", State4);
		}

		void State4() {
			Accept();
		}

		void State6() {
			Transition<Ws>(State3);
		}

		void State5() {
			Transition<ArgumentList>(State6);
		}

		void State2() {
			Transition<Expression>(State8);
		}

		void State1() {
			Transition<Ws>(State5);
		}

		void State7() {
			Transition("(", State1);
		}

	}
}
