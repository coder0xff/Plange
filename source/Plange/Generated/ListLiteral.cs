using Parlex;

namespace Generated {
	public partial class ListLiteral : Production {
		public ListLiteral() : base("ListLiteral", false) { }
		public override void Start() {
			State5();
		}

		void State1() {
			Transition<Ws>(State6);
		}

		void State2() {
			Accept();
		}

		void State3() {
			Transition<Expression>(State1);
		}

		void State4() {
			Transition<Ws>(State3);
		}

		void State5() {
			Transition("[", State4);
		}

		void State6() {
			Transition(",", State4);
			Transition("]", State2);
		}

	}
}
