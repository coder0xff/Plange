using Parlex;

namespace Generated {
	public partial class MemberAccessorExpression : Production {
		public MemberAccessorExpression() : base("MemberAccessorExpression", false) { }
		public override void Start() {
			State4();
		}

		void State4() {
			Transition<Expression>(State2);
		}

		void State1() {
			Transition<Identifier>(State3);
		}

		void State2() {
			Transition(".", State1);
		}

		void State3() {
			Accept();
		}

	}
}
