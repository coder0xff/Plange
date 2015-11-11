using Parlex;

namespace Generated {
	public partial class ExplicitTypeDereference : Production {
		public ExplicitTypeDereference() : base("ExplicitTypeDereference", false) { }
		public override void Start() {
			State5();
		}

		void State8() {
			Transition<Expression>(State4);
		}

		void State7() {
			Transition(">", State6);
		}

		void State1() {
			Transition<Expression>(State4);
			Transition<VolatileKeyword>(State2);
		}

		void State2() {
			Transition<Ws>(State8);
		}

		void State3() {
			Transition<Ws>(State1);
		}

		void State6() {
			Accept();
		}

		void State4() {
			Transition<Ws>(State7);
		}

		void State5() {
			Transition("<", State3);
		}

	}
}
