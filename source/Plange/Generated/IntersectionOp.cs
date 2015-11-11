using Parlex;

namespace Generated {
	public partial class IntersectionOp : Production {
		public IntersectionOp() : base("IntersectionOp", false) { }
		public override void Start() {
			State1();
		}

		void State1() {
			Transition("∩", State2);
		}

		void State2() {
			Accept();
		}

	}
}
