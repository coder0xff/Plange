using Parlex;

namespace Generated {
	public partial class ThisKeyword : Production {
		public ThisKeyword() : base("ThisKeyword", false) { }
		public override void Start() {
			State1();
		}

		void State2() {
			Accept();
		}

		void State1() {
			Transition("this", State2);
		}

	}
}
