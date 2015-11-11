using Parlex;

namespace Generated {
	public partial class ArgumentDefinitionList : Production {
		public ArgumentDefinitionList() : base("ArgumentDefinitionList", false) { }
		public override void Start() {
			State3();
			State2();
		}

		void State2() {
			Accept();
		}

		void State1() {
			Transition(",", State4);
		}

		void State3() {
			Transition<ArgumentDefinition>(State5);
		}

		void State4() {
			Transition<Ws>(State3);
		}

		void State5() {
			Accept();
			Transition<Ws>(State1);
		}

	}
}
