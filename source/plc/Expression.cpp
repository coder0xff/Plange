#include "Expression.h"
#include "Errors.h"

#include "AddSubExp.h"
#include "AdditionExp.h"
#include "AllExp.h"
#include "AllocationExp.h"
#include "AndExp.h"
#include "ArrayExp.h"
#include "AsmFunctionExp.h"
#include "BijectionExp.h"
#include "BitAndExp.h"
#include "BitOrExp.h"
#include "BitXorExp.h"
#include "BoolExp.h"
#include "CardinalityExp.h"
#include "CastExp.h"
#include "CastsExp.h"
#include "CeilingExp.h"
#include "ComplementExp.h"
#include "CompositionExp.h"
#include "CompoundExp.h"
#include "ConditionalExp.h"
#include "CrossProductExp.h"
#include "DeltaExp.h"
#include "DimensionalNumberExp.h"
#include "DivisionExp.h"
#include "DotProductExp.h"
#include "EqualityExp.h"
#include "ExistsExp.h"
#include "ExistsOneExp.h"
#include "ExponentiationExp.h"
#include "FactorialExp.h"
#include "FloorExp.h"
#include "FunctionExp.h"
#include "GreaterThanExp.h"
#include "HasExp.h"
#include "IdentifierExp.h"
#include "IfExp.h"
#include "IffExp.h"
#include "ImplicationExp.h"
#include "InExp.h"
#include "InequalityExp.h"
#include "IntegerDivisionExp.h"
#include "IntersectionExp.h"
#include "InvocationExp.h"
#include "IsExp.h"
#include "KleeneStarExp.h"
#include "LesserThanExp.h"
#include "ListExp.h"
#include "MagnitudeExp.h"
#include "MapExp.h"
#include "MapsToExp.h"
#include "MemberAccessExp.h"
#include "ModulationExp.h"
#include "MultiplicationExp.h"
#include "NandExp.h"
#include "NearestIntegerExp.h"
#include "NegationExp.h"
#include "NonNegativeNumberExp.h"
#include "NorExp.h"
#include "NotExp.h"
#include "NotGreaterThanExp.h"
#include "NotHasExp.h"
#include "NotInExp.h"
#include "NotLesserThanExp.h"
#include "NullCoalesceExp.h"
#include "OrExp.h"
#include "ParentheticalExp.h"
#include "PostDecExp.h"
#include "PostIncExp.h"
#include "PreDecExp.h"
#include "PreIncExp.h"
#include "PrependExp.h"
#include "ProperSubsetExp.h"
#include "ProperSupersetExp.h"
#include "PropertyExp.h"
#include "RadicalExp.h"
#include "RangeExp.h"
#include "SetComprehensionExp.h"
#include "SetExp.h"
#include "ShiftLExp.h"
#include "ShiftRExp.h"
#include "StringExp.h"
#include "SubsetExp.h"
#include "SubtractionExp.h"
#include "SupersetExp.h"
#include "SymmetricDifferenceExp.h"
#include "TupleExp.h"
#include "TypeExp.h"
#include "UnionExp.h"
#include "VectorNormExp.h"
#include "XorExp.h"

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
