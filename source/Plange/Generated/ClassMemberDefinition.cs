using Parlex;

namespace Generated {
	public partial class ClassMemberDefinition : Production {
		public ClassMemberDefinition() : base("ClassMemberDefinition", false) { }
		public override void Start() {
			State7();
		}

		void State5() {
			Transition<Symbol>(State4);
		}

		void State7() {
			Transition<ExplicitTypeDereference>(State6);
			Transition<DeducedTypeDereference>(State6);
		}

		void State8() {
			Accept();
		}

		void State4() {
			Transition<Ws>(State1);
		}

		void State3() {
			Transition<Ws>(State2);
		}

		void State6() {
			Transition<Ws>(State5);
		}

		void State1() {
			Transition<DefinedAsOp>(State3);
		}

		void State2() {
			Transition<Expression>(State8);
		}

	}
}
