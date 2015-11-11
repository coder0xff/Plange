using Parlex;

namespace Generated {
	public partial class NewExpression : Production {
		public NewExpression() : base("NewExpression", false) { }
		public override void Start() {
			State1();
		}

		void State5() {
			Transition<Ws>(State4);
		}

		void State2() {
			Transition("(", State9);
		}

		void State9() {
			Transition<Ws>(State8);
		}

		void State10() {
			Transition<Ws>(State2);
		}

		void State6() {
			Transition<ExplicitTypeDereference>(State10);
		}

		void State8() {
			Transition<ArgumentList>(State5);
		}

		void State1() {
			Transition("new", State3);
		}

		void State3() {
			Transition<Ws>(State6);
		}

		void State4() {
			Transition(")", State7);
		}

		void State7() {
			Accept();
		}

	}
}
