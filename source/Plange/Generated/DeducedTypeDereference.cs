using Parlex;

namespace Generated {
	public partial class DeducedTypeDereference : Production {
		public DeducedTypeDereference() : base("DeducedTypeDereference", false) { }
		public override void Start() {
			State3();
		}

		void State4() {
			Transition<Ws>(State2);
		}

		void State5() {
			Transition<Ws>(State6);
		}

		void State3() {
			Transition("<", State4);
		}

		void State2() {
			Transition(">", State1);
			Transition<VolatileKeyword>(State5);
		}

		void State1() {
			Accept();
		}

		void State6() {
			Transition(">", State1);
		}

	}
}
