using Parlex;

namespace Generated {
	public partial class ArgumentDefinition : Production {
		public ArgumentDefinition() : base("ArgumentDefinition", false) { }
		public override void Start() {
			State6();
		}

		void State2() {
			Accept();
			Transition<Ws>(State7);
		}

		void State6() {
			Transition<Symbol>(State2);
			Transition<ExplicitTypeDereference>(State8);
		}

		void State7() {
			Transition("=", State5);
		}

		void State5() {
			Transition<Ws>(State4);
		}

		void State3() {
			Transition<Symbol>(State2);
		}

		void State8() {
			Transition<Ws>(State3);
		}

		void State4() {
			Transition<Expression>(State1);
		}

		void State1() {
			Accept();
		}

	}
}
