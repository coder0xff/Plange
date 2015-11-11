using Parlex;

namespace Generated {
	public partial class ClassMemberDeclaration : Production {
		public ClassMemberDeclaration() : base("ClassMemberDeclaration", false) { }
		public override void Start() {
			State2();
		}

		void State3() {
			Transition<Ws>(State1);
		}

		void State4() {
			Accept();
		}

		void State1() {
			Transition<Symbol>(State4);
		}

		void State2() {
			Transition<ExplicitTypeDereference>(State3);
		}

	}
}
