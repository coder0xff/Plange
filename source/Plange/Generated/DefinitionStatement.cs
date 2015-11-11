using Parlex;

namespace Generated {
	public partial class DefinitionStatement : Production {
		public DefinitionStatement() : base("DefinitionStatement", false) { }
		public override void Start() {
			State2();
			State7();
			State1();
		}

		void State4() {
			Transition<Expression>(State3);
		}

		void State3() {
			Transition<Ws>(State9);
		}

		void State12() {
			Transition<Ws>(State7);
			Transition<Ws>(State1);
		}

		void State8() {
			Accept();
		}

		void State2() {
			Transition<XmlDocString>(State12);
		}

		void State11() {
			Transition<Ws>(State1);
		}

		void State7() {
			Transition<Symbol>(State10);
			Transition<ExplicitTypeDereference>(State11);
			Transition<DeducedTypeDereference>(State11);
		}

		void State9() {
			Transition(";", State8);
		}

		void State6() {
			Transition<Ws>(State4);
		}

		void State10() {
			Transition<Ws>(State5);
		}

		void State1() {
			Transition<Symbol>(State10);
		}

		void State5() {
			Transition<DefinedAsOp>(State6);
		}

	}
}
