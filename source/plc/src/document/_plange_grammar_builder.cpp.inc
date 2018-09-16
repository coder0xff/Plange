static parlex::production ADDITION() {
	parlex::reference const v0("EXPRESSION");
	parlex::reference const v1("IC");
	parlex::repetition const v2(v1);
	parlex::literal const v3(U"+");
	parlex::reference const v4("IC");
	parlex::repetition const v5(v4);
	parlex::reference const v6("EXPRESSION");
	parlex::sequence const v7("ADDITION", {v0, v2, v3, v5, v6});
	return parlex::production("ADDITION",v7, parlex::associativity::ANY);
}

static parlex::production ADDITION_ASSIGNMENT() {
	parlex::reference const v0("EXPRESSION");
	parlex::reference const v1("IC");
	parlex::repetition const v2(v1);
	parlex::literal const v3(U"+<-");
	parlex::literal const v4(U"+←");
	parlex::literal const v5(U"⥆");
	parlex::choice const v6({v3, v4, v5});
	parlex::reference const v7("IC");
	parlex::repetition const v8(v7);
	parlex::reference const v9("EXPRESSION");
	parlex::sequence const v10("ADDITION_ASSIGNMENT", {v0, v2, v6, v8, v9});
	return parlex::production("ADDITION_ASSIGNMENT",v10);
}

static parlex::production ADD_SUB() {
	parlex::reference const v0("EXPRESSION");
	parlex::reference const v1("IC");
	parlex::repetition const v2(v1);
	parlex::literal const v3(U"±");
	parlex::literal const v4(U"+-");
	parlex::choice const v5({v3, v4});
	parlex::reference const v6("IC");
	parlex::repetition const v7(v6);
	parlex::reference const v8("EXPRESSION");
	parlex::sequence const v9("ADD_SUB", {v0, v2, v5, v7, v8});
	return parlex::production("ADD_SUB",v9, parlex::associativity::LEFT);
}

static parlex::production ADD_SUB_ASSIGNMENT() {
	parlex::reference const v0("EXPRESSION");
	parlex::reference const v1("IC");
	parlex::repetition const v2(v1);
	parlex::literal const v3(U"±");
	parlex::literal const v4(U"+-");
	parlex::choice const v5({v3, v4});
	parlex::literal const v6(U"<-");
	parlex::literal const v7(U"←");
	parlex::choice const v8({v6, v7});
	parlex::reference const v9("IC");
	parlex::repetition const v10(v9);
	parlex::reference const v11("EXPRESSION");
	parlex::sequence const v12("ADD_SUB_ASSIGNMENT", {v0, v2, v5, v8, v10, v11});
	return parlex::production("ADD_SUB_ASSIGNMENT",v12);
}

static parlex::production ALL() {
	parlex::literal const v0(U"∀");
	parlex::literal const v1(U"all");
	parlex::choice const v2({v0, v1});
	parlex::reference const v3("IC");
	parlex::repetition const v4(v3);
	parlex::reference const v5("EXPRESSION");
	parlex::sequence const v6("ALL", {v2, v4, v5});
	return parlex::production("ALL",v6);
}

static parlex::production ALLOCATION() {
	parlex::literal const v0(U"alloc");
	parlex::reference const v1("IC");
	parlex::repetition const v2(v1);
	parlex::reference const v3("PARENTHETICAL_INVOCATION");
	parlex::sequence const v4("ALLOCATION", {v0, v2, v3});
	return parlex::production("ALLOCATION",v4);
}

static parlex::production AND() {
	parlex::reference const v0("EXPRESSION");
	parlex::reference const v1("IC");
	parlex::repetition const v2(v1);
	parlex::literal const v3(U"∧");
	parlex::literal const v4(U"and");
	parlex::choice const v5({v3, v4});
	parlex::reference const v6("IC");
	parlex::repetition const v7(v6);
	parlex::reference const v8("EXPRESSION");
	parlex::sequence const v9("AND", {v0, v2, v5, v7, v8});
	return parlex::production("AND",v9, parlex::associativity::ANY, parlex::filter_function(), {"IFF", "IMPLICATION", "OR", "XOR", });
}

static parlex::production AND_ASSIGNMENT() {
	parlex::reference const v0("EXPRESSION");
	parlex::reference const v1("IC");
	parlex::repetition const v2(v1);
	parlex::literal const v3(U"∧");
	parlex::literal const v4(U"and");
	parlex::choice const v5({v3, v4});
	parlex::literal const v6(U"<-");
	parlex::literal const v7(U"←");
	parlex::choice const v8({v6, v7});
	parlex::reference const v9("IC");
	parlex::repetition const v10(v9);
	parlex::reference const v11("EXPRESSION");
	parlex::sequence const v12("AND_ASSIGNMENT", {v0, v2, v5, v8, v10, v11});
	return parlex::production("AND_ASSIGNMENT",v12);
}

static parlex::production ARGUMENT() {
	parlex::reference const v0("ARGUMENT", "EXPRESSION");
	return parlex::production("ARGUMENT",v0);
}

static parlex::production ARGUMENT_PACK() {
	parlex::reference const v0("EXPRESSION");
	parlex::reference const v1("IC");
	parlex::repetition const v2(v1);
	parlex::literal const v3(U"...");
	parlex::sequence const v4("ARGUMENT_PACK", {v0, v2, v3});
	return parlex::production("ARGUMENT_PACK",v4);
}

static parlex::production ARRAY() {
	parlex::literal const v0(U"[");
	parlex::reference const v1("IC");
	parlex::repetition const v2(v1);
	parlex::reference const v3("expression", "EXPRESSION");
	parlex::reference const v4("IC");
	parlex::repetition const v5(v4);
	parlex::literal const v6(U",");
	parlex::reference const v7("IC");
	parlex::repetition const v8(v7);
	parlex::reference const v9("expression", "EXPRESSION");
	parlex::sequence const v10({v5, v6, v8, v9});
	parlex::repetition const v11(v10);
	parlex::reference const v12("IC");
	parlex::repetition const v13(v12);
	parlex::sequence const v14({v3, v11, v13});
	parlex::optional const v15(v14);
	parlex::literal const v16(U"]");
	parlex::sequence const v17("ARRAY", {v0, v2, v15, v16});
	return parlex::production("ARRAY",v17);
}

static parlex::production ARRAY_INDEXER() {
	parlex::reference const v0("IC");
	parlex::repetition const v1(v0);
	parlex::reference const v2("ARGUMENT");
	parlex::reference const v3("ARGUMENT_PACK");
	parlex::reference const v4("SLICE");
	parlex::choice const v5({v2, v3, v4});
	parlex::sequence const v6("ARRAY_INDEXER", {v1, v5});
	return parlex::production("ARRAY_INDEXER",v6);
}

static parlex::production ARRAY_INVOCATION() {
	parlex::reference const v0("target", "EXPRESSION");
	parlex::literal const v1(U"[");
	parlex::reference const v2("array_indexer", "ARRAY_INDEXER");
	parlex::optional const v3("argsHead", v2);
	parlex::reference const v4("IC");
	parlex::repetition const v5(v4);
	parlex::literal const v6(U",");
	parlex::reference const v7("array_indexer", "ARRAY_INDEXER");
	parlex::optional const v8(v7);
	parlex::sequence const v9({v5, v6, v8});
	parlex::repetition const v10("argsTail", v9);
	parlex::reference const v11("IC");
	parlex::repetition const v12(v11);
	parlex::literal const v13(U"]");
	parlex::sequence const v14("ARRAY_INVOCATION", {v0, v1, v3, v10, v12, v13});
	return parlex::production("ARRAY_INVOCATION",v14);
}

static parlex::production ASM_EXPRESSION() {
	parlex::reference const v0("ASM_IDENTIFIER");
	parlex::reference const v1("ASM_PTR_ARITHMETIC_ATT");
	parlex::reference const v2("ASM_PTR_ARITHMETIC_INTEL");
	parlex::reference const v3("NON_FRACTIONAL");
	parlex::choice const v4("ASM_EXPRESSION", {v0, v1, v2, v3});
	return parlex::production("ASM_EXPRESSION",v4);
}

static parlex::production ASM_FUNCTION() {
	parlex::literal const v0(U"(");
	parlex::reference const v1("IC");
	parlex::repetition const v2(v1);
	parlex::reference const v3("parameter", "PARAMETER");
	parlex::reference const v4("IC");
	parlex::repetition const v5(v4);
	parlex::literal const v6(U",");
	parlex::reference const v7("IC");
	parlex::repetition const v8(v7);
	parlex::reference const v9("parameter", "PARAMETER");
	parlex::sequence const v10({v5, v6, v8, v9});
	parlex::repetition const v11(v10);
	parlex::reference const v12("IC");
	parlex::repetition const v13(v12);
	parlex::sequence const v14({v3, v11, v13});
	parlex::optional const v15(v14);
	parlex::literal const v16(U")");
	parlex::reference const v17("IC");
	parlex::repetition const v18(v17);
	parlex::sequence const v19({v0, v2, v15, v16, v18});
	parlex::optional const v20(v19);
	parlex::reference const v21("FUNCTION_MODIFIER_0");
	parlex::optional const v22(v21);
	parlex::literal const v23(U"asm");
	parlex::reference const v24("IC");
	parlex::repetition const v25(v24);
	parlex::literal const v26(U"{");
	parlex::reference const v27("ASM_SCOPE");
	parlex::literal const v28(U"}");
	parlex::sequence const v29("ASM_FUNCTION", {v20, v22, v23, v25, v26, v27, v28});
	return parlex::production("ASM_FUNCTION",v29);
}

static parlex::production ASM_IDENTIFIER() {
	parlex::literal const v0(U"%");
	parlex::optional const v1(v0);
	parlex::reference const v2("IDENTIFIER");
	parlex::sequence const v3("ASM_IDENTIFIER", {v1, v2});
	return parlex::production("ASM_IDENTIFIER",v3);
}

static parlex::production ASM_OP() {
	parlex::reference const v0("lowercase_letter");
	parlex::reference const v1("lowercase_letter");
	parlex::repetition const v2(v1);
	parlex::sequence const v3("ASM_OP", {v0, v2});
	return parlex::production("ASM_OP",v3);
}

static parlex::production ASM_PTR_ARITHMETIC_ATT() {
	parlex::reference const v0("ASM_IDENTIFIER");
	parlex::literal const v1(U":");
	parlex::reference const v2("NON_FRACTIONAL");
	parlex::sequence const v3({v0, v1, v2});
	parlex::reference const v4("ASM_IDENTIFIER");
	parlex::literal const v5(U":");
	parlex::reference const v6("NON_FRACTIONAL");
	parlex::reference const v7("ASM_PTR_ARITHMETIC_ATT_REG");
	parlex::sequence const v8({v4, v5, v6, v7});
	parlex::reference const v9("NON_FRACTIONAL");
	parlex::reference const v10("ASM_PTR_ARITHMETIC_ATT_REG");
	parlex::sequence const v11({v9, v10});
	parlex::choice const v12("ASM_PTR_ARITHMETIC_ATT", {v3, v8, v11});
	return parlex::production("ASM_PTR_ARITHMETIC_ATT",v12);
}

static parlex::production ASM_PTR_ARITHMETIC_ATT_REG() {
	parlex::literal const v0(U"(");
	parlex::reference const v1("asm_identifier", "ASM_IDENTIFIER");
	parlex::optional const v2(v1);
	parlex::literal const v3(U",");
	parlex::reference const v4("asm_identifier", "ASM_IDENTIFIER");
	parlex::literal const v5(U",");
	parlex::reference const v6("NON_NEG_NON_FRACTIONAL");
	parlex::sequence const v7({v5, v6});
	parlex::optional const v8(v7);
	parlex::sequence const v9({v3, v4, v8});
	parlex::optional const v10(v9);
	parlex::literal const v11(U")");
	parlex::sequence const v12("ASM_PTR_ARITHMETIC_ATT_REG", {v0, v2, v10, v11});
	return parlex::production("ASM_PTR_ARITHMETIC_ATT_REG",v12);
}

static parlex::production ASM_PTR_ARITHMETIC_INTEL() {
	parlex::literal const v0(U"BYTE");
	parlex::literal const v1(U"WORD");
	parlex::literal const v2(U"DWORD");
	parlex::literal const v3(U"QWORD");
	parlex::choice const v4({v0, v1, v2, v3});
	parlex::literal const v5(U" PTR");
	parlex::sequence const v6({v4, v5});
	parlex::optional const v7(v6);
	parlex::literal const v8(U"[");
	parlex::reference const v9("ASM_IDENTIFIER");
	parlex::literal const v10(U":");
	parlex::sequence const v11({v9, v10});
	parlex::optional const v12(v11);
	parlex::reference const v13("ASM_IDENTIFIER");
	parlex::literal const v14(U"+");
	parlex::reference const v15("ASM_IDENTIFIER");
	parlex::literal const v16(U"*");
	parlex::reference const v17("NON_NEG_NON_FRACTIONAL");
	parlex::sequence const v18({v16, v17});
	parlex::optional const v19(v18);
	parlex::sequence const v20({v14, v15, v19});
	parlex::optional const v21(v20);
	parlex::literal const v22(U"+");
	parlex::literal const v23(U"-");
	parlex::choice const v24({v22, v23});
	parlex::reference const v25("NON_NEG_INTEGER");
	parlex::sequence const v26({v24, v25});
	parlex::optional const v27(v26);
	parlex::literal const v28(U"]");
	parlex::sequence const v29("ASM_PTR_ARITHMETIC_INTEL", {v7, v8, v12, v13, v21, v27, v28});
	return parlex::production("ASM_PTR_ARITHMETIC_INTEL",v29);
}

static parlex::production ASM_SCOPE() {
	parlex::reference const v0("IC");
	parlex::reference const v1("ASM_STATEMENT");
	parlex::choice const v2({v0, v1});
	parlex::repetition const v3("ASM_SCOPE", v2);
	return parlex::production("ASM_SCOPE",v3);
}

static parlex::production ASM_STATEMENT() {
	parlex::reference const v0("ASM_OP");
	parlex::reference const v1("IC");
	parlex::repetition const v2(v1);
	parlex::reference const v3("ASM_EXPRESSION");
	parlex::reference const v4("IC");
	parlex::repetition const v5(v4);
	parlex::literal const v6(U",");
	parlex::reference const v7("IC");
	parlex::repetition const v8(v7);
	parlex::reference const v9("ASM_EXPRESSION");
	parlex::sequence const v10({v8, v9});
	parlex::optional const v11(v10);
	parlex::sequence const v12({v5, v6, v11});
	parlex::repetition const v13(v12);
	parlex::sequence const v14({v2, v3, v13});
	parlex::optional const v15(v14);
	parlex::reference const v16("IC");
	parlex::repetition const v17(v16);
	parlex::literal const v18(U"\n");
	parlex::sequence const v19("ASM_STATEMENT", {v0, v15, v17, v18});
	return parlex::production("ASM_STATEMENT",v19);
}

static parlex::production ASSIGNMENT_CHAIN() {
	parlex::reference const v0("xml_doc_string", "XML_DOC_STRING");
	parlex::reference const v1("IC");
	parlex::repetition const v2(v1);
	parlex::sequence const v3({v0, v2});
	parlex::optional const v4(v3);
	parlex::reference const v5("identifier", "IDENTIFIER");
	parlex::reference const v6("IC");
	parlex::repetition const v7(v6);
	parlex::literal const v8(U"←");
	parlex::literal const v9(U"<-");
	parlex::choice const v10({v8, v9});
	parlex::reference const v11("IC");
	parlex::repetition const v12(v11);
	parlex::reference const v13("expression", "EXPRESSION");
	parlex::reference const v14("ASSIGNMENT_CHAIN");
	parlex::choice const v15({v13, v14});
	parlex::sequence const v16("ASSIGNMENT_CHAIN", {v4, v5, v7, v10, v12, v15});
	return parlex::production("ASSIGNMENT_CHAIN",v16, parlex::associativity::NONE, parlex::filter_function(), {"EXPRESSION", "LESSER_CHAIN", });
}

static parlex::production ATTRIBUTE() {
	parlex::literal const v0(U"@");
	parlex::reference const v1("IC");
	parlex::repetition const v2(v1);
	parlex::reference const v3("EXPRESSION");
	parlex::reference const v4("IC");
	parlex::repetition const v5(v4);
	parlex::literal const v6(U"@");
	parlex::sequence const v7("ATTRIBUTE", {v0, v2, v3, v5, v6});
	return parlex::production("ATTRIBUTE",v7);
}

static parlex::production BIJECTION() {
	parlex::reference const v0("EXPRESSION");
	parlex::reference const v1("IC");
	parlex::repetition const v2(v1);
	parlex::literal const v3(U"↔");
	parlex::literal const v4(U"<->");
	parlex::choice const v5({v3, v4});
	parlex::reference const v6("IC");
	parlex::repetition const v7(v6);
	parlex::reference const v8("EXPRESSION");
	parlex::sequence const v9("BIJECTION", {v0, v2, v5, v7, v8});
	return parlex::production("BIJECTION",v9, parlex::associativity::ANY);
}

static parlex::production BINARY_ARITHMETIC_OP() {
	parlex::reference const v0("ADD_SUB");
	parlex::reference const v1("ADDITION");
	parlex::reference const v2("DIVISION");
	parlex::reference const v3("EXPONENTIATION");
	parlex::reference const v4("INTEGER_DIVISION");
	parlex::reference const v5("MODULATION");
	parlex::reference const v6("MULTIPLICATIVE_OP");
	parlex::reference const v7("SHIFTL");
	parlex::reference const v8("SHIFTR");
	parlex::reference const v9("SUBTRACTION");
	parlex::choice const v10("BINARY_ARITHMETIC_OP", {v0, v1, v2, v3, v4, v5, v6, v7, v8, v9});
	return parlex::production("BINARY_ARITHMETIC_OP",v10);
}

static parlex::production BINARY_COLLECTION_OP() {
	parlex::reference const v0("BIJECTION");
	parlex::reference const v1("INTERSECTION");
	parlex::reference const v2("SYMMETRIC_DIFFERENCE");
	parlex::reference const v3("UNION");
	parlex::choice const v4("BINARY_COLLECTION_OP", {v0, v1, v2, v3});
	return parlex::production("BINARY_COLLECTION_OP",v4);
}

static parlex::production BINARY_LOGICAL_OP() {
	parlex::reference const v0("AND");
	parlex::reference const v1("IFF");
	parlex::reference const v2("IMPLICATION");
	parlex::reference const v3("MAPS_TO");
	parlex::reference const v4("NAND");
	parlex::reference const v5("NOR");
	parlex::reference const v6("OR");
	parlex::reference const v7("XOR");
	parlex::choice const v8("BINARY_LOGICAL_OP", {v0, v1, v2, v3, v4, v5, v6, v7});
	return parlex::production("BINARY_LOGICAL_OP",v8);
}

static parlex::production BINARY_OP() {
	parlex::reference const v0("BINARY_ARITHMETIC_OP");
	parlex::reference const v1("BINARY_COLLECTION_OP");
	parlex::reference const v2("BINARY_LOGICAL_OP");
	parlex::reference const v3("BITWISE_OP");
	parlex::reference const v4("CONSTRUCTIVE_OP");
	parlex::reference const v5("RELATIONAL_OP");
	parlex::choice const v6("BINARY_OP", {v0, v1, v2, v3, v4, v5});
	return parlex::production("BINARY_OP",v6);
}

static parlex::production BITWISE_OP() {
	parlex::reference const v0("BIT_AND");
	parlex::reference const v1("BIT_OR");
	parlex::reference const v2("BIT_XOR");
	parlex::choice const v3("BITWISE_OP", {v0, v1, v2});
	return parlex::production("BITWISE_OP",v3);
}

static parlex::production BIT_AND() {
	parlex::reference const v0("EXPRESSION");
	parlex::reference const v1("IC");
	parlex::repetition const v2(v1);
	parlex::literal const v3(U"&&");
	parlex::reference const v4("IC");
	parlex::repetition const v5(v4);
	parlex::reference const v6("EXPRESSION");
	parlex::sequence const v7("BIT_AND", {v0, v2, v3, v5, v6});
	return parlex::production("BIT_AND",v7, parlex::associativity::ANY);
}

static parlex::production BIT_AND_ASSIGNMENT() {
	parlex::reference const v0("EXPRESSION");
	parlex::reference const v1("IC");
	parlex::repetition const v2(v1);
	parlex::literal const v3(U"&&");
	parlex::literal const v4(U"<-");
	parlex::literal const v5(U"←");
	parlex::choice const v6({v4, v5});
	parlex::reference const v7("IC");
	parlex::repetition const v8(v7);
	parlex::reference const v9("EXPRESSION");
	parlex::sequence const v10("BIT_AND_ASSIGNMENT", {v0, v2, v3, v6, v8, v9});
	return parlex::production("BIT_AND_ASSIGNMENT",v10);
}

static parlex::production BIT_NOT() {
	parlex::literal const v0(U"~~");
	parlex::reference const v1("IC");
	parlex::repetition const v2(v1);
	parlex::reference const v3("EXPRESSION");
	parlex::sequence const v4("BIT_NOT", {v0, v2, v3});
	return parlex::production("BIT_NOT",v4);
}

static parlex::production BIT_NOT_ASSIGNMENT() {
	parlex::reference const v0("EXPRESSION");
	parlex::reference const v1("IC");
	parlex::repetition const v2(v1);
	parlex::literal const v3(U"~~");
	parlex::literal const v4(U"<-");
	parlex::literal const v5(U"←");
	parlex::choice const v6({v4, v5});
	parlex::sequence const v7("BIT_NOT_ASSIGNMENT", {v0, v2, v3, v6});
	return parlex::production("BIT_NOT_ASSIGNMENT",v7);
}

static parlex::production BIT_OR() {
	parlex::reference const v0("EXPRESSION");
	parlex::reference const v1("IC");
	parlex::repetition const v2(v1);
	parlex::literal const v3(U"||");
	parlex::reference const v4("IC");
	parlex::repetition const v5(v4);
	parlex::reference const v6("EXPRESSION");
	parlex::sequence const v7("BIT_OR", {v0, v2, v3, v5, v6});
	return parlex::production("BIT_OR",v7, parlex::associativity::ANY);
}

static parlex::production BIT_OR_ASSIGNMENT() {
	parlex::reference const v0("EXPRESSION");
	parlex::reference const v1("IC");
	parlex::repetition const v2(v1);
	parlex::literal const v3(U"||");
	parlex::literal const v4(U"<-");
	parlex::literal const v5(U"←");
	parlex::choice const v6({v4, v5});
	parlex::reference const v7("IC");
	parlex::repetition const v8(v7);
	parlex::reference const v9("EXPRESSION");
	parlex::sequence const v10("BIT_OR_ASSIGNMENT", {v0, v2, v3, v6, v8, v9});
	return parlex::production("BIT_OR_ASSIGNMENT",v10);
}

static parlex::production BIT_XOR() {
	parlex::reference const v0("EXPRESSION");
	parlex::reference const v1("IC");
	parlex::repetition const v2(v1);
	parlex::literal const v3(U"^^");
	parlex::reference const v4("IC");
	parlex::repetition const v5(v4);
	parlex::reference const v6("EXPRESSION");
	parlex::sequence const v7("BIT_XOR", {v0, v2, v3, v5, v6});
	return parlex::production("BIT_XOR",v7, parlex::associativity::ANY);
}

static parlex::production BIT_XOR_ASSIGNMENT() {
	parlex::reference const v0("EXPRESSION");
	parlex::reference const v1("IC");
	parlex::repetition const v2(v1);
	parlex::literal const v3(U"^^");
	parlex::literal const v4(U"<-");
	parlex::literal const v5(U"←");
	parlex::choice const v6({v4, v5});
	parlex::reference const v7("IC");
	parlex::repetition const v8(v7);
	parlex::reference const v9("EXPRESSION");
	parlex::sequence const v10("BIT_XOR_ASSIGNMENT", {v0, v2, v3, v6, v8, v9});
	return parlex::production("BIT_XOR_ASSIGNMENT",v10);
}

static parlex::production BLOCK() {
	parlex::literal const v0(U"{");
	parlex::reference const v1("STATEMENT_SCOPE");
	parlex::literal const v2(U"}");
	parlex::sequence const v3("BLOCK", {v0, v1, v2});
	return parlex::production("BLOCK",v3);
}

static parlex::production BOOL() {
	parlex::literal const v0(U"true");
	parlex::literal const v1(U"false");
	parlex::choice const v2("BOOL", {v0, v1});
	return parlex::production("BOOL",v2);
}

static parlex::production BREAK() {
	parlex::literal const v0(U"break");
	parlex::reference const v1("IC");
	parlex::repetition const v2(v1);
	parlex::literal const v3(U"[");
	parlex::reference const v4("IC");
	parlex::repetition const v5(v4);
	parlex::reference const v6("expression", "EXPRESSION");
	parlex::reference const v7("IC");
	parlex::repetition const v8(v7);
	parlex::literal const v9(U"]");
	parlex::sequence const v10({v2, v3, v5, v6, v8, v9});
	parlex::reference const v11("IC");
	parlex::reference const v12("IC");
	parlex::repetition const v13(v12);
	parlex::reference const v14("identifier", "IDENTIFIER");
	parlex::sequence const v15({v11, v13, v14});
	parlex::choice const v16({v10, v15});
	parlex::optional const v17(v16);
	parlex::sequence const v18("BREAK", {v0, v17});
	return parlex::production("BREAK",v18);
}

static parlex::production CARDINALITY() {
	parlex::literal const v0(U"#");
	parlex::reference const v1("IC");
	parlex::repetition const v2(v1);
	parlex::reference const v3("EXPRESSION");
	parlex::sequence const v4("CARDINALITY", {v0, v2, v3});
	return parlex::production("CARDINALITY",v4, parlex::associativity::NONE, parlex::filter_function(), {"BINARY_OP", });
}

static parlex::production CAST() {
	parlex::reference const v0("PARENTHETICAL");
	parlex::reference const v1("IC");
	parlex::repetition const v2(v1);
	parlex::reference const v3("EXPRESSION");
	parlex::sequence const v4("CAST", {v0, v2, v3});
	return parlex::production("CAST",v4, parlex::associativity::NONE, parlex::filter_function(), {"BINARY_OP", });
}

static parlex::production CASTS() {
	parlex::reference const v0("EXPRESSION");
	parlex::reference const v1("IC");
	parlex::repetition const v2(v1);
	parlex::literal const v3(U"casts");
	parlex::reference const v4("IC");
	parlex::repetition const v5(v4);
	parlex::reference const v6("EXPRESSION");
	parlex::sequence const v7("CASTS", {v0, v2, v3, v5, v6});
	return parlex::production("CASTS",v7);
}

static parlex::production CEILING() {
	parlex::literal const v0(U"⌈");
	parlex::reference const v1("IC");
	parlex::repetition const v2(v1);
	parlex::reference const v3("EXPRESSION");
	parlex::reference const v4("IC");
	parlex::repetition const v5(v4);
	parlex::literal const v6(U"⌉");
	parlex::sequence const v7({v0, v2, v3, v5, v6});
	parlex::literal const v8(U"|\'");
	parlex::reference const v9("IC");
	parlex::repetition const v10(v9);
	parlex::reference const v11("EXPRESSION");
	parlex::reference const v12("IC");
	parlex::repetition const v13(v12);
	parlex::literal const v14(U"\'|");
	parlex::sequence const v15({v8, v10, v11, v13, v14});
	parlex::choice const v16("CEILING", {v7, v15});
	return parlex::production("CEILING",v16);
}

static parlex::production COMMENT() {
	parlex::literal const v0(U"/*");
	parlex::reference const v1("all");
	parlex::repetition const v2(v1);
	parlex::literal const v3(U"*/");
	parlex::sequence const v4("COMMENT", {v0, v2, v3});
	return parlex::production("COMMENT",v4);
}

static parlex::production COMPLEMENT() {
	parlex::reference const v0("EXPRESSION");
	parlex::reference const v1("IC");
	parlex::repetition const v2(v1);
	parlex::literal const v3(U"ᶜ");
	parlex::sequence const v4("COMPLEMENT", {v0, v2, v3});
	return parlex::production("COMPLEMENT",v4, parlex::associativity::NONE, parlex::filter_function(), {"BINARY_OP", });
}

static parlex::production COMPOSITION() {
	parlex::reference const v0("EXPRESSION");
	parlex::reference const v1("IC");
	parlex::repetition const v2(v1);
	parlex::literal const v3(U"∘");
	parlex::literal const v4(U"_o_");
	parlex::choice const v5({v3, v4});
	parlex::reference const v6("IC");
	parlex::repetition const v7(v6);
	parlex::reference const v8("EXPRESSION");
	parlex::sequence const v9("COMPOSITION", {v0, v2, v5, v7, v8});
	return parlex::production("COMPOSITION",v9, parlex::associativity::ANY);
}

static parlex::production COMPOSITION_ASSIGNMENT() {
	parlex::reference const v0("EXPRESSION");
	parlex::reference const v1("IC");
	parlex::repetition const v2(v1);
	parlex::literal const v3(U"∘");
	parlex::literal const v4(U"_o_");
	parlex::choice const v5({v3, v4});
	parlex::literal const v6(U"<-");
	parlex::literal const v7(U"←");
	parlex::choice const v8({v6, v7});
	parlex::reference const v9("IC");
	parlex::repetition const v10(v9);
	parlex::reference const v11("EXPRESSION");
	parlex::sequence const v12("COMPOSITION_ASSIGNMENT", {v0, v2, v5, v8, v10, v11});
	return parlex::production("COMPOSITION_ASSIGNMENT",v12);
}

static parlex::production COMPOUND() {
	parlex::reference const v0("EXPRESSION");
	parlex::reference const v1("IC");
	parlex::repetition const v2(v1);
	parlex::literal const v3(U"|");
	parlex::reference const v4("IC");
	parlex::repetition const v5(v4);
	parlex::reference const v6("EXPRESSION");
	parlex::sequence const v7("COMPOUND", {v0, v2, v3, v5, v6});
	return parlex::production("COMPOUND",v7, parlex::associativity::LEFT);
}

static parlex::production COMPOUND_ASSIGNMENT() {
	parlex::reference const v0("EXPRESSION");
	parlex::reference const v1("IC");
	parlex::repetition const v2(v1);
	parlex::literal const v3(U"|");
	parlex::literal const v4(U"<-");
	parlex::literal const v5(U"←");
	parlex::choice const v6({v4, v5});
	parlex::reference const v7("IC");
	parlex::repetition const v8(v7);
	parlex::reference const v9("EXPRESSION");
	parlex::sequence const v10("COMPOUND_ASSIGNMENT", {v0, v2, v3, v6, v8, v9});
	return parlex::production("COMPOUND_ASSIGNMENT",v10);
}

static parlex::production CONDITIONAL() {
	parlex::reference const v0("condition", "EXPRESSION");
	parlex::reference const v1("IC");
	parlex::repetition const v2(v1);
	parlex::literal const v3(U"\?");
	parlex::reference const v4("IC");
	parlex::repetition const v5(v4);
	parlex::reference const v6("true_case", "EXPRESSION");
	parlex::reference const v7("IC");
	parlex::repetition const v8(v7);
	parlex::literal const v9(U":");
	parlex::reference const v10("IC");
	parlex::repetition const v11(v10);
	parlex::reference const v12("false_case", "EXPRESSION");
	parlex::sequence const v13("CONDITIONAL", {v0, v2, v3, v5, v6, v8, v9, v11, v12});
	return parlex::production("CONDITIONAL",v13, parlex::associativity::RIGHT);
}

static parlex::production CONSTRUCTIVE_OP() {
	parlex::reference const v0("COMPOSITION");
	parlex::reference const v1("COMPOUND");
	parlex::reference const v2("PREPEND");
	parlex::reference const v3("NULL_COALESCE");
	parlex::choice const v4("CONSTRUCTIVE_OP", {v0, v1, v2, v3});
	return parlex::production("CONSTRUCTIVE_OP",v4);
}

static parlex::production CONTINUE() {
	parlex::literal const v0(U"continue");
	parlex::reference const v1("IC");
	parlex::repetition const v2(v1);
	parlex::literal const v3(U"[");
	parlex::reference const v4("IC");
	parlex::repetition const v5(v4);
	parlex::reference const v6("expression", "EXPRESSION");
	parlex::reference const v7("IC");
	parlex::repetition const v8(v7);
	parlex::literal const v9(U"]");
	parlex::sequence const v10({v2, v3, v5, v6, v8, v9});
	parlex::reference const v11("IC");
	parlex::reference const v12("IC");
	parlex::repetition const v13(v12);
	parlex::reference const v14("identifier", "IDENTIFIER");
	parlex::sequence const v15({v11, v13, v14});
	parlex::choice const v16({v10, v15});
	parlex::optional const v17(v16);
	parlex::sequence const v18("CONTINUE", {v0, v17});
	return parlex::production("CONTINUE",v18);
}

static parlex::production CROSS_PRODUCT() {
	parlex::reference const v0("EXPRESSION");
	parlex::reference const v1("IC");
	parlex::repetition const v2(v1);
	parlex::literal const v3(U"×");
	parlex::literal const v4(U"_x_");
	parlex::choice const v5({v3, v4});
	parlex::reference const v6("IC");
	parlex::repetition const v7(v6);
	parlex::reference const v8("EXPRESSION");
	parlex::sequence const v9("CROSS_PRODUCT", {v0, v2, v5, v7, v8});
	return parlex::production("CROSS_PRODUCT",v9, parlex::associativity::LEFT, parlex::filter_function(), {"DOT_PRODUCT", });
}

static parlex::production CROSS_PRODUCT_ASSIGNMENT() {
	parlex::reference const v0("EXPRESSION");
	parlex::reference const v1("IC");
	parlex::repetition const v2(v1);
	parlex::literal const v3(U"×");
	parlex::literal const v4(U"_x_");
	parlex::choice const v5({v3, v4});
	parlex::literal const v6(U"<-");
	parlex::literal const v7(U"←");
	parlex::choice const v8({v6, v7});
	parlex::reference const v9("IC");
	parlex::repetition const v10(v9);
	parlex::reference const v11("EXPRESSION");
	parlex::sequence const v12("CROSS_PRODUCT_ASSIGNMENT", {v0, v2, v5, v8, v10, v11});
	return parlex::production("CROSS_PRODUCT_ASSIGNMENT",v12);
}

static parlex::production DATE() {
	parlex::reference const v0("DATE_YEAR_MONTH_DAY");
	parlex::reference const v1("DATE_YEAR_DAY");
	parlex::choice const v2("DATE", {v0, v1});
	return parlex::production("DATE",v2);
}

static parlex::production DATE_TIME() {
	parlex::reference const v0("DATE");
	parlex::literal const v1(U"T");
	parlex::reference const v2("TIME");
	parlex::sequence const v3("DATE_TIME", {v0, v1, v2});
	return parlex::production("DATE_TIME",v3);
}

static parlex::production DATE_YEAR_DAY() {
	parlex::reference const v0("decimal_digit");
	parlex::reference const v1("decimal_digit");
	parlex::reference const v2("decimal_digit");
	parlex::reference const v3("decimal_digit");
	parlex::literal const v4(U"-");
	parlex::reference const v5("decimal_digit");
	parlex::reference const v6("decimal_digit");
	parlex::reference const v7("decimal_digit");
	parlex::sequence const v8("DATE_YEAR_DAY", {v0, v1, v2, v3, v4, v5, v6, v7});
	return parlex::production("DATE_YEAR_DAY",v8, parlex::associativity::NONE, parlex::filter_function(), {"SUBTRACTION", });
}

static parlex::production DATE_YEAR_MONTH_DAY() {
	parlex::reference const v0("decimal_digit");
	parlex::reference const v1("decimal_digit");
	parlex::reference const v2("decimal_digit");
	parlex::reference const v3("decimal_digit");
	parlex::literal const v4(U"-");
	parlex::reference const v5("decimal_digit");
	parlex::reference const v6("decimal_digit");
	parlex::literal const v7(U"-");
	parlex::reference const v8("decimal_digit");
	parlex::reference const v9("decimal_digit");
	parlex::sequence const v10("DATE_YEAR_MONTH_DAY", {v0, v1, v2, v3, v4, v5, v6, v7, v8, v9});
	return parlex::production("DATE_YEAR_MONTH_DAY",v10, parlex::associativity::NONE, parlex::filter_function(), {"SUBTRACTION", });
}

static parlex::production DECLARATION() {
	parlex::reference const v0("xml_doc_string", "XML_DOC_STRING");
	parlex::reference const v1("IC");
	parlex::repetition const v2(v1);
	parlex::sequence const v3({v0, v2});
	parlex::optional const v4(v3);
	parlex::reference const v5("identifier", "IDENTIFIER");
	parlex::sequence const v6("DECLARATION", {v4, v5});
	return parlex::production("DECLARATION",v6);
}

static parlex::production DEFINITION() {
	parlex::reference const v0("xml_doc_string", "XML_DOC_STRING");
	parlex::reference const v1("IC");
	parlex::repetition const v2(v1);
	parlex::sequence const v3({v0, v2});
	parlex::optional const v4(v3);
	parlex::reference const v5("identifier", "IDENTIFIER");
	parlex::reference const v6("IC");
	parlex::repetition const v7(v6);
	parlex::literal const v8(U":=");
	parlex::reference const v9("IC");
	parlex::repetition const v10(v9);
	parlex::reference const v11("expression", "EXPRESSION");
	parlex::sequence const v12("DEFINITION", {v4, v5, v7, v8, v10, v11});
	return parlex::production("DEFINITION",v12);
}

static parlex::production DELTA() {
	parlex::literal const v0(U"Δ");
	parlex::literal const v1(U"_delta_");
	parlex::choice const v2({v0, v1});
	parlex::literal const v3(U"^");
	parlex::reference const v4("whole_number", "WHOLE_NUMBER");
	parlex::sequence const v5({v3, v4});
	parlex::optional const v6(v5);
	parlex::reference const v7("expression", "EXPRESSION");
	parlex::sequence const v8("DELTA", {v2, v6, v7});
	return parlex::production("DELTA",v8, parlex::associativity::NONE, parlex::filter_function(), {"BINARY_OP", "EXPONENTIATION", });
}

static parlex::production DIMENSION() {
	parlex::reference const v0("IDENTIFIER");
	parlex::reference const v1("DIMENSIONAL_ANALYSIS_OP");
	parlex::choice const v2("DIMENSION", {v0, v1});
	return parlex::production("DIMENSION",v2);
}

static parlex::production DIMENSIONAL_ANALYSIS_OP() {
	parlex::reference const v0("UNIT_DIVISION");
	parlex::reference const v1("UNIT_EXPONENTIATION");
	parlex::reference const v2("UNIT_MULTIPLICATION");
	parlex::choice const v3("DIMENSIONAL_ANALYSIS_OP", {v0, v1, v2});
	return parlex::production("DIMENSIONAL_ANALYSIS_OP",v3);
}

static parlex::production DIMENSIONAL_NUMBER() {
	parlex::reference const v0("NON_NEG_NUMBER");
	parlex::reference const v1("DIMENSION");
	parlex::sequence const v2("DIMENSIONAL_NUMBER", {v0, v1});
	return parlex::production("DIMENSIONAL_NUMBER",v2, parlex::associativity::NONE, parlex::filter_function(), {"BINARY_OP", "EXPONENTIATION", });
}

static parlex::production DIVISION() {
	parlex::reference const v0("EXPRESSION");
	parlex::reference const v1("IC");
	parlex::repetition const v2(v1);
	parlex::literal const v3(U"÷");
	parlex::literal const v4(U"/");
	parlex::choice const v5({v3, v4});
	parlex::reference const v6("IC");
	parlex::repetition const v7(v6);
	parlex::reference const v8("EXPRESSION");
	parlex::sequence const v9("DIVISION", {v0, v2, v5, v7, v8});
	return parlex::production("DIVISION",v9, parlex::associativity::LEFT, parlex::filter_function(), {"ADDITION", "ADD_SUB", "INTEGER_DIVISION", "MAPS_TO", "MODULATION", "SUBTRACTION", });
}

static parlex::production DIVISION_ASSIGNMENT() {
	parlex::reference const v0("EXPRESSION");
	parlex::reference const v1("IC");
	parlex::repetition const v2(v1);
	parlex::literal const v3(U"÷");
	parlex::literal const v4(U"/");
	parlex::choice const v5({v3, v4});
	parlex::literal const v6(U"<-");
	parlex::literal const v7(U"←");
	parlex::choice const v8({v6, v7});
	parlex::reference const v9("IC");
	parlex::repetition const v10(v9);
	parlex::reference const v11("EXPRESSION");
	parlex::sequence const v12("DIVISION_ASSIGNMENT", {v0, v2, v5, v8, v10, v11});
	return parlex::production("DIVISION_ASSIGNMENT",v12);
}

static parlex::production DO() {
	parlex::literal const v0(U"do");
	parlex::reference const v1("IC");
	parlex::repetition const v2(v1);
	parlex::reference const v3("expression", "EXPRESSION");
	parlex::reference const v4("IC");
	parlex::repetition const v5(v4);
	parlex::literal const v6(U"while");
	parlex::literal const v7(U"until");
	parlex::choice const v8({v6, v7});
	parlex::reference const v9("IC");
	parlex::repetition const v10(v9);
	parlex::reference const v11("condition", "PARENTHETICAL");
	parlex::sequence const v12({v5, v8, v10, v11});
	parlex::optional const v13(v12);
	parlex::sequence const v14("DO", {v0, v2, v3, v13});
	return parlex::production("DO",v14);
}

static parlex::production DOT_PRODUCT() {
	parlex::reference const v0("EXPRESSION");
	parlex::reference const v1("IC");
	parlex::repetition const v2(v1);
	parlex::literal const v3(U"⋅");
	parlex::literal const v4(U"_dot_");
	parlex::choice const v5({v3, v4});
	parlex::reference const v6("IC");
	parlex::repetition const v7(v6);
	parlex::reference const v8("EXPRESSION");
	parlex::sequence const v9("DOT_PRODUCT", {v0, v2, v5, v7, v8});
	return parlex::production("DOT_PRODUCT",v9, parlex::associativity::LEFT);
}

static parlex::production DOWNCASTS() {
	parlex::reference const v0("EXPRESSION");
	parlex::reference const v1("IC");
	parlex::repetition const v2(v1);
	parlex::literal const v3(U"downcasts");
	parlex::reference const v4("IC");
	parlex::repetition const v5(v4);
	parlex::reference const v6("EXPRESSION");
	parlex::sequence const v7("DOWNCASTS", {v0, v2, v3, v5, v6});
	return parlex::production("DOWNCASTS",v7);
}

static parlex::production EMBEDDED_COMMENT() {
	parlex::literal const v0(U"/***");
	parlex::reference const v1("EMBEDDED_COMMENT_INTERIOR");
	parlex::literal const v2(U"***/");
	parlex::sequence const v3("EMBEDDED_COMMENT", {v0, v1, v2});
	return parlex::production("EMBEDDED_COMMENT",v3, parlex::associativity::NONE, parlex::shortest(), {"COMMENT", });
}

static parlex::production EMBEDDED_COMMENT_INTERIOR() {
	parlex::reference const v0("payload", "PAYLOAD");
	parlex::literal const v1(U"*");
	parlex::reference const v2("EMBEDDED_COMMENT_INTERIOR");
	parlex::literal const v3(U"*");
	parlex::sequence const v4({v1, v2, v3});
	parlex::choice const v5("EMBEDDED_COMMENT_INTERIOR", {v0, v4});
	return parlex::production("EMBEDDED_COMMENT_INTERIOR",v5, parlex::associativity::NONE, parlex::filter_function(), {"PAYLOAD", });
}

static parlex::production EMBEDDED_NEWLINE_STRING() {
	parlex::literal const v0(U"\"\"\"");
	parlex::reference const v1("EMBEDDED_NEWLINE_STRING_INTERIOR");
	parlex::literal const v2(U"\"\"\"");
	parlex::sequence const v3("EMBEDDED_NEWLINE_STRING", {v0, v1, v2});
	return parlex::production("EMBEDDED_NEWLINE_STRING",v3, parlex::associativity::NONE, parlex::shortest(), {"EMBEDDED_STRING", });
}

static parlex::production EMBEDDED_NEWLINE_STRING_INTERIOR() {
	parlex::literal const v0(U"\n");
	parlex::reference const v1("payload", "PAYLOAD");
	parlex::literal const v2(U"\n");
	parlex::sequence const v3({v0, v1, v2});
	parlex::literal const v4(U"\"");
	parlex::reference const v5("EMBEDDED_NEWLINE_STRING_INTERIOR");
	parlex::literal const v6(U"\"");
	parlex::sequence const v7({v4, v5, v6});
	parlex::choice const v8("EMBEDDED_NEWLINE_STRING_INTERIOR", {v3, v7});
	return parlex::production("EMBEDDED_NEWLINE_STRING_INTERIOR",v8, parlex::associativity::NONE, parlex::filter_function(), {"PAYLOAD", });
}

static parlex::production EMBEDDED_STRING() {
	parlex::literal const v0(U"\"\"\"");
	parlex::reference const v1("EMBEDDED_STRING_INTERIOR");
	parlex::literal const v2(U"\"\"\"");
	parlex::sequence const v3("EMBEDDED_STRING", {v0, v1, v2});
	return parlex::production("EMBEDDED_STRING",v3, parlex::associativity::NONE, parlex::shortest());
}

static parlex::production EMBEDDED_STRING_INTERIOR() {
	parlex::reference const v0("payload", "PAYLOAD");
	parlex::literal const v1(U"\"");
	parlex::reference const v2("EMBEDDED_STRING_INTERIOR");
	parlex::literal const v3(U"\"");
	parlex::sequence const v4({v1, v2, v3});
	parlex::choice const v5("EMBEDDED_STRING_INTERIOR", {v0, v4});
	return parlex::production("EMBEDDED_STRING_INTERIOR",v5, parlex::associativity::NONE, parlex::filter_function(), {"PAYLOAD", });
}

static parlex::production END_OF_LINE_COMMENT() {
	parlex::literal const v0(U"//");
	parlex::reference const v1("not_newline");
	parlex::repetition const v2(v1);
	parlex::literal const v3(U"\n");
	parlex::sequence const v4("END_OF_LINE_COMMENT", {v0, v2, v3});
	return parlex::production("END_OF_LINE_COMMENT",v4);
}

static parlex::production ENUM() {
	parlex::literal const v0(U"enum");
	parlex::reference const v1("IC");
	parlex::repetition const v2(v1);
	parlex::literal const v3(U"inheriting");
	parlex::reference const v4("IC");
	parlex::repetition const v5(v4);
	parlex::reference const v6("INHERITANCE_LIST");
	parlex::reference const v7("IC");
	parlex::repetition const v8(v7);
	parlex::sequence const v9({v3, v5, v6, v8});
	parlex::optional const v10(v9);
	parlex::literal const v11(U"implementing");
	parlex::reference const v12("IC");
	parlex::repetition const v13(v12);
	parlex::reference const v14("INHERITANCE_LIST");
	parlex::reference const v15("IC");
	parlex::repetition const v16(v15);
	parlex::sequence const v17({v11, v13, v14, v16});
	parlex::optional const v18(v17);
	parlex::literal const v19(U"{");
	parlex::reference const v20("enum_element", "ENUM_ELEMENT");
	parlex::reference const v21("IC");
	parlex::repetition const v22(v21);
	parlex::literal const v23(U";");
	parlex::reference const v24("IC");
	parlex::repetition const v25(v24);
	parlex::reference const v26("enum_element", "ENUM_ELEMENT");
	parlex::sequence const v27({v22, v23, v25, v26});
	parlex::repetition const v28(v27);
	parlex::sequence const v29({v20, v28});
	parlex::optional const v30(v29);
	parlex::literal const v31(U"}");
	parlex::sequence const v32("ENUM", {v0, v2, v10, v18, v19, v30, v31});
	return parlex::production("ENUM",v32);
}

static parlex::production ENUM_ELEMENT() {
	parlex::reference const v0("identifier", "IDENTIFIER");
	parlex::reference const v1("IC");
	parlex::repetition const v2(v1);
	parlex::literal const v3(U":=");
	parlex::reference const v4("IC");
	parlex::repetition const v5(v4);
	parlex::reference const v6("expression", "EXPRESSION");
	parlex::sequence const v7({v2, v3, v5, v6});
	parlex::optional const v8(v7);
	parlex::sequence const v9("ENUM_ELEMENT", {v0, v8});
	return parlex::production("ENUM_ELEMENT",v9);
}

static parlex::production EQUALITY_CHAIN() {
	parlex::reference const v0("expression", "EXPRESSION");
	parlex::reference const v1("IC");
	parlex::repetition const v2(v1);
	parlex::reference const v3("equality_chain_loop", "EQUALITY_CHAIN_LOOP");
	parlex::sequence const v4("EQUALITY_CHAIN", {v0, v2, v3});
	return parlex::production("EQUALITY_CHAIN",v4, parlex::associativity::NONE, parlex::filter_function(), {"GREATER_CHAIN", "LESSER_CHAIN", "SUBSET_CHAIN", "SUPERSET_CHAIN", });
}

static parlex::production EQUALITY_CHAIN_LOOP() {
	parlex::literal const v0(U"=");
	parlex::reference const v1("IC");
	parlex::repetition const v2(v1);
	parlex::reference const v3("expression", "EXPRESSION");
	parlex::reference const v4("IC");
	parlex::repetition const v5(v4);
	parlex::reference const v6("equality_chain_loop", "EQUALITY_CHAIN_LOOP");
	parlex::sequence const v7({v5, v6});
	parlex::optional const v8(v7);
	parlex::sequence const v9("EQUALITY_CHAIN_LOOP", {v0, v2, v3, v8});
	return parlex::production("EQUALITY_CHAIN_LOOP",v9, parlex::associativity::NONE, parlex::filter_function(), {"EXPRESSION", });
}

static parlex::production EXACTLY() {
	parlex::reference const v0("EXPRESSION");
	parlex::reference const v1("IC");
	parlex::repetition const v2(v1);
	parlex::literal const v3(U"exactly");
	parlex::reference const v4("IC");
	parlex::repetition const v5(v4);
	parlex::reference const v6("EXPRESSION");
	parlex::sequence const v7("EXACTLY", {v0, v2, v3, v5, v6});
	return parlex::production("EXACTLY",v7);
}

static parlex::production EXISTS() {
	parlex::literal const v0(U"∃");
	parlex::literal const v1(U"exists");
	parlex::choice const v2({v0, v1});
	parlex::reference const v3("IC");
	parlex::repetition const v4(v3);
	parlex::reference const v5("EXPRESSION");
	parlex::sequence const v6("EXISTS", {v2, v4, v5});
	return parlex::production("EXISTS",v6);
}

static parlex::production EXISTS_ONE() {
	parlex::literal const v0(U"∃!");
	parlex::literal const v1(U"exists!");
	parlex::choice const v2({v0, v1});
	parlex::reference const v3("IC");
	parlex::repetition const v4(v3);
	parlex::reference const v5("EXPRESSION");
	parlex::sequence const v6("EXISTS_ONE", {v2, v4, v5});
	return parlex::production("EXISTS_ONE",v6);
}

static parlex::production EXPONENTIATION() {
	parlex::reference const v0("EXPRESSION");
	parlex::reference const v1("IC");
	parlex::repetition const v2(v1);
	parlex::literal const v3(U"^");
	parlex::reference const v4("IC");
	parlex::repetition const v5(v4);
	parlex::reference const v6("EXPRESSION");
	parlex::sequence const v7("EXPONENTIATION", {v0, v2, v3, v5, v6});
	return parlex::production("EXPONENTIATION",v7, parlex::associativity::RIGHT, parlex::filter_function(), {"ADDITION", "ADD_SUB", "DIVISION", "INTEGER_DIVISION", "MODULATION", "MULTIPLICATIVE_OP", "SUBTRACTION", });
}

static parlex::production EXPONENTIATION_ASSIGNMENT() {
	parlex::reference const v0("EXPRESSION");
	parlex::reference const v1("IC");
	parlex::repetition const v2(v1);
	parlex::literal const v3(U"^");
	parlex::literal const v4(U"<-");
	parlex::literal const v5(U"←");
	parlex::choice const v6({v4, v5});
	parlex::reference const v7("IC");
	parlex::repetition const v8(v7);
	parlex::reference const v9("EXPRESSION");
	parlex::sequence const v10("EXPONENTIATION_ASSIGNMENT", {v0, v2, v3, v6, v8, v9});
	return parlex::production("EXPONENTIATION_ASSIGNMENT",v10);
}

static parlex::production EXPRESSION() {
	parlex::reference const v0("ARRAY");
	parlex::reference const v1("ASM_FUNCTION");
	parlex::reference const v2("BINARY_OP");
	parlex::reference const v3("BOOL");
	parlex::reference const v4("CAST");
	parlex::reference const v5("CEILING");
	parlex::reference const v6("COMPLEMENT");
	parlex::reference const v7("CONDITIONAL");
	parlex::reference const v8("DATE");
	parlex::reference const v9("DATE_TIME");
	parlex::reference const v10("DELTA");
	parlex::reference const v11("DIMENSIONAL_NUMBER");
	parlex::reference const v12("EMBEDDED_STRING");
	parlex::reference const v13("ENUM");
	parlex::reference const v14("EQUALITY_CHAIN");
	parlex::reference const v15("FLOOR");
	parlex::reference const v16("FUNCTION");
	parlex::reference const v17("GREATER_CHAIN");
	parlex::reference const v18("IDENTIFIER");
	parlex::reference const v19("IF");
	parlex::reference const v20("INVOCATION");
	parlex::reference const v21("LESSER_CHAIN");
	parlex::reference const v22("LIST");
	parlex::reference const v23("MAGNITUDE");
	parlex::reference const v24("MAP");
	parlex::reference const v25("MEMBER_ACCESS");
	parlex::reference const v26("NEAREST_INTEGER");
	parlex::reference const v27("NON_NEG_NUMBER");
	parlex::reference const v28("OBJECT");
	parlex::reference const v29("PARENTHETICAL");
	parlex::reference const v30("RANGE");
	parlex::reference const v31("REGEX");
	parlex::reference const v32("SET");
	parlex::reference const v33("SET_COMPREHENSION");
	parlex::reference const v34("SUBSET_CHAIN");
	parlex::reference const v35("SUPERSET_CHAIN");
	parlex::reference const v36("SWIZZLE");
	parlex::reference const v37("THIS");
	parlex::reference const v38("THIS_FUNC");
	parlex::reference const v39("THIS_TYPE");
	parlex::reference const v40("TIME");
	parlex::reference const v41("TUPLE");
	parlex::reference const v42("TYPE");
	parlex::reference const v43("UNARY_OP");
	parlex::reference const v44("VECTOR_NORM");
	parlex::literal const v45(U"context");
	parlex::literal const v46(U"null");
	parlex::reference const v47("c_string");
	parlex::choice const v48("EXPRESSION", {v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46, v47});
	return parlex::production("EXPRESSION",v48);
}

static parlex::production EXTERN() {
	parlex::literal const v0(U"extern");
	return parlex::production("EXTERN",v0, parlex::associativity::NONE, parlex::filter_function(), {"IDENTIFIER", });
}

static parlex::production FACTORIAL() {
	parlex::reference const v0("EXPRESSION");
	parlex::reference const v1("IC");
	parlex::repetition const v2(v1);
	parlex::literal const v3(U"!");
	parlex::sequence const v4("FACTORIAL", {v0, v2, v3});
	return parlex::production("FACTORIAL",v4, parlex::associativity::NONE, parlex::filter_function(), {"BINARY_OP", });
}

static parlex::production FACTORIAL_ASSIGNMENT() {
	parlex::reference const v0("EXPRESSION");
	parlex::reference const v1("IC");
	parlex::repetition const v2(v1);
	parlex::literal const v3(U"!");
	parlex::literal const v4(U"<-");
	parlex::literal const v5(U"←");
	parlex::choice const v6({v4, v5});
	parlex::sequence const v7("FACTORIAL_ASSIGNMENT", {v0, v2, v3, v6});
	return parlex::production("FACTORIAL_ASSIGNMENT",v7);
}

static parlex::production FLOOR() {
	parlex::literal const v0(U"⌊");
	parlex::reference const v1("IC");
	parlex::repetition const v2(v1);
	parlex::reference const v3("expression", "EXPRESSION");
	parlex::reference const v4("IC");
	parlex::repetition const v5(v4);
	parlex::literal const v6(U"⌋");
	parlex::sequence const v7({v0, v2, v3, v5, v6});
	parlex::literal const v8(U"|_");
	parlex::reference const v9("IC");
	parlex::repetition const v10(v9);
	parlex::reference const v11("expression", "EXPRESSION");
	parlex::reference const v12("IC");
	parlex::repetition const v13(v12);
	parlex::literal const v14(U"_|");
	parlex::sequence const v15({v8, v10, v11, v13, v14});
	parlex::choice const v16("FLOOR", {v7, v15});
	return parlex::production("FLOOR",v16);
}

static parlex::production FOR() {
	parlex::literal const v0(U"for");
	parlex::reference const v1("IC");
	parlex::repetition const v2(v1);
	parlex::literal const v3(U"(");
	parlex::reference const v4("IC");
	parlex::repetition const v5(v4);
	parlex::reference const v6("STATEMENT_SCOPE");
	parlex::reference const v7("IC");
	parlex::repetition const v8(v7);
	parlex::sequence const v9({v6, v8});
	parlex::optional const v10("initializer", v9);
	parlex::reference const v11("condition", "EXPRESSION");
	parlex::reference const v12("IC");
	parlex::repetition const v13(v12);
	parlex::literal const v14(U";");
	parlex::reference const v15("IC");
	parlex::repetition const v16(v15);
	parlex::reference const v17("ASSIGNMENT_CHAIN");
	parlex::reference const v18("IC");
	parlex::repetition const v19(v18);
	parlex::literal const v20(U",");
	parlex::reference const v21("IC");
	parlex::repetition const v22(v21);
	parlex::reference const v23("ASSIGNMENT_CHAIN");
	parlex::sequence const v24({v19, v20, v22, v23});
	parlex::repetition const v25(v24);
	parlex::reference const v26("IC");
	parlex::repetition const v27(v26);
	parlex::sequence const v28({v17, v25, v27});
	parlex::optional const v29("step", v28);
	parlex::literal const v30(U")");
	parlex::reference const v31("IC");
	parlex::repetition const v32(v31);
	parlex::reference const v33("EXPRESSION");
	parlex::sequence const v34("FOR", {v0, v2, v3, v5, v10, v11, v13, v14, v16, v29, v30, v32, v33});
	return parlex::production("FOR",v34);
}

static parlex::production FOR_COLLECTION() {
	parlex::literal const v0(U"for");
	parlex::reference const v1("IC");
	parlex::repetition const v2(v1);
	parlex::literal const v3(U"(");
	parlex::reference const v4("IC");
	parlex::repetition const v5(v4);
	parlex::reference const v6("TYPE_DEREFERENCE");
	parlex::reference const v7("IMPLICIT_TYPE_DEREFERENCE");
	parlex::choice const v8({v6, v7});
	parlex::reference const v9("IC");
	parlex::repetition const v10(v9);
	parlex::sequence const v11({v8, v10});
	parlex::optional const v12(v11);
	parlex::reference const v13("IDENTIFIER");
	parlex::sequence const v14("declaration", {v12, v13});
	parlex::reference const v15("expression", "EXPRESSION");
	parlex::choice const v16({v14, v15});
	parlex::reference const v17("IC");
	parlex::repetition const v18(v17);
	parlex::literal const v19(U"in");
	parlex::literal const v20(U"∈");
	parlex::choice const v21({v19, v20});
	parlex::reference const v22("IC");
	parlex::repetition const v23(v22);
	parlex::reference const v24("collection", "EXPRESSION");
	parlex::reference const v25("IC");
	parlex::repetition const v26(v25);
	parlex::literal const v27(U")");
	parlex::reference const v28("IC");
	parlex::repetition const v29(v28);
	parlex::reference const v30("invoke", "EXPRESSION");
	parlex::sequence const v31("FOR_COLLECTION", {v0, v2, v3, v5, v16, v18, v21, v23, v24, v26, v27, v29, v30});
	return parlex::production("FOR_COLLECTION",v31);
}

static parlex::production FREE() {
	parlex::literal const v0(U"free");
	parlex::reference const v1("IC");
	parlex::repetition const v2(v1);
	parlex::reference const v3("EXPRESSION");
	parlex::sequence const v4("FREE", {v0, v2, v3});
	return parlex::production("FREE",v4);
}

static parlex::production FUNCTION() {
	parlex::literal const v0(U"(");
	parlex::reference const v1("IC");
	parlex::repetition const v2(v1);
	parlex::reference const v3("parameter", "PARAMETER");
	parlex::reference const v4("IC");
	parlex::repetition const v5(v4);
	parlex::literal const v6(U",");
	parlex::reference const v7("IC");
	parlex::repetition const v8(v7);
	parlex::reference const v9("parameter", "PARAMETER");
	parlex::sequence const v10({v5, v6, v8, v9});
	parlex::repetition const v11(v10);
	parlex::reference const v12("IC");
	parlex::repetition const v13(v12);
	parlex::sequence const v14({v3, v11, v13});
	parlex::optional const v15(v14);
	parlex::literal const v16(U")");
	parlex::reference const v17("IC");
	parlex::repetition const v18(v17);
	parlex::sequence const v19({v0, v2, v15, v16, v18});
	parlex::optional const v20(v19);
	parlex::reference const v21("FUNCTION_MODIFIER_0");
	parlex::reference const v22("IC");
	parlex::repetition const v23(v22);
	parlex::sequence const v24({v21, v23});
	parlex::optional const v25(v24);
	parlex::reference const v26("block", "BLOCK");
	parlex::sequence const v27("FUNCTION", {v20, v25, v26});
	return parlex::production("FUNCTION",v27, parlex::associativity::NONE, parlex::filter_function(), {"CAST", });
}

static parlex::production FUNCTION_MODIFIER_0() {
	parlex::reference const v0("FUNCTION_MODIFIER_STABILITY");
	parlex::reference const v1("FUNCTION_MODIFIER_1");
	parlex::choice const v2("FUNCTION_MODIFIER_0", {v0, v1});
	return parlex::production("FUNCTION_MODIFIER_0",v2);
}

static parlex::production FUNCTION_MODIFIER_1() {
	parlex::reference const v0("FUNCTION_MODIFIER_THROWING");
	parlex::reference const v1("FUNCTION_MODIFIER_2");
	parlex::choice const v2("FUNCTION_MODIFIER_1", {v0, v1});
	return parlex::production("FUNCTION_MODIFIER_1",v2);
}

static parlex::production FUNCTION_MODIFIER_2() {
	parlex::reference const v0("FUNCTION_MODIFIER_ATOMIC");
	parlex::reference const v1("FUNCTION_MODIFIER_3");
	parlex::choice const v2("FUNCTION_MODIFIER_2", {v0, v1});
	return parlex::production("FUNCTION_MODIFIER_2",v2);
}

static parlex::production FUNCTION_MODIFIER_3() {
	parlex::reference const v0("FUNCTION_MODIFIER_PLATFORM");
	parlex::reference const v1("FUNCTION_MODIFIER_4");
	parlex::choice const v2("FUNCTION_MODIFIER_3", {v0, v1});
	return parlex::production("FUNCTION_MODIFIER_3",v2);
}

static parlex::production FUNCTION_MODIFIER_4() {
	parlex::reference const v0("FUNCTION_MODIFIER_MODEL");
	parlex::reference const v1("FUNCTION_MODIFIER_CALLING_CONVENTION");
	parlex::choice const v2("FUNCTION_MODIFIER_4", {v0, v1});
	return parlex::production("FUNCTION_MODIFIER_4",v2);
}

static parlex::production FUNCTION_MODIFIER_ATOMIC() {
	parlex::literal const v0(U"atomic");
	parlex::reference const v1("IC");
	parlex::reference const v2("IC");
	parlex::repetition const v3(v2);
	parlex::reference const v4("FUNCTION_MODIFIER_3");
	parlex::sequence const v5({v1, v3, v4});
	parlex::optional const v6(v5);
	parlex::sequence const v7("FUNCTION_MODIFIER_ATOMIC", {v0, v6});
	return parlex::production("FUNCTION_MODIFIER_ATOMIC",v7);
}

static parlex::production FUNCTION_MODIFIER_CALLING_CONVENTION() {
	parlex::literal const v0(U"c_call");
	parlex::literal const v1(U"fast_call");
	parlex::literal const v2(U"cold_call");
	parlex::literal const v3(U"ghc_call");
	parlex::literal const v4(U"hipe_call");
	parlex::literal const v5(U"webkit_js_call");
	parlex::literal const v6(U"any_reg_call");
	parlex::literal const v7(U"preserve_most_call");
	parlex::literal const v8(U"preserve_all_call");
	parlex::literal const v9(U"swift_call");
	parlex::literal const v10(U"cxx_fast_tls_call");
	parlex::literal const v11(U"first_target_call");
	parlex::literal const v12(U"x86_std_call");
	parlex::literal const v13(U"X86_fast_call");
	parlex::literal const v14(U"arm_apcs_call");
	parlex::literal const v15(U"arm_aapcs_call");
	parlex::literal const v16(U"arm_aapcs_vfp_call");
	parlex::literal const v17(U"msp430_intr_call");
	parlex::literal const v18(U"x86_this_call");
	parlex::literal const v19(U"ptx_kernel_call");
	parlex::literal const v20(U"ptx_device_call");
	parlex::literal const v21(U"spir_func_call");
	parlex::literal const v22(U"spir_kernel_call");
	parlex::literal const v23(U"intel_ocl_bi_call");
	parlex::literal const v24(U"x86_64_sysv_call");
	parlex::literal const v25(U"x86_64_win64_call");
	parlex::literal const v26(U"x86_vector_call");
	parlex::literal const v27(U"hhvm_call");
	parlex::literal const v28(U"x86_intr_call");
	parlex::literal const v29(U"avr_intr_call");
	parlex::literal const v30(U"avr_signal_call");
	parlex::literal const v31(U"avr_builtin_call");
	parlex::choice const v32("FUNCTION_MODIFIER_CALLING_CONVENTION", {v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31});
	return parlex::production("FUNCTION_MODIFIER_CALLING_CONVENTION",v32);
}

static parlex::production FUNCTION_MODIFIER_MODEL() {
	parlex::literal const v0(U"pure");
	parlex::literal const v1(U"imperative");
	parlex::literal const v2(U"opaque");
	parlex::choice const v3("model", {v0, v1, v2});
	parlex::reference const v4("IC");
	parlex::reference const v5("IC");
	parlex::repetition const v6(v5);
	parlex::reference const v7("FUNCTION_MODIFIER_CALLING_CONVENTION");
	parlex::sequence const v8({v4, v6, v7});
	parlex::optional const v9(v8);
	parlex::sequence const v10("FUNCTION_MODIFIER_MODEL", {v3, v9});
	return parlex::production("FUNCTION_MODIFIER_MODEL",v10);
}

static parlex::production FUNCTION_MODIFIER_PLATFORM() {
	parlex::reference const v0("PLATFORM");
	parlex::reference const v1("IC");
	parlex::reference const v2("IC");
	parlex::repetition const v3(v2);
	parlex::reference const v4("PLATFORM");
	parlex::sequence const v5({v1, v3, v4});
	parlex::repetition const v6(v5);
	parlex::reference const v7("IC");
	parlex::reference const v8("IC");
	parlex::repetition const v9(v8);
	parlex::reference const v10("FUNCTION_MODIFIER_4");
	parlex::sequence const v11({v7, v9, v10});
	parlex::optional const v12(v11);
	parlex::sequence const v13("FUNCTION_MODIFIER_PLATFORM", {v0, v6, v12});
	return parlex::production("FUNCTION_MODIFIER_PLATFORM",v13);
}

static parlex::production FUNCTION_MODIFIER_STABILITY() {
	parlex::literal const v0(U"stable");
	parlex::literal const v1(U"unstable");
	parlex::choice const v2("stability", {v0, v1});
	parlex::reference const v3("IC");
	parlex::reference const v4("IC");
	parlex::repetition const v5(v4);
	parlex::reference const v6("FUNCTION_MODIFIER_1");
	parlex::sequence const v7({v3, v5, v6});
	parlex::optional const v8(v7);
	parlex::sequence const v9("FUNCTION_MODIFIER_STABILITY", {v2, v8});
	return parlex::production("FUNCTION_MODIFIER_STABILITY",v9);
}

static parlex::production FUNCTION_MODIFIER_THROWING() {
	parlex::literal const v0(U"throwing");
	parlex::reference const v1("IC");
	parlex::repetition const v2(v1);
	parlex::reference const v3("ARRAY");
	parlex::sequence const v4({v2, v3});
	parlex::optional const v5(v4);
	parlex::reference const v6("IC");
	parlex::reference const v7("IC");
	parlex::repetition const v8(v7);
	parlex::reference const v9("FUNCTION_MODIFIER_2");
	parlex::sequence const v10({v6, v8, v9});
	parlex::optional const v11(v10);
	parlex::sequence const v12("FUNCTION_MODIFIER_THROWING", {v0, v5, v11});
	return parlex::production("FUNCTION_MODIFIER_THROWING",v12);
}

static parlex::production GREATER_CHAIN() {
	parlex::reference const v0("expression", "EXPRESSION");
	parlex::reference const v1("IC");
	parlex::repetition const v2(v1);
	parlex::reference const v3("greater_chain_loop", "GREATER_CHAIN_LOOP");
	parlex::sequence const v4("GREATER_CHAIN", {v0, v2, v3});
	return parlex::production("GREATER_CHAIN",v4);
}

static parlex::production GREATER_CHAIN_LOOP() {
	parlex::literal const v0(U"=");
	parlex::literal const v1(U">");
	parlex::literal const v2(U"=>");
	parlex::literal const v3(U"≥");
	parlex::choice const v4({v0, v1, v2, v3});
	parlex::reference const v5("IC");
	parlex::repetition const v6(v5);
	parlex::reference const v7("expression", "EXPRESSION");
	parlex::reference const v8("IC");
	parlex::repetition const v9(v8);
	parlex::reference const v10("greater_chain_loop", "GREATER_CHAIN_LOOP");
	parlex::sequence const v11({v9, v10});
	parlex::optional const v12(v11);
	parlex::sequence const v13("GREATER_CHAIN_LOOP", {v4, v6, v7, v12});
	return parlex::production("GREATER_CHAIN_LOOP",v13);
}

static parlex::production HAS() {
	parlex::reference const v0("EXPRESSION");
	parlex::reference const v1("IC");
	parlex::repetition const v2(v1);
	parlex::literal const v3(U"∋");
	parlex::literal const v4(U"has");
	parlex::choice const v5({v3, v4});
	parlex::reference const v6("IC");
	parlex::repetition const v7(v6);
	parlex::reference const v8("EXPRESSION");
	parlex::sequence const v9("HAS", {v0, v2, v5, v7, v8});
	return parlex::production("HAS",v9, parlex::associativity::LEFT);
}

static parlex::production HEX() {
	parlex::literal const v0(U"0x");
	parlex::reference const v1("hexadecimal_digit");
	parlex::reference const v2("hexadecimal_digit");
	parlex::repetition const v3(v2);
	parlex::sequence const v4("HEX", {v0, v1, v3});
	return parlex::production("HEX",v4);
}

static parlex::production IC() {
	parlex::reference const v0("COMMENT");
	parlex::reference const v1("EMBEDDED_COMMENT");
	parlex::reference const v2("END_OF_LINE_COMMENT");
	parlex::reference const v3("WS");
	parlex::choice const v4("IC", {v0, v1, v2, v3});
	return parlex::production("IC",v4);
}

static parlex::production IDENTIFIER() {
	parlex::reference const v0("letter");
	parlex::literal const v1(U"_");
	parlex::choice const v2("head", {v0, v1});
	parlex::reference const v3("letter");
	parlex::reference const v4("number");
	parlex::literal const v5(U"_");
	parlex::choice const v6({v3, v4, v5});
	parlex::repetition const v7("tail", v6);
	parlex::sequence const v8("IDENTIFIER", {v2, v7});
	return parlex::production("IDENTIFIER",v8, parlex::associativity::NONE, parlex::longest(), {"ALL", });
}

static parlex::production IF() {
	parlex::literal const v0(U"if");
	parlex::reference const v1("IC");
	parlex::repetition const v2(v1);
	parlex::reference const v3("condition", "PARENTHETICAL");
	parlex::reference const v4("IC");
	parlex::repetition const v5(v4);
	parlex::reference const v6("invoke", "EXPRESSION");
	parlex::reference const v7("IC");
	parlex::repetition const v8(v7);
	parlex::literal const v9(U"elif");
	parlex::reference const v10("IC");
	parlex::repetition const v11(v10);
	parlex::reference const v12("condition", "PARENTHETICAL");
	parlex::reference const v13("IC");
	parlex::repetition const v14(v13);
	parlex::reference const v15("invoke", "EXPRESSION");
	parlex::sequence const v16({v8, v9, v11, v12, v14, v15});
	parlex::repetition const v17(v16);
	parlex::reference const v18("IC");
	parlex::repetition const v19(v18);
	parlex::literal const v20(U"else");
	parlex::reference const v21("IC");
	parlex::repetition const v22(v21);
	parlex::reference const v23("else_invoke", "EXPRESSION");
	parlex::sequence const v24({v19, v20, v22, v23});
	parlex::optional const v25(v24);
	parlex::sequence const v26("IF", {v0, v2, v3, v5, v6, v17, v25});
	return parlex::production("IF",v26);
}

static parlex::production IFF() {
	parlex::reference const v0("EXPRESSION");
	parlex::reference const v1("IC");
	parlex::repetition const v2(v1);
	parlex::literal const v3(U"⇔");
	parlex::literal const v4(U"<=>");
	parlex::choice const v5({v3, v4});
	parlex::reference const v6("IC");
	parlex::repetition const v7(v6);
	parlex::reference const v8("EXPRESSION");
	parlex::sequence const v9("IFF", {v0, v2, v5, v7, v8});
	return parlex::production("IFF",v9, parlex::associativity::ANY);
}

static parlex::production IMPLEMENTS() {
	parlex::reference const v0("EXPRESSION");
	parlex::reference const v1("IC");
	parlex::repetition const v2(v1);
	parlex::literal const v3(U"implements");
	parlex::reference const v4("IC");
	parlex::repetition const v5(v4);
	parlex::reference const v6("EXPRESSION");
	parlex::sequence const v7("IMPLEMENTS", {v0, v2, v3, v5, v6});
	return parlex::production("IMPLEMENTS",v7);
}

static parlex::production IMPLICATION() {
	parlex::reference const v0("EXPRESSION");
	parlex::reference const v1("IC");
	parlex::repetition const v2(v1);
	parlex::literal const v3(U"⇒");
	parlex::literal const v4(U"=>");
	parlex::choice const v5({v3, v4});
	parlex::reference const v6("IC");
	parlex::repetition const v7(v6);
	parlex::reference const v8("EXPRESSION");
	parlex::sequence const v9("IMPLICATION", {v0, v2, v5, v7, v8});
	return parlex::production("IMPLICATION",v9, parlex::associativity::RIGHT, parlex::filter_function(), {"IFF", "XOR", });
}

static parlex::production IMPLICATION_ASSIGNMENT() {
	parlex::reference const v0("EXPRESSION");
	parlex::reference const v1("IC");
	parlex::repetition const v2(v1);
	parlex::literal const v3(U"⇒");
	parlex::literal const v4(U"=>");
	parlex::choice const v5({v3, v4});
	parlex::literal const v6(U"<-");
	parlex::literal const v7(U"←");
	parlex::choice const v8({v6, v7});
	parlex::reference const v9("IC");
	parlex::repetition const v10(v9);
	parlex::reference const v11("EXPRESSION");
	parlex::sequence const v12("IMPLICATION_ASSIGNMENT", {v0, v2, v5, v8, v10, v11});
	return parlex::production("IMPLICATION_ASSIGNMENT",v12);
}

static parlex::production IMPLICIT_TYPE_DEREFERENCE() {
	parlex::literal const v0(U"<");
	parlex::reference const v1("IC");
	parlex::repetition const v2(v1);
	parlex::literal const v3(U">");
	parlex::sequence const v4("IMPLICIT_TYPE_DEREFERENCE", {v0, v2, v3});
	return parlex::production("IMPLICIT_TYPE_DEREFERENCE",v4);
}

static parlex::production IMPORT() {
	parlex::literal const v0(U"import");
	parlex::reference const v1("IC");
	parlex::repetition const v2(v1);
	parlex::reference const v3("EXPRESSION");
	parlex::sequence const v4("IMPORT", {v0, v2, v3});
	return parlex::production("IMPORT",v4);
}

static parlex::production IN() {
	parlex::reference const v0("EXPRESSION");
	parlex::reference const v1("IC");
	parlex::repetition const v2(v1);
	parlex::literal const v3(U"∈");
	parlex::literal const v4(U"in");
	parlex::choice const v5({v3, v4});
	parlex::reference const v6("IC");
	parlex::repetition const v7(v6);
	parlex::reference const v8("EXPRESSION");
	parlex::sequence const v9("IN", {v0, v2, v5, v7, v8});
	return parlex::production("IN",v9, parlex::associativity::LEFT);
}

static parlex::production INEQUALITY() {
	parlex::reference const v0("EXPRESSION");
	parlex::reference const v1("IC");
	parlex::repetition const v2(v1);
	parlex::literal const v3(U"≠");
	parlex::literal const v4(U"/=");
	parlex::choice const v5({v3, v4});
	parlex::reference const v6("IC");
	parlex::repetition const v7(v6);
	parlex::reference const v8("EXPRESSION");
	parlex::sequence const v9("INEQUALITY", {v0, v2, v5, v7, v8});
	return parlex::production("INEQUALITY",v9, parlex::associativity::LEFT);
}

static parlex::production INHERITANCE_ITEM_PREFIX() {
	parlex::reference const v0("VISIBILITY_MODIFIER");
	parlex::reference const v1("VISIBILITY_MODIFIER");
	parlex::reference const v2("IC");
	parlex::reference const v3("IC");
	parlex::repetition const v4(v3);
	parlex::literal const v5(U"diamond");
	parlex::sequence const v6({v1, v2, v4, v5});
	parlex::literal const v7(U"diamond");
	parlex::choice const v8({v0, v6, v7});
	parlex::reference const v9("IC");
	parlex::reference const v10("IC");
	parlex::repetition const v11(v10);
	parlex::sequence const v12("INHERITANCE_ITEM_PREFIX", {v8, v9, v11});
	return parlex::production("INHERITANCE_ITEM_PREFIX",v12);
}

static parlex::production INHERITANCE_LIST() {
	parlex::reference const v0("INHERITANCE_ITEM_PREFIX");
	parlex::optional const v1(v0);
	parlex::reference const v2("expression", "EXPRESSION");
	parlex::reference const v3("IC");
	parlex::repetition const v4(v3);
	parlex::literal const v5(U",");
	parlex::reference const v6("IC");
	parlex::repetition const v7(v6);
	parlex::reference const v8("INHERITANCE_ITEM_PREFIX");
	parlex::optional const v9(v8);
	parlex::reference const v10("expression", "EXPRESSION");
	parlex::sequence const v11({v4, v5, v7, v9, v10});
	parlex::repetition const v12(v11);
	parlex::sequence const v13("INHERITANCE_LIST", {v1, v2, v12});
	return parlex::production("INHERITANCE_LIST",v13);
}

static parlex::production INHERITS() {
	parlex::reference const v0("EXPRESSION");
	parlex::reference const v1("IC");
	parlex::repetition const v2(v1);
	parlex::literal const v3(U"inherits");
	parlex::reference const v4("IC");
	parlex::repetition const v5(v4);
	parlex::reference const v6("EXPRESSION");
	parlex::sequence const v7("INHERITS", {v0, v2, v3, v5, v6});
	return parlex::production("INHERITS",v7);
}

static parlex::production INTEGER_DIVISION() {
	parlex::reference const v0("EXPRESSION");
	parlex::reference const v1("IC");
	parlex::repetition const v2(v1);
	parlex::literal const v3(U"\\");
	parlex::reference const v4("IC");
	parlex::repetition const v5(v4);
	parlex::reference const v6("EXPRESSION");
	parlex::sequence const v7("INTEGER_DIVISION", {v0, v2, v3, v5, v6});
	return parlex::production("INTEGER_DIVISION",v7, parlex::associativity::LEFT, parlex::filter_function(), {"ADDITION", "ADD_SUB", "SUBTRACTION", });
}

static parlex::production INTEGER_DIVISION_ASSIGNMENT() {
	parlex::reference const v0("EXPRESSION");
	parlex::reference const v1("IC");
	parlex::repetition const v2(v1);
	parlex::literal const v3(U"\\");
	parlex::literal const v4(U"<-");
	parlex::literal const v5(U"←");
	parlex::choice const v6({v4, v5});
	parlex::reference const v7("IC");
	parlex::repetition const v8(v7);
	parlex::reference const v9("EXPRESSION");
	parlex::sequence const v10("INTEGER_DIVISION_ASSIGNMENT", {v0, v2, v3, v6, v8, v9});
	return parlex::production("INTEGER_DIVISION_ASSIGNMENT",v10);
}

static parlex::production INTERSECTION() {
	parlex::reference const v0("EXPRESSION");
	parlex::reference const v1("IC");
	parlex::repetition const v2(v1);
	parlex::literal const v3(U"∩");
	parlex::reference const v4("IC");
	parlex::repetition const v5(v4);
	parlex::reference const v6("EXPRESSION");
	parlex::sequence const v7("INTERSECTION", {v0, v2, v3, v5, v6});
	return parlex::production("INTERSECTION",v7, parlex::associativity::ANY);
}

static parlex::production INTERSECTION_ASSIGNMENT() {
	parlex::reference const v0("EXPRESSION");
	parlex::reference const v1("IC");
	parlex::repetition const v2(v1);
	parlex::literal const v3(U"∩");
	parlex::literal const v4(U"<-");
	parlex::literal const v5(U"←");
	parlex::choice const v6({v4, v5});
	parlex::reference const v7("IC");
	parlex::repetition const v8(v7);
	parlex::reference const v9("EXPRESSION");
	parlex::sequence const v10("INTERSECTION_ASSIGNMENT", {v0, v2, v3, v6, v8, v9});
	return parlex::production("INTERSECTION_ASSIGNMENT",v10);
}

static parlex::production INVOCATION() {
	parlex::reference const v0("PARENTHETICAL_INVOCATION");
	parlex::reference const v1("ARRAY_INVOCATION");
	parlex::reference const v2("TYPE_INVOCATION");
	parlex::choice const v3("INVOCATION", {v0, v1, v2});
	return parlex::production("INVOCATION",v3, parlex::associativity::NONE, parlex::filter_function(), {"BINARY_OP", "NEGATION", "RADICAL", });
}

static parlex::production IS() {
	parlex::reference const v0("EXPRESSION");
	parlex::reference const v1("IC");
	parlex::repetition const v2(v1);
	parlex::literal const v3(U"is");
	parlex::reference const v4("IC");
	parlex::repetition const v5(v4);
	parlex::reference const v6("EXPRESSION");
	parlex::sequence const v7("IS", {v0, v2, v3, v5, v6});
	return parlex::production("IS",v7);
}

static parlex::production KLEENE_STAR() {
	parlex::reference const v0("EXPRESSION");
	parlex::reference const v1("IC");
	parlex::repetition const v2(v1);
	parlex::literal const v3(U"*");
	parlex::sequence const v4("KLEENE_STAR", {v0, v2, v3});
	return parlex::production("KLEENE_STAR",v4);
}

static parlex::production LESSER_CHAIN() {
	parlex::reference const v0("EXPRESSION");
	parlex::reference const v1("IC");
	parlex::repetition const v2(v1);
	parlex::reference const v3("LESSER_CHAIN_LOOP");
	parlex::sequence const v4("LESSER_CHAIN", {v0, v2, v3});
	return parlex::production("LESSER_CHAIN",v4);
}

static parlex::production LESSER_CHAIN_LOOP() {
	parlex::literal const v0(U"=");
	parlex::literal const v1(U"<");
	parlex::literal const v2(U"=<");
	parlex::literal const v3(U"≤");
	parlex::choice const v4({v0, v1, v2, v3});
	parlex::reference const v5("IC");
	parlex::repetition const v6(v5);
	parlex::reference const v7("EXPRESSION");
	parlex::reference const v8("IC");
	parlex::repetition const v9(v8);
	parlex::reference const v10("LESSER_CHAIN_LOOP");
	parlex::sequence const v11({v9, v10});
	parlex::optional const v12(v11);
	parlex::sequence const v13("LESSER_CHAIN_LOOP", {v4, v6, v7, v12});
	return parlex::production("LESSER_CHAIN_LOOP",v13);
}

static parlex::production LIST() {
	parlex::literal const v0(U"[|");
	parlex::reference const v1("IC");
	parlex::repetition const v2(v1);
	parlex::reference const v3("EXPRESSION");
	parlex::reference const v4("IC");
	parlex::repetition const v5(v4);
	parlex::literal const v6(U", ");
	parlex::reference const v7("IC");
	parlex::repetition const v8(v7);
	parlex::reference const v9("EXPRESSION");
	parlex::sequence const v10({v5, v6, v8, v9});
	parlex::repetition const v11(v10);
	parlex::reference const v12("IC");
	parlex::repetition const v13(v12);
	parlex::sequence const v14({v3, v11, v13});
	parlex::optional const v15("elements", v14);
	parlex::literal const v16(U"|]");
	parlex::sequence const v17("LIST", {v0, v2, v15, v16});
	return parlex::production("LIST",v17);
}

static parlex::production LOCK() {
	parlex::literal const v0(U"lock");
	parlex::reference const v1("IC");
	parlex::repetition const v2(v1);
	parlex::reference const v3("PARENTHETICAL");
	parlex::reference const v4("IC");
	parlex::repetition const v5(v4);
	parlex::reference const v6("BLOCK");
	parlex::sequence const v7("LOCK", {v0, v2, v3, v5, v6});
	return parlex::production("LOCK",v7);
}

static parlex::production LOOP() {
	parlex::literal const v0(U"while");
	parlex::literal const v1(U"until");
	parlex::choice const v2({v0, v1});
	parlex::reference const v3("IC");
	parlex::repetition const v4(v3);
	parlex::reference const v5("PARENTHETICAL");
	parlex::reference const v6("IC");
	parlex::repetition const v7(v6);
	parlex::reference const v8("EXPRESSION");
	parlex::sequence const v9("LOOP", {v2, v4, v5, v7, v8});
	return parlex::production("LOOP",v9);
}

static parlex::production MAGNITUDE() {
	parlex::literal const v0(U"|");
	parlex::reference const v1("IC");
	parlex::repetition const v2(v1);
	parlex::reference const v3("EXPRESSION");
	parlex::reference const v4("IC");
	parlex::repetition const v5(v4);
	parlex::literal const v6(U"|");
	parlex::sequence const v7("MAGNITUDE", {v0, v2, v3, v5, v6});
	return parlex::production("MAGNITUDE",v7);
}

static parlex::production MAP() {
	parlex::literal const v0(U"{");
	parlex::reference const v1("IC");
	parlex::repetition const v2(v1);
	parlex::reference const v3("EXPRESSION");
	parlex::reference const v4("IC");
	parlex::repetition const v5(v4);
	parlex::literal const v6(U":");
	parlex::reference const v7("IC");
	parlex::repetition const v8(v7);
	parlex::reference const v9("EXPRESSION");
	parlex::reference const v10("IC");
	parlex::repetition const v11(v10);
	parlex::literal const v12(U",");
	parlex::reference const v13("IC");
	parlex::repetition const v14(v13);
	parlex::reference const v15("EXPRESSION");
	parlex::reference const v16("IC");
	parlex::repetition const v17(v16);
	parlex::literal const v18(U":");
	parlex::reference const v19("IC");
	parlex::repetition const v20(v19);
	parlex::reference const v21("EXPRESSION");
	parlex::sequence const v22({v11, v12, v14, v15, v17, v18, v20, v21});
	parlex::repetition const v23(v22);
	parlex::sequence const v24({v2, v3, v5, v6, v8, v9, v23});
	parlex::optional const v25(v24);
	parlex::reference const v26("IC");
	parlex::repetition const v27(v26);
	parlex::literal const v28(U"}");
	parlex::sequence const v29("MAP", {v0, v25, v27, v28});
	return parlex::production("MAP",v29, parlex::associativity::NONE, parlex::filter_function(), {"FUNCTION", });
}

static parlex::production MAPS_TO() {
	parlex::reference const v0("EXPRESSION");
	parlex::reference const v1("IC");
	parlex::repetition const v2(v1);
	parlex::literal const v3(U"→");
	parlex::literal const v4(U"->");
	parlex::choice const v5({v3, v4});
	parlex::reference const v6("IC");
	parlex::repetition const v7(v6);
	parlex::reference const v8("EXPRESSION");
	parlex::sequence const v9("MAPS_TO", {v0, v2, v5, v7, v8});
	return parlex::production("MAPS_TO",v9, parlex::associativity::RIGHT);
}

static parlex::production MEMBER_ACCESS() {
	parlex::reference const v0("EXPRESSION");
	parlex::reference const v1("IC");
	parlex::repetition const v2(v1);
	parlex::literal const v3(U".");
	parlex::reference const v4("IC");
	parlex::repetition const v5(v4);
	parlex::reference const v6("IDENTIFIER");
	parlex::sequence const v7("MEMBER_ACCESS", {v0, v2, v3, v5, v6});
	return parlex::production("MEMBER_ACCESS",v7, parlex::associativity::LEFT);
}

static parlex::production MEMBER_OFFSET() {
	parlex::literal const v0(U"@");
	parlex::reference const v1("IC");
	parlex::repetition const v2(v1);
	parlex::reference const v3("WHOLE_NUMBER");
	parlex::sequence const v4("MEMBER_OFFSET", {v0, v2, v3});
	return parlex::production("MEMBER_OFFSET",v4);
}

static parlex::production MODULATION() {
	parlex::reference const v0("EXPRESSION");
	parlex::reference const v1("IC");
	parlex::repetition const v2(v1);
	parlex::literal const v3(U"%");
	parlex::reference const v4("IC");
	parlex::repetition const v5(v4);
	parlex::reference const v6("EXPRESSION");
	parlex::sequence const v7("MODULATION", {v0, v2, v3, v5, v6});
	return parlex::production("MODULATION",v7, parlex::associativity::LEFT, parlex::filter_function(), {"ADDITION", "ADD_SUB", "SUBTRACTION", });
}

static parlex::production MODULATION_ASSIGNMENT() {
	parlex::reference const v0("EXPRESSION");
	parlex::reference const v1("IC");
	parlex::repetition const v2(v1);
	parlex::literal const v3(U"%");
	parlex::literal const v4(U"<-");
	parlex::literal const v5(U"←");
	parlex::choice const v6({v4, v5});
	parlex::reference const v7("IC");
	parlex::repetition const v8(v7);
	parlex::reference const v9("EXPRESSION");
	parlex::sequence const v10("MODULATION_ASSIGNMENT", {v0, v2, v3, v6, v8, v9});
	return parlex::production("MODULATION_ASSIGNMENT",v10);
}

static parlex::production MULTIPLICATION() {
	parlex::reference const v0("EXPRESSION");
	parlex::reference const v1("IC");
	parlex::repetition const v2(v1);
	parlex::literal const v3(U"*");
	parlex::reference const v4("IC");
	parlex::repetition const v5(v4);
	parlex::reference const v6("EXPRESSION");
	parlex::sequence const v7("MULTIPLICATION", {v0, v2, v3, v5, v6});
	return parlex::production("MULTIPLICATION",v7, parlex::associativity::ANY);
}

static parlex::production MULTIPLICATION_ASSIGNMENT() {
	parlex::reference const v0("EXPRESSION");
	parlex::reference const v1("IC");
	parlex::repetition const v2(v1);
	parlex::literal const v3(U"*");
	parlex::literal const v4(U"<-");
	parlex::literal const v5(U"←");
	parlex::choice const v6({v4, v5});
	parlex::reference const v7("IC");
	parlex::repetition const v8(v7);
	parlex::reference const v9("EXPRESSION");
	parlex::sequence const v10("MULTIPLICATION_ASSIGNMENT", {v0, v2, v3, v6, v8, v9});
	return parlex::production("MULTIPLICATION_ASSIGNMENT",v10);
}

static parlex::production MULTIPLICATIVE_OP() {
	parlex::reference const v0("CROSS_PRODUCT");
	parlex::reference const v1("DOT_PRODUCT");
	parlex::reference const v2("MULTIPLICATION");
	parlex::choice const v3("MULTIPLICATIVE_OP", {v0, v1, v2});
	return parlex::production("MULTIPLICATIVE_OP",v3, parlex::associativity::NONE, parlex::filter_function(), {"ADDITION", "ADD_SUB", "INTEGER_DIVISION", "MAPS_TO", "MODULATION", "SUBTRACTION", });
}

static parlex::production NAND() {
	parlex::reference const v0("EXPRESSION");
	parlex::reference const v1("IC");
	parlex::repetition const v2(v1);
	parlex::literal const v3(U"↑");
	parlex::literal const v4(U"nand");
	parlex::choice const v5({v3, v4});
	parlex::reference const v6("IC");
	parlex::repetition const v7(v6);
	parlex::reference const v8("EXPRESSION");
	parlex::sequence const v9("NAND", {v0, v2, v5, v7, v8});
	return parlex::production("NAND",v9, parlex::associativity::LEFT, parlex::filter_function(), {"IFF", "IMPLICATION", "OR", "XOR", });
}

static parlex::production NAND_ASSIGNMENT() {
	parlex::reference const v0("EXPRESSION");
	parlex::reference const v1("IC");
	parlex::repetition const v2(v1);
	parlex::literal const v3(U"↑");
	parlex::literal const v4(U"nand");
	parlex::choice const v5({v3, v4});
	parlex::literal const v6(U"<-");
	parlex::literal const v7(U"←");
	parlex::choice const v8({v6, v7});
	parlex::reference const v9("IC");
	parlex::repetition const v10(v9);
	parlex::reference const v11("EXPRESSION");
	parlex::sequence const v12("NAND_ASSIGNMENT", {v0, v2, v5, v8, v10, v11});
	return parlex::production("NAND_ASSIGNMENT",v12);
}

static parlex::production NEAREST_INTEGER() {
	parlex::literal const v0(U"⌊");
	parlex::reference const v1("IC");
	parlex::repetition const v2(v1);
	parlex::reference const v3("EXPRESSION");
	parlex::reference const v4("IC");
	parlex::repetition const v5(v4);
	parlex::literal const v6(U"⌉");
	parlex::sequence const v7({v0, v2, v3, v5, v6});
	parlex::literal const v8(U"|_");
	parlex::reference const v9("IC");
	parlex::repetition const v10(v9);
	parlex::reference const v11("EXPRESSION");
	parlex::reference const v12("IC");
	parlex::repetition const v13(v12);
	parlex::literal const v14(U"\'|");
	parlex::sequence const v15({v8, v10, v11, v13, v14});
	parlex::choice const v16("NEAREST_INTEGER", {v7, v15});
	return parlex::production("NEAREST_INTEGER",v16);
}

static parlex::production NEGATION() {
	parlex::literal const v0(U"-");
	parlex::reference const v1("IC");
	parlex::repetition const v2(v1);
	parlex::reference const v3("EXPRESSION");
	parlex::sequence const v4("NEGATION", {v0, v2, v3});
	return parlex::production("NEGATION",v4, parlex::associativity::NONE, parlex::filter_function(), {"BINARY_OP", });
}

static parlex::production NEGATION_ASSIGNMENT() {
	parlex::reference const v0("EXPRESSION");
	parlex::reference const v1("IC");
	parlex::repetition const v2(v1);
	parlex::literal const v3(U"-");
	parlex::literal const v4(U"<-");
	parlex::literal const v5(U"←");
	parlex::choice const v6({v4, v5});
	parlex::sequence const v7("NEGATION_ASSIGNMENT", {v0, v2, v3, v6});
	return parlex::production("NEGATION_ASSIGNMENT",v7);
}

static parlex::production NON_FRACTIONAL() {
	parlex::literal const v0(U"-");
	parlex::optional const v1(v0);
	parlex::reference const v2("NON_NEG_NON_FRACTIONAL");
	parlex::sequence const v3("NON_FRACTIONAL", {v1, v2});
	return parlex::production("NON_FRACTIONAL",v3);
}

static parlex::production NON_NEG_FRACTIONAL() {
	parlex::reference const v0("decimal_digit");
	parlex::reference const v1("decimal_digit");
	parlex::repetition const v2(v1);
	parlex::literal const v3(U".");
	parlex::reference const v4("decimal_digit");
	parlex::repetition const v5(v4);
	parlex::sequence const v6({v0, v2, v3, v5});
	parlex::literal const v7(U".");
	parlex::reference const v8("decimal_digit");
	parlex::reference const v9("decimal_digit");
	parlex::repetition const v10(v9);
	parlex::sequence const v11({v7, v8, v10});
	parlex::choice const v12("NON_NEG_FRACTIONAL", {v6, v11});
	return parlex::production("NON_NEG_FRACTIONAL",v12);
}

static parlex::production NON_NEG_INTEGER() {
	parlex::reference const v0("NON_ZERO_DECIMAL_DIGIT");
	parlex::reference const v1("decimal_digit");
	parlex::repetition const v2(v1);
	parlex::sequence const v3({v0, v2});
	parlex::literal const v4(U"0");
	parlex::choice const v5("NON_NEG_INTEGER", {v3, v4});
	return parlex::production("NON_NEG_INTEGER",v5);
}

static parlex::production NON_NEG_NON_FRACTIONAL() {
	parlex::reference const v0("NON_NEG_INTEGER");
	parlex::reference const v1("HEX");
	parlex::reference const v2("OCTAL");
	parlex::choice const v3("NON_NEG_NON_FRACTIONAL", {v0, v1, v2});
	return parlex::production("NON_NEG_NON_FRACTIONAL",v3);
}

static parlex::production NON_NEG_NUMBER() {
	parlex::reference const v0("NON_NEG_NON_FRACTIONAL");
	parlex::reference const v1("NON_NEG_FRACTIONAL");
	parlex::choice const v2("NON_NEG_NUMBER", {v0, v1});
	return parlex::production("NON_NEG_NUMBER",v2);
}

static parlex::production NON_ZERO_DECIMAL_DIGIT() {
	parlex::literal const v0(U"1");
	parlex::literal const v1(U"2");
	parlex::literal const v2(U"3");
	parlex::literal const v3(U"4");
	parlex::literal const v4(U"5");
	parlex::literal const v5(U"6");
	parlex::literal const v6(U"7");
	parlex::literal const v7(U"8");
	parlex::literal const v8(U"9");
	parlex::choice const v9("NON_ZERO_DECIMAL_DIGIT", {v0, v1, v2, v3, v4, v5, v6, v7, v8});
	return parlex::production("NON_ZERO_DECIMAL_DIGIT",v9);
}

static parlex::production NOR() {
	parlex::reference const v0("EXPRESSION");
	parlex::reference const v1("IC");
	parlex::repetition const v2(v1);
	parlex::literal const v3(U"↓");
	parlex::literal const v4(U"nor");
	parlex::choice const v5({v3, v4});
	parlex::reference const v6("IC");
	parlex::repetition const v7(v6);
	parlex::reference const v8("EXPRESSION");
	parlex::sequence const v9("NOR", {v0, v2, v5, v7, v8});
	return parlex::production("NOR",v9, parlex::associativity::LEFT, parlex::filter_function(), {"IFF", "IMPLICATION", "OR", "XOR", });
}

static parlex::production NOR_ASSIGNMENT() {
	parlex::reference const v0("EXPRESSION");
	parlex::reference const v1("IC");
	parlex::repetition const v2(v1);
	parlex::literal const v3(U"↓");
	parlex::literal const v4(U"nor");
	parlex::choice const v5({v3, v4});
	parlex::literal const v6(U"<-");
	parlex::literal const v7(U"←");
	parlex::choice const v8({v6, v7});
	parlex::reference const v9("IC");
	parlex::repetition const v10(v9);
	parlex::reference const v11("EXPRESSION");
	parlex::sequence const v12("NOR_ASSIGNMENT", {v0, v2, v5, v8, v10, v11});
	return parlex::production("NOR_ASSIGNMENT",v12);
}

static parlex::production NOT() {
	parlex::literal const v0(U"¬");
	parlex::literal const v1(U"~");
	parlex::choice const v2({v0, v1});
	parlex::reference const v3("IC");
	parlex::repetition const v4(v3);
	parlex::reference const v5("EXPRESSION");
	parlex::sequence const v6("NOT", {v2, v4, v5});
	return parlex::production("NOT",v6, parlex::associativity::NONE, parlex::filter_function(), {"BINARY_OP", });
}

static parlex::production NOT_ASSIGNMENT() {
	parlex::reference const v0("EXPRESSION");
	parlex::reference const v1("IC");
	parlex::repetition const v2(v1);
	parlex::literal const v3(U"¬");
	parlex::literal const v4(U"~");
	parlex::choice const v5({v3, v4});
	parlex::literal const v6(U"<-");
	parlex::literal const v7(U"←");
	parlex::choice const v8({v6, v7});
	parlex::sequence const v9("NOT_ASSIGNMENT", {v0, v2, v5, v8});
	return parlex::production("NOT_ASSIGNMENT",v9);
}

static parlex::production NOT_HAS() {
	parlex::reference const v0("EXPRESSION");
	parlex::reference const v1("IC");
	parlex::repetition const v2(v1);
	parlex::literal const v3(U"∌");
	parlex::literal const v4(U"/has");
	parlex::choice const v5({v3, v4});
	parlex::reference const v6("IC");
	parlex::repetition const v7(v6);
	parlex::reference const v8("EXPRESSION");
	parlex::sequence const v9("NOT_HAS", {v0, v2, v5, v7, v8});
	return parlex::production("NOT_HAS",v9, parlex::associativity::LEFT);
}

static parlex::production NOT_IN() {
	parlex::reference const v0("EXPRESSION");
	parlex::reference const v1("IC");
	parlex::repetition const v2(v1);
	parlex::literal const v3(U"∉");
	parlex::literal const v4(U"/in");
	parlex::choice const v5({v3, v4});
	parlex::reference const v6("IC");
	parlex::repetition const v7(v6);
	parlex::reference const v8("EXPRESSION");
	parlex::sequence const v9("NOT_IN", {v0, v2, v5, v7, v8});
	return parlex::production("NOT_IN",v9, parlex::associativity::LEFT);
}

static parlex::production NULL_COALESCE() {
	parlex::reference const v0("EXPRESSION");
	parlex::reference const v1("IC");
	parlex::repetition const v2(v1);
	parlex::literal const v3(U"\?\?");
	parlex::reference const v4("IC");
	parlex::repetition const v5(v4);
	parlex::reference const v6("EXPRESSION");
	parlex::sequence const v7("NULL_COALESCE", {v0, v2, v3, v5, v6});
	return parlex::production("NULL_COALESCE",v7, parlex::associativity::LEFT);
}

static parlex::production NULL_COALESCE_ASSIGNMENT() {
	parlex::reference const v0("EXPRESSION");
	parlex::reference const v1("IC");
	parlex::repetition const v2(v1);
	parlex::literal const v3(U"\?\?");
	parlex::literal const v4(U"<-");
	parlex::literal const v5(U"←");
	parlex::choice const v6({v4, v5});
	parlex::reference const v7("IC");
	parlex::repetition const v8(v7);
	parlex::reference const v9("EXPRESSION");
	parlex::sequence const v10("NULL_COALESCE_ASSIGNMENT", {v0, v2, v3, v6, v8, v9});
	return parlex::production("NULL_COALESCE_ASSIGNMENT",v10);
}

static parlex::production OBJECT() {
	parlex::literal const v0(U"object");
	parlex::reference const v1("IC");
	parlex::repetition const v2(v1);
	parlex::literal const v3(U"inheriting");
	parlex::reference const v4("IC");
	parlex::repetition const v5(v4);
	parlex::reference const v6("INHERITANCE_LIST");
	parlex::reference const v7("IC");
	parlex::repetition const v8(v7);
	parlex::sequence const v9({v3, v5, v6, v8});
	parlex::optional const v10(v9);
	parlex::literal const v11(U"implementing");
	parlex::reference const v12("IC");
	parlex::repetition const v13(v12);
	parlex::reference const v14("INHERITANCE_LIST");
	parlex::reference const v15("IC");
	parlex::repetition const v16(v15);
	parlex::sequence const v17({v11, v13, v14, v16});
	parlex::optional const v18(v17);
	parlex::literal const v19(U"{");
	parlex::reference const v20("TYPE_SCOPE");
	parlex::literal const v21(U"}");
	parlex::sequence const v22("OBJECT", {v0, v2, v10, v18, v19, v20, v21});
	return parlex::production("OBJECT",v22);
}

static parlex::production OCTAL() {
	parlex::literal const v0(U"0");
	parlex::reference const v1("octal_digit");
	parlex::reference const v2("octal_digit");
	parlex::repetition const v3(v2);
	parlex::sequence const v4("OCTAL", {v0, v1, v3});
	return parlex::production("OCTAL",v4);
}

static parlex::production OP_ASSIGNMENT() {
	parlex::reference const v0("ADD_SUB_ASSIGNMENT");
	parlex::reference const v1("ADDITION_ASSIGNMENT");
	parlex::reference const v2("AND_ASSIGNMENT");
	parlex::reference const v3("BIT_AND_ASSIGNMENT");
	parlex::reference const v4("BIT_NOT_ASSIGNMENT");
	parlex::reference const v5("BIT_OR_ASSIGNMENT");
	parlex::reference const v6("BIT_XOR_ASSIGNMENT");
	parlex::reference const v7("COMPOUND_ASSIGNMENT");
	parlex::reference const v8("COMPOSITION_ASSIGNMENT");
	parlex::reference const v9("CROSS_PRODUCT_ASSIGNMENT");
	parlex::reference const v10("DIVISION_ASSIGNMENT");
	parlex::reference const v11("EXPONENTIATION_ASSIGNMENT");
	parlex::reference const v12("FACTORIAL_ASSIGNMENT");
	parlex::reference const v13("IMPLICATION_ASSIGNMENT");
	parlex::reference const v14("INTEGER_DIVISION_ASSIGNMENT");
	parlex::reference const v15("INTERSECTION_ASSIGNMENT");
	parlex::reference const v16("MODULATION_ASSIGNMENT");
	parlex::reference const v17("MULTIPLICATION_ASSIGNMENT");
	parlex::reference const v18("NAND_ASSIGNMENT");
	parlex::reference const v19("NEGATION_ASSIGNMENT");
	parlex::reference const v20("NOR_ASSIGNMENT");
	parlex::reference const v21("NOT_ASSIGNMENT");
	parlex::reference const v22("NULL_COALESCE_ASSIGNMENT");
	parlex::reference const v23("OR_ASSIGNMENT");
	parlex::reference const v24("PRE_DEC");
	parlex::reference const v25("PRE_INC");
	parlex::reference const v26("PREPEND_ASSIGNMENT");
	parlex::reference const v27("POST_DEC");
	parlex::reference const v28("POST_INC");
	parlex::reference const v29("RADICAL_ASSIGNMENT");
	parlex::reference const v30("SHIFTL_ASSIGNMENT");
	parlex::reference const v31("SHIFTR_ASSIGNMENT");
	parlex::reference const v32("SUBTRACTION_ASSIGNMENT");
	parlex::reference const v33("SYMMETRIC_DIFFERENCE_ASSIGNMENT");
	parlex::reference const v34("UNION_ASSIGNMENT");
	parlex::reference const v35("XOR_ASSIGNMENT");
	parlex::choice const v36("OP_ASSIGNMENT", {v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35});
	return parlex::production("OP_ASSIGNMENT",v36);
}

static parlex::production OR() {
	parlex::reference const v0("EXPRESSION");
	parlex::reference const v1("IC");
	parlex::repetition const v2(v1);
	parlex::literal const v3(U"∨");
	parlex::literal const v4(U"or");
	parlex::choice const v5({v3, v4});
	parlex::reference const v6("IC");
	parlex::repetition const v7(v6);
	parlex::reference const v8("EXPRESSION");
	parlex::sequence const v9("OR", {v0, v2, v5, v7, v8});
	return parlex::production("OR",v9, parlex::associativity::ANY, parlex::filter_function(), {"IFF", "IMPLICATION", "XOR", });
}

static parlex::production OR_ASSIGNMENT() {
	parlex::reference const v0("EXPRESSION");
	parlex::reference const v1("IC");
	parlex::repetition const v2(v1);
	parlex::literal const v3(U"∨");
	parlex::literal const v4(U"or");
	parlex::choice const v5({v3, v4});
	parlex::literal const v6(U"<-");
	parlex::literal const v7(U"←");
	parlex::choice const v8({v6, v7});
	parlex::reference const v9("IC");
	parlex::repetition const v10(v9);
	parlex::reference const v11("EXPRESSION");
	parlex::sequence const v12("OR_ASSIGNMENT", {v0, v2, v5, v8, v10, v11});
	return parlex::production("OR_ASSIGNMENT",v12);
}

static parlex::production PARAMETER() {
	parlex::reference const v0("PARAMETER_NATURAL");
	parlex::reference const v1("PARAMETER_ANALYTIC");
	parlex::choice const v2("PARAMETER", {v0, v1});
	return parlex::production("PARAMETER",v2);
}

static parlex::production PARAMETER_ANALYTIC() {
	parlex::reference const v0("EXPRESSION");
	parlex::reference const v1("IC");
	parlex::repetition const v2(v1);
	parlex::literal const v3(U"=");
	parlex::reference const v4("IC");
	parlex::repetition const v5(v4);
	parlex::reference const v6("EXPRESSION");
	parlex::sequence const v7({v2, v3, v5, v6});
	parlex::optional const v8(v7);
	parlex::sequence const v9("PARAMETER_ANALYTIC", {v0, v8});
	return parlex::production("PARAMETER_ANALYTIC",v9);
}

static parlex::production PARAMETER_NATURAL() {
	parlex::reference const v0("TYPE_DEREFERENCE");
	parlex::reference const v1("IC");
	parlex::repetition const v2(v1);
	parlex::sequence const v3({v0, v2});
	parlex::optional const v4(v3);
	parlex::reference const v5("IDENTIFIER");
	parlex::literal const v6(U"...");
	parlex::optional const v7(v6);
	parlex::sequence const v8({v4, v5, v7});
	parlex::reference const v9("TYPE_DEREFERENCE");
	parlex::reference const v10("IMPLICIT_TYPE_DEREFERENCE");
	parlex::choice const v11({v9, v10});
	parlex::reference const v12("IC");
	parlex::repetition const v13(v12);
	parlex::sequence const v14({v11, v13});
	parlex::optional const v15(v14);
	parlex::reference const v16("IDENTIFIER");
	parlex::literal const v17(U"...");
	parlex::optional const v18(v17);
	parlex::reference const v19("IC");
	parlex::repetition const v20(v19);
	parlex::literal const v21(U"=");
	parlex::reference const v22("IC");
	parlex::repetition const v23(v22);
	parlex::reference const v24("EXPRESSION");
	parlex::literal const v25(U"...");
	parlex::optional const v26(v25);
	parlex::sequence const v27({v15, v16, v18, v20, v21, v23, v24, v26});
	parlex::choice const v28("PARAMETER_NATURAL", {v8, v27});
	return parlex::production("PARAMETER_NATURAL",v28, parlex::associativity::NONE, parlex::filter_function(), {"PARAMETER_ANALYTIC", });
}

static parlex::production PARENTHETICAL() {
	parlex::literal const v0(U"(");
	parlex::reference const v1("IC");
	parlex::repetition const v2(v1);
	parlex::reference const v3("EXPRESSION");
	parlex::reference const v4("IC");
	parlex::repetition const v5(v4);
	parlex::literal const v6(U")");
	parlex::sequence const v7("PARENTHETICAL", {v0, v2, v3, v5, v6});
	return parlex::production("PARENTHETICAL",v7);
}

static parlex::production PARENTHETICAL_INVOCATION() {
	parlex::reference const v0("target", "EXPRESSION");
	parlex::reference const v1("IC");
	parlex::repetition const v2(v1);
	parlex::literal const v3(U"(");
	parlex::reference const v4("IC");
	parlex::repetition const v5(v4);
	parlex::reference const v6("ARGUMENT");
	parlex::reference const v7("ARGUMENT_PACK");
	parlex::choice const v8({v6, v7});
	parlex::sequence const v9({v5, v8});
	parlex::optional const v10("argsHead", v9);
	parlex::reference const v11("IC");
	parlex::repetition const v12(v11);
	parlex::literal const v13(U",");
	parlex::reference const v14("IC");
	parlex::repetition const v15(v14);
	parlex::reference const v16("ARGUMENT");
	parlex::reference const v17("ARGUMENT_PACK");
	parlex::choice const v18({v16, v17});
	parlex::sequence const v19({v15, v18});
	parlex::optional const v20(v19);
	parlex::sequence const v21({v12, v13, v20});
	parlex::repetition const v22("argsTail", v21);
	parlex::reference const v23("IC");
	parlex::repetition const v24(v23);
	parlex::literal const v25(U")");
	parlex::sequence const v26("PARENTHETICAL_INVOCATION", {v0, v2, v3, v10, v22, v24, v25});
	return parlex::production("PARENTHETICAL_INVOCATION",v26);
}

static parlex::production PAYLOAD() {
	parlex::reference const v0("all");
	parlex::reference const v1("all");
	parlex::repetition const v2(v1);
	parlex::sequence const v3("PAYLOAD", {v0, v2});
	return parlex::production("PAYLOAD",v3);
}

static parlex::production PLATFORM() {
	parlex::literal const v0(U"_");
	parlex::reference const v1("letter");
	parlex::reference const v2("number");
	parlex::choice const v3({v1, v2});
	parlex::reference const v4("letter");
	parlex::reference const v5("number");
	parlex::literal const v6(U"_");
	parlex::choice const v7({v4, v5, v6});
	parlex::repetition const v8(v7);
	parlex::sequence const v9("PLATFORM", {v0, v3, v8});
	return parlex::production("PLATFORM",v9, parlex::associativity::NONE, parlex::longest());
}

static parlex::production POST_DEC() {
	parlex::reference const v0("EXPRESSION");
	parlex::reference const v1("IC");
	parlex::repetition const v2(v1);
	parlex::literal const v3(U"--");
	parlex::sequence const v4("POST_DEC", {v0, v2, v3});
	return parlex::production("POST_DEC",v4, parlex::associativity::NONE, parlex::filter_function(), {"BINARY_OP", "NEGATION", });
}

static parlex::production POST_INC() {
	parlex::reference const v0("EXPRESSION");
	parlex::reference const v1("IC");
	parlex::repetition const v2(v1);
	parlex::literal const v3(U"++");
	parlex::sequence const v4("POST_INC", {v0, v2, v3});
	return parlex::production("POST_INC",v4, parlex::associativity::NONE, parlex::filter_function(), {"BINARY_OP", "NEGATION", });
}

static parlex::production PREPEND() {
	parlex::reference const v0("EXPRESSION");
	parlex::reference const v1("IC");
	parlex::repetition const v2(v1);
	parlex::literal const v3(U"&");
	parlex::reference const v4("IC");
	parlex::repetition const v5(v4);
	parlex::reference const v6("EXPRESSION");
	parlex::sequence const v7("PREPEND", {v0, v2, v3, v5, v6});
	return parlex::production("PREPEND",v7, parlex::associativity::RIGHT);
}

static parlex::production PREPEND_ASSIGNMENT() {
	parlex::reference const v0("EXPRESSION");
	parlex::reference const v1("IC");
	parlex::repetition const v2(v1);
	parlex::literal const v3(U"&");
	parlex::literal const v4(U"<-");
	parlex::literal const v5(U"←");
	parlex::choice const v6({v4, v5});
	parlex::reference const v7("IC");
	parlex::repetition const v8(v7);
	parlex::reference const v9("EXPRESSION");
	parlex::sequence const v10("PREPEND_ASSIGNMENT", {v0, v2, v3, v6, v8, v9});
	return parlex::production("PREPEND_ASSIGNMENT",v10);
}

static parlex::production PRE_DEC() {
	parlex::literal const v0(U"--");
	parlex::reference const v1("IC");
	parlex::repetition const v2(v1);
	parlex::reference const v3("EXPRESSION");
	parlex::sequence const v4("PRE_DEC", {v0, v2, v3});
	return parlex::production("PRE_DEC",v4, parlex::associativity::NONE, parlex::filter_function(), {"BINARY_OP", "NEGATION", });
}

static parlex::production PRE_INC() {
	parlex::literal const v0(U"++");
	parlex::reference const v1("IC");
	parlex::repetition const v2(v1);
	parlex::reference const v3("EXPRESSION");
	parlex::sequence const v4("PRE_INC", {v0, v2, v3});
	return parlex::production("PRE_INC",v4, parlex::associativity::NONE, parlex::filter_function(), {"BINARY_OP", "NEGATION", });
}

static parlex::production RADICAL() {
	parlex::literal const v0(U"√");
	parlex::literal const v1(U"sqrt");
	parlex::choice const v2({v0, v1});
	parlex::reference const v3("IC");
	parlex::repetition const v4(v3);
	parlex::reference const v5("EXPRESSION");
	parlex::sequence const v6("RADICAL", {v2, v4, v5});
	return parlex::production("RADICAL",v6, parlex::associativity::NONE, parlex::filter_function(), {"ADDITION", "ADD_SUB", "DIVISION", "INTEGER_DIVISION", "MODULATION", "MULTIPLICATIVE_OP", "SUBTRACTION", });
}

static parlex::production RADICAL_ASSIGNMENT() {
	parlex::reference const v0("EXPRESSION");
	parlex::reference const v1("IC");
	parlex::repetition const v2(v1);
	parlex::literal const v3(U"√");
	parlex::literal const v4(U"sqrt");
	parlex::choice const v5({v3, v4});
	parlex::literal const v6(U"<-");
	parlex::literal const v7(U"←");
	parlex::choice const v8({v6, v7});
	parlex::sequence const v9("RADICAL_ASSIGNMENT", {v0, v2, v5, v8});
	return parlex::production("RADICAL_ASSIGNMENT",v9);
}

static parlex::production RANGE() {
	parlex::literal const v0(U"(");
	parlex::reference const v1("IC");
	parlex::repetition const v2(v1);
	parlex::literal const v3(U"...");
	parlex::reference const v4("IC");
	parlex::repetition const v5(v4);
	parlex::reference const v6("EXPRESSION");
	parlex::reference const v7("IC");
	parlex::repetition const v8(v7);
	parlex::literal const v9(U"]");
	parlex::literal const v10(U")");
	parlex::choice const v11({v9, v10});
	parlex::sequence const v12({v0, v2, v3, v5, v6, v8, v11});
	parlex::literal const v13(U"[");
	parlex::literal const v14(U"(");
	parlex::choice const v15({v13, v14});
	parlex::reference const v16("IC");
	parlex::repetition const v17(v16);
	parlex::reference const v18("EXPRESSION");
	parlex::reference const v19("IC");
	parlex::repetition const v20(v19);
	parlex::literal const v21(U"...");
	parlex::reference const v22("IC");
	parlex::repetition const v23(v22);
	parlex::literal const v24(U")");
	parlex::sequence const v25({v15, v17, v18, v20, v21, v23, v24});
	parlex::literal const v26(U"(");
	parlex::literal const v27(U"[");
	parlex::choice const v28({v26, v27});
	parlex::reference const v29("IC");
	parlex::repetition const v30(v29);
	parlex::reference const v31("EXPRESSION");
	parlex::reference const v32("IC");
	parlex::repetition const v33(v32);
	parlex::literal const v34(U"...");
	parlex::reference const v35("IC");
	parlex::repetition const v36(v35);
	parlex::reference const v37("EXPRESSION");
	parlex::reference const v38("IC");
	parlex::repetition const v39(v38);
	parlex::literal const v40(U"]");
	parlex::literal const v41(U")");
	parlex::choice const v42({v40, v41});
	parlex::sequence const v43({v28, v30, v31, v33, v34, v36, v37, v39, v42});
	parlex::choice const v44("RANGE", {v12, v25, v43});
	return parlex::production("RANGE",v44);
}

static parlex::production READ_LOCK() {
	parlex::literal const v0(U"read_lock");
	parlex::reference const v1("IC");
	parlex::repetition const v2(v1);
	parlex::reference const v3("PARENTHETICAL");
	parlex::reference const v4("IC");
	parlex::repetition const v5(v4);
	parlex::reference const v6("EXPRESSION");
	parlex::sequence const v7("READ_LOCK", {v0, v2, v3, v5, v6});
	return parlex::production("READ_LOCK",v7);
}

static parlex::production RECORD() {
	parlex::literal const v0(U"record");
	parlex::reference const v1("IC");
	parlex::reference const v2("IC");
	parlex::repetition const v3(v2);
	parlex::reference const v4("TYPE");
	parlex::sequence const v5("RECORD", {v0, v1, v3, v4});
	return parlex::production("RECORD",v5);
}

static parlex::production REGEX() {
	parlex::literal const v0(U"R");
	parlex::reference const v1("c_string");
	parlex::sequence const v2("REGEX", {v0, v1});
	return parlex::production("REGEX",v2);
}

static parlex::production RELATIONAL_COLLECTION_OP() {
	parlex::reference const v0("HAS");
	parlex::reference const v1("IN");
	parlex::reference const v2("NOT_HAS");
	parlex::reference const v3("NOT_IN");
	parlex::choice const v4("RELATIONAL_COLLECTION_OP", {v0, v1, v2, v3});
	return parlex::production("RELATIONAL_COLLECTION_OP",v4);
}

static parlex::production RELATIONAL_OP() {
	parlex::reference const v0("CASTS");
	parlex::reference const v1("DOWNCASTS");
	parlex::reference const v2("EXACTLY");
	parlex::reference const v3("IMPLEMENTS");
	parlex::reference const v4("INEQUALITY");
	parlex::reference const v5("INHERITS");
	parlex::reference const v6("IS");
	parlex::reference const v7("RELATIONAL_COLLECTION_OP");
	parlex::reference const v8("UPCASTS");
	parlex::choice const v9("RELATIONAL_OP", {v0, v1, v2, v3, v4, v5, v6, v7, v8});
	return parlex::production("RELATIONAL_OP",v9, parlex::associativity::NONE, parlex::filter_function(), {"BINARY_LOGICAL_OP", });
}

static parlex::production RETURN() {
	parlex::literal const v0(U"return");
	parlex::reference const v1("IC");
	parlex::repetition const v2(v1);
	parlex::literal const v3(U"[");
	parlex::reference const v4("IC");
	parlex::repetition const v5(v4);
	parlex::reference const v6("EXPRESSION");
	parlex::reference const v7("IC");
	parlex::repetition const v8(v7);
	parlex::literal const v9(U"]");
	parlex::sequence const v10({v2, v3, v5, v6, v8, v9});
	parlex::optional const v11(v10);
	parlex::reference const v12("IC");
	parlex::repetition const v13(v12);
	parlex::reference const v14("EXPRESSION");
	parlex::sequence const v15({v13, v14});
	parlex::optional const v16(v15);
	parlex::sequence const v17("RETURN", {v0, v11, v16});
	return parlex::production("RETURN",v17);
}

static parlex::production SET() {
	parlex::literal const v0(U"{|");
	parlex::reference const v1("IC");
	parlex::repetition const v2(v1);
	parlex::reference const v3("EXPRESSION");
	parlex::reference const v4("IC");
	parlex::repetition const v5(v4);
	parlex::literal const v6(U",");
	parlex::reference const v7("IC");
	parlex::repetition const v8(v7);
	parlex::reference const v9("EXPRESSION");
	parlex::sequence const v10({v5, v6, v8, v9});
	parlex::repetition const v11(v10);
	parlex::reference const v12("IC");
	parlex::repetition const v13(v12);
	parlex::sequence const v14({v3, v11, v13});
	parlex::optional const v15("elements", v14);
	parlex::literal const v16(U"|}");
	parlex::sequence const v17("SET", {v0, v2, v15, v16});
	return parlex::production("SET",v17, parlex::associativity::NONE, parlex::filter_function(), {"MAGNITUDE", });
}

static parlex::production SET_COMPREHENSION() {
	parlex::literal const v0(U"{");
	parlex::reference const v1("IC");
	parlex::repetition const v2(v1);
	parlex::reference const v3("EXPRESSION");
	parlex::reference const v4("IC");
	parlex::repetition const v5(v4);
	parlex::literal const v6(U"|");
	parlex::reference const v7("IC");
	parlex::repetition const v8(v7);
	parlex::reference const v9("EXPRESSION");
	parlex::reference const v10("IC");
	parlex::repetition const v11(v10);
	parlex::literal const v12(U"}");
	parlex::sequence const v13("SET_COMPREHENSION", {v0, v2, v3, v5, v6, v8, v9, v11, v12});
	return parlex::production("SET_COMPREHENSION",v13);
}

static parlex::production SHIFTL() {
	parlex::reference const v0("EXPRESSION");
	parlex::reference const v1("IC");
	parlex::repetition const v2(v1);
	parlex::literal const v3(U"<<");
	parlex::reference const v4("IC");
	parlex::repetition const v5(v4);
	parlex::reference const v6("EXPRESSION");
	parlex::sequence const v7("SHIFTL", {v0, v2, v3, v5, v6});
	return parlex::production("SHIFTL",v7, parlex::associativity::LEFT);
}

static parlex::production SHIFTL_ASSIGNMENT() {
	parlex::reference const v0("EXPRESSION");
	parlex::reference const v1("IC");
	parlex::repetition const v2(v1);
	parlex::literal const v3(U"<<");
	parlex::literal const v4(U"<-");
	parlex::literal const v5(U"←");
	parlex::choice const v6({v4, v5});
	parlex::reference const v7("IC");
	parlex::repetition const v8(v7);
	parlex::reference const v9("EXPRESSION");
	parlex::sequence const v10("SHIFTL_ASSIGNMENT", {v0, v2, v3, v6, v8, v9});
	return parlex::production("SHIFTL_ASSIGNMENT",v10);
}

static parlex::production SHIFTR() {
	parlex::reference const v0("EXPRESSION");
	parlex::reference const v1("IC");
	parlex::repetition const v2(v1);
	parlex::literal const v3(U">>");
	parlex::reference const v4("IC");
	parlex::repetition const v5(v4);
	parlex::reference const v6("EXPRESSION");
	parlex::sequence const v7("SHIFTR", {v0, v2, v3, v5, v6});
	return parlex::production("SHIFTR",v7, parlex::associativity::LEFT);
}

static parlex::production SHIFTR_ASSIGNMENT() {
	parlex::reference const v0("EXPRESSION");
	parlex::reference const v1("IC");
	parlex::repetition const v2(v1);
	parlex::literal const v3(U">>");
	parlex::literal const v4(U"<-");
	parlex::literal const v5(U"←");
	parlex::choice const v6({v4, v5});
	parlex::reference const v7("IC");
	parlex::repetition const v8(v7);
	parlex::reference const v9("EXPRESSION");
	parlex::sequence const v10("SHIFTR_ASSIGNMENT", {v0, v2, v3, v6, v8, v9});
	return parlex::production("SHIFTR_ASSIGNMENT",v10);
}

static parlex::production SLICE() {
	parlex::reference const v0("EXPRESSION");
	parlex::reference const v1("IC");
	parlex::repetition const v2(v1);
	parlex::literal const v3(U":");
	parlex::reference const v4("IC");
	parlex::repetition const v5(v4);
	parlex::reference const v6("EXPRESSION");
	parlex::sequence const v7("SLICE", {v0, v2, v3, v5, v6});
	return parlex::production("SLICE",v7);
}

static parlex::production STATEMENT() {
	parlex::reference const v0("ASSIGNMENT_CHAIN");
	parlex::reference const v1("BREAK");
	parlex::reference const v2("CONTINUE");
	parlex::reference const v3("DEFINITION");
	parlex::reference const v4("DO");
	parlex::reference const v5("EXPRESSION");
	parlex::reference const v6("FOR");
	parlex::reference const v7("FOR_COLLECTION");
	parlex::reference const v8("FREE");
	parlex::reference const v9("IMPORT");
	parlex::reference const v10("LOCK");
	parlex::reference const v11("LOOP");
	parlex::reference const v12("OP_ASSIGNMENT");
	parlex::reference const v13("READ_LOCK");
	parlex::reference const v14("RETURN");
	parlex::reference const v15("THROW");
	parlex::reference const v16("TRY");
	parlex::reference const v17("TYPE_CONSTRAINT");
	parlex::reference const v18("WRITE_LOCK");
	parlex::reference const v19("USING");
	parlex::choice const v20("value", {v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19});
	parlex::reference const v21("IC");
	parlex::repetition const v22("ic", v21);
	parlex::literal const v23(U";");
	parlex::sequence const v24("STATEMENT", {v20, v22, v23});
	return parlex::production("STATEMENT",v24);
}

static parlex::production STATEMENT_SCOPE() {
	parlex::reference const v0("IC");
	parlex::reference const v1("STATEMENT");
	parlex::choice const v2({v0, v1});
	parlex::repetition const v3("STATEMENT_SCOPE", v2);
	return parlex::production("STATEMENT_SCOPE",v3);
}

static parlex::production STATIC() {
	parlex::literal const v0(U"static");
	return parlex::production("STATIC",v0, parlex::associativity::NONE, parlex::filter_function(), {"IDENTIFIER", });
}

static parlex::production SUBSET_CHAIN() {
	parlex::reference const v0("EXPRESSION");
	parlex::reference const v1("IC");
	parlex::repetition const v2(v1);
	parlex::reference const v3("SUBSET_CHAIN_LOOP");
	parlex::sequence const v4("SUBSET_CHAIN", {v0, v2, v3});
	return parlex::production("SUBSET_CHAIN",v4);
}

static parlex::production SUBSET_CHAIN_LOOP() {
	parlex::literal const v0(U"=");
	parlex::literal const v1(U"⊆");
	parlex::literal const v2(U"subs");
	parlex::literal const v3(U"⊂");
	parlex::literal const v4(U"psubs");
	parlex::choice const v5({v0, v1, v2, v3, v4});
	parlex::reference const v6("IC");
	parlex::repetition const v7(v6);
	parlex::reference const v8("EXPRESSION");
	parlex::reference const v9("IC");
	parlex::repetition const v10(v9);
	parlex::reference const v11("SUBSET_CHAIN_LOOP");
	parlex::sequence const v12({v10, v11});
	parlex::optional const v13(v12);
	parlex::sequence const v14("SUBSET_CHAIN_LOOP", {v5, v7, v8, v13});
	return parlex::production("SUBSET_CHAIN_LOOP",v14, parlex::associativity::NONE, parlex::filter_function(), {"EXPRESSION", });
}

static parlex::production SUBTRACTION() {
	parlex::reference const v0("EXPRESSION");
	parlex::reference const v1("IC");
	parlex::repetition const v2(v1);
	parlex::literal const v3(U"-");
	parlex::reference const v4("IC");
	parlex::repetition const v5(v4);
	parlex::reference const v6("EXPRESSION");
	parlex::sequence const v7("SUBTRACTION", {v0, v2, v3, v5, v6});
	return parlex::production("SUBTRACTION",v7, parlex::associativity::LEFT);
}

static parlex::production SUBTRACTION_ASSIGNMENT() {
	parlex::reference const v0("EXPRESSION");
	parlex::reference const v1("IC");
	parlex::repetition const v2(v1);
	parlex::literal const v3(U"-");
	parlex::literal const v4(U"<-");
	parlex::literal const v5(U"←");
	parlex::choice const v6({v4, v5});
	parlex::reference const v7("IC");
	parlex::repetition const v8(v7);
	parlex::reference const v9("EXPRESSION");
	parlex::sequence const v10("SUBTRACTION_ASSIGNMENT", {v0, v2, v3, v6, v8, v9});
	return parlex::production("SUBTRACTION_ASSIGNMENT",v10);
}

static parlex::production SUPERSET_CHAIN() {
	parlex::reference const v0("EXPRESSION");
	parlex::reference const v1("IC");
	parlex::repetition const v2(v1);
	parlex::reference const v3("SUPERSET_CHAIN_LOOP");
	parlex::sequence const v4("SUPERSET_CHAIN", {v0, v2, v3});
	return parlex::production("SUPERSET_CHAIN",v4);
}

static parlex::production SUPERSET_CHAIN_LOOP() {
	parlex::literal const v0(U"=");
	parlex::literal const v1(U"⊇");
	parlex::literal const v2(U"sups");
	parlex::literal const v3(U"⊃");
	parlex::literal const v4(U"psups");
	parlex::choice const v5({v0, v1, v2, v3, v4});
	parlex::reference const v6("IC");
	parlex::repetition const v7(v6);
	parlex::reference const v8("EXPRESSION");
	parlex::reference const v9("IC");
	parlex::repetition const v10(v9);
	parlex::reference const v11("SUPERSET_CHAIN_LOOP");
	parlex::sequence const v12({v10, v11});
	parlex::optional const v13(v12);
	parlex::sequence const v14("SUPERSET_CHAIN_LOOP", {v5, v7, v8, v13});
	return parlex::production("SUPERSET_CHAIN_LOOP",v14, parlex::associativity::NONE, parlex::filter_function(), {"EXPRESSION", });
}

static parlex::production SWIZZLE() {
	parlex::reference const v0("EXPRESSION");
	parlex::reference const v1("IC");
	parlex::repetition const v2(v1);
	parlex::literal const v3(U"⋮");
	parlex::literal const v4(U"_swiz_");
	parlex::choice const v5({v3, v4});
	parlex::reference const v6("IC");
	parlex::repetition const v7(v6);
	parlex::reference const v8("EXPRESSION");
	parlex::sequence const v9("SWIZZLE", {v0, v2, v5, v7, v8});
	return parlex::production("SWIZZLE",v9);
}

static parlex::production SYMMETRIC_DIFFERENCE() {
	parlex::reference const v0("EXPRESSION");
	parlex::reference const v1("IC");
	parlex::repetition const v2(v1);
	parlex::literal const v3(U"⊖");
	parlex::reference const v4("IC");
	parlex::repetition const v5(v4);
	parlex::reference const v6("EXPRESSION");
	parlex::sequence const v7("SYMMETRIC_DIFFERENCE", {v0, v2, v3, v5, v6});
	return parlex::production("SYMMETRIC_DIFFERENCE",v7, parlex::associativity::LEFT);
}

static parlex::production SYMMETRIC_DIFFERENCE_ASSIGNMENT() {
	parlex::reference const v0("EXPRESSION");
	parlex::reference const v1("IC");
	parlex::repetition const v2(v1);
	parlex::literal const v3(U"⊖");
	parlex::literal const v4(U"<-");
	parlex::literal const v5(U"←");
	parlex::choice const v6({v4, v5});
	parlex::reference const v7("IC");
	parlex::repetition const v8(v7);
	parlex::reference const v9("EXPRESSION");
	parlex::sequence const v10("SYMMETRIC_DIFFERENCE_ASSIGNMENT", {v0, v2, v3, v6, v8, v9});
	return parlex::production("SYMMETRIC_DIFFERENCE_ASSIGNMENT",v10);
}

static parlex::production THIS() {
	parlex::literal const v0(U"this");
	parlex::reference const v1("IC");
	parlex::repetition const v2(v1);
	parlex::literal const v3(U"[");
	parlex::reference const v4("IC");
	parlex::repetition const v5(v4);
	parlex::reference const v6("EXPRESSION");
	parlex::reference const v7("IC");
	parlex::repetition const v8(v7);
	parlex::literal const v9(U"]");
	parlex::sequence const v10({v2, v3, v5, v6, v8, v9});
	parlex::optional const v11(v10);
	parlex::sequence const v12("THIS", {v0, v11});
	return parlex::production("THIS",v12);
}

static parlex::production THIS_FUNC() {
	parlex::literal const v0(U"this_func");
	parlex::reference const v1("IC");
	parlex::repetition const v2(v1);
	parlex::literal const v3(U"[");
	parlex::reference const v4("IC");
	parlex::repetition const v5(v4);
	parlex::reference const v6("EXPRESSION");
	parlex::reference const v7("IC");
	parlex::repetition const v8(v7);
	parlex::literal const v9(U"]");
	parlex::sequence const v10({v2, v3, v5, v6, v8, v9});
	parlex::optional const v11(v10);
	parlex::sequence const v12("THIS_FUNC", {v0, v11});
	return parlex::production("THIS_FUNC",v12);
}

static parlex::production THIS_TYPE() {
	parlex::literal const v0(U"this_type");
	parlex::reference const v1("IC");
	parlex::repetition const v2(v1);
	parlex::literal const v3(U"[");
	parlex::reference const v4("IC");
	parlex::repetition const v5(v4);
	parlex::reference const v6("EXPRESSION");
	parlex::reference const v7("IC");
	parlex::repetition const v8(v7);
	parlex::literal const v9(U"]");
	parlex::sequence const v10({v2, v3, v5, v6, v8, v9});
	parlex::optional const v11(v10);
	parlex::sequence const v12("THIS_TYPE", {v0, v11});
	return parlex::production("THIS_TYPE",v12);
}

static parlex::production THROW() {
	parlex::literal const v0(U"throw");
	parlex::reference const v1("IC");
	parlex::repetition const v2(v1);
	parlex::literal const v3(U"[");
	parlex::reference const v4("IC");
	parlex::repetition const v5(v4);
	parlex::reference const v6("EXPRESSION");
	parlex::reference const v7("IC");
	parlex::repetition const v8(v7);
	parlex::literal const v9(U"]");
	parlex::sequence const v10({v2, v3, v5, v6, v8, v9});
	parlex::optional const v11(v10);
	parlex::reference const v12("IC");
	parlex::repetition const v13(v12);
	parlex::reference const v14("EXPRESSION");
	parlex::sequence const v15({v13, v14});
	parlex::optional const v16(v15);
	parlex::sequence const v17("THROW", {v0, v11, v16});
	return parlex::production("THROW",v17);
}

static parlex::production TIME() {
	parlex::literal const v0(U"-");
	parlex::optional const v1(v0);
	parlex::reference const v2("decimal_digit");
	parlex::reference const v3("decimal_digit");
	parlex::literal const v4(U":");
	parlex::reference const v5("decimal_digit");
	parlex::reference const v6("decimal_digit");
	parlex::literal const v7(U":");
	parlex::reference const v8("decimal_digit");
	parlex::reference const v9("decimal_digit");
	parlex::literal const v10(U".");
	parlex::reference const v11("decimal_digit");
	parlex::reference const v12("decimal_digit");
	parlex::repetition const v13(v12);
	parlex::sequence const v14({v10, v11, v13});
	parlex::optional const v15(v14);
	parlex::literal const v16(U"Z");
	parlex::literal const v17(U"+");
	parlex::literal const v18(U"-");
	parlex::choice const v19({v17, v18});
	parlex::reference const v20("decimal_digit");
	parlex::reference const v21("decimal_digit");
	parlex::literal const v22(U":");
	parlex::reference const v23("decimal_digit");
	parlex::reference const v24("decimal_digit");
	parlex::sequence const v25({v22, v23, v24});
	parlex::optional const v26(v25);
	parlex::sequence const v27({v19, v20, v21, v26});
	parlex::choice const v28({v16, v27});
	parlex::optional const v29(v28);
	parlex::sequence const v30("TIME", {v1, v2, v3, v4, v5, v6, v7, v8, v9, v15, v29});
	return parlex::production("TIME",v30);
}

static parlex::production TRY() {
	parlex::literal const v0(U"try");
	parlex::reference const v1("IC");
	parlex::repetition const v2(v1);
	parlex::reference const v3("EXPRESSION");
	parlex::reference const v4("IC");
	parlex::repetition const v5(v4);
	parlex::literal const v6(U"catch");
	parlex::reference const v7("IC");
	parlex::repetition const v8(v7);
	parlex::reference const v9("EXPRESSION");
	parlex::literal const v10(U"catch");
	parlex::reference const v11("IC");
	parlex::repetition const v12(v11);
	parlex::reference const v13("EXPRESSION");
	parlex::sequence const v14({v10, v12, v13});
	parlex::repetition const v15(v14);
	parlex::reference const v16("IC");
	parlex::repetition const v17(v16);
	parlex::literal const v18(U"finally");
	parlex::reference const v19("IC");
	parlex::repetition const v20(v19);
	parlex::reference const v21("EXPRESSION");
	parlex::sequence const v22({v17, v18, v20, v21});
	parlex::optional const v23(v22);
	parlex::sequence const v24("TRY", {v0, v2, v3, v5, v6, v8, v9, v15, v23});
	return parlex::production("TRY",v24);
}

static parlex::production TUPLE() {
	parlex::literal const v0(U"(|");
	parlex::reference const v1("IC");
	parlex::repetition const v2(v1);
	parlex::reference const v3("EXPRESSION");
	parlex::reference const v4("IC");
	parlex::repetition const v5(v4);
	parlex::literal const v6(U",");
	parlex::reference const v7("IC");
	parlex::repetition const v8(v7);
	parlex::reference const v9("EXPRESSION");
	parlex::sequence const v10({v5, v6, v8, v9});
	parlex::repetition const v11(v10);
	parlex::reference const v12("IC");
	parlex::repetition const v13(v12);
	parlex::literal const v14(U"|)");
	parlex::sequence const v15("TUPLE", {v0, v2, v3, v11, v13, v14});
	return parlex::production("TUPLE",v15, parlex::associativity::NONE, parlex::filter_function(), {"MAGNITUDE", });
}

static parlex::production TYPE() {
	parlex::literal const v0(U"type");
	parlex::reference const v1("IC");
	parlex::repetition const v2(v1);
	parlex::literal const v3(U"inheriting");
	parlex::reference const v4("IC");
	parlex::repetition const v5(v4);
	parlex::reference const v6("INHERITANCE_LIST");
	parlex::reference const v7("IC");
	parlex::repetition const v8(v7);
	parlex::sequence const v9({v3, v5, v6, v8});
	parlex::optional const v10(v9);
	parlex::literal const v11(U"implementing");
	parlex::reference const v12("IC");
	parlex::repetition const v13(v12);
	parlex::reference const v14("INHERITANCE_LIST");
	parlex::reference const v15("IC");
	parlex::repetition const v16(v15);
	parlex::sequence const v17({v11, v13, v14, v16});
	parlex::optional const v18(v17);
	parlex::literal const v19(U"{");
	parlex::reference const v20("TYPE_SCOPE");
	parlex::literal const v21(U"}");
	parlex::sequence const v22("TYPE", {v0, v2, v10, v18, v19, v20, v21});
	return parlex::production("TYPE",v22);
}

static parlex::production TYPE_CONSTRAINT() {
	parlex::reference const v0("TYPE_CONSTRAINT_HEAD");
	parlex::reference const v1("IC");
	parlex::repetition const v2(v1);
	parlex::reference const v3("TYPE_CONSTRAINT_CHAIN");
	parlex::sequence const v4("TYPE_CONSTRAINT", {v0, v2, v3});
	return parlex::production("TYPE_CONSTRAINT",v4, parlex::associativity::NONE, parlex::filter_function(), {"EXPRESSION", });
}

static parlex::production TYPE_CONSTRAINT_CHAIN() {
	parlex::reference const v0("DECLARATION");
	parlex::reference const v1("ASSIGNMENT_CHAIN");
	parlex::reference const v2("DEFINITION");
	parlex::choice const v3({v0, v1, v2});
	parlex::reference const v4("IC");
	parlex::repetition const v5(v4);
	parlex::literal const v6(U",");
	parlex::reference const v7("IC");
	parlex::repetition const v8(v7);
	parlex::reference const v9("TYPE_CONSTRAINT_CHAIN");
	parlex::sequence const v10({v5, v6, v8, v9});
	parlex::optional const v11(v10);
	parlex::sequence const v12("TYPE_CONSTRAINT_CHAIN", {v3, v11});
	return parlex::production("TYPE_CONSTRAINT_CHAIN",v12);
}

static parlex::production TYPE_CONSTRAINT_HEAD() {
	parlex::reference const v0("xml_doc_string", "XML_DOC_STRING");
	parlex::reference const v1("IC");
	parlex::repetition const v2(v1);
	parlex::sequence const v3({v0, v2});
	parlex::optional const v4(v3);
	parlex::reference const v5("ATTRIBUTE");
	parlex::reference const v6("IC");
	parlex::repetition const v7(v6);
	parlex::sequence const v8({v5, v7});
	parlex::repetition const v9(v8);
	parlex::reference const v10("visibility_modifier", "VISIBILITY_MODIFIER");
	parlex::reference const v11("IC");
	parlex::repetition const v12(v11);
	parlex::sequence const v13({v10, v12});
	parlex::optional const v14(v13);
	parlex::reference const v15("STATIC");
	parlex::reference const v16("IC");
	parlex::repetition const v17(v16);
	parlex::sequence const v18({v15, v17});
	parlex::optional const v19(v18);
	parlex::reference const v20("EXTERN");
	parlex::reference const v21("IC");
	parlex::repetition const v22(v21);
	parlex::sequence const v23({v20, v22});
	parlex::optional const v24(v23);
	parlex::reference const v25("TYPE_DEREFERENCE");
	parlex::reference const v26("VOLATILE_TYPE_DEREFERENCE");
	parlex::reference const v27("IMPLICIT_TYPE_DEREFERENCE");
	parlex::reference const v28("VOLATILE_IMPLICIT_TYPE_DEREFERENCE");
	parlex::choice const v29("type_dereference", {v25, v26, v27, v28});
	parlex::sequence const v30("TYPE_CONSTRAINT_HEAD", {v4, v9, v14, v19, v24, v29});
	return parlex::production("TYPE_CONSTRAINT_HEAD",v30);
}

static parlex::production TYPE_DEREFERENCE() {
	parlex::literal const v0(U"<");
	parlex::reference const v1("IC");
	parlex::repetition const v2(v1);
	parlex::reference const v3("EXPRESSION");
	parlex::reference const v4("IC");
	parlex::repetition const v5(v4);
	parlex::literal const v6(U">");
	parlex::sequence const v7("TYPE_DEREFERENCE", {v0, v2, v3, v5, v6});
	return parlex::production("TYPE_DEREFERENCE",v7);
}

static parlex::production TYPE_INVOCATION() {
	parlex::reference const v0("target", "EXPRESSION");
	parlex::literal const v1(U"<");
	parlex::reference const v2("IC");
	parlex::repetition const v3(v2);
	parlex::reference const v4("ARGUMENT");
	parlex::reference const v5("ARGUMENT_PACK");
	parlex::choice const v6({v4, v5});
	parlex::sequence const v7({v3, v6});
	parlex::optional const v8("argsHead", v7);
	parlex::reference const v9("IC");
	parlex::repetition const v10(v9);
	parlex::literal const v11(U",");
	parlex::reference const v12("IC");
	parlex::repetition const v13(v12);
	parlex::reference const v14("ARGUMENT");
	parlex::reference const v15("ARGUMENT_PACK");
	parlex::choice const v16({v14, v15});
	parlex::sequence const v17({v13, v16});
	parlex::optional const v18(v17);
	parlex::sequence const v19({v10, v11, v18});
	parlex::repetition const v20("argsTail", v19);
	parlex::reference const v21("IC");
	parlex::repetition const v22(v21);
	parlex::literal const v23(U">");
	parlex::sequence const v24({v1, v8, v20, v22, v23});
	parlex::sequence const v25("TYPE_INVOCATION", {v0, v24});
	return parlex::production("TYPE_INVOCATION",v25);
}

static parlex::production TYPE_SCOPE() {
	parlex::reference const v0("IC");
	parlex::repetition const v1(v0);
	parlex::reference const v2("TYPE_STATEMENT");
	parlex::reference const v3("IC");
	parlex::repetition const v4(v3);
	parlex::sequence const v5({v2, v4});
	parlex::repetition const v6(v5);
	parlex::sequence const v7("TYPE_SCOPE", {v1, v6});
	return parlex::production("TYPE_SCOPE",v7);
}

static parlex::production TYPE_SCOPE_ASSIGNMENT_CHAIN() {
	parlex::reference const v0("XML_DOC_STRING");
	parlex::reference const v1("IC");
	parlex::repetition const v2(v1);
	parlex::sequence const v3({v0, v2});
	parlex::optional const v4(v3);
	parlex::reference const v5("IDENTIFIER");
	parlex::reference const v6("IC");
	parlex::repetition const v7(v6);
	parlex::reference const v8("MEMBER_OFFSET");
	parlex::sequence const v9({v7, v8});
	parlex::optional const v10(v9);
	parlex::reference const v11("IC");
	parlex::repetition const v12(v11);
	parlex::literal const v13(U"←");
	parlex::literal const v14(U"<-");
	parlex::choice const v15({v13, v14});
	parlex::reference const v16("IC");
	parlex::repetition const v17(v16);
	parlex::reference const v18("EXPRESSION");
	parlex::reference const v19("ASSIGNMENT_CHAIN");
	parlex::choice const v20({v18, v19});
	parlex::sequence const v21("TYPE_SCOPE_ASSIGNMENT_CHAIN", {v4, v5, v10, v12, v15, v17, v20});
	return parlex::production("TYPE_SCOPE_ASSIGNMENT_CHAIN",v21, parlex::associativity::NONE, parlex::filter_function(), {"EXPRESSION", });
}

static parlex::production TYPE_SCOPE_DECLARATION() {
	parlex::reference const v0("XML_DOC_STRING");
	parlex::reference const v1("IC");
	parlex::repetition const v2(v1);
	parlex::sequence const v3({v0, v2});
	parlex::optional const v4(v3);
	parlex::reference const v5("IDENTIFIER");
	parlex::reference const v6("IC");
	parlex::repetition const v7(v6);
	parlex::reference const v8("MEMBER_OFFSET");
	parlex::sequence const v9({v7, v8});
	parlex::optional const v10(v9);
	parlex::sequence const v11("TYPE_SCOPE_DECLARATION", {v4, v5, v10});
	return parlex::production("TYPE_SCOPE_DECLARATION",v11);
}

static parlex::production TYPE_SCOPE_TYPE_CONSTRAINT() {
	parlex::reference const v0("TYPE_CONSTRAINT_HEAD");
	parlex::reference const v1("IC");
	parlex::repetition const v2(v1);
	parlex::reference const v3("TYPE_SCOPE_TYPE_CONSTRAINT_CHAIN");
	parlex::sequence const v4("TYPE_SCOPE_TYPE_CONSTRAINT", {v0, v2, v3});
	return parlex::production("TYPE_SCOPE_TYPE_CONSTRAINT",v4, parlex::associativity::NONE, parlex::filter_function(), {"TYPE_CONSTRAINT", });
}

static parlex::production TYPE_SCOPE_TYPE_CONSTRAINT_CHAIN() {
	parlex::reference const v0("XML_DOC_STRING");
	parlex::reference const v1("IC");
	parlex::repetition const v2(v1);
	parlex::sequence const v3({v0, v2});
	parlex::optional const v4(v3);
	parlex::reference const v5("TYPE_SCOPE_DECLARATION");
	parlex::reference const v6("TYPE_SCOPE_ASSIGNMENT_CHAIN");
	parlex::reference const v7("DEFINITION");
	parlex::choice const v8({v5, v6, v7});
	parlex::reference const v9("IC");
	parlex::repetition const v10(v9);
	parlex::literal const v11(U",");
	parlex::reference const v12("IC");
	parlex::repetition const v13(v12);
	parlex::reference const v14("TYPE_SCOPE_TYPE_CONSTRAINT_CHAIN");
	parlex::sequence const v15({v10, v11, v13, v14});
	parlex::optional const v16(v15);
	parlex::sequence const v17("TYPE_SCOPE_TYPE_CONSTRAINT_CHAIN", {v4, v8, v16});
	return parlex::production("TYPE_SCOPE_TYPE_CONSTRAINT_CHAIN",v17);
}

static parlex::production TYPE_STATEMENT() {
	parlex::reference const v0("VISIBILITY_MODIFIER");
	parlex::reference const v1("IC");
	parlex::repetition const v2(v1);
	parlex::literal const v3(U":");
	parlex::sequence const v4({v0, v2, v3});
	parlex::reference const v5("TYPE_SCOPE_TYPE_CONSTRAINT");
	parlex::reference const v6("STATEMENT");
	parlex::choice const v7("TYPE_STATEMENT", {v4, v5, v6});
	return parlex::production("TYPE_STATEMENT",v7);
}

static parlex::production UNARY_ARITHMETIC_OP() {
	parlex::reference const v0("FACTORIAL");
	parlex::reference const v1("NEGATION");
	parlex::reference const v2("RADICAL");
	parlex::choice const v3("UNARY_ARITHMETIC_OP", {v0, v1, v2});
	return parlex::production("UNARY_ARITHMETIC_OP",v3);
}

static parlex::production UNARY_LOGICAL_OP() {
	parlex::reference const v0("ALL");
	parlex::reference const v1("EXISTS");
	parlex::reference const v2("EXISTS_ONE");
	parlex::reference const v3("NOT");
	parlex::choice const v4("UNARY_LOGICAL_OP", {v0, v1, v2, v3});
	return parlex::production("UNARY_LOGICAL_OP",v4, parlex::associativity::NONE, parlex::filter_function(), {"BINARY_LOGICAL_OP", });
}

static parlex::production UNARY_OP() {
	parlex::reference const v0("ALLOCATION");
	parlex::reference const v1("CARDINALITY");
	parlex::reference const v2("KLEENE_STAR");
	parlex::reference const v3("UNARY_ARITHMETIC_OP");
	parlex::reference const v4("UNARY_LOGICAL_OP");
	parlex::choice const v5("UNARY_OP", {v0, v1, v2, v3, v4});
	return parlex::production("UNARY_OP",v5);
}

static parlex::production UNION() {
	parlex::reference const v0("EXPRESSION");
	parlex::reference const v1("IC");
	parlex::repetition const v2(v1);
	parlex::literal const v3(U"∪");
	parlex::reference const v4("IC");
	parlex::repetition const v5(v4);
	parlex::reference const v6("EXPRESSION");
	parlex::sequence const v7("UNION", {v0, v2, v3, v5, v6});
	return parlex::production("UNION",v7, parlex::associativity::ANY);
}

static parlex::production UNION_ASSIGNMENT() {
	parlex::reference const v0("EXPRESSION");
	parlex::reference const v1("IC");
	parlex::repetition const v2(v1);
	parlex::literal const v3(U"∪");
	parlex::literal const v4(U"<-");
	parlex::literal const v5(U"←");
	parlex::choice const v6({v4, v5});
	parlex::reference const v7("IC");
	parlex::repetition const v8(v7);
	parlex::reference const v9("EXPRESSION");
	parlex::sequence const v10("UNION_ASSIGNMENT", {v0, v2, v3, v6, v8, v9});
	return parlex::production("UNION_ASSIGNMENT",v10);
}

static parlex::production UNIT_DIVISION() {
	parlex::reference const v0("DIMENSION");
	parlex::literal const v1(U"/");
	parlex::reference const v2("DIMENSION");
	parlex::sequence const v3("UNIT_DIVISION", {v0, v1, v2});
	return parlex::production("UNIT_DIVISION",v3, parlex::associativity::LEFT);
}

static parlex::production UNIT_EXPONENTIATION() {
	parlex::reference const v0("DIMENSION");
	parlex::literal const v1(U"^");
	parlex::reference const v2("NON_FRACTIONAL");
	parlex::sequence const v3("UNIT_EXPONENTIATION", {v0, v1, v2});
	return parlex::production("UNIT_EXPONENTIATION",v3, parlex::associativity::RIGHT, parlex::filter_function(), {"UNIT_DIVISION", "UNIT_MULTIPLICATION", });
}

static parlex::production UNIT_MULTIPLICATION() {
	parlex::reference const v0("DIMENSION");
	parlex::literal const v1(U"*");
	parlex::reference const v2("DIMENSION");
	parlex::sequence const v3("UNIT_MULTIPLICATION", {v0, v1, v2});
	return parlex::production("UNIT_MULTIPLICATION",v3, parlex::associativity::LEFT);
}

static parlex::production UPCASTS() {
	parlex::reference const v0("EXPRESSION");
	parlex::reference const v1("IC");
	parlex::repetition const v2(v1);
	parlex::literal const v3(U"upcasts");
	parlex::reference const v4("IC");
	parlex::repetition const v5(v4);
	parlex::reference const v6("EXPRESSION");
	parlex::sequence const v7("UPCASTS", {v0, v2, v3, v5, v6});
	return parlex::production("UPCASTS",v7);
}

static parlex::production USING() {
	parlex::literal const v0(U"using");
	parlex::reference const v1("IC");
	parlex::repetition const v2(v1);
	parlex::literal const v3(U"(");
	parlex::reference const v4("IC");
	parlex::repetition const v5(v4);
	parlex::reference const v6("EXPRESSION");
	parlex::reference const v7("IC");
	parlex::repetition const v8(v7);
	parlex::literal const v9(U")");
	parlex::reference const v10("IC");
	parlex::repetition const v11(v10);
	parlex::reference const v12("BLOCK");
	parlex::sequence const v13("USING", {v0, v2, v3, v5, v6, v8, v9, v11, v12});
	return parlex::production("USING",v13);
}

static parlex::production VECTOR_NORM() {
	parlex::literal const v0(U"||");
	parlex::reference const v1("IC");
	parlex::repetition const v2(v1);
	parlex::reference const v3("EXPRESSION");
	parlex::reference const v4("IC");
	parlex::repetition const v5(v4);
	parlex::literal const v6(U"||");
	parlex::sequence const v7("VECTOR_NORM", {v0, v2, v3, v5, v6});
	return parlex::production("VECTOR_NORM",v7);
}

static parlex::production VISIBILITY_MODIFIER() {
	parlex::literal const v0(U"public");
	parlex::literal const v1(U"protected");
	parlex::literal const v2(U"protected internal");
	parlex::literal const v3(U"internal");
	parlex::literal const v4(U"private");
	parlex::choice const v5("VISIBILITY_MODIFIER", {v0, v1, v2, v3, v4});
	return parlex::production("VISIBILITY_MODIFIER",v5);
}

static parlex::production VOLATILE_IMPLICIT_TYPE_DEREFERENCE() {
	parlex::literal const v0(U"<");
	parlex::reference const v1("IC");
	parlex::repetition const v2(v1);
	parlex::literal const v3(U"volatile");
	parlex::reference const v4("IC");
	parlex::repetition const v5(v4);
	parlex::literal const v6(U">");
	parlex::sequence const v7("VOLATILE_IMPLICIT_TYPE_DEREFERENCE", {v0, v2, v3, v5, v6});
	return parlex::production("VOLATILE_IMPLICIT_TYPE_DEREFERENCE",v7);
}

static parlex::production VOLATILE_TYPE_DEREFERENCE() {
	parlex::literal const v0(U"<");
	parlex::reference const v1("IC");
	parlex::repetition const v2(v1);
	parlex::literal const v3(U"volatile");
	parlex::reference const v4("IC");
	parlex::repetition const v5(v4);
	parlex::reference const v6("EXPRESSION");
	parlex::reference const v7("IC");
	parlex::repetition const v8(v7);
	parlex::literal const v9(U">");
	parlex::sequence const v10("VOLATILE_TYPE_DEREFERENCE", {v0, v2, v3, v5, v6, v8, v9});
	return parlex::production("VOLATILE_TYPE_DEREFERENCE",v10);
}

static parlex::production WHOLE_NUMBER() {
	parlex::literal const v0(U"1");
	parlex::literal const v1(U"2");
	parlex::literal const v2(U"3");
	parlex::literal const v3(U"4");
	parlex::literal const v4(U"5");
	parlex::literal const v5(U"6");
	parlex::literal const v6(U"7");
	parlex::literal const v7(U"8");
	parlex::literal const v8(U"9");
	parlex::choice const v9({v0, v1, v2, v3, v4, v5, v6, v7, v8});
	parlex::literal const v10(U"0");
	parlex::literal const v11(U"1");
	parlex::literal const v12(U"2");
	parlex::literal const v13(U"3");
	parlex::literal const v14(U"4");
	parlex::literal const v15(U"5");
	parlex::literal const v16(U"6");
	parlex::literal const v17(U"7");
	parlex::literal const v18(U"8");
	parlex::literal const v19(U"9");
	parlex::choice const v20({v10, v11, v12, v13, v14, v15, v16, v17, v18, v19});
	parlex::repetition const v21(v20);
	parlex::sequence const v22("WHOLE_NUMBER", {v9, v21});
	return parlex::production("WHOLE_NUMBER",v22);
}

static parlex::production WRITE_LOCK() {
	parlex::literal const v0(U"write_lock");
	parlex::reference const v1("IC");
	parlex::repetition const v2(v1);
	parlex::reference const v3("PARENTHETICAL");
	parlex::reference const v4("IC");
	parlex::repetition const v5(v4);
	parlex::reference const v6("EXPRESSION");
	parlex::sequence const v7("WRITE_LOCK", {v0, v2, v3, v5, v6});
	return parlex::production("WRITE_LOCK",v7);
}

static parlex::production WS() {
	parlex::reference const v0("white_space");
	parlex::reference const v1("white_space");
	parlex::repetition const v2(v1);
	parlex::sequence const v3("WS", {v0, v2});
	return parlex::production("WS",v3, parlex::associativity::NONE, parlex::longest());
}

static parlex::production XML_DOC_STRING() {
	parlex::literal const v0(U"```");
	parlex::reference const v1("XML_DOC_STRING_INTERIOR");
	parlex::literal const v2(U"```");
	parlex::sequence const v3("XML_DOC_STRING", {v0, v1, v2});
	return parlex::production("XML_DOC_STRING",v3);
}

static parlex::production XML_DOC_STRING_INTERIOR() {
	parlex::reference const v0("payload", "PAYLOAD");
	parlex::literal const v1(U"`");
	parlex::reference const v2("XML_DOC_STRING_INTERIOR");
	parlex::literal const v3(U"`");
	parlex::sequence const v4({v1, v2, v3});
	parlex::choice const v5("XML_DOC_STRING_INTERIOR", {v0, v4});
	return parlex::production("XML_DOC_STRING_INTERIOR",v5, parlex::associativity::NONE, parlex::filter_function(), {"PAYLOAD", });
}

static parlex::production XOR() {
	parlex::reference const v0("EXPRESSION");
	parlex::reference const v1("IC");
	parlex::repetition const v2(v1);
	parlex::literal const v3(U"⊕");
	parlex::literal const v4(U"xor");
	parlex::choice const v5({v3, v4});
	parlex::reference const v6("IC");
	parlex::repetition const v7(v6);
	parlex::reference const v8("EXPRESSION");
	parlex::sequence const v9("XOR", {v0, v2, v5, v7, v8});
	return parlex::production("XOR",v9, parlex::associativity::LEFT);
}

static parlex::production XOR_ASSIGNMENT() {
	parlex::reference const v0("EXPRESSION");
	parlex::reference const v1("IC");
	parlex::repetition const v2(v1);
	parlex::literal const v3(U"⊕");
	parlex::literal const v4(U"xor");
	parlex::choice const v5({v3, v4});
	parlex::literal const v6(U"<-");
	parlex::literal const v7(U"←");
	parlex::choice const v8({v6, v7});
	parlex::reference const v9("IC");
	parlex::repetition const v10(v9);
	parlex::reference const v11("EXPRESSION");
	parlex::sequence const v12("XOR_ASSIGNMENT", {v0, v2, v5, v8, v10, v11});
	return parlex::production("XOR_ASSIGNMENT",v12);
}

static parlex::builder const & builder() {
	static parlex::builder const result("STATEMENT_SCOPE", {
		ADDITION(),
		ADDITION_ASSIGNMENT(),
		ADD_SUB(),
		ADD_SUB_ASSIGNMENT(),
		ALL(),
		ALLOCATION(),
		AND(),
		AND_ASSIGNMENT(),
		ARGUMENT(),
		ARGUMENT_PACK(),
		ARRAY(),
		ARRAY_INDEXER(),
		ARRAY_INVOCATION(),
		ASM_EXPRESSION(),
		ASM_FUNCTION(),
		ASM_IDENTIFIER(),
		ASM_OP(),
		ASM_PTR_ARITHMETIC_ATT(),
		ASM_PTR_ARITHMETIC_ATT_REG(),
		ASM_PTR_ARITHMETIC_INTEL(),
		ASM_SCOPE(),
		ASM_STATEMENT(),
		ASSIGNMENT_CHAIN(),
		ATTRIBUTE(),
		BIJECTION(),
		BINARY_ARITHMETIC_OP(),
		BINARY_COLLECTION_OP(),
		BINARY_LOGICAL_OP(),
		BINARY_OP(),
		BITWISE_OP(),
		BIT_AND(),
		BIT_AND_ASSIGNMENT(),
		BIT_NOT(),
		BIT_NOT_ASSIGNMENT(),
		BIT_OR(),
		BIT_OR_ASSIGNMENT(),
		BIT_XOR(),
		BIT_XOR_ASSIGNMENT(),
		BLOCK(),
		BOOL(),
		BREAK(),
		CARDINALITY(),
		CAST(),
		CASTS(),
		CEILING(),
		COMMENT(),
		COMPLEMENT(),
		COMPOSITION(),
		COMPOSITION_ASSIGNMENT(),
		COMPOUND(),
		COMPOUND_ASSIGNMENT(),
		CONDITIONAL(),
		CONSTRUCTIVE_OP(),
		CONTINUE(),
		CROSS_PRODUCT(),
		CROSS_PRODUCT_ASSIGNMENT(),
		DATE(),
		DATE_TIME(),
		DATE_YEAR_DAY(),
		DATE_YEAR_MONTH_DAY(),
		DECLARATION(),
		DEFINITION(),
		DELTA(),
		DIMENSION(),
		DIMENSIONAL_ANALYSIS_OP(),
		DIMENSIONAL_NUMBER(),
		DIVISION(),
		DIVISION_ASSIGNMENT(),
		DO(),
		DOT_PRODUCT(),
		DOWNCASTS(),
		EMBEDDED_COMMENT(),
		EMBEDDED_COMMENT_INTERIOR(),
		EMBEDDED_NEWLINE_STRING(),
		EMBEDDED_NEWLINE_STRING_INTERIOR(),
		EMBEDDED_STRING(),
		EMBEDDED_STRING_INTERIOR(),
		END_OF_LINE_COMMENT(),
		ENUM(),
		ENUM_ELEMENT(),
		EQUALITY_CHAIN(),
		EQUALITY_CHAIN_LOOP(),
		EXACTLY(),
		EXISTS(),
		EXISTS_ONE(),
		EXPONENTIATION(),
		EXPONENTIATION_ASSIGNMENT(),
		EXPRESSION(),
		EXTERN(),
		FACTORIAL(),
		FACTORIAL_ASSIGNMENT(),
		FLOOR(),
		FOR(),
		FOR_COLLECTION(),
		FREE(),
		FUNCTION(),
		FUNCTION_MODIFIER_0(),
		FUNCTION_MODIFIER_1(),
		FUNCTION_MODIFIER_2(),
		FUNCTION_MODIFIER_3(),
		FUNCTION_MODIFIER_4(),
		FUNCTION_MODIFIER_ATOMIC(),
		FUNCTION_MODIFIER_CALLING_CONVENTION(),
		FUNCTION_MODIFIER_MODEL(),
		FUNCTION_MODIFIER_PLATFORM(),
		FUNCTION_MODIFIER_STABILITY(),
		FUNCTION_MODIFIER_THROWING(),
		GREATER_CHAIN(),
		GREATER_CHAIN_LOOP(),
		HAS(),
		HEX(),
		IC(),
		IDENTIFIER(),
		IF(),
		IFF(),
		IMPLEMENTS(),
		IMPLICATION(),
		IMPLICATION_ASSIGNMENT(),
		IMPLICIT_TYPE_DEREFERENCE(),
		IMPORT(),
		IN(),
		INEQUALITY(),
		INHERITANCE_ITEM_PREFIX(),
		INHERITANCE_LIST(),
		INHERITS(),
		INTEGER_DIVISION(),
		INTEGER_DIVISION_ASSIGNMENT(),
		INTERSECTION(),
		INTERSECTION_ASSIGNMENT(),
		INVOCATION(),
		IS(),
		KLEENE_STAR(),
		LESSER_CHAIN(),
		LESSER_CHAIN_LOOP(),
		LIST(),
		LOCK(),
		LOOP(),
		MAGNITUDE(),
		MAP(),
		MAPS_TO(),
		MEMBER_ACCESS(),
		MEMBER_OFFSET(),
		MODULATION(),
		MODULATION_ASSIGNMENT(),
		MULTIPLICATION(),
		MULTIPLICATION_ASSIGNMENT(),
		MULTIPLICATIVE_OP(),
		NAND(),
		NAND_ASSIGNMENT(),
		NEAREST_INTEGER(),
		NEGATION(),
		NEGATION_ASSIGNMENT(),
		NON_FRACTIONAL(),
		NON_NEG_FRACTIONAL(),
		NON_NEG_INTEGER(),
		NON_NEG_NON_FRACTIONAL(),
		NON_NEG_NUMBER(),
		NON_ZERO_DECIMAL_DIGIT(),
		NOR(),
		NOR_ASSIGNMENT(),
		NOT(),
		NOT_ASSIGNMENT(),
		NOT_HAS(),
		NOT_IN(),
		NULL_COALESCE(),
		NULL_COALESCE_ASSIGNMENT(),
		OBJECT(),
		OCTAL(),
		OP_ASSIGNMENT(),
		OR(),
		OR_ASSIGNMENT(),
		PARAMETER(),
		PARAMETER_ANALYTIC(),
		PARAMETER_NATURAL(),
		PARENTHETICAL(),
		PARENTHETICAL_INVOCATION(),
		PAYLOAD(),
		PLATFORM(),
		POST_DEC(),
		POST_INC(),
		PREPEND(),
		PREPEND_ASSIGNMENT(),
		PRE_DEC(),
		PRE_INC(),
		RADICAL(),
		RADICAL_ASSIGNMENT(),
		RANGE(),
		READ_LOCK(),
		RECORD(),
		REGEX(),
		RELATIONAL_COLLECTION_OP(),
		RELATIONAL_OP(),
		RETURN(),
		SET(),
		SET_COMPREHENSION(),
		SHIFTL(),
		SHIFTL_ASSIGNMENT(),
		SHIFTR(),
		SHIFTR_ASSIGNMENT(),
		SLICE(),
		STATEMENT(),
		STATEMENT_SCOPE(),
		STATIC(),
		SUBSET_CHAIN(),
		SUBSET_CHAIN_LOOP(),
		SUBTRACTION(),
		SUBTRACTION_ASSIGNMENT(),
		SUPERSET_CHAIN(),
		SUPERSET_CHAIN_LOOP(),
		SWIZZLE(),
		SYMMETRIC_DIFFERENCE(),
		SYMMETRIC_DIFFERENCE_ASSIGNMENT(),
		THIS(),
		THIS_FUNC(),
		THIS_TYPE(),
		THROW(),
		TIME(),
		TRY(),
		TUPLE(),
		TYPE(),
		TYPE_CONSTRAINT(),
		TYPE_CONSTRAINT_CHAIN(),
		TYPE_CONSTRAINT_HEAD(),
		TYPE_DEREFERENCE(),
		TYPE_INVOCATION(),
		TYPE_SCOPE(),
		TYPE_SCOPE_ASSIGNMENT_CHAIN(),
		TYPE_SCOPE_DECLARATION(),
		TYPE_SCOPE_TYPE_CONSTRAINT(),
		TYPE_SCOPE_TYPE_CONSTRAINT_CHAIN(),
		TYPE_STATEMENT(),
		UNARY_ARITHMETIC_OP(),
		UNARY_LOGICAL_OP(),
		UNARY_OP(),
		UNION(),
		UNION_ASSIGNMENT(),
		UNIT_DIVISION(),
		UNIT_EXPONENTIATION(),
		UNIT_MULTIPLICATION(),
		UPCASTS(),
		USING(),
		VECTOR_NORM(),
		VISIBILITY_MODIFIER(),
		VOLATILE_IMPLICIT_TYPE_DEREFERENCE(),
		VOLATILE_TYPE_DEREFERENCE(),
		WHOLE_NUMBER(),
		WRITE_LOCK(),
		WS(),
		XML_DOC_STRING(),
		XML_DOC_STRING_INTERIOR(),
		XOR(),
		XOR_ASSIGNMENT(),
	});
	return result;
}
