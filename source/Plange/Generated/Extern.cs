using Parlex;

namespace Generated {
	public partial class Extern : Production {
		public Extern() : base("Extern", false) { }
		public override void Start() {
			State5();
		}

		void State1() {
			Transition<Ws>(State2);
		}

		void State4() {
			Accept();
		}

		void State3() {
			Transition<Ws>(State6);
		}

		void State6() {
			Transition<FunctionTypeConstructor>(State1);
		}

		void State5() {
			Transition("extern ", State3);
		}

		void State2() {
			Transition<Symbol>(State4);
		}

	}
}
