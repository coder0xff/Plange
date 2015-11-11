using Parlex;

namespace Generated {
	public partial class ConjunctionOp : Production {
		public ConjunctionOp() : base("ConjunctionOp", false) { }
		public override void Start() {
			State2();
		}

		void State2() {
			Transition("∧", State1);
		}

		void State1() {
			Accept();
		}

	}
}
