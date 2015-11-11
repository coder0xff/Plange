using Parlex;

namespace Generated {
	public partial class ExponentiationOp : Production {
		public ExponentiationOp() : base("ExponentiationOp", false) { }
		public override void Start() {
			State2();
		}

		void State1() {
			Accept();
		}

		void State2() {
			Transition("^", State1);
		}

	}
}
