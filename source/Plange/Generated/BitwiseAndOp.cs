using Parlex;

namespace Generated {
	public partial class BitwiseAndOp : Production {
		public BitwiseAndOp() : base("BitwiseAndOp", false) { }
		public override void Start() {
			State1();
		}

		void State2() {
			Accept();
		}

		void State1() {
			Transition("&", State2);
		}

	}
}
