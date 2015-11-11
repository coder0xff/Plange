using Parlex;

namespace Generated {
	public partial class NumericLiteral : Production {
		public NumericLiteral() : base("NumericLiteral", false) { }
		public override void Start() {
			State1();
		}

		void State1() {
			Transition<IntegerLiteral>(State2);
			Transition<HexLiteral>(State2);
			Transition<FloatLiteral>(State2);
		}

		void State2() {
			Accept();
		}

	}
}
