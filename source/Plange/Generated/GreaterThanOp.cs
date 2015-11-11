using Parlex;

namespace Generated {
	public partial class GreaterThanOp : Production {
		public GreaterThanOp() : base("GreaterThanOp", false) { }
		public override void Start() {
			State2();
		}

		void State2() {
			Transition(">", State1);
		}

		void State1() {
			Accept();
		}

	}
}
