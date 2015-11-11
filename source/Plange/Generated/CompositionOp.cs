using Parlex;

namespace Generated {
	public partial class CompositionOp : Production {
		public CompositionOp() : base("CompositionOp", false) { }
		public override void Start() {
			State1();
		}

		void State2() {
			Accept();
		}

		void State1() {
			Transition("○", State2);
		}

	}
}
