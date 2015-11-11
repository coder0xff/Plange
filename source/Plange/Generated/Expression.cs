using Parlex;

namespace Generated {
	public partial class Expression : Production {
		public Expression() : base("Expression", false) { }
		public override void Start() {
			State1();
		}

		void State1() {
			Transition<NewExpression>(State2);
			Transition<NegationExpression>(State2);
			Transition<AddressOf>(State2);
			Transition<TupleLiteral>(State2);
			Transition<NearestIntegerExpression>(State2);
			Transition<ListLiteral>(State2);
			Transition<SurfaceIntegralExpression>(State2);
			Transition<Identifier>(State2);
			Transition<StaticCastExpression>(State2);
			Transition<MagnitudeExpression>(State2);
			Transition<ClassLiteral>(State2);
			Transition<CeilingExpression>(State2);
			Transition<SummationExpression>(State2);
			Transition<FunctionLiteral>(State2);
			Transition(StandardSymbols.StringLiteral, State2);
			Transition<SetBuilderExpression>(State2);
			Transition<DimensionedNumericLiteral>(State2);
			Transition<InfixExpression>(State2);
			Transition<LineIntegralExpression>(State2);
			Transition<PointerToExpression>(State2);
			Transition<NumericLiteral>(State2);
			Transition<FloorExpression>(State2);
			Transition<ArrayAccessorExpression>(State2);
			Transition<DereferenceExpression>(State2);
			Transition<NotExpression>(State2);
			Transition<ArrayLiteral>(State2);
			Transition<Alloc>(State2);
			Transition<MemberAccessorExpression>(State2);
			Transition<ParentheticalExpression>(State2);
			Transition<TypeofExpression>(State2);
			Transition<PoundCardinalityExpression>(State2);
			Transition<ProductIntegralExpression>(State2);
			Transition<FunctionTypeConstructor>(State2);
			Transition<SetLiteral>(State2);
			Transition<DerivativeExpression>(State2);
			Transition<IntervalExpression>(State2);
			Transition<ReservedConstant>(State2);
			Transition<FunctionCall>(State2);
			Transition<IntegralExpression>(State2);
			Transition<PipeParentheticalExpression>(State2);
			Transition<If>(State2);
			Transition<MultilineStringLiteral>(State2);
		}

		void State2() {
			Accept();
		}

	}
}
