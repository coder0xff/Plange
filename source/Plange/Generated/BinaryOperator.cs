using Parlex;

namespace Generated {
	public partial class BinaryOperator : Production {
		public BinaryOperator() : base("BinaryOperator", false) { }
		public override void Start() {
			State1();
		}

		void State2() {
			Accept();
		}

		void State1() {
			Transition<ProductOp>(State2);
			Transition<LessThanOp>(State2);
			Transition<LessThanEqualToOp>(State2);
			Transition<ModuloOp>(State2);
			Transition<SymmetricDifferenceOp>(State2);
			Transition<SetNonmembershipOp>(State2);
			Transition<NotEqualOp>(State2);
			Transition<GreaterThanOp>(State2);
			Transition<StrictSubsetOp>(State2);
			Transition<SetContainmentOp>(State2);
			Transition<SumOp>(State2);
			Transition<DisjunctionOp>(State2);
			Transition<BitwiseOrOp>(State2);
			Transition<PlusMinusOp>(State2);
			Transition<ExponentiationOp>(State2);
			Transition<BitwiseAndOp>(State2);
			Transition<ConjunctionOp>(State2);
			Transition<GreaterThanEqualToOp>(State2);
			Transition<DifferenceOp>(State2);
			Transition<LogicalXorOp>(State2);
			Transition<FunctionArrowOp>(State2);
			Transition<EqualToOp>(State2);
			Transition<UnionOp>(State2);
			Transition<CompositionOp>(State2);
			Transition<QuotientOp>(State2);
			Transition<StrictSupersetOp>(State2);
			Transition<SubsetOp>(State2);
			Transition<SupersetOp>(State2);
			Transition<IntersectionOp>(State2);
			Transition<ImplicationOp>(State2);
			Transition<IffOp>(State2);
			Transition<SetMembershipOp>(State2);
			Transition<BitwiseXorOp>(State2);
			Transition<SetNoncontainmentOp>(State2);
		}

	}
}
