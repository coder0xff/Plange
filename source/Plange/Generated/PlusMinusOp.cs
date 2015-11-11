using Parlex;

namespace Generated {
	public partial class PlusMinusOp : Production {
		public PlusMinusOp() : base("PlusMinusOp", false) { }
		public override void Start() {
			State1();
		}

		void State1() {
			Transition("±", State2);
		}

		void State2() {
			Accept();
		}

	}
}
