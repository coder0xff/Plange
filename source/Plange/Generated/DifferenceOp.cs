using Parlex;

namespace Generated {
	public partial class DifferenceOp : Production {
		public DifferenceOp() : base("DifferenceOp", false) { }
		public override void Start() {
			State1();
		}

		void State2() {
			Accept();
		}

		void State1() {
			Transition("-", State2);
		}

	}
}
