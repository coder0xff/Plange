using Parlex;

namespace Generated {
	public partial class SymmetricDifferenceOp : Production {
		public SymmetricDifferenceOp() : base("SymmetricDifferenceOp", false) { }
		public override void Start() {
			State2();
		}

		void State1() {
			Accept();
		}

		void State2() {
			Transition("⊖", State1);
		}

	}
}
