using Parlex;

namespace Generated {
	public partial class MapsToTernaryExpression : Production {
		public MapsToTernaryExpression() : base("MapsToTernaryExpression", false) { }
		public override void Start() {
			State4();
		}

		void State8() {
			Accept();
		}

		void State5() {
			Transition<Ws>(State2);
		}

		void State6() {
			Transition<Expression>(State8);
		}

		void State3() {
			Transition<Ws>(State1);
		}

		void State4() {
			Transition<Expression>(State5);
		}

		void State10() {
			Transition<Ws>(State9);
		}

		void State1() {
			Transition<Expression>(State10);
		}

		void State2() {
			Transition(":", State3);
		}

		void State9() {
			Transition("↦", State7);
		}

		void State7() {
			Transition<Ws>(State6);
		}

	}
}
