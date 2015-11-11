using Parlex;

namespace Generated {
	public partial class FloatLiteral : Production {
		public FloatLiteral() : base("FloatLiteral", false) { }
		public override void Start() {
			State2();
		}

		void State1() {
			Accept();
		}

		void State2() {
			Transition<FloatLiteral1>(State1);
			Transition<FloatLiteral0>(State1);
		}

	}
}
