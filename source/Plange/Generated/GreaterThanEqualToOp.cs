using Parlex;

namespace Generated {
	public partial class GreaterThanEqualToOp : Production {
		public GreaterThanEqualToOp() : base("GreaterThanEqualToOp", false) { }
		public override void Start() {
			State1();
		}

		void State2() {
			Accept();
		}

		void State1() {
			Transition("≥", State2);
			Transition(">=", State2);
		}

	}
}
