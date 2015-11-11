using Parlex;

namespace Generated {
	public partial class Statement : Production {
		public Statement() : base("Statement", false) { }
		public override void Start() {
			State1();
		}

		void State1() {
			Transition<PlatformBlock>(State2);
			Transition<DeducedDeclarationRelationStatement>(State2);
			Transition<ExplicitDeclarationStatement>(State2);
			Transition<ContinueStatement>(State2);
			Transition<ForStatement>(State2);
			Transition<FreeStatement>(State2);
			Transition<DoWhileStatement>(State2);
			Transition<DefinitionStatement>(State2);
			Transition<ImportStatement>(State2);
			Transition<ExplicitDeclarationRelationStatement>(State2);
			Transition<AssignmentStatement>(State2);
			Transition<WhileStatement>(State2);
			Transition<TryCatchFinallyStatement>(State2);
			Transition<UntilStatement>(State2);
			Transition<Expression>(State3);
			Transition<DoUntilStatement>(State2);
			Transition<ForeachStatement>(State2);
			Transition<ReturnStatement>(State2);
			Transition<BreakStatement>(State2);
			Transition<If>(State2);
		}

		void State2() {
			Accept();
		}

		void State3() {
			Transition(";", State2);
		}

	}
}
