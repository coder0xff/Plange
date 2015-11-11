using Parlex;

namespace Generated {
	public partial class AddressOf : Production {
		public AddressOf() : base("AddressOf", false) { }
		public override void Start() {
			State2();
		}

		void State4() {
			Transition(")", State3);
		}

		void State1() {
			Transition<Ws>(State4);
		}

		void State3() {
			Accept();
		}

		void State5() {
			Transition<Ws>(State6);
		}

		void State6() {
			Transition<Identifier>(State1);
		}

		void State2() {
			Transition("address_of(", State5);
		}

	}
}
