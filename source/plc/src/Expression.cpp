#include "Expression.hpp"

#include "AddSubExp.hpp"
#include "AdditionExp.hpp"
#include "AllExp.hpp"
#include "AllocationExp.hpp"
#include "AndExp.hpp"
#include "ArrayExp.hpp"
#include "AsmFunctionExp.hpp"
#include "BijectionExp.hpp"
#include "BitAndExp.hpp"
#include "BitOrExp.hpp"
#include "BitXorExp.hpp"
#include "BoolExp.hpp"
#include "CardinalityExp.hpp"
#include "CastExp.hpp"
#include "CastsExp.hpp"
#include "CeilingExp.hpp"
#include "ComplementExp.hpp"
#include "CompositionExp.hpp"
#include "CompoundExp.hpp"
#include "ConditionalExp.hpp"
#include "CrossProductExp.hpp"
#include "DeltaExp.hpp"
#include "DimensionalNumberExp.hpp"
#include "DivisionExp.hpp"
#include "DotProductExp.hpp"
#include "EqualityExp.hpp"
#include "ExistsExp.hpp"
#include "ExistsOneExp.hpp"
#include "ExponentiationExp.hpp"
#include "FactorialExp.hpp"
#include "FloorExp.hpp"
#include "FunctionExp.hpp"
#include "GreaterThanExp.hpp"
#include "HasExp.hpp"
#include "IdentifierExp.hpp"
#include "IfExp.hpp"
#include "IffExp.hpp"
#include "ImplicationExp.hpp"
#include "InExp.hpp"
#include "InequalityExp.hpp"
#include "IntegerDivisionExp.hpp"
#include "IntersectionExp.hpp"
#include "InvocationExp.hpp"
#include "IsExp.hpp"
#include "KleeneStarExp.hpp"
#include "LesserThanExp.hpp"
#include "ListExp.hpp"
#include "MagnitudeExp.hpp"
#include "MapExp.hpp"
#include "MapsToExp.hpp"
#include "MemberAccessExp.hpp"
#include "ModulationExp.hpp"
#include "MultiplicationExp.hpp"
#include "NandExp.hpp"
#include "NearestIntegerExp.hpp"
#include "NegationExp.hpp"
#include "NonNegativeNumberExp.hpp"
#include "NorExp.hpp"
#include "NotExp.hpp"
#include "NotGreaterThanExp.hpp"
#include "NotHasExp.hpp"
#include "NotInExp.hpp"
#include "NotLesserThanExp.hpp"
#include "NullCoalesceExp.hpp"
#include "OrExp.hpp"
#include "ParentheticalExp.hpp"
#include "PostDecExp.hpp"
#include "PostIncExp.hpp"
#include "PreDecExp.hpp"
#include "PreIncExp.hpp"
#include "PrependExp.hpp"
#include "ProperSubsetExp.hpp"
#include "ProperSupersetExp.hpp"
#include "PropertyExp.hpp"
#include "RadicalExp.hpp"
#include "RangeExp.hpp"
#include "SetComprehensionExp.hpp"
#include "SetExp.hpp"
#include "ShiftLExp.hpp"
#include "ShiftRExp.hpp"
#include "StringExp.hpp"
#include "SubsetExp.hpp"
#include "SubtractionExp.hpp"
#include "SupersetExp.hpp"
#include "SymmetricDifferenceExp.hpp"
#include "TupleExp.hpp"
#include "TypeExp.hpp"
#include "UnionExp.hpp"
#include "VectorNormExp.hpp"
#include "XorExp.hpp"

Expression::Expression() {}


Expression::~Expression() {}

std::unique_ptr<Expression> Expression::clone(Expression const & other)
{
#define CASE(x) auto as##x = dynamic_cast<x##Exp const *>(&other); if (as##x) return std::unique_ptr<Expression>(new x##Exp(*as##x))
	CASE(Addition);
	CASE(AddSub);
	CASE(All);
	CASE(Allocation);
	CASE(And);
	CASE(Array);
	CASE(AsmFunction);
	CASE(Bijection);
	CASE(BitAnd);
	CASE(BitOr);
	CASE(BitXor);
	CASE(Bool);
	CASE(Cardinality);
	CASE(Cast);
	CASE(Casts);
	CASE(Ceiling);
	CASE(Complement);
	CASE(Composition);
	CASE(Compound);
	CASE(Conditional);
	CASE(CrossProduct);
	CASE(Delta);
	CASE(DimensionalNumber);
	CASE(Division);
	CASE(DotProduct);
	CASE(Equality);
	CASE(Exists);
	CASE(ExistsOne);
	CASE(Exponentiation);
	CASE(Factorial);
	CASE(Floor);
	CASE(Function);
	CASE(GreaterThan);
	CASE(Has);
	CASE(Identifier);
	CASE(If);
	CASE(Iff);
	CASE(Implication);
	CASE(Inequality);
	CASE(In);
	CASE(IntegerDivision);
	CASE(Intersection);
	CASE(Invocation);
	CASE(Is);
	CASE(KleeneStar);
	CASE(LesserThan);
	CASE(List);
	CASE(Magnitude);
	CASE(Map);
	CASE(MapsTo);
	CASE(MemberAccess);
	CASE(Modulation);
	CASE(Multiplication);
	CASE(Nand);
	CASE(NearestInteger);
	CASE(Negation);
	CASE(NonNegativeNumber);
	CASE(Nor);
	CASE(Not);
	CASE(NotGreaterThan);
	CASE(NotHas);
	CASE(NotIn);
	CASE(NotLesserThan);
	CASE(NullCoalesce);
	CASE(Or);
	CASE(Parenthetical);
	CASE(PostDec);
	CASE(PostInc);
	CASE(PreDec);
	CASE(PreInc);
	CASE(Prepend);
	CASE(ProperSubset);
	CASE(ProperSuperset);
	CASE(Property);
	CASE(Radical);
	CASE(Range);
	CASE(SetComprehension);
	CASE(Set);
	CASE(ShiftL);
	CASE(ShiftR);
	CASE(String);
	CASE(Subset);
	CASE(Subtraction);
	CASE(Superset);
	CASE(SymmetricDifference);
	CASE(Tuple);
	CASE(Type);
	CASE(Union);
	CASE(VectorNorm);
	CASE(Xor);
	ERROR(Unknown, "Expression did not match any known type");
}
