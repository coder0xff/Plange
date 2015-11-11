using Parlex;

namespace Generated {
	public partial class AtKeyword : Production {
		public AtKeyword() : base("AtKeyword", false) { }
		public override void Start() {
			State2();
		}

		void State2() {
			Transition("at", State1);
		}

		void State1() {
			Accept();
		}

	}
}
