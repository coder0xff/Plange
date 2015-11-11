using Parlex;

namespace Generated {
	public partial class VolatileKeyword : Production {
		public VolatileKeyword() : base("VolatileKeyword", false) { }
		public override void Start() {
			State2();
		}

		void State2() {
			Transition("volatile", State1);
		}

		void State1() {
			Accept();
		}

	}
}
