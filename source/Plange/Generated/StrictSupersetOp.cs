using Parlex;

namespace Generated {
	public partial class StrictSupersetOp : Production {
		public StrictSupersetOp() : base("StrictSupersetOp", false) { }
		public override void Start() {
			State2();
		}

		void State1() {
			Accept();
		}

		void State2() {
			Transition("⊃", State1);
		}

	}
}
