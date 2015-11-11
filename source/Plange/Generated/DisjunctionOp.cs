using Parlex;

namespace Generated {
	public partial class DisjunctionOp : Production {
		public DisjunctionOp() : base("DisjunctionOp", false) { }
		public override void Start() {
			State2();
		}

		void State1() {
			Accept();
		}

		void State2() {
			Transition("∨", State1);
		}

	}
}
