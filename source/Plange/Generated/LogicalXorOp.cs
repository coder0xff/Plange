using Parlex;

namespace Generated {
	public partial class LogicalXorOp : Production {
		public LogicalXorOp() : base("LogicalXorOp", false) { }
		public override void Start() {
			State1();
		}

		void State2() {
			Accept();
		}

		void State1() {
			Transition("⊻", State2);
		}

	}
}
