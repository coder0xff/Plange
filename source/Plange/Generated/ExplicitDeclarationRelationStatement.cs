using Parlex;

namespace Generated {
	public partial class ExplicitDeclarationRelationStatement : Production {
		public ExplicitDeclarationRelationStatement() : base("ExplicitDeclarationRelationStatement", false) { }
		public override void Start() {
			State2();
		}

		void State3() {
			Transition<Ws>(State6);
		}

		void State1() {
			Transition<Expression>(State10);
		}

		void State4() {
			Transition<RelationalOp>(State9);
		}

		void State5() {
			Accept();
		}

		void State10() {
			Transition<Ws>(State8);
		}

		void State9() {
			Transition<Ws>(State1);
		}

		void State8() {
			Transition(";", State5);
		}

		void State6() {
			Transition<Symbol>(State7);
		}

		void State7() {
			Transition<Ws>(State4);
		}

		void State2() {
			Transition<ExplicitTypeDereference>(State3);
		}

	}
}
