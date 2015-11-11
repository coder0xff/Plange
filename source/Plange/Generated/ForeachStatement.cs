using Parlex;

namespace Generated {
	public partial class ForeachStatement : Production {
		public ForeachStatement() : base("ForeachStatement", false) { }
		public override void Start() {
			State9();
		}

		void State1() {
			Transition<Ws>(State8);
		}

		void State14() {
			Transition<TypeDereference>(State10);
			Transition<Symbol>(State11);
		}

		void State5() {
			Transition<Ws>(State14);
		}

		void State11() {
			Transition<Ws>(State13);
		}

		void State2() {
			Transition<Ws>(State7);
		}

		void State12() {
			Accept();
		}

		void State13() {
			Transition("in", State2);
		}

		void State4() {
			Transition<Ws>(State6);
		}

		void State3() {
			Transition<BlockLiteral>(State12);
		}

		void State9() {
			Transition("foreach", State4);
		}

		void State16() {
			Transition<Ws>(State3);
		}

		void State6() {
			Transition("(", State5);
		}

		void State15() {
			Transition<Symbol>(State11);
		}

		void State10() {
			Transition<Ws>(State15);
		}

		void State7() {
			Transition<Expression>(State1);
		}

		void State8() {
			Transition(")", State16);
		}

	}
}
