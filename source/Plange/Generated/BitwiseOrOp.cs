using Parlex;

namespace Generated {
	public partial class BitwiseOrOp : Production {
		public BitwiseOrOp() : base("BitwiseOrOp", false) { }
		public override void Start() {
			State2();
		}

		void State1() {
			Accept();
		}

		void State2() {
			Transition("|", State1);
		}

	}
}
