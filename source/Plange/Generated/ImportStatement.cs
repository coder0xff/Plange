using Parlex;

namespace Generated {
	public partial class ImportStatement : Production {
		public ImportStatement() : base("ImportStatement", false) { }
		public override void Start() {
			State5();
		}

		void State6() {
			Accept();
		}

		void State2() {
			Transition(";", State6);
		}

		void State4() {
			Transition<Ws>(State1);
		}

		void State5() {
			Transition("import ", State4);
		}

		void State3() {
			Transition<Ws>(State2);
		}

		void State1() {
			Transition<Identifier>(State3);
		}

	}
}
