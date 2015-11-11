using Parlex;

namespace Generated {
	public partial class XmlDocString : Production {
		public XmlDocString() : base("XmlDocString", false) { }
		public override void Start() {
			State3();
		}

		void State3() {
			Transition("`", State4);
			Transition("```", State5);
		}

		void State1() {
			Accept();
		}

		void State4() {
			Transition<XmlDocString>(State2);
		}

		void State5() {
			Transition("```", State1);
			Transition(StandardSymbols.Any, State5);
		}

		void State2() {
			Transition("`", State1);
		}

	}
}
