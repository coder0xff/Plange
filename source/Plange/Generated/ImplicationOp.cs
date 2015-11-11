using Parlex;

namespace Generated {
	public partial class ImplicationOp : Production {
		public ImplicationOp() : base("ImplicationOp", false) { }
		public override void Start() {
			State1();
		}

		void State1() {
			Transition("⇒", State2);
			Transition("=>", State2);
		}

		void State2() {
			Accept();
		}

	}
}
