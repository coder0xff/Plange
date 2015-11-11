using Parlex;

namespace Generated {
	public partial class QuotientOp : Production {
		public QuotientOp() : base("QuotientOp", false) { }
		public override void Start() {
			State1();
		}

		void State1() {
			Transition("/", State2);
			Transition("÷", State2);
		}

		void State2() {
			Accept();
		}

	}
}
