using Parlex;

namespace Generated {
	public partial class SupersetOp : Production {
		public SupersetOp() : base("SupersetOp", false) { }
		public override void Start() {
			State2();
		}

		void State1() {
			Accept();
		}

		void State2() {
			Transition("⊇", State1);
		}

	}
}
