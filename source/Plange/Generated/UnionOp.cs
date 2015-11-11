using Parlex;

namespace Generated {
	public partial class UnionOp : Production {
		public UnionOp() : base("UnionOp", false) { }
		public override void Start() {
			State2();
		}

		void State2() {
			Transition("∪", State1);
		}

		void State1() {
			Accept();
		}

	}
}
