using Parlex;

namespace Generated {
	public partial class ModuloOp : Production {
		public ModuloOp() : base("ModuloOp", false) { }
		public override void Start() {
			State2();
		}

		void State2() {
			Transition("%", State1);
		}

		void State1() {
			Accept();
		}

	}
}
