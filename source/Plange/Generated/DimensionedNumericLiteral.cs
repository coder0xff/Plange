using Parlex;

namespace Generated {
	public partial class DimensionedNumericLiteral : Production {
		public DimensionedNumericLiteral() : base("DimensionedNumericLiteral", false) { }
		public override void Start() {
			State1();
		}

		void State2() {
			Transition<DimensionalSymbol>(State3);
		}

		void State1() {
			Transition<NumericLiteral>(State2);
		}

		void State3() {
			Accept();
		}

	}
}
