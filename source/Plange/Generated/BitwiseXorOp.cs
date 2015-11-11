using Parlex;

namespace Generated {
	public partial class BitwiseXorOp : Production {
		public BitwiseXorOp() : base("BitwiseXorOp", false) { }
		public override void Start() {
			State2();
		}

		void State2() {
			Transition("⊕", State1);
		}

		void State1() {
			Accept();
		}

	}
}
