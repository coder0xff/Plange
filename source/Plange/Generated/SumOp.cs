using Parlex;

namespace Generated {
	public partial class SumOp : Production {
		public SumOp() : base("SumOp", false) { }
		public override void Start() {
			State1();
		}

		void State1() {
			Transition("+", State2);
		}

		void State2() {
			Accept();
		}

	}
}
