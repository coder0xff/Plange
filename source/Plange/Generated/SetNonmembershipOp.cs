using Parlex;

namespace Generated {
	public partial class SetNonmembershipOp : Production {
		public SetNonmembershipOp() : base("SetNonmembershipOp", false) { }
		public override void Start() {
			State2();
		}

		void State2() {
			Transition("∉", State1);
		}

		void State1() {
			Accept();
		}

	}
}
