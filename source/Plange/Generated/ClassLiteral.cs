using Parlex;

namespace Generated {
	public partial class ClassLiteral : Production {
		public ClassLiteral() : base("ClassLiteral", false) { }
		public override void Start() {
			State3();
		}

		void State2() {
			Transition<Ws>(State4);
		}

		void State7() {
			Transition<Ws>(State6);
		}

		void State3() {
			Transition("class", State7);
		}

		void State4() {
			Transition<ClassMember>(State1);
			Transition("}", State8);
		}

		void State6() {
			Transition("{", State2);
		}

		void State8() {
			Accept();
		}

		void State5() {
			Transition(";", State2);
		}

		void State1() {
			Transition<Ws>(State5);
		}

	}
}
