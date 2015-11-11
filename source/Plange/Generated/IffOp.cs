using Parlex;

namespace Generated {
	public partial class IffOp : Production {
		public IffOp() : base("IffOp", false) { }
		public override void Start() {
			State2();
		}

		void State2() {
			Transition("<=>", State1);
			Transition("⇔", State1);
		}

		void State1() {
			Accept();
		}

	}
}
