using Parlex;

namespace Generated {
	public partial class DefinedAsOp : Production {
		public DefinedAsOp() : base("DefinedAsOp", false) { }
		public override void Start() {
			State2();
		}

		void State1() {
			Accept();
		}

		void State2() {
			Transition(":=", State1);
		}

	}
}
