using Parlex;

namespace Generated {
	public partial class ClassMember : Production {
		public ClassMember() : base("ClassMember", false) { }
		public override void Start() {
			State12();
			State5();
			State4();
		}

		void State10() {
			Accept();
		}

		void State8() {
			Transition<Expression>(State10);
		}

		void State1() {
			Transition<Ws>(State8);
		}

		void State12() {
			Transition("static", State9);
			Transition("public", State6);
			Transition("protected", State6);
			Transition("private", State6);
			Transition("internal", State6);
		}

		void State6() {
			Transition<Ws>(State3);
		}

		void State4() {
			Transition<XmlDocString>(State11);
		}

		void State2() {
			Transition<AtKeyword>(State1);
		}

		void State9() {
			Transition<Ws>(State5);
		}

		void State11() {
			Transition<Ws>(State12);
			Transition<Ws>(State5);
		}

		void State7() {
			Accept();
			Transition<Ws>(State2);
		}

		void State5() {
			Transition("public", State6);
			Transition("protected", State6);
			Transition("private", State6);
			Transition("internal", State6);
		}

		void State3() {
			Transition<ClassMemberDefinition>(State7);
			Transition<ClassMemberDeclaration>(State7);
		}

	}
}
