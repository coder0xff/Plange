using Parlex;

namespace Generated {
	public partial class FunctionLiteral : Production {
		public FunctionLiteral() : base("FunctionLiteral", false) { }
		public override void Start() {
			State1();
			State4();
			State7();
		}

		void State5() {
			Accept();
		}

		void State4() {
			Transition<BlockLiteral>(State5);
		}

		void State1() {
			Transition("opaque", State3);
			Transition("pure", State3);
			Transition("imperative", State3);
		}

		void State6() {
			Transition(")", State8);
		}

		void State3() {
			Transition<Ws>(State7);
		}

		void State7() {
			Transition<BlockLiteral>(State5);
			Transition("(", State2);
		}

		void State2() {
			Transition<ArgumentDefinitionList>(State6);
		}

		void State8() {
			Transition<Ws>(State4);
		}

	}
}
