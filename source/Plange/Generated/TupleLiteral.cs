using Parlex;

namespace Generated {
	public partial class TupleLiteral : Production {
		public TupleLiteral() : base("TupleLiteral", false) { }
		public override void Start() {
			State2();
		}

		void State3() {
			Transition<Ws>(State7);
		}

		void State8() {
			Transition<Expression>(State6);
		}

		void State10() {
			Transition(")", State5);
			Transition<Expression>(State6);
			Transition<Expression>(State3);
		}

		void State1() {
			Transition(", ", State4);
		}

		void State2() {
			Transition("(", State9);
		}

		void State6() {
			Transition<Ws>(State1);
		}

		void State9() {
			Transition<Ws>(State8);
		}

		void State7() {
			Transition(")", State5);
		}

		void State5() {
			Accept();
		}

		void State4() {
			Transition<Ws>(State10);
		}

	}
}
