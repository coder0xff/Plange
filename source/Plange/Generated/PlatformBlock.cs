using Parlex;

namespace Generated {
	public partial class PlatformBlock : Production {
		public PlatformBlock() : base("PlatformBlock", false) { }
		public override void Start() {
			State2();
		}

		void State1() {
			Transition<BlockLiteral>(State3);
		}

		void State4() {
			Transition<Symbol>(State1);
		}

		void State2() {
			Transition("_", State4);
		}

		void State3() {
			Accept();
		}

	}
}
