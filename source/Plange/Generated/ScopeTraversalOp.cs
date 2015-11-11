using Parlex;

namespace Generated {
	public partial class ScopeTraversalOp : Production {
		public ScopeTraversalOp() : base("ScopeTraversalOp", false) { }
		public override void Start() {
			State2();
		}

		void State2() {
			Transition("::", State1);
		}

		void State1() {
			Accept();
		}

	}
}
