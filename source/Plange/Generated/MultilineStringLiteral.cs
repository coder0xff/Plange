using Parlex;

namespace Generated {
	public partial class MultilineStringLiteral : Production {
		public MultilineStringLiteral() : base("MultilineStringLiteral", false) { }
		public override void Start() {
			State1();
		}

		void State2() {
			Transition("***", State6);
		}

		void State4() {
			Transition("*", State6);
		}

		void State1() {
			Transition("*", State3);
			Transition("***", State7);
		}

		void State7() {
			Transition(StandardSymbols.Newline, State5);
		}

		void State5() {
			Transition(StandardSymbols.Any, State5);
			Transition(StandardSymbols.Newline, State2);
		}

		void State6() {
			Accept();
		}

		void State3() {
			Transition<MultilineStringLiteral>(State4);
		}

	}
}
