using Parlex;

namespace Generated {
	public partial class SetBuilderExpression : Production {
		public SetBuilderExpression() : base("SetBuilderExpression", false) { }
		public override void Start() {
			State6();
		}

		void State9() {
			Transition<Ws>(State3);
		}

		void State6() {
			Transition("{", State9);
		}

		void State8() {
			Transition("}", State7);
		}

		void State1() {
			Transition<Ws>(State2);
		}

		void State3() {
			Transition<Expression>(State1);
		}

		void State2() {
			Transition(":", State5);
		}

		void State5() {
			Transition<Ws>(State4);
		}

		void State7() {
			Accept();
		}

		void State4() {
			Transition<Expression>(State8);
		}

	}
}
