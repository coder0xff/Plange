using Parlex;

namespace Generated {
	public partial class SetContainmentOp : Production {
		public SetContainmentOp() : base("SetContainmentOp", false) { }
		public override void Start() {
			State2();
		}

		void State2() {
			Transition("∋", State1);
		}

		void State1() {
			Accept();
		}

	}
}
