using Parlex;

namespace Generated {
	public partial class Alloc : Production {
		public Alloc() : base("Alloc", false) { }
		public override void Start() {
			State3();
		}

		void State6() {
			Transition<Ws>(State9);
		}

		void State7() {
			Transition<Ws>(State2);
		}

		void State4() {
			Transition<Ws>(State1);
		}

		void State8() {
			Transition<ArgumentList>(State7);
		}

		void State5() {
			Transition<Ws>(State8);
		}

		void State9() {
			Transition("(", State5);
		}

		void State3() {
			Transition("alloc", State4);
		}

		void State2() {
			Transition(")", State10);
		}

		void State1() {
			Transition<ExplicitTypeDereference>(State6);
		}

		void State10() {
			Accept();
		}

	}
}
