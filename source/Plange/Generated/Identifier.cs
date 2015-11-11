using Parlex;

namespace Generated {
	public partial class Identifier : Production {
		public Identifier() : base("Identifier", false) { }
		public override void Start() {
			State4();
		}

		void State6() {
			Accept();
		}

		void State5() {
			Transition<Ws>(State2);
		}

		void State4() {
			Transition<Symbol>(State3);
			Transition<ThisKeyword>(State6);
		}

		void State2() {
			Transition<Symbol>(State3);
		}

		void State1() {
			Transition<ScopeTraversalOp>(State5);
		}

		void State3() {
			Accept();
			Transition<Ws>(State1);
		}

	}
}
