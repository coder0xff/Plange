using Parlex;

namespace Generated {
	public partial class ReservedConstant : Production {
		public ReservedConstant() : base("ReservedConstant", false) { }
		public override void Start() {
			State2();
		}

		void State1() {
			Accept();
		}

		void State2() {
			Transition("ℕ", State1);
			Transition("e", State1);
			Transition("ℝ", State1);
			Transition("∅", State1);
			Transition("𝕀", State1);
			Transition("π", State1);
			Transition("ℚ", State1);
			Transition("𝕎", State1);
			Transition("ℤ", State1);
			Transition("𝔹", State1);
			Transition("ℂ", State1);
			Transition("ℵ(0)", State1);
			Transition<MatrixSet>(State1);
			Transition("𝑒", State1);
			Transition("ℍ", State1);
			Transition("𝕆", State1);
			Transition("ⅈ", State1);
		}

	}
}
