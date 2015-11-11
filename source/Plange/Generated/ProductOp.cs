using Parlex;

namespace Generated {
	public partial class ProductOp : Production {
		public ProductOp() : base("ProductOp", false) { }
		public override void Start() {
			State2();
		}

		void State1() {
			Accept();
		}

		void State2() {
			Transition("·", State1);
			Transition("*", State1);
			Transition("×", State1);
		}

	}
}
