using Parlex;

namespace Generated {
	public partial class SetLiteral : Production {
		public SetLiteral() : base("SetLiteral", false) { }
		public override void Start() {
			State5();
		}

		void State6() {
			Transition<Ws>(State1);
		}

		void State3() {
			Accept();
		}

		void State2() {
			Transition(",", State6);
			Transition("}", State3);
		}

		void State5() {
			Transition("{", State6);
		}

		void State4() {
			Transition<Ws>(State2);
		}

		void State1() {
			Transition<Expression>(State4);
		}

	}
}
