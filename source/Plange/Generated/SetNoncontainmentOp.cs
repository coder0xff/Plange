using Parlex;

namespace Generated {
	public partial class SetNoncontainmentOp : Production {
		public SetNoncontainmentOp() : base("SetNoncontainmentOp", false) { }
		public override void Start() {
			State2();
		}

		void State2() {
			Transition("∌", State1);
		}

		void State1() {
			Accept();
		}

	}
}
