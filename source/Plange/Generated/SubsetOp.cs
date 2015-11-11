using Parlex;

namespace Generated {
	public partial class SubsetOp : Production {
		public SubsetOp() : base("SubsetOp", false) { }
		public override void Start() {
			State2();
		}

		void State1() {
			Accept();
		}

		void State2() {
			Transition("⊆", State1);
		}

	}
}
