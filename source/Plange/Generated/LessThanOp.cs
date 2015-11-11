using Parlex;

namespace Generated {
	public partial class LessThanOp : Production {
		public LessThanOp() : base("LessThanOp", false) { }
		public override void Start() {
			State2();
		}

		void State1() {
			Accept();
		}

		void State2() {
			Transition("<", State1);
		}

	}
}
