using Parlex;

namespace Generated {
	public partial class NotEqualOp : Production {
		public NotEqualOp() : base("NotEqualOp", false) { }
		public override void Start() {
			State2();
		}

		void State2() {
			Transition("!=", State1);
			Transition("≠", State1);
		}

		void State1() {
			Accept();
		}

	}
}
