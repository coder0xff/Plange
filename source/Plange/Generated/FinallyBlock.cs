using Parlex;

namespace Generated {
	public partial class FinallyBlock : Production {
		public FinallyBlock() : base("FinallyBlock", false) { }
		public override void Start() {
			State3();
		}

		void State3() {
			Transition("finally", State4);
		}

		void State4() {
			Transition<Ws>(State2);
		}

		void State2() {
			Transition<BlockLiteral>(State1);
		}

		void State1() {
			Accept();
		}

	}
}
