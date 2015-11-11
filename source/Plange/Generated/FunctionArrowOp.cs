using Parlex;

namespace Generated {
	public partial class FunctionArrowOp : Production {
		public FunctionArrowOp() : base("FunctionArrowOp", false) { }
		public override void Start() {
			State1();
		}

		void State2() {
			Accept();
		}

		void State1() {
			Transition("->", State2);
			Transition("→", State2);
		}

	}
}
