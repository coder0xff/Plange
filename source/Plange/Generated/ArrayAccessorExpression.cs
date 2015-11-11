using Parlex;

namespace Generated {
	public partial class ArrayAccessorExpression : Production {
		public ArrayAccessorExpression() : base("ArrayAccessorExpression", false) { }
		public override void Start() {
			State5();
		}

		void State4() {
			Transition<Ws>(State2);
		}

		void State5() {
			Transition<Expression>(State7);
		}

		void State6() {
			Transition("[", State3);
		}

		void State7() {
			Transition<Ws>(State6);
		}

		void State3() {
			Transition<Ws>(State1);
		}

		void State8() {
			Accept();
		}

		void State1() {
			Transition<ArgumentList>(State4);
		}

		void State2() {
			Transition("]", State8);
		}

	}
}
