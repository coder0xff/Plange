using Parlex;

namespace Generated {
	public partial class ArrayLiteral : Production {
		public ArrayLiteral() : base("ArrayLiteral", false) { }
		public override void Start() {
			State1();
		}

		void State7() {
			Accept();
		}

		void State5() {
			Transition(",", State9);
		}

		void State8() {
			Transition<Expression>(State6);
			Transition<Expression>(State4);
		}

		void State2() {
			Transition<Ws>(State6);
			Transition<Ws>(State8);
		}

		void State6() {
			Transition<Ws>(State3);
		}

		void State9() {
			Transition<Ws>(State8);
		}

		void State1() {
			Transition("[", State2);
		}

		void State4() {
			Transition<Ws>(State5);
		}

		void State3() {
			Transition("]", State7);
		}

	}
}
