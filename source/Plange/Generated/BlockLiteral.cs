using Parlex;

namespace Generated {
	public partial class BlockLiteral : Production {
		public BlockLiteral() : base("BlockLiteral", false) { }
		public override void Start() {
			State4();
		}

		void State2() {
			Transition("}", State1);
			Transition<Statement>(State3);
		}

		void State4() {
			Transition("{", State3);
		}

		void State1() {
			Accept();
		}

		void State3() {
			Transition<Ws>(State2);
		}

	}
}
