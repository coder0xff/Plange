using Parlex;

namespace Generated {
	public partial class NotExpression : Production {
		public NotExpression() : base("NotExpression", false) { }
		public override void Start() {
			State1();
		}

		void State3() {
			Transition<Ws>(State2);
		}

		void State2() {
			Transition<Expression>(State4);
		}

		void State1() {
			Transition("!", State3);
		}

		void State4() {
			Accept();
		}

	}
}
