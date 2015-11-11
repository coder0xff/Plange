using Parlex;

namespace Generated {
	public partial class StrictSubsetOp : Production {
		public StrictSubsetOp() : base("StrictSubsetOp", false) { }
		public override void Start() {
			State1();
		}

		void State2() {
			Accept();
		}

		void State1() {
			Transition("⊂", State2);
		}

	}
}
