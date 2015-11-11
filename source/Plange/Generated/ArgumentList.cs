using Parlex;

namespace Generated {
	public partial class ArgumentList : Production {
		public ArgumentList() : base("ArgumentList", false) { }
		public override void Start() {
			State4();
			State3();
		}

		void State3() {
			Accept();
		}

		void State1() {
			Transition(",", State4);
		}

		void State4() {
			Transition<Expression>(State2);
		}

		void State2() {
			Accept();
			Transition<Ws>(State1);
		}

	}
}
