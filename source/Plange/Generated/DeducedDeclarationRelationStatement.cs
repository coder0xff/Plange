using Parlex;

namespace Generated {
	public partial class DeducedDeclarationRelationStatement : Production {
		public DeducedDeclarationRelationStatement() : base("DeducedDeclarationRelationStatement", false) { }
		public override void Start() {
			State3();
		}

		void State10() {
			Transition<RelationalOp>(State2);
		}

		void State5() {
			Transition<Ws>(State10);
		}

		void State6() {
			Transition(";", State9);
		}

		void State4() {
			Transition<Ws>(State6);
		}

		void State8() {
			Transition<Symbol>(State5);
		}

		void State9() {
			Accept();
		}

		void State2() {
			Transition<Ws>(State1);
		}

		void State3() {
			Transition<DeducedTypeDereference>(State7);
		}

		void State7() {
			Transition<Ws>(State8);
		}

		void State1() {
			Transition<Expression>(State4);
		}

	}
}
