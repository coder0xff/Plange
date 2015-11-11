using Parlex;

namespace Generated {
	public partial class PredicateOp : Production {
		public PredicateOp() : base("PredicateOp", false) { }
		public override void Start() {
			State2();
		}

		void State2() {
			Transition<SetNonmembershipOp>(State1);
			Transition<SupersetOp>(State1);
			Transition<RelationalOp>(State1);
			Transition<IffOp>(State1);
			Transition<SetNoncontainmentOp>(State1);
			Transition<StrictSubsetOp>(State1);
			Transition<FunctionArrowOp>(State1);
			Transition<ImplicationOp>(State1);
			Transition<StrictSupersetOp>(State1);
			Transition<SetMembershipOp>(State1);
			Transition<SubsetOp>(State1);
			Transition<SetContainmentOp>(State1);
		}

		void State1() {
			Accept();
		}

	}
}
