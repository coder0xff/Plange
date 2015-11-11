using Parlex;

namespace Generated {
	public partial class EqualToOp : Production {
		public EqualToOp() : base("EqualToOp", false) { }
		public override void Start() {
			State2();
		}

		void State2() {
			Transition("=", State1);
		}

		void State1() {
			Accept();
		}

	}
}
