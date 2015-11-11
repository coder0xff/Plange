using Parlex;

namespace Generated {
	public partial class Syntax : Production {
		public Syntax() : base("Syntax", false) { }
		public override void Start() {
			State2();
		}

		void State2() {
			Transition<Ws>(State1);
		}

		void State1() {
			Accept();
			Transition<Statement>(State2);
		}

	}
}
