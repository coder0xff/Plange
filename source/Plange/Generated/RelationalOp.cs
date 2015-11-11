using Parlex;

namespace Generated {
	public partial class RelationalOp : Production {
		public RelationalOp() : base("RelationalOp", false) { }
		public override void Start() {
			State2();
		}

		void State2() {
			Transition<NotEqualOp>(State1);
			Transition<GreaterThanOp>(State1);
			Transition<EqualToOp>(State1);
			Transition<GreaterThanEqualToOp>(State1);
			Transition<LessThanOp>(State1);
			Transition<LessThanEqualToOp>(State1);
		}

		void State1() {
			Accept();
		}

	}
}
