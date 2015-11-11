using Parlex;

namespace Generated {
	public partial class MatrixSet : Production {
		public MatrixSet() : base("MatrixSet", false) { }
		public override void Start() {
			State3();
		}

		void State4() {
			Transition(")", State1);
		}

		void State7() {
			Transition(",", State6);
		}

		void State2() {
			Transition("(", State5);
		}

		void State3() {
			Transition("𝕄", State2);
		}

		void State5() {
			Transition<IntegerLiteral>(State7);
		}

		void State6() {
			Transition<IntegerLiteral>(State4);
		}

		void State1() {
			Accept();
		}

	}
}
