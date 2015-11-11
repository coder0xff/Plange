using Parlex;

namespace Generated {
	public partial class ExplicitDeclarationStatement : Production {
		public ExplicitDeclarationStatement() : base("ExplicitDeclarationStatement", false) { }
		public override void Start() {
			State3();
		}

		void State1() {
			Accept();
		}

		void State3() {
			Transition<ExplicitTypeDereference>(State6);
		}

		void State6() {
			Transition<Ws>(State2);
		}

		void State5() {
			Transition(";", State1);
		}

		void State2() {
			Transition<Symbol>(State4);
		}

		void State4() {
			Transition<Ws>(State5);
		}

	}
}
