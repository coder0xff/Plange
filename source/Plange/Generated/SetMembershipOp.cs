using Parlex;

namespace Generated {
	public partial class SetMembershipOp : Production {
		public SetMembershipOp() : base("SetMembershipOp", false) { }
		public override void Start() {
			State1();
		}

		void State1() {
			Transition("∈", State2);
		}

		void State2() {
			Accept();
		}

	}
}
