static parlex::builder const & builder() {
	static parlex::builder const result("STATEMENT_SCOPE", {
		parlex::production("ADDITION",
		parlex::sequence("ADDITION", {
			parlex::reference("EXPRESSION"),
			parlex::repetition(	parlex::reference("IC")
			),
			parlex::literal("+", U"+"),
			parlex::repetition(	parlex::reference("IC")
			),
			parlex::reference("EXPRESSION")
		}),
		parlex::associativity::ANY),
		parlex::production("ADDITION_ASSIGNMENT",
		parlex::sequence("ADDITION_ASSIGNMENT", {
			parlex::reference("EXPRESSION"),
			parlex::repetition(	parlex::reference("IC")
			),
			parlex::choice ({
				parlex::literal("+<-", U"+<-"),
				parlex::literal("+←", U"+←"),
				parlex::literal("⥆", U"⥆")
			}),
			parlex::repetition(	parlex::reference("IC")
			),
			parlex::reference("EXPRESSION")
		})),
		parlex::production("ADD_SUB",
		parlex::sequence("ADD_SUB", {
			parlex::reference("EXPRESSION"),
			parlex::repetition(	parlex::reference("IC")
			),
			parlex::choice ({
				parlex::literal("±", U"±"),
				parlex::literal("+-", U"+-")
			}),
			parlex::repetition(	parlex::reference("IC")
			),
			parlex::reference("EXPRESSION")
		}),
		parlex::associativity::LEFT),
		parlex::production("ADD_SUB_ASSIGNMENT",
		parlex::sequence("ADD_SUB_ASSIGNMENT", {
			parlex::reference("EXPRESSION"),
			parlex::repetition(	parlex::reference("IC")
			),
			parlex::choice ({
				parlex::literal("±", U"±"),
				parlex::literal("+-", U"+-")
			}),
			parlex::choice ({
				parlex::literal("<-", U"<-"),
				parlex::literal("←", U"←")
			}),
			parlex::repetition(	parlex::reference("IC")
			),
			parlex::reference("EXPRESSION")
		})),
		parlex::production("ALL",
		parlex::sequence("ALL", {
			parlex::choice ({
				parlex::literal("∀", U"∀"),
				parlex::literal("all", U"all")
			}),
			parlex::repetition(	parlex::reference("IC")
			),
			parlex::reference("EXPRESSION")
		})),
		parlex::production("ALLOCATION",
		parlex::sequence("ALLOCATION", {
			parlex::literal("alloc", U"alloc"),
			parlex::repetition(	parlex::reference("IC")
			),
			parlex::reference("PARENTHETICAL_INVOCATION")
		})),
		parlex::production("AND",
		parlex::sequence("AND", {
			parlex::reference("EXPRESSION"),
			parlex::repetition(	parlex::reference("IC")
			),
			parlex::choice ({
				parlex::literal("∧", U"∧"),
				parlex::literal("and", U"and")
			}),
			parlex::repetition(	parlex::reference("IC")
			),
			parlex::reference("EXPRESSION")
		}),
		parlex::associativity::ANY, parlex::filter_function(), {"IFF", "IMPLICATION", "OR", "XOR", }),
		parlex::production("AND_ASSIGNMENT",
		parlex::sequence("AND_ASSIGNMENT", {
			parlex::reference("EXPRESSION"),
			parlex::repetition(	parlex::reference("IC")
			),
			parlex::choice ({
				parlex::literal("∧", U"∧"),
				parlex::literal("and", U"and")
			}),
			parlex::choice ({
				parlex::literal("<-", U"<-"),
				parlex::literal("←", U"←")
			}),
			parlex::repetition(	parlex::reference("IC")
			),
			parlex::reference("EXPRESSION")
		})),
		parlex::production("ARGUMENT",
		parlex::reference("ARGUMENT", "EXPRESSION")),
		parlex::production("ARGUMENT_PACK",
		parlex::sequence("ARGUMENT_PACK", {
			parlex::reference("EXPRESSION"),
			parlex::repetition(	parlex::reference("IC")
			),
			parlex::literal("...", U"...")
		})),
		parlex::production("ARRAY",
		parlex::sequence("ARRAY", {
			parlex::literal("[", U"["),
			parlex::repetition(	parlex::reference("IC")
			),
			parlex::optional(	parlex::sequence({
					parlex::reference("expression", "EXPRESSION"),
					parlex::repetition(	parlex::sequence({
							parlex::repetition(	parlex::reference("IC")
							),
							parlex::literal(",", U","),
							parlex::repetition(	parlex::reference("IC")
							),
							parlex::reference("expression", "EXPRESSION")
						})
					),
					parlex::repetition(	parlex::reference("IC")
					)
				})
			),
			parlex::literal("]", U"]")
		})),
		parlex::production("ARRAY_INDEXER",
		parlex::sequence("ARRAY_INDEXER", {
			parlex::repetition(	parlex::reference("IC")
			),
			parlex::choice ({
				parlex::reference("ARGUMENT"),
				parlex::reference("ARGUMENT_PACK"),
				parlex::reference("SLICE")
			})
		})),
		parlex::production("ARRAY_INVOCATION",
		parlex::sequence("ARRAY_INVOCATION", {
			parlex::reference("target", "EXPRESSION"),
			parlex::literal("[", U"["),
			parlex::optional("argsHead", 	parlex::reference("array_indexer", "ARRAY_INDEXER")
			),
			parlex::repetition("argsTail", 	parlex::sequence({
					parlex::repetition(	parlex::reference("IC")
					),
					parlex::literal(",", U","),
					parlex::optional(	parlex::reference("array_indexer", "ARRAY_INDEXER")
					)
				})
			),
			parlex::repetition(	parlex::reference("IC")
			),
			parlex::literal("]", U"]")
		})),
		parlex::production("ASM_EXPRESSION",
		parlex::choice ("ASM_EXPRESSION", {
			parlex::reference("ASM_IDENTIFIER"),
			parlex::reference("ASM_PTR_ARITHMETIC_ATT"),
			parlex::reference("ASM_PTR_ARITHMETIC_INTEL"),
			parlex::reference("NON_FRACTIONAL")
		})),
		parlex::production("ASM_FUNCTION",
		parlex::sequence("ASM_FUNCTION", {
			parlex::optional(	parlex::sequence({
					parlex::literal("(", U"("),
					parlex::repetition(	parlex::reference("IC")
					),
					parlex::optional(	parlex::sequence({
							parlex::reference("parameter", "PARAMETER"),
							parlex::repetition(	parlex::sequence({
									parlex::repetition(	parlex::reference("IC")
									),
									parlex::literal(",", U","),
									parlex::repetition(	parlex::reference("IC")
									),
									parlex::reference("parameter", "PARAMETER")
								})
							),
							parlex::repetition(	parlex::reference("IC")
							)
						})
					),
					parlex::literal(")", U")"),
					parlex::repetition(	parlex::reference("IC")
					)
				})
			),
			parlex::optional(	parlex::reference("FUNCTION_MODIFIER_0")
			),
			parlex::literal("asm", U"asm"),
			parlex::repetition(	parlex::reference("IC")
			),
			parlex::literal("{", U"{"),
			parlex::reference("ASM_SCOPE"),
			parlex::literal("}", U"}")
		})),
		parlex::production("ASM_IDENTIFIER",
		parlex::sequence("ASM_IDENTIFIER", {
			parlex::optional(	parlex::literal("%", U"%")
			),
			parlex::reference("IDENTIFIER")
		})),
		parlex::production("ASM_OP",
		parlex::sequence("ASM_OP", {
			parlex::reference("lowercase_letter"),
			parlex::repetition(	parlex::reference("lowercase_letter")
			)
		})),
		parlex::production("ASM_PTR_ARITHMETIC_ATT",
		parlex::choice ("ASM_PTR_ARITHMETIC_ATT", {
			parlex::sequence({
				parlex::reference("ASM_IDENTIFIER"),
				parlex::literal(":", U":"),
				parlex::reference("NON_FRACTIONAL")
			}),
			parlex::sequence({
				parlex::reference("ASM_IDENTIFIER"),
				parlex::literal(":", U":"),
				parlex::reference("NON_FRACTIONAL"),
				parlex::reference("ASM_PTR_ARITHMETIC_ATT_REG")
			}),
			parlex::sequence({
				parlex::reference("NON_FRACTIONAL"),
				parlex::reference("ASM_PTR_ARITHMETIC_ATT_REG")
			})
		})),
		parlex::production("ASM_PTR_ARITHMETIC_ATT_REG",
		parlex::sequence("ASM_PTR_ARITHMETIC_ATT_REG", {
			parlex::literal("(", U"("),
			parlex::optional(	parlex::reference("asm_identifier", "ASM_IDENTIFIER")
			),
			parlex::optional(	parlex::sequence({
					parlex::literal(",", U","),
					parlex::reference("asm_identifier", "ASM_IDENTIFIER"),
					parlex::optional(	parlex::sequence({
							parlex::literal(",", U","),
							parlex::reference("NON_NEG_NON_FRACTIONAL")
						})
					)
				})
			),
			parlex::literal(")", U")")
		})),
		parlex::production("ASM_PTR_ARITHMETIC_INTEL",
		parlex::sequence("ASM_PTR_ARITHMETIC_INTEL", {
			parlex::optional(	parlex::sequence({
					parlex::choice ({
						parlex::literal("BYTE", U"BYTE"),
						parlex::literal("WORD", U"WORD"),
						parlex::literal("DWORD", U"DWORD"),
						parlex::literal("QWORD", U"QWORD")
					}),
					parlex::literal(" PTR", U" PTR")
				})
			),
			parlex::literal("[", U"["),
			parlex::optional(	parlex::sequence({
					parlex::reference("ASM_IDENTIFIER"),
					parlex::literal(":", U":")
				})
			),
			parlex::reference("ASM_IDENTIFIER"),
			parlex::optional(	parlex::sequence({
					parlex::literal("+", U"+"),
					parlex::reference("ASM_IDENTIFIER"),
					parlex::optional(	parlex::sequence({
							parlex::literal("*", U"*"),
							parlex::reference("NON_NEG_NON_FRACTIONAL")
						})
					)
				})
			),
			parlex::optional(	parlex::sequence({
					parlex::choice ({
						parlex::literal("+", U"+"),
						parlex::literal("-", U"-")
					}),
					parlex::reference("NON_NEG_INTEGER")
				})
			),
			parlex::literal("]", U"]")
		})),
		parlex::production("ASM_SCOPE",
		parlex::repetition("ASM_SCOPE", 	parlex::choice ({
				parlex::reference("IC"),
				parlex::reference("ASM_STATEMENT")
			})
		)),
		parlex::production("ASM_STATEMENT",
		parlex::sequence("ASM_STATEMENT", {
			parlex::reference("ASM_OP"),
			parlex::optional(	parlex::sequence({
					parlex::repetition(	parlex::reference("IC")
					),
					parlex::reference("ASM_EXPRESSION"),
					parlex::repetition(	parlex::sequence({
							parlex::repetition(	parlex::reference("IC")
							),
							parlex::literal(",", U","),
							parlex::optional(	parlex::sequence({
									parlex::repetition(	parlex::reference("IC")
									),
									parlex::reference("ASM_EXPRESSION")
								})
							)
						})
					)
				})
			),
			parlex::repetition(	parlex::reference("IC")
			),
			parlex::literal("\n", U"\n")
		})),
		parlex::production("ASSIGNMENT_CHAIN",
		parlex::sequence("ASSIGNMENT_CHAIN", {
			parlex::optional(	parlex::sequence({
					parlex::reference("xml_doc_string", "XML_DOC_STRING"),
					parlex::repetition(	parlex::reference("IC")
					)
				})
			),
			parlex::reference("identifier", "IDENTIFIER"),
			parlex::repetition(	parlex::reference("IC")
			),
			parlex::choice ({
				parlex::literal("←", U"←"),
				parlex::literal("<-", U"<-")
			}),
			parlex::repetition(	parlex::reference("IC")
			),
			parlex::choice ({
				parlex::reference("expression", "EXPRESSION"),
				parlex::reference("ASSIGNMENT_CHAIN")
			})
		}),
		parlex::associativity::NONE, parlex::filter_function(), {"EXPRESSION", "LESSER_CHAIN", }),
		parlex::production("ATTRIBUTE",
		parlex::sequence("ATTRIBUTE", {
			parlex::literal("@", U"@"),
			parlex::repetition(	parlex::reference("IC")
			),
			parlex::reference("EXPRESSION"),
			parlex::repetition(	parlex::reference("IC")
			),
			parlex::literal("@", U"@")
		})),
		parlex::production("BIJECTION",
		parlex::sequence("BIJECTION", {
			parlex::reference("EXPRESSION"),
			parlex::repetition(	parlex::reference("IC")
			),
			parlex::choice ({
				parlex::literal("↔", U"↔"),
				parlex::literal("<->", U"<->")
			}),
			parlex::repetition(	parlex::reference("IC")
			),
			parlex::reference("EXPRESSION")
		}),
		parlex::associativity::ANY),
		parlex::production("BINARY_ARITHMETIC_OP",
		parlex::choice ("BINARY_ARITHMETIC_OP", {
			parlex::reference("ADD_SUB"),
			parlex::reference("ADDITION"),
			parlex::reference("DIVISION"),
			parlex::reference("EXPONENTIATION"),
			parlex::reference("INTEGER_DIVISION"),
			parlex::reference("MODULATION"),
			parlex::reference("MULTIPLICATIVE_OP"),
			parlex::reference("SHIFTL"),
			parlex::reference("SHIFTR"),
			parlex::reference("SUBTRACTION")
		})),
		parlex::production("BINARY_COLLECTION_OP",
		parlex::choice ("BINARY_COLLECTION_OP", {
			parlex::reference("BIJECTION"),
			parlex::reference("INTERSECTION"),
			parlex::reference("SYMMETRIC_DIFFERENCE"),
			parlex::reference("UNION")
		})),
		parlex::production("BINARY_LOGICAL_OP",
		parlex::choice ("BINARY_LOGICAL_OP", {
			parlex::reference("AND"),
			parlex::reference("IFF"),
			parlex::reference("IMPLICATION"),
			parlex::reference("MAPS_TO"),
			parlex::reference("NAND"),
			parlex::reference("NOR"),
			parlex::reference("OR"),
			parlex::reference("XOR")
		})),
		parlex::production("BINARY_OP",
		parlex::choice ("BINARY_OP", {
			parlex::reference("BINARY_ARITHMETIC_OP"),
			parlex::reference("BINARY_COLLECTION_OP"),
			parlex::reference("BINARY_LOGICAL_OP"),
			parlex::reference("BITWISE_OP"),
			parlex::reference("CONSTRUCTIVE_OP"),
			parlex::reference("RELATIONAL_OP")
		})),
		parlex::production("BITWISE_OP",
		parlex::choice ("BITWISE_OP", {
			parlex::reference("BIT_AND"),
			parlex::reference("BIT_OR"),
			parlex::reference("BIT_XOR")
		})),
		parlex::production("BIT_AND",
		parlex::sequence("BIT_AND", {
			parlex::reference("EXPRESSION"),
			parlex::repetition(	parlex::reference("IC")
			),
			parlex::literal("&&", U"&&"),
			parlex::repetition(	parlex::reference("IC")
			),
			parlex::reference("EXPRESSION")
		}),
		parlex::associativity::ANY),
		parlex::production("BIT_AND_ASSIGNMENT",
		parlex::sequence("BIT_AND_ASSIGNMENT", {
			parlex::reference("EXPRESSION"),
			parlex::repetition(	parlex::reference("IC")
			),
			parlex::literal("&&", U"&&"),
			parlex::choice ({
				parlex::literal("<-", U"<-"),
				parlex::literal("←", U"←")
			}),
			parlex::repetition(	parlex::reference("IC")
			),
			parlex::reference("EXPRESSION")
		})),
		parlex::production("BIT_NOT",
		parlex::sequence("BIT_NOT", {
			parlex::literal("~~", U"~~"),
			parlex::repetition(	parlex::reference("IC")
			),
			parlex::reference("EXPRESSION")
		})),
		parlex::production("BIT_NOT_ASSIGNMENT",
		parlex::sequence("BIT_NOT_ASSIGNMENT", {
			parlex::reference("EXPRESSION"),
			parlex::repetition(	parlex::reference("IC")
			),
			parlex::literal("~~", U"~~"),
			parlex::choice ({
				parlex::literal("<-", U"<-"),
				parlex::literal("←", U"←")
			})
		})),
		parlex::production("BIT_OR",
		parlex::sequence("BIT_OR", {
			parlex::reference("EXPRESSION"),
			parlex::repetition(	parlex::reference("IC")
			),
			parlex::literal("||", U"||"),
			parlex::repetition(	parlex::reference("IC")
			),
			parlex::reference("EXPRESSION")
		}),
		parlex::associativity::ANY),
		parlex::production("BIT_OR_ASSIGNMENT",
		parlex::sequence("BIT_OR_ASSIGNMENT", {
			parlex::reference("EXPRESSION"),
			parlex::repetition(	parlex::reference("IC")
			),
			parlex::literal("||", U"||"),
			parlex::choice ({
				parlex::literal("<-", U"<-"),
				parlex::literal("←", U"←")
			}),
			parlex::repetition(	parlex::reference("IC")
			),
			parlex::reference("EXPRESSION")
		})),
		parlex::production("BIT_XOR",
		parlex::sequence("BIT_XOR", {
			parlex::reference("EXPRESSION"),
			parlex::repetition(	parlex::reference("IC")
			),
			parlex::literal("^^", U"^^"),
			parlex::repetition(	parlex::reference("IC")
			),
			parlex::reference("EXPRESSION")
		}),
		parlex::associativity::ANY),
		parlex::production("BIT_XOR_ASSIGNMENT",
		parlex::sequence("BIT_XOR_ASSIGNMENT", {
			parlex::reference("EXPRESSION"),
			parlex::repetition(	parlex::reference("IC")
			),
			parlex::literal("^^", U"^^"),
			parlex::choice ({
				parlex::literal("<-", U"<-"),
				parlex::literal("←", U"←")
			}),
			parlex::repetition(	parlex::reference("IC")
			),
			parlex::reference("EXPRESSION")
		})),
		parlex::production("BLOCK",
		parlex::sequence("BLOCK", {
			parlex::literal("{", U"{"),
			parlex::reference("STATEMENT_SCOPE"),
			parlex::literal("}", U"}")
		})),
		parlex::production("BOOL",
		parlex::choice ("BOOL", {
			parlex::literal("true", U"true"),
			parlex::literal("false", U"false")
		})),
		parlex::production("BREAK",
		parlex::sequence("BREAK", {
			parlex::literal("break", U"break"),
			parlex::optional(	parlex::choice ({
					parlex::sequence({
						parlex::repetition(	parlex::reference("IC")
						),
						parlex::literal("[", U"["),
						parlex::repetition(	parlex::reference("IC")
						),
						parlex::reference("expression", "EXPRESSION"),
						parlex::repetition(	parlex::reference("IC")
						),
						parlex::literal("]", U"]")
					}),
					parlex::sequence({
						parlex::reference("IC"),
						parlex::repetition(	parlex::reference("IC")
						),
						parlex::reference("identifier", "IDENTIFIER")
					})
				})
			)
		})),
		parlex::production("CARDINALITY",
		parlex::sequence("CARDINALITY", {
			parlex::literal("#", U"#"),
			parlex::repetition(	parlex::reference("IC")
			),
			parlex::reference("EXPRESSION")
		}),
		parlex::associativity::NONE, parlex::filter_function(), {"BINARY_OP", }),
		parlex::production("CAST",
		parlex::sequence("CAST", {
			parlex::reference("PARENTHETICAL"),
			parlex::repetition(	parlex::reference("IC")
			),
			parlex::reference("EXPRESSION")
		}),
		parlex::associativity::NONE, parlex::filter_function(), {"BINARY_OP", }),
		parlex::production("CASTS",
		parlex::sequence("CASTS", {
			parlex::reference("EXPRESSION"),
			parlex::repetition(	parlex::reference("IC")
			),
			parlex::literal("casts", U"casts"),
			parlex::repetition(	parlex::reference("IC")
			),
			parlex::reference("EXPRESSION")
		})),
		parlex::production("CEILING",
		parlex::choice ("CEILING", {
			parlex::sequence({
				parlex::literal("⌈", U"⌈"),
				parlex::repetition(	parlex::reference("IC")
				),
				parlex::reference("EXPRESSION"),
				parlex::repetition(	parlex::reference("IC")
				),
				parlex::literal("⌉", U"⌉")
			}),
			parlex::sequence({
				parlex::literal("|\'", U"|\'"),
				parlex::repetition(	parlex::reference("IC")
				),
				parlex::reference("EXPRESSION"),
				parlex::repetition(	parlex::reference("IC")
				),
				parlex::literal("\'|", U"\'|")
			})
		})),
		parlex::production("COMMENT",
		parlex::sequence("COMMENT", {
			parlex::literal("/*", U"/*"),
			parlex::repetition(	parlex::reference("all")
			),
			parlex::literal("*/", U"*/")
		})),
		parlex::production("COMPLEMENT",
		parlex::sequence("COMPLEMENT", {
			parlex::reference("EXPRESSION"),
			parlex::repetition(	parlex::reference("IC")
			),
			parlex::literal("ᶜ", U"ᶜ")
		}),
		parlex::associativity::NONE, parlex::filter_function(), {"BINARY_OP", }),
		parlex::production("COMPOSITION",
		parlex::sequence("COMPOSITION", {
			parlex::reference("EXPRESSION"),
			parlex::repetition(	parlex::reference("IC")
			),
			parlex::choice ({
				parlex::literal("∘", U"∘"),
				parlex::literal("_o_", U"_o_")
			}),
			parlex::repetition(	parlex::reference("IC")
			),
			parlex::reference("EXPRESSION")
		}),
		parlex::associativity::ANY),
		parlex::production("COMPOSITION_ASSIGNMENT",
		parlex::sequence("COMPOSITION_ASSIGNMENT", {
			parlex::reference("EXPRESSION"),
			parlex::repetition(	parlex::reference("IC")
			),
			parlex::choice ({
				parlex::literal("∘", U"∘"),
				parlex::literal("_o_", U"_o_")
			}),
			parlex::choice ({
				parlex::literal("<-", U"<-"),
				parlex::literal("←", U"←")
			}),
			parlex::repetition(	parlex::reference("IC")
			),
			parlex::reference("EXPRESSION")
		})),
		parlex::production("COMPOUND",
		parlex::sequence("COMPOUND", {
			parlex::reference("EXPRESSION"),
			parlex::repetition(	parlex::reference("IC")
			),
			parlex::literal("|", U"|"),
			parlex::repetition(	parlex::reference("IC")
			),
			parlex::reference("EXPRESSION")
		}),
		parlex::associativity::LEFT),
		parlex::production("COMPOUND_ASSIGNMENT",
		parlex::sequence("COMPOUND_ASSIGNMENT", {
			parlex::reference("EXPRESSION"),
			parlex::repetition(	parlex::reference("IC")
			),
			parlex::literal("|", U"|"),
			parlex::choice ({
				parlex::literal("<-", U"<-"),
				parlex::literal("←", U"←")
			}),
			parlex::repetition(	parlex::reference("IC")
			),
			parlex::reference("EXPRESSION")
		})),
		parlex::production("CONDITIONAL",
		parlex::sequence("CONDITIONAL", {
			parlex::reference("condition", "EXPRESSION"),
			parlex::repetition(	parlex::reference("IC")
			),
			parlex::literal("\?", U"\?"),
			parlex::repetition(	parlex::reference("IC")
			),
			parlex::reference("true_case", "EXPRESSION"),
			parlex::repetition(	parlex::reference("IC")
			),
			parlex::literal(":", U":"),
			parlex::repetition(	parlex::reference("IC")
			),
			parlex::reference("false_case", "EXPRESSION")
		}),
		parlex::associativity::RIGHT),
		parlex::production("CONSTRUCTIVE_OP",
		parlex::choice ("CONSTRUCTIVE_OP", {
			parlex::reference("COMPOSITION"),
			parlex::reference("COMPOUND"),
			parlex::reference("PREPEND"),
			parlex::reference("NULL_COALESCE")
		})),
		parlex::production("CONTINUE",
		parlex::sequence("CONTINUE", {
			parlex::literal("continue", U"continue"),
			parlex::optional(	parlex::choice ({
					parlex::sequence({
						parlex::repetition(	parlex::reference("IC")
						),
						parlex::literal("[", U"["),
						parlex::repetition(	parlex::reference("IC")
						),
						parlex::reference("expression", "EXPRESSION"),
						parlex::repetition(	parlex::reference("IC")
						),
						parlex::literal("]", U"]")
					}),
					parlex::sequence({
						parlex::reference("IC"),
						parlex::repetition(	parlex::reference("IC")
						),
						parlex::reference("identifier", "IDENTIFIER")
					})
				})
			)
		})),
		parlex::production("CROSS_PRODUCT",
		parlex::sequence("CROSS_PRODUCT", {
			parlex::reference("EXPRESSION"),
			parlex::repetition(	parlex::reference("IC")
			),
			parlex::choice ({
				parlex::literal("×", U"×"),
				parlex::literal("_x_", U"_x_")
			}),
			parlex::repetition(	parlex::reference("IC")
			),
			parlex::reference("EXPRESSION")
		}),
		parlex::associativity::LEFT, parlex::filter_function(), {"DOT_PRODUCT", }),
		parlex::production("CROSS_PRODUCT_ASSIGNMENT",
		parlex::sequence("CROSS_PRODUCT_ASSIGNMENT", {
			parlex::reference("EXPRESSION"),
			parlex::repetition(	parlex::reference("IC")
			),
			parlex::choice ({
				parlex::literal("×", U"×"),
				parlex::literal("_x_", U"_x_")
			}),
			parlex::choice ({
				parlex::literal("<-", U"<-"),
				parlex::literal("←", U"←")
			}),
			parlex::repetition(	parlex::reference("IC")
			),
			parlex::reference("EXPRESSION")
		})),
		parlex::production("DATE",
		parlex::choice ("DATE", {
			parlex::reference("DATE_YEAR_MONTH_DAY"),
			parlex::reference("DATE_YEAR_DAY")
		})),
		parlex::production("DATE_TIME",
		parlex::sequence("DATE_TIME", {
			parlex::reference("DATE"),
			parlex::literal("T", U"T"),
			parlex::reference("TIME")
		})),
		parlex::production("DATE_YEAR_DAY",
		parlex::sequence("DATE_YEAR_DAY", {
			parlex::reference("decimal_digit"),
			parlex::reference("decimal_digit"),
			parlex::reference("decimal_digit"),
			parlex::reference("decimal_digit"),
			parlex::literal("-", U"-"),
			parlex::reference("decimal_digit"),
			parlex::reference("decimal_digit"),
			parlex::reference("decimal_digit")
		}),
		parlex::associativity::NONE, parlex::filter_function(), {"SUBTRACTION", }),
		parlex::production("DATE_YEAR_MONTH_DAY",
		parlex::sequence("DATE_YEAR_MONTH_DAY", {
			parlex::reference("decimal_digit"),
			parlex::reference("decimal_digit"),
			parlex::reference("decimal_digit"),
			parlex::reference("decimal_digit"),
			parlex::literal("-", U"-"),
			parlex::reference("decimal_digit"),
			parlex::reference("decimal_digit"),
			parlex::literal("-", U"-"),
			parlex::reference("decimal_digit"),
			parlex::reference("decimal_digit")
		}),
		parlex::associativity::NONE, parlex::filter_function(), {"SUBTRACTION", }),
		parlex::production("DECLARATION",
		parlex::sequence("DECLARATION", {
			parlex::optional(	parlex::sequence({
					parlex::reference("xml_doc_string", "XML_DOC_STRING"),
					parlex::repetition(	parlex::reference("IC")
					)
				})
			),
			parlex::reference("identifier", "IDENTIFIER")
		})),
		parlex::production("DEFINITION",
		parlex::sequence("DEFINITION", {
			parlex::optional(	parlex::sequence({
					parlex::reference("xml_doc_string", "XML_DOC_STRING"),
					parlex::repetition(	parlex::reference("IC")
					)
				})
			),
			parlex::reference("identifier", "IDENTIFIER"),
			parlex::repetition(	parlex::reference("IC")
			),
			parlex::literal(":=", U":="),
			parlex::repetition(	parlex::reference("IC")
			),
			parlex::reference("expression", "EXPRESSION")
		})),
		parlex::production("DELTA",
		parlex::sequence("DELTA", {
			parlex::choice ({
				parlex::literal("Δ", U"Δ"),
				parlex::literal("_delta_", U"_delta_")
			}),
			parlex::optional(	parlex::sequence({
					parlex::literal("^", U"^"),
					parlex::reference("whole_number", "WHOLE_NUMBER")
				})
			),
			parlex::reference("expression", "EXPRESSION")
		}),
		parlex::associativity::NONE, parlex::filter_function(), {"BINARY_OP", "EXPONENTIATION", }),
		parlex::production("DIMENSION",
		parlex::choice ("DIMENSION", {
			parlex::reference("IDENTIFIER"),
			parlex::reference("DIMENSIONAL_ANALYSIS_OP")
		})),
		parlex::production("DIMENSIONAL_ANALYSIS_OP",
		parlex::choice ("DIMENSIONAL_ANALYSIS_OP", {
			parlex::reference("UNIT_DIVISION"),
			parlex::reference("UNIT_EXPONENTIATION"),
			parlex::reference("UNIT_MULTIPLICATION")
		})),
		parlex::production("DIMENSIONAL_NUMBER",
		parlex::sequence("DIMENSIONAL_NUMBER", {
			parlex::reference("NON_NEG_NUMBER"),
			parlex::reference("DIMENSION")
		}),
		parlex::associativity::NONE, parlex::filter_function(), {"BINARY_OP", "EXPONENTIATION", }),
		parlex::production("DIVISION",
		parlex::sequence("DIVISION", {
			parlex::reference("EXPRESSION"),
			parlex::repetition(	parlex::reference("IC")
			),
			parlex::choice ({
				parlex::literal("÷", U"÷"),
				parlex::literal("/", U"/")
			}),
			parlex::repetition(	parlex::reference("IC")
			),
			parlex::reference("EXPRESSION")
		}),
		parlex::associativity::LEFT, parlex::filter_function(), {"ADDITION", "ADD_SUB", "INTEGER_DIVISION", "MAPS_TO", "MODULATION", "SUBTRACTION", }),
		parlex::production("DIVISION_ASSIGNMENT",
		parlex::sequence("DIVISION_ASSIGNMENT", {
			parlex::reference("EXPRESSION"),
			parlex::repetition(	parlex::reference("IC")
			),
			parlex::choice ({
				parlex::literal("÷", U"÷"),
				parlex::literal("/", U"/")
			}),
			parlex::choice ({
				parlex::literal("<-", U"<-"),
				parlex::literal("←", U"←")
			}),
			parlex::repetition(	parlex::reference("IC")
			),
			parlex::reference("EXPRESSION")
		})),
		parlex::production("DO",
		parlex::sequence("DO", {
			parlex::literal("do", U"do"),
			parlex::repetition(	parlex::reference("IC")
			),
			parlex::reference("expression", "EXPRESSION"),
			parlex::optional(	parlex::sequence({
					parlex::repetition(	parlex::reference("IC")
					),
					parlex::choice ({
						parlex::literal("while", U"while"),
						parlex::literal("until", U"until")
					}),
					parlex::repetition(	parlex::reference("IC")
					),
					parlex::reference("condition", "PARENTHETICAL")
				})
			)
		})),
		parlex::production("DOT_PRODUCT",
		parlex::sequence("DOT_PRODUCT", {
			parlex::reference("EXPRESSION"),
			parlex::repetition(	parlex::reference("IC")
			),
			parlex::choice ({
				parlex::literal("⋅", U"⋅"),
				parlex::literal("_dot_", U"_dot_")
			}),
			parlex::repetition(	parlex::reference("IC")
			),
			parlex::reference("EXPRESSION")
		}),
		parlex::associativity::LEFT),
		parlex::production("DOWNCASTS",
		parlex::sequence("DOWNCASTS", {
			parlex::reference("EXPRESSION"),
			parlex::repetition(	parlex::reference("IC")
			),
			parlex::literal("downcasts", U"downcasts"),
			parlex::repetition(	parlex::reference("IC")
			),
			parlex::reference("EXPRESSION")
		})),
		parlex::production("EMBEDDED_COMMENT",
		parlex::sequence("EMBEDDED_COMMENT", {
			parlex::literal("/***", U"/***"),
			parlex::reference("EMBEDDED_COMMENT_INTERIOR"),
			parlex::literal("***/", U"***/")
		}),
		parlex::associativity::NONE, parlex::shortest(), {"COMMENT", }),
		parlex::production("EMBEDDED_COMMENT_INTERIOR",
		parlex::choice ("EMBEDDED_COMMENT_INTERIOR", {
			parlex::reference("payload", "PAYLOAD"),
			parlex::sequence({
				parlex::literal("*", U"*"),
				parlex::reference("EMBEDDED_COMMENT_INTERIOR"),
				parlex::literal("*", U"*")
			})
		}),
		parlex::associativity::NONE, parlex::filter_function(), {"PAYLOAD", }),
		parlex::production("EMBEDDED_NEWLINE_STRING",
		parlex::sequence("EMBEDDED_NEWLINE_STRING", {
			parlex::literal("\"\"\"", U"\"\"\""),
			parlex::reference("EMBEDDED_NEWLINE_STRING_INTERIOR"),
			parlex::literal("\"\"\"", U"\"\"\"")
		}),
		parlex::associativity::NONE, parlex::shortest(), {"EMBEDDED_STRING", }),
		parlex::production("EMBEDDED_NEWLINE_STRING_INTERIOR",
		parlex::choice ("EMBEDDED_NEWLINE_STRING_INTERIOR", {
			parlex::sequence({
				parlex::literal("\n", U"\n"),
				parlex::reference("payload", "PAYLOAD"),
				parlex::literal("\n", U"\n")
			}),
			parlex::sequence({
				parlex::literal("\"", U"\""),
				parlex::reference("EMBEDDED_NEWLINE_STRING_INTERIOR"),
				parlex::literal("\"", U"\"")
			})
		}),
		parlex::associativity::NONE, parlex::filter_function(), {"PAYLOAD", }),
		parlex::production("EMBEDDED_STRING",
		parlex::sequence("EMBEDDED_STRING", {
			parlex::literal("\"\"\"", U"\"\"\""),
			parlex::reference("EMBEDDED_STRING_INTERIOR"),
			parlex::literal("\"\"\"", U"\"\"\"")
		}),
		parlex::associativity::NONE, parlex::shortest()),
		parlex::production("EMBEDDED_STRING_INTERIOR",
		parlex::choice ("EMBEDDED_STRING_INTERIOR", {
			parlex::reference("payload", "PAYLOAD"),
			parlex::sequence({
				parlex::literal("\"", U"\""),
				parlex::reference("EMBEDDED_STRING_INTERIOR"),
				parlex::literal("\"", U"\"")
			})
		}),
		parlex::associativity::NONE, parlex::filter_function(), {"PAYLOAD", }),
		parlex::production("END_OF_LINE_COMMENT",
		parlex::sequence("END_OF_LINE_COMMENT", {
			parlex::literal("//", U"//"),
			parlex::repetition(	parlex::reference("not_newline")
			),
			parlex::literal("\n", U"\n")
		})),
		parlex::production("ENUM",
		parlex::sequence("ENUM", {
			parlex::literal("enum", U"enum"),
			parlex::repetition(	parlex::reference("IC")
			),
			parlex::optional(	parlex::sequence({
					parlex::literal("inheriting", U"inheriting"),
					parlex::repetition(	parlex::reference("IC")
					),
					parlex::reference("INHERITANCE_LIST"),
					parlex::repetition(	parlex::reference("IC")
					)
				})
			),
			parlex::optional(	parlex::sequence({
					parlex::literal("implementing", U"implementing"),
					parlex::repetition(	parlex::reference("IC")
					),
					parlex::reference("INHERITANCE_LIST"),
					parlex::repetition(	parlex::reference("IC")
					)
				})
			),
			parlex::literal("{", U"{"),
			parlex::optional(	parlex::sequence({
					parlex::reference("enum_element", "ENUM_ELEMENT"),
					parlex::repetition(	parlex::sequence({
							parlex::repetition(	parlex::reference("IC")
							),
							parlex::literal(";", U";"),
							parlex::repetition(	parlex::reference("IC")
							),
							parlex::reference("enum_element", "ENUM_ELEMENT")
						})
					)
				})
			),
			parlex::literal("}", U"}")
		})),
		parlex::production("ENUM_ELEMENT",
		parlex::sequence("ENUM_ELEMENT", {
			parlex::reference("identifier", "IDENTIFIER"),
			parlex::optional(	parlex::sequence({
					parlex::repetition(	parlex::reference("IC")
					),
					parlex::literal(":=", U":="),
					parlex::repetition(	parlex::reference("IC")
					),
					parlex::reference("expression", "EXPRESSION")
				})
			)
		})),
		parlex::production("EQUALITY_CHAIN",
		parlex::sequence("EQUALITY_CHAIN", {
			parlex::reference("expression", "EXPRESSION"),
			parlex::repetition(	parlex::reference("IC")
			),
			parlex::reference("equality_chain_loop", "EQUALITY_CHAIN_LOOP")
		}),
		parlex::associativity::NONE, parlex::filter_function(), {"GREATER_CHAIN", "LESSER_CHAIN", "SUBSET_CHAIN", "SUPERSET_CHAIN", }),
		parlex::production("EQUALITY_CHAIN_LOOP",
		parlex::sequence("EQUALITY_CHAIN_LOOP", {
			parlex::literal("=", U"="),
			parlex::repetition(	parlex::reference("IC")
			),
			parlex::reference("expression", "EXPRESSION"),
			parlex::optional(	parlex::sequence({
					parlex::repetition(	parlex::reference("IC")
					),
					parlex::reference("equality_chain_loop", "EQUALITY_CHAIN_LOOP")
				})
			)
		}),
		parlex::associativity::NONE, parlex::filter_function(), {"EXPRESSION", }),
		parlex::production("EXACTLY",
		parlex::sequence("EXACTLY", {
			parlex::reference("EXPRESSION"),
			parlex::repetition(	parlex::reference("IC")
			),
			parlex::literal("exactly", U"exactly"),
			parlex::repetition(	parlex::reference("IC")
			),
			parlex::reference("EXPRESSION")
		})),
		parlex::production("EXISTS",
		parlex::sequence("EXISTS", {
			parlex::choice ({
				parlex::literal("∃", U"∃"),
				parlex::literal("exists", U"exists")
			}),
			parlex::repetition(	parlex::reference("IC")
			),
			parlex::reference("EXPRESSION")
		})),
		parlex::production("EXISTS_ONE",
		parlex::sequence("EXISTS_ONE", {
			parlex::choice ({
				parlex::literal("∃!", U"∃!"),
				parlex::literal("exists!", U"exists!")
			}),
			parlex::repetition(	parlex::reference("IC")
			),
			parlex::reference("EXPRESSION")
		})),
		parlex::production("EXPONENTIATION",
		parlex::sequence("EXPONENTIATION", {
			parlex::reference("EXPRESSION"),
			parlex::repetition(	parlex::reference("IC")
			),
			parlex::literal("^", U"^"),
			parlex::repetition(	parlex::reference("IC")
			),
			parlex::reference("EXPRESSION")
		}),
		parlex::associativity::RIGHT, parlex::filter_function(), {"ADDITION", "ADD_SUB", "DIVISION", "INTEGER_DIVISION", "MODULATION", "MULTIPLICATIVE_OP", "SUBTRACTION", }),
		parlex::production("EXPONENTIATION_ASSIGNMENT",
		parlex::sequence("EXPONENTIATION_ASSIGNMENT", {
			parlex::reference("EXPRESSION"),
			parlex::repetition(	parlex::reference("IC")
			),
			parlex::literal("^", U"^"),
			parlex::choice ({
				parlex::literal("<-", U"<-"),
				parlex::literal("←", U"←")
			}),
			parlex::repetition(	parlex::reference("IC")
			),
			parlex::reference("EXPRESSION")
		})),
		parlex::production("EXPRESSION",
		parlex::choice ("EXPRESSION", {
			parlex::reference("ARRAY"),
			parlex::reference("ASM_FUNCTION"),
			parlex::reference("BINARY_OP"),
			parlex::reference("BOOL"),
			parlex::reference("CAST"),
			parlex::reference("CEILING"),
			parlex::reference("COMPLEMENT"),
			parlex::reference("CONDITIONAL"),
			parlex::reference("DATE"),
			parlex::reference("DATE_TIME"),
			parlex::reference("DELTA"),
			parlex::reference("DIMENSIONAL_NUMBER"),
			parlex::reference("EMBEDDED_STRING"),
			parlex::reference("ENUM"),
			parlex::reference("EQUALITY_CHAIN"),
			parlex::reference("FLOOR"),
			parlex::reference("FUNCTION"),
			parlex::reference("GREATER_CHAIN"),
			parlex::reference("IDENTIFIER"),
			parlex::reference("IF"),
			parlex::reference("INVOCATION"),
			parlex::reference("LESSER_CHAIN"),
			parlex::reference("LIST"),
			parlex::reference("MAGNITUDE"),
			parlex::reference("MAP"),
			parlex::reference("MEMBER_ACCESS"),
			parlex::reference("NEAREST_INTEGER"),
			parlex::reference("NON_NEG_NUMBER"),
			parlex::reference("OBJECT"),
			parlex::reference("PARENTHETICAL"),
			parlex::reference("RANGE"),
			parlex::reference("REGEX"),
			parlex::reference("SET"),
			parlex::reference("SET_COMPREHENSION"),
			parlex::reference("SUBSET_CHAIN"),
			parlex::reference("SUPERSET_CHAIN"),
			parlex::reference("SWIZZLE"),
			parlex::reference("THIS"),
			parlex::reference("THIS_FUNC"),
			parlex::reference("THIS_TYPE"),
			parlex::reference("TIME"),
			parlex::reference("TUPLE"),
			parlex::reference("TYPE"),
			parlex::reference("UNARY_OP"),
			parlex::reference("VECTOR_NORM"),
			parlex::literal("context", U"context"),
			parlex::literal("null", U"null"),
			parlex::reference("c_string")
		})),
		parlex::production("EXTERN",
		parlex::literal("EXTERN", U"extern"),
		parlex::associativity::NONE, parlex::filter_function(), {"IDENTIFIER", }),
		parlex::production("FACTORIAL",
		parlex::sequence("FACTORIAL", {
			parlex::reference("EXPRESSION"),
			parlex::repetition(	parlex::reference("IC")
			),
			parlex::literal("!", U"!")
		}),
		parlex::associativity::NONE, parlex::filter_function(), {"BINARY_OP", }),
		parlex::production("FACTORIAL_ASSIGNMENT",
		parlex::sequence("FACTORIAL_ASSIGNMENT", {
			parlex::reference("EXPRESSION"),
			parlex::repetition(	parlex::reference("IC")
			),
			parlex::literal("!", U"!"),
			parlex::choice ({
				parlex::literal("<-", U"<-"),
				parlex::literal("←", U"←")
			})
		})),
		parlex::production("FLOOR",
		parlex::choice ("FLOOR", {
			parlex::sequence({
				parlex::literal("⌊", U"⌊"),
				parlex::repetition(	parlex::reference("IC")
				),
				parlex::reference("expression", "EXPRESSION"),
				parlex::repetition(	parlex::reference("IC")
				),
				parlex::literal("⌋", U"⌋")
			}),
			parlex::sequence({
				parlex::literal("|_", U"|_"),
				parlex::repetition(	parlex::reference("IC")
				),
				parlex::reference("expression", "EXPRESSION"),
				parlex::repetition(	parlex::reference("IC")
				),
				parlex::literal("_|", U"_|")
			})
		})),
		parlex::production("FOR",
		parlex::sequence("FOR", {
			parlex::literal("for", U"for"),
			parlex::repetition(	parlex::reference("IC")
			),
			parlex::literal("(", U"("),
			parlex::repetition(	parlex::reference("IC")
			),
			parlex::optional("initializer", 	parlex::sequence({
					parlex::reference("STATEMENT_SCOPE"),
					parlex::repetition(	parlex::reference("IC")
					)
				})
			),
			parlex::reference("condition", "EXPRESSION"),
			parlex::repetition(	parlex::reference("IC")
			),
			parlex::literal(";", U";"),
			parlex::repetition(	parlex::reference("IC")
			),
			parlex::optional("step", 	parlex::sequence({
					parlex::reference("ASSIGNMENT_CHAIN"),
					parlex::repetition(	parlex::sequence({
							parlex::repetition(	parlex::reference("IC")
							),
							parlex::literal(",", U","),
							parlex::repetition(	parlex::reference("IC")
							),
							parlex::reference("ASSIGNMENT_CHAIN")
						})
					),
					parlex::repetition(	parlex::reference("IC")
					)
				})
			),
			parlex::literal(")", U")"),
			parlex::repetition(	parlex::reference("IC")
			),
			parlex::reference("EXPRESSION")
		})),
		parlex::production("FOR_COLLECTION",
		parlex::sequence("FOR_COLLECTION", {
			parlex::literal("for", U"for"),
			parlex::repetition(	parlex::reference("IC")
			),
			parlex::literal("(", U"("),
			parlex::repetition(	parlex::reference("IC")
			),
			parlex::choice ({
				parlex::sequence("declaration", {
					parlex::optional(	parlex::sequence({
							parlex::choice ({
								parlex::reference("TYPE_DEREFERENCE"),
								parlex::reference("IMPLICIT_TYPE_DEREFERENCE")
							}),
							parlex::repetition(	parlex::reference("IC")
							)
						})
					),
					parlex::reference("IDENTIFIER")
				}),
				parlex::reference("expression", "EXPRESSION")
			}),
			parlex::repetition(	parlex::reference("IC")
			),
			parlex::choice ({
				parlex::literal("in", U"in"),
				parlex::literal("∈", U"∈")
			}),
			parlex::repetition(	parlex::reference("IC")
			),
			parlex::reference("collection", "EXPRESSION"),
			parlex::repetition(	parlex::reference("IC")
			),
			parlex::literal(")", U")"),
			parlex::repetition(	parlex::reference("IC")
			),
			parlex::reference("invoke", "EXPRESSION")
		})),
		parlex::production("FREE",
		parlex::sequence("FREE", {
			parlex::literal("free", U"free"),
			parlex::repetition(	parlex::reference("IC")
			),
			parlex::reference("EXPRESSION")
		})),
		parlex::production("FUNCTION",
		parlex::sequence("FUNCTION", {
			parlex::optional(	parlex::sequence({
					parlex::literal("(", U"("),
					parlex::repetition(	parlex::reference("IC")
					),
					parlex::optional(	parlex::sequence({
							parlex::reference("parameter", "PARAMETER"),
							parlex::repetition(	parlex::sequence({
									parlex::repetition(	parlex::reference("IC")
									),
									parlex::literal(",", U","),
									parlex::repetition(	parlex::reference("IC")
									),
									parlex::reference("parameter", "PARAMETER")
								})
							),
							parlex::repetition(	parlex::reference("IC")
							)
						})
					),
					parlex::literal(")", U")"),
					parlex::repetition(	parlex::reference("IC")
					)
				})
			),
			parlex::optional(	parlex::sequence({
					parlex::reference("FUNCTION_MODIFIER_0"),
					parlex::repetition(	parlex::reference("IC")
					)
				})
			),
			parlex::reference("block", "BLOCK")
		}),
		parlex::associativity::NONE, parlex::filter_function(), {"CAST", }),
		parlex::production("FUNCTION_MODIFIER_0",
		parlex::choice ("FUNCTION_MODIFIER_0", {
			parlex::reference("FUNCTION_MODIFIER_STABILITY"),
			parlex::reference("FUNCTION_MODIFIER_1")
		})),
		parlex::production("FUNCTION_MODIFIER_1",
		parlex::choice ("FUNCTION_MODIFIER_1", {
			parlex::reference("FUNCTION_MODIFIER_THROWING"),
			parlex::reference("FUNCTION_MODIFIER_2")
		})),
		parlex::production("FUNCTION_MODIFIER_2",
		parlex::choice ("FUNCTION_MODIFIER_2", {
			parlex::reference("FUNCTION_MODIFIER_ATOMIC"),
			parlex::reference("FUNCTION_MODIFIER_3")
		})),
		parlex::production("FUNCTION_MODIFIER_3",
		parlex::choice ("FUNCTION_MODIFIER_3", {
			parlex::reference("FUNCTION_MODIFIER_PLATFORM"),
			parlex::reference("FUNCTION_MODIFIER_4")
		})),
		parlex::production("FUNCTION_MODIFIER_4",
		parlex::choice ("FUNCTION_MODIFIER_4", {
			parlex::reference("FUNCTION_MODIFIER_MODEL"),
			parlex::reference("FUNCTION_MODIFIER_CALLING_CONVENTION")
		})),
		parlex::production("FUNCTION_MODIFIER_ATOMIC",
		parlex::sequence("FUNCTION_MODIFIER_ATOMIC", {
			parlex::literal("atomic", U"atomic"),
			parlex::optional(	parlex::sequence({
					parlex::reference("IC"),
					parlex::repetition(	parlex::reference("IC")
					),
					parlex::reference("FUNCTION_MODIFIER_3")
				})
			)
		})),
		parlex::production("FUNCTION_MODIFIER_CALLING_CONVENTION",
		parlex::choice ("FUNCTION_MODIFIER_CALLING_CONVENTION", {
			parlex::literal("c_call", U"c_call"),
			parlex::literal("fast_call", U"fast_call"),
			parlex::literal("cold_call", U"cold_call"),
			parlex::literal("ghc_call", U"ghc_call"),
			parlex::literal("hipe_call", U"hipe_call"),
			parlex::literal("webkit_js_call", U"webkit_js_call"),
			parlex::literal("any_reg_call", U"any_reg_call"),
			parlex::literal("preserve_most_call", U"preserve_most_call"),
			parlex::literal("preserve_all_call", U"preserve_all_call"),
			parlex::literal("swift_call", U"swift_call"),
			parlex::literal("cxx_fast_tls_call", U"cxx_fast_tls_call"),
			parlex::literal("first_target_call", U"first_target_call"),
			parlex::literal("x86_std_call", U"x86_std_call"),
			parlex::literal("X86_fast_call", U"X86_fast_call"),
			parlex::literal("arm_apcs_call", U"arm_apcs_call"),
			parlex::literal("arm_aapcs_call", U"arm_aapcs_call"),
			parlex::literal("arm_aapcs_vfp_call", U"arm_aapcs_vfp_call"),
			parlex::literal("msp430_intr_call", U"msp430_intr_call"),
			parlex::literal("x86_this_call", U"x86_this_call"),
			parlex::literal("ptx_kernel_call", U"ptx_kernel_call"),
			parlex::literal("ptx_device_call", U"ptx_device_call"),
			parlex::literal("spir_func_call", U"spir_func_call"),
			parlex::literal("spir_kernel_call", U"spir_kernel_call"),
			parlex::literal("intel_ocl_bi_call", U"intel_ocl_bi_call"),
			parlex::literal("x86_64_sysv_call", U"x86_64_sysv_call"),
			parlex::literal("x86_64_win64_call", U"x86_64_win64_call"),
			parlex::literal("x86_vector_call", U"x86_vector_call"),
			parlex::literal("hhvm_call", U"hhvm_call"),
			parlex::literal("x86_intr_call", U"x86_intr_call"),
			parlex::literal("avr_intr_call", U"avr_intr_call"),
			parlex::literal("avr_signal_call", U"avr_signal_call"),
			parlex::literal("avr_builtin_call", U"avr_builtin_call")
		})),
		parlex::production("FUNCTION_MODIFIER_MODEL",
		parlex::sequence("FUNCTION_MODIFIER_MODEL", {
			parlex::choice ("model", {
				parlex::literal("pure", U"pure"),
				parlex::literal("imperative", U"imperative"),
				parlex::literal("opaque", U"opaque")
			}),
			parlex::optional(	parlex::sequence({
					parlex::reference("IC"),
					parlex::repetition(	parlex::reference("IC")
					),
					parlex::reference("FUNCTION_MODIFIER_CALLING_CONVENTION")
				})
			)
		})),
		parlex::production("FUNCTION_MODIFIER_PLATFORM",
		parlex::sequence("FUNCTION_MODIFIER_PLATFORM", {
			parlex::reference("PLATFORM"),
			parlex::repetition(	parlex::sequence({
					parlex::reference("IC"),
					parlex::repetition(	parlex::reference("IC")
					),
					parlex::reference("PLATFORM")
				})
			),
			parlex::optional(	parlex::sequence({
					parlex::reference("IC"),
					parlex::repetition(	parlex::reference("IC")
					),
					parlex::reference("FUNCTION_MODIFIER_4")
				})
			)
		})),
		parlex::production("FUNCTION_MODIFIER_STABILITY",
		parlex::sequence("FUNCTION_MODIFIER_STABILITY", {
			parlex::choice ("stability", {
				parlex::literal("stable", U"stable"),
				parlex::literal("unstable", U"unstable")
			}),
			parlex::optional(	parlex::sequence({
					parlex::reference("IC"),
					parlex::repetition(	parlex::reference("IC")
					),
					parlex::reference("FUNCTION_MODIFIER_1")
				})
			)
		})),
		parlex::production("FUNCTION_MODIFIER_THROWING",
		parlex::sequence("FUNCTION_MODIFIER_THROWING", {
			parlex::literal("throwing", U"throwing"),
			parlex::optional(	parlex::sequence({
					parlex::repetition(	parlex::reference("IC")
					),
					parlex::reference("ARRAY")
				})
			),
			parlex::optional(	parlex::sequence({
					parlex::reference("IC"),
					parlex::repetition(	parlex::reference("IC")
					),
					parlex::reference("FUNCTION_MODIFIER_2")
				})
			)
		})),
		parlex::production("GREATER_CHAIN",
		parlex::sequence("GREATER_CHAIN", {
			parlex::reference("expression", "EXPRESSION"),
			parlex::repetition(	parlex::reference("IC")
			),
			parlex::reference("greater_chain_loop", "GREATER_CHAIN_LOOP")
		})),
		parlex::production("GREATER_CHAIN_LOOP",
		parlex::sequence("GREATER_CHAIN_LOOP", {
			parlex::choice ({
				parlex::literal("=", U"="),
				parlex::literal(">", U">"),
				parlex::literal("=>", U"=>"),
				parlex::literal("≥", U"≥")
			}),
			parlex::repetition(	parlex::reference("IC")
			),
			parlex::reference("expression", "EXPRESSION"),
			parlex::optional(	parlex::sequence({
					parlex::repetition(	parlex::reference("IC")
					),
					parlex::reference("greater_chain_loop", "GREATER_CHAIN_LOOP")
				})
			)
		})),
		parlex::production("HAS",
		parlex::sequence("HAS", {
			parlex::reference("EXPRESSION"),
			parlex::repetition(	parlex::reference("IC")
			),
			parlex::choice ({
				parlex::literal("∋", U"∋"),
				parlex::literal("has", U"has")
			}),
			parlex::repetition(	parlex::reference("IC")
			),
			parlex::reference("EXPRESSION")
		}),
		parlex::associativity::LEFT),
		parlex::production("HEX",
		parlex::sequence("HEX", {
			parlex::literal("0x", U"0x"),
			parlex::reference("hexadecimal_digit"),
			parlex::repetition(	parlex::reference("hexadecimal_digit")
			)
		})),
		parlex::production("IC",
		parlex::choice ("IC", {
			parlex::reference("COMMENT"),
			parlex::reference("EMBEDDED_COMMENT"),
			parlex::reference("END_OF_LINE_COMMENT"),
			parlex::reference("WS")
		})),
		parlex::production("IDENTIFIER",
		parlex::sequence("IDENTIFIER", {
			parlex::choice ("head", {
				parlex::reference("letter"),
				parlex::literal("_", U"_")
			}),
			parlex::repetition("tail", 	parlex::choice ({
					parlex::reference("letter"),
					parlex::reference("number"),
					parlex::literal("_", U"_")
				})
			)
		}),
		parlex::associativity::NONE, parlex::longest(), {"ALL", }),
		parlex::production("IF",
		parlex::sequence("IF", {
			parlex::literal("if", U"if"),
			parlex::repetition(	parlex::reference("IC")
			),
			parlex::reference("condition", "PARENTHETICAL"),
			parlex::repetition(	parlex::reference("IC")
			),
			parlex::reference("invoke", "EXPRESSION"),
			parlex::repetition(	parlex::sequence({
					parlex::repetition(	parlex::reference("IC")
					),
					parlex::literal("elif", U"elif"),
					parlex::repetition(	parlex::reference("IC")
					),
					parlex::reference("condition", "PARENTHETICAL"),
					parlex::repetition(	parlex::reference("IC")
					),
					parlex::reference("invoke", "EXPRESSION")
				})
			),
			parlex::optional(	parlex::sequence({
					parlex::repetition(	parlex::reference("IC")
					),
					parlex::literal("else", U"else"),
					parlex::repetition(	parlex::reference("IC")
					),
					parlex::reference("else_invoke", "EXPRESSION")
				})
			)
		})),
		parlex::production("IFF",
		parlex::sequence("IFF", {
			parlex::reference("EXPRESSION"),
			parlex::repetition(	parlex::reference("IC")
			),
			parlex::choice ({
				parlex::literal("⇔", U"⇔"),
				parlex::literal("<=>", U"<=>")
			}),
			parlex::repetition(	parlex::reference("IC")
			),
			parlex::reference("EXPRESSION")
		}),
		parlex::associativity::ANY),
		parlex::production("IMPLEMENTS",
		parlex::sequence("IMPLEMENTS", {
			parlex::reference("EXPRESSION"),
			parlex::repetition(	parlex::reference("IC")
			),
			parlex::literal("implements", U"implements"),
			parlex::repetition(	parlex::reference("IC")
			),
			parlex::reference("EXPRESSION")
		})),
		parlex::production("IMPLICATION",
		parlex::sequence("IMPLICATION", {
			parlex::reference("EXPRESSION"),
			parlex::repetition(	parlex::reference("IC")
			),
			parlex::choice ({
				parlex::literal("⇒", U"⇒"),
				parlex::literal("=>", U"=>")
			}),
			parlex::repetition(	parlex::reference("IC")
			),
			parlex::reference("EXPRESSION")
		}),
		parlex::associativity::RIGHT, parlex::filter_function(), {"IFF", "XOR", }),
		parlex::production("IMPLICATION_ASSIGNMENT",
		parlex::sequence("IMPLICATION_ASSIGNMENT", {
			parlex::reference("EXPRESSION"),
			parlex::repetition(	parlex::reference("IC")
			),
			parlex::choice ({
				parlex::literal("⇒", U"⇒"),
				parlex::literal("=>", U"=>")
			}),
			parlex::choice ({
				parlex::literal("<-", U"<-"),
				parlex::literal("←", U"←")
			}),
			parlex::repetition(	parlex::reference("IC")
			),
			parlex::reference("EXPRESSION")
		})),
		parlex::production("IMPLICIT_TYPE_DEREFERENCE",
		parlex::sequence("IMPLICIT_TYPE_DEREFERENCE", {
			parlex::literal("<", U"<"),
			parlex::repetition(	parlex::reference("IC")
			),
			parlex::literal(">", U">")
		})),
		parlex::production("IMPORT",
		parlex::sequence("IMPORT", {
			parlex::literal("import", U"import"),
			parlex::repetition(	parlex::reference("IC")
			),
			parlex::reference("EXPRESSION")
		})),
		parlex::production("IN",
		parlex::sequence("IN", {
			parlex::reference("EXPRESSION"),
			parlex::repetition(	parlex::reference("IC")
			),
			parlex::choice ({
				parlex::literal("∈", U"∈"),
				parlex::literal("in", U"in")
			}),
			parlex::repetition(	parlex::reference("IC")
			),
			parlex::reference("EXPRESSION")
		}),
		parlex::associativity::LEFT),
		parlex::production("INEQUALITY",
		parlex::sequence("INEQUALITY", {
			parlex::reference("EXPRESSION"),
			parlex::repetition(	parlex::reference("IC")
			),
			parlex::choice ({
				parlex::literal("≠", U"≠"),
				parlex::literal("/=", U"/=")
			}),
			parlex::repetition(	parlex::reference("IC")
			),
			parlex::reference("EXPRESSION")
		}),
		parlex::associativity::LEFT),
		parlex::production("INHERITANCE_ITEM_PREFIX",
		parlex::sequence("INHERITANCE_ITEM_PREFIX", {
			parlex::choice ({
				parlex::reference("VISIBILITY_MODIFIER"),
				parlex::sequence({
					parlex::reference("VISIBILITY_MODIFIER"),
					parlex::reference("IC"),
					parlex::repetition(	parlex::reference("IC")
					),
					parlex::literal("diamond", U"diamond")
				}),
				parlex::literal("diamond", U"diamond")
			}),
			parlex::reference("IC"),
			parlex::repetition(	parlex::reference("IC")
			)
		})),
		parlex::production("INHERITANCE_LIST",
		parlex::sequence("INHERITANCE_LIST", {
			parlex::optional(	parlex::reference("INHERITANCE_ITEM_PREFIX")
			),
			parlex::reference("expression", "EXPRESSION"),
			parlex::repetition(	parlex::sequence({
					parlex::repetition(	parlex::reference("IC")
					),
					parlex::literal(",", U","),
					parlex::repetition(	parlex::reference("IC")
					),
					parlex::optional(	parlex::reference("INHERITANCE_ITEM_PREFIX")
					),
					parlex::reference("expression", "EXPRESSION")
				})
			)
		})),
		parlex::production("INHERITS",
		parlex::sequence("INHERITS", {
			parlex::reference("EXPRESSION"),
			parlex::repetition(	parlex::reference("IC")
			),
			parlex::literal("inherits", U"inherits"),
			parlex::repetition(	parlex::reference("IC")
			),
			parlex::reference("EXPRESSION")
		})),
		parlex::production("INTEGER_DIVISION",
		parlex::sequence("INTEGER_DIVISION", {
			parlex::reference("EXPRESSION"),
			parlex::repetition(	parlex::reference("IC")
			),
			parlex::literal("\\", U"\\"),
			parlex::repetition(	parlex::reference("IC")
			),
			parlex::reference("EXPRESSION")
		}),
		parlex::associativity::LEFT, parlex::filter_function(), {"ADDITION", "ADD_SUB", "SUBTRACTION", }),
		parlex::production("INTEGER_DIVISION_ASSIGNMENT",
		parlex::sequence("INTEGER_DIVISION_ASSIGNMENT", {
			parlex::reference("EXPRESSION"),
			parlex::repetition(	parlex::reference("IC")
			),
			parlex::literal("\\", U"\\"),
			parlex::choice ({
				parlex::literal("<-", U"<-"),
				parlex::literal("←", U"←")
			}),
			parlex::repetition(	parlex::reference("IC")
			),
			parlex::reference("EXPRESSION")
		})),
		parlex::production("INTERSECTION",
		parlex::sequence("INTERSECTION", {
			parlex::reference("EXPRESSION"),
			parlex::repetition(	parlex::reference("IC")
			),
			parlex::literal("∩", U"∩"),
			parlex::repetition(	parlex::reference("IC")
			),
			parlex::reference("EXPRESSION")
		}),
		parlex::associativity::ANY),
		parlex::production("INTERSECTION_ASSIGNMENT",
		parlex::sequence("INTERSECTION_ASSIGNMENT", {
			parlex::reference("EXPRESSION"),
			parlex::repetition(	parlex::reference("IC")
			),
			parlex::literal("∩", U"∩"),
			parlex::choice ({
				parlex::literal("<-", U"<-"),
				parlex::literal("←", U"←")
			}),
			parlex::repetition(	parlex::reference("IC")
			),
			parlex::reference("EXPRESSION")
		})),
		parlex::production("INVOCATION",
		parlex::choice ("INVOCATION", {
			parlex::reference("PARENTHETICAL_INVOCATION"),
			parlex::reference("ARRAY_INVOCATION"),
			parlex::reference("TYPE_INVOCATION")
		}),
		parlex::associativity::NONE, parlex::filter_function(), {"BINARY_OP", "NEGATION", "RADICAL", }),
		parlex::production("IS",
		parlex::sequence("IS", {
			parlex::reference("EXPRESSION"),
			parlex::repetition(	parlex::reference("IC")
			),
			parlex::literal("is", U"is"),
			parlex::repetition(	parlex::reference("IC")
			),
			parlex::reference("EXPRESSION")
		})),
		parlex::production("KLEENE_STAR",
		parlex::sequence("KLEENE_STAR", {
			parlex::reference("EXPRESSION"),
			parlex::repetition(	parlex::reference("IC")
			),
			parlex::literal("*", U"*")
		})),
		parlex::production("LESSER_CHAIN",
		parlex::sequence("LESSER_CHAIN", {
			parlex::reference("EXPRESSION"),
			parlex::repetition(	parlex::reference("IC")
			),
			parlex::reference("LESSER_CHAIN_LOOP")
		})),
		parlex::production("LESSER_CHAIN_LOOP",
		parlex::sequence("LESSER_CHAIN_LOOP", {
			parlex::choice ({
				parlex::literal("=", U"="),
				parlex::literal("<", U"<"),
				parlex::literal("=<", U"=<"),
				parlex::literal("≤", U"≤")
			}),
			parlex::repetition(	parlex::reference("IC")
			),
			parlex::reference("EXPRESSION"),
			parlex::optional(	parlex::sequence({
					parlex::repetition(	parlex::reference("IC")
					),
					parlex::reference("LESSER_CHAIN_LOOP")
				})
			)
		})),
		parlex::production("LIST",
		parlex::sequence("LIST", {
			parlex::literal("[|", U"[|"),
			parlex::repetition(	parlex::reference("IC")
			),
			parlex::optional("elements", 	parlex::sequence({
					parlex::reference("EXPRESSION"),
					parlex::repetition(	parlex::sequence({
							parlex::repetition(	parlex::reference("IC")
							),
							parlex::literal(", ", U", "),
							parlex::repetition(	parlex::reference("IC")
							),
							parlex::reference("EXPRESSION")
						})
					),
					parlex::repetition(	parlex::reference("IC")
					)
				})
			),
			parlex::literal("|]", U"|]")
		})),
		parlex::production("LOCK",
		parlex::sequence("LOCK", {
			parlex::literal("lock", U"lock"),
			parlex::repetition(	parlex::reference("IC")
			),
			parlex::reference("PARENTHETICAL"),
			parlex::repetition(	parlex::reference("IC")
			),
			parlex::reference("BLOCK")
		})),
		parlex::production("LOOP",
		parlex::sequence("LOOP", {
			parlex::choice ({
				parlex::literal("while", U"while"),
				parlex::literal("until", U"until")
			}),
			parlex::repetition(	parlex::reference("IC")
			),
			parlex::reference("PARENTHETICAL"),
			parlex::repetition(	parlex::reference("IC")
			),
			parlex::reference("EXPRESSION")
		})),
		parlex::production("MAGNITUDE",
		parlex::sequence("MAGNITUDE", {
			parlex::literal("|", U"|"),
			parlex::repetition(	parlex::reference("IC")
			),
			parlex::reference("EXPRESSION"),
			parlex::repetition(	parlex::reference("IC")
			),
			parlex::literal("|", U"|")
		})),
		parlex::production("MAP",
		parlex::sequence("MAP", {
			parlex::literal("{", U"{"),
			parlex::optional(	parlex::sequence({
					parlex::repetition(	parlex::reference("IC")
					),
					parlex::reference("EXPRESSION"),
					parlex::repetition(	parlex::reference("IC")
					),
					parlex::literal(":", U":"),
					parlex::repetition(	parlex::reference("IC")
					),
					parlex::reference("EXPRESSION"),
					parlex::repetition(	parlex::sequence({
							parlex::repetition(	parlex::reference("IC")
							),
							parlex::literal(",", U","),
							parlex::repetition(	parlex::reference("IC")
							),
							parlex::reference("EXPRESSION"),
							parlex::repetition(	parlex::reference("IC")
							),
							parlex::literal(":", U":"),
							parlex::repetition(	parlex::reference("IC")
							),
							parlex::reference("EXPRESSION")
						})
					)
				})
			),
			parlex::repetition(	parlex::reference("IC")
			),
			parlex::literal("}", U"}")
		}),
		parlex::associativity::NONE, parlex::filter_function(), {"FUNCTION", }),
		parlex::production("MAPS_TO",
		parlex::sequence("MAPS_TO", {
			parlex::reference("EXPRESSION"),
			parlex::repetition(	parlex::reference("IC")
			),
			parlex::choice ({
				parlex::literal("→", U"→"),
				parlex::literal("->", U"->")
			}),
			parlex::repetition(	parlex::reference("IC")
			),
			parlex::reference("EXPRESSION")
		}),
		parlex::associativity::RIGHT),
		parlex::production("MEMBER_ACCESS",
		parlex::sequence("MEMBER_ACCESS", {
			parlex::reference("EXPRESSION"),
			parlex::repetition(	parlex::reference("IC")
			),
			parlex::literal(".", U"."),
			parlex::repetition(	parlex::reference("IC")
			),
			parlex::reference("IDENTIFIER")
		}),
		parlex::associativity::LEFT),
		parlex::production("MEMBER_OFFSET",
		parlex::sequence("MEMBER_OFFSET", {
			parlex::literal("@", U"@"),
			parlex::repetition(	parlex::reference("IC")
			),
			parlex::reference("WHOLE_NUMBER")
		})),
		parlex::production("MODULATION",
		parlex::sequence("MODULATION", {
			parlex::reference("EXPRESSION"),
			parlex::repetition(	parlex::reference("IC")
			),
			parlex::literal("%", U"%"),
			parlex::repetition(	parlex::reference("IC")
			),
			parlex::reference("EXPRESSION")
		}),
		parlex::associativity::LEFT, parlex::filter_function(), {"ADDITION", "ADD_SUB", "SUBTRACTION", }),
		parlex::production("MODULATION_ASSIGNMENT",
		parlex::sequence("MODULATION_ASSIGNMENT", {
			parlex::reference("EXPRESSION"),
			parlex::repetition(	parlex::reference("IC")
			),
			parlex::literal("%", U"%"),
			parlex::choice ({
				parlex::literal("<-", U"<-"),
				parlex::literal("←", U"←")
			}),
			parlex::repetition(	parlex::reference("IC")
			),
			parlex::reference("EXPRESSION")
		})),
		parlex::production("MULTIPLICATION",
		parlex::sequence("MULTIPLICATION", {
			parlex::reference("EXPRESSION"),
			parlex::repetition(	parlex::reference("IC")
			),
			parlex::literal("*", U"*"),
			parlex::repetition(	parlex::reference("IC")
			),
			parlex::reference("EXPRESSION")
		}),
		parlex::associativity::ANY),
		parlex::production("MULTIPLICATION_ASSIGNMENT",
		parlex::sequence("MULTIPLICATION_ASSIGNMENT", {
			parlex::reference("EXPRESSION"),
			parlex::repetition(	parlex::reference("IC")
			),
			parlex::literal("*", U"*"),
			parlex::choice ({
				parlex::literal("<-", U"<-"),
				parlex::literal("←", U"←")
			}),
			parlex::repetition(	parlex::reference("IC")
			),
			parlex::reference("EXPRESSION")
		})),
		parlex::production("MULTIPLICATIVE_OP",
		parlex::choice ("MULTIPLICATIVE_OP", {
			parlex::reference("CROSS_PRODUCT"),
			parlex::reference("DOT_PRODUCT"),
			parlex::reference("MULTIPLICATION")
		}),
		parlex::associativity::NONE, parlex::filter_function(), {"ADDITION", "ADD_SUB", "INTEGER_DIVISION", "MAPS_TO", "MODULATION", "SUBTRACTION", }),
		parlex::production("NAND",
		parlex::sequence("NAND", {
			parlex::reference("EXPRESSION"),
			parlex::repetition(	parlex::reference("IC")
			),
			parlex::choice ({
				parlex::literal("↑", U"↑"),
				parlex::literal("nand", U"nand")
			}),
			parlex::repetition(	parlex::reference("IC")
			),
			parlex::reference("EXPRESSION")
		}),
		parlex::associativity::LEFT, parlex::filter_function(), {"IFF", "IMPLICATION", "OR", "XOR", }),
		parlex::production("NAND_ASSIGNMENT",
		parlex::sequence("NAND_ASSIGNMENT", {
			parlex::reference("EXPRESSION"),
			parlex::repetition(	parlex::reference("IC")
			),
			parlex::choice ({
				parlex::literal("↑", U"↑"),
				parlex::literal("nand", U"nand")
			}),
			parlex::choice ({
				parlex::literal("<-", U"<-"),
				parlex::literal("←", U"←")
			}),
			parlex::repetition(	parlex::reference("IC")
			),
			parlex::reference("EXPRESSION")
		})),
		parlex::production("NEAREST_INTEGER",
		parlex::choice ("NEAREST_INTEGER", {
			parlex::sequence({
				parlex::literal("⌊", U"⌊"),
				parlex::repetition(	parlex::reference("IC")
				),
				parlex::reference("EXPRESSION"),
				parlex::repetition(	parlex::reference("IC")
				),
				parlex::literal("⌉", U"⌉")
			}),
			parlex::sequence({
				parlex::literal("|_", U"|_"),
				parlex::repetition(	parlex::reference("IC")
				),
				parlex::reference("EXPRESSION"),
				parlex::repetition(	parlex::reference("IC")
				),
				parlex::literal("\'|", U"\'|")
			})
		})),
		parlex::production("NEGATION",
		parlex::sequence("NEGATION", {
			parlex::literal("-", U"-"),
			parlex::repetition(	parlex::reference("IC")
			),
			parlex::reference("EXPRESSION")
		}),
		parlex::associativity::NONE, parlex::filter_function(), {"BINARY_OP", }),
		parlex::production("NEGATION_ASSIGNMENT",
		parlex::sequence("NEGATION_ASSIGNMENT", {
			parlex::reference("EXPRESSION"),
			parlex::repetition(	parlex::reference("IC")
			),
			parlex::literal("-", U"-"),
			parlex::choice ({
				parlex::literal("<-", U"<-"),
				parlex::literal("←", U"←")
			})
		})),
		parlex::production("NON_FRACTIONAL",
		parlex::sequence("NON_FRACTIONAL", {
			parlex::optional(	parlex::literal("-", U"-")
			),
			parlex::reference("NON_NEG_NON_FRACTIONAL")
		})),
		parlex::production("NON_NEG_FRACTIONAL",
		parlex::choice ("NON_NEG_FRACTIONAL", {
			parlex::sequence({
				parlex::reference("decimal_digit"),
				parlex::repetition(	parlex::reference("decimal_digit")
				),
				parlex::literal(".", U"."),
				parlex::repetition(	parlex::reference("decimal_digit")
				)
			}),
			parlex::sequence({
				parlex::literal(".", U"."),
				parlex::reference("decimal_digit"),
				parlex::repetition(	parlex::reference("decimal_digit")
				)
			})
		})),
		parlex::production("NON_NEG_INTEGER",
		parlex::choice ("NON_NEG_INTEGER", {
			parlex::sequence({
				parlex::reference("NON_ZERO_DECIMAL_DIGIT"),
				parlex::repetition(	parlex::reference("decimal_digit")
				)
			}),
			parlex::literal("0", U"0")
		})),
		parlex::production("NON_NEG_NON_FRACTIONAL",
		parlex::choice ("NON_NEG_NON_FRACTIONAL", {
			parlex::reference("NON_NEG_INTEGER"),
			parlex::reference("HEX"),
			parlex::reference("OCTAL")
		})),
		parlex::production("NON_NEG_NUMBER",
		parlex::choice ("NON_NEG_NUMBER", {
			parlex::reference("NON_NEG_NON_FRACTIONAL"),
			parlex::reference("NON_NEG_FRACTIONAL")
		})),
		parlex::production("NON_ZERO_DECIMAL_DIGIT",
		parlex::choice ("NON_ZERO_DECIMAL_DIGIT", {
			parlex::literal("1", U"1"),
			parlex::literal("2", U"2"),
			parlex::literal("3", U"3"),
			parlex::literal("4", U"4"),
			parlex::literal("5", U"5"),
			parlex::literal("6", U"6"),
			parlex::literal("7", U"7"),
			parlex::literal("8", U"8"),
			parlex::literal("9", U"9")
		})),
		parlex::production("NOR",
		parlex::sequence("NOR", {
			parlex::reference("EXPRESSION"),
			parlex::repetition(	parlex::reference("IC")
			),
			parlex::choice ({
				parlex::literal("↓", U"↓"),
				parlex::literal("nor", U"nor")
			}),
			parlex::repetition(	parlex::reference("IC")
			),
			parlex::reference("EXPRESSION")
		}),
		parlex::associativity::LEFT, parlex::filter_function(), {"IFF", "IMPLICATION", "OR", "XOR", }),
		parlex::production("NOR_ASSIGNMENT",
		parlex::sequence("NOR_ASSIGNMENT", {
			parlex::reference("EXPRESSION"),
			parlex::repetition(	parlex::reference("IC")
			),
			parlex::choice ({
				parlex::literal("↓", U"↓"),
				parlex::literal("nor", U"nor")
			}),
			parlex::choice ({
				parlex::literal("<-", U"<-"),
				parlex::literal("←", U"←")
			}),
			parlex::repetition(	parlex::reference("IC")
			),
			parlex::reference("EXPRESSION")
		})),
		parlex::production("NOT",
		parlex::sequence("NOT", {
			parlex::choice ({
				parlex::literal("¬", U"¬"),
				parlex::literal("~", U"~")
			}),
			parlex::repetition(	parlex::reference("IC")
			),
			parlex::reference("EXPRESSION")
		}),
		parlex::associativity::NONE, parlex::filter_function(), {"BINARY_OP", }),
		parlex::production("NOT_ASSIGNMENT",
		parlex::sequence("NOT_ASSIGNMENT", {
			parlex::reference("EXPRESSION"),
			parlex::repetition(	parlex::reference("IC")
			),
			parlex::choice ({
				parlex::literal("¬", U"¬"),
				parlex::literal("~", U"~")
			}),
			parlex::choice ({
				parlex::literal("<-", U"<-"),
				parlex::literal("←", U"←")
			})
		})),
		parlex::production("NOT_HAS",
		parlex::sequence("NOT_HAS", {
			parlex::reference("EXPRESSION"),
			parlex::repetition(	parlex::reference("IC")
			),
			parlex::choice ({
				parlex::literal("∌", U"∌"),
				parlex::literal("/has", U"/has")
			}),
			parlex::repetition(	parlex::reference("IC")
			),
			parlex::reference("EXPRESSION")
		}),
		parlex::associativity::LEFT),
		parlex::production("NOT_IN",
		parlex::sequence("NOT_IN", {
			parlex::reference("EXPRESSION"),
			parlex::repetition(	parlex::reference("IC")
			),
			parlex::choice ({
				parlex::literal("∉", U"∉"),
				parlex::literal("/in", U"/in")
			}),
			parlex::repetition(	parlex::reference("IC")
			),
			parlex::reference("EXPRESSION")
		}),
		parlex::associativity::LEFT),
		parlex::production("NULL_COALESCE",
		parlex::sequence("NULL_COALESCE", {
			parlex::reference("EXPRESSION"),
			parlex::repetition(	parlex::reference("IC")
			),
			parlex::literal("\?\?", U"\?\?"),
			parlex::repetition(	parlex::reference("IC")
			),
			parlex::reference("EXPRESSION")
		}),
		parlex::associativity::LEFT),
		parlex::production("NULL_COALESCE_ASSIGNMENT",
		parlex::sequence("NULL_COALESCE_ASSIGNMENT", {
			parlex::reference("EXPRESSION"),
			parlex::repetition(	parlex::reference("IC")
			),
			parlex::literal("\?\?", U"\?\?"),
			parlex::choice ({
				parlex::literal("<-", U"<-"),
				parlex::literal("←", U"←")
			}),
			parlex::repetition(	parlex::reference("IC")
			),
			parlex::reference("EXPRESSION")
		})),
		parlex::production("OBJECT",
		parlex::sequence("OBJECT", {
			parlex::literal("object", U"object"),
			parlex::repetition(	parlex::reference("IC")
			),
			parlex::optional(	parlex::sequence({
					parlex::literal("inheriting", U"inheriting"),
					parlex::repetition(	parlex::reference("IC")
					),
					parlex::reference("INHERITANCE_LIST"),
					parlex::repetition(	parlex::reference("IC")
					)
				})
			),
			parlex::optional(	parlex::sequence({
					parlex::literal("implementing", U"implementing"),
					parlex::repetition(	parlex::reference("IC")
					),
					parlex::reference("INHERITANCE_LIST"),
					parlex::repetition(	parlex::reference("IC")
					)
				})
			),
			parlex::literal("{", U"{"),
			parlex::reference("TYPE_SCOPE"),
			parlex::literal("}", U"}")
		})),
		parlex::production("OCTAL",
		parlex::sequence("OCTAL", {
			parlex::literal("0", U"0"),
			parlex::reference("octal_digit"),
			parlex::repetition(	parlex::reference("octal_digit")
			)
		})),
		parlex::production("OP_ASSIGNMENT",
		parlex::choice ("OP_ASSIGNMENT", {
			parlex::reference("ADD_SUB_ASSIGNMENT"),
			parlex::reference("ADDITION_ASSIGNMENT"),
			parlex::reference("AND_ASSIGNMENT"),
			parlex::reference("BIT_AND_ASSIGNMENT"),
			parlex::reference("BIT_NOT_ASSIGNMENT"),
			parlex::reference("BIT_OR_ASSIGNMENT"),
			parlex::reference("BIT_XOR_ASSIGNMENT"),
			parlex::reference("COMPOUND_ASSIGNMENT"),
			parlex::reference("COMPOSITION_ASSIGNMENT"),
			parlex::reference("CROSS_PRODUCT_ASSIGNMENT"),
			parlex::reference("DIVISION_ASSIGNMENT"),
			parlex::reference("EXPONENTIATION_ASSIGNMENT"),
			parlex::reference("FACTORIAL_ASSIGNMENT"),
			parlex::reference("IMPLICATION_ASSIGNMENT"),
			parlex::reference("INTEGER_DIVISION_ASSIGNMENT"),
			parlex::reference("INTERSECTION_ASSIGNMENT"),
			parlex::reference("MODULATION_ASSIGNMENT"),
			parlex::reference("MULTIPLICATION_ASSIGNMENT"),
			parlex::reference("NAND_ASSIGNMENT"),
			parlex::reference("NEGATION_ASSIGNMENT"),
			parlex::reference("NOR_ASSIGNMENT"),
			parlex::reference("NOT_ASSIGNMENT"),
			parlex::reference("NULL_COALESCE_ASSIGNMENT"),
			parlex::reference("OR_ASSIGNMENT"),
			parlex::reference("PRE_DEC"),
			parlex::reference("PRE_INC"),
			parlex::reference("PREPEND_ASSIGNMENT"),
			parlex::reference("POST_DEC"),
			parlex::reference("POST_INC"),
			parlex::reference("RADICAL_ASSIGNMENT"),
			parlex::reference("SHIFTL_ASSIGNMENT"),
			parlex::reference("SHIFTR_ASSIGNMENT"),
			parlex::reference("SUBTRACTION_ASSIGNMENT"),
			parlex::reference("SYMMETRIC_DIFFERENCE_ASSIGNMENT"),
			parlex::reference("UNION_ASSIGNMENT"),
			parlex::reference("XOR_ASSIGNMENT")
		})),
		parlex::production("OR",
		parlex::sequence("OR", {
			parlex::reference("EXPRESSION"),
			parlex::repetition(	parlex::reference("IC")
			),
			parlex::choice ({
				parlex::literal("∨", U"∨"),
				parlex::literal("or", U"or")
			}),
			parlex::repetition(	parlex::reference("IC")
			),
			parlex::reference("EXPRESSION")
		}),
		parlex::associativity::ANY, parlex::filter_function(), {"IFF", "IMPLICATION", "XOR", }),
		parlex::production("OR_ASSIGNMENT",
		parlex::sequence("OR_ASSIGNMENT", {
			parlex::reference("EXPRESSION"),
			parlex::repetition(	parlex::reference("IC")
			),
			parlex::choice ({
				parlex::literal("∨", U"∨"),
				parlex::literal("or", U"or")
			}),
			parlex::choice ({
				parlex::literal("<-", U"<-"),
				parlex::literal("←", U"←")
			}),
			parlex::repetition(	parlex::reference("IC")
			),
			parlex::reference("EXPRESSION")
		})),
		parlex::production("PARAMETER",
		parlex::choice ("PARAMETER", {
			parlex::reference("PARAMETER_NATURAL"),
			parlex::reference("PARAMETER_ANALYTIC")
		})),
		parlex::production("PARAMETER_ANALYTIC",
		parlex::sequence("PARAMETER_ANALYTIC", {
			parlex::reference("EXPRESSION"),
			parlex::optional(	parlex::sequence({
					parlex::repetition(	parlex::reference("IC")
					),
					parlex::literal("=", U"="),
					parlex::repetition(	parlex::reference("IC")
					),
					parlex::reference("EXPRESSION")
				})
			)
		})),
		parlex::production("PARAMETER_NATURAL",
		parlex::choice ("PARAMETER_NATURAL", {
			parlex::sequence({
				parlex::optional(	parlex::sequence({
						parlex::reference("TYPE_DEREFERENCE"),
						parlex::repetition(	parlex::reference("IC")
						)
					})
				),
				parlex::reference("IDENTIFIER"),
				parlex::optional(	parlex::literal("...", U"...")
				)
			}),
			parlex::sequence({
				parlex::optional(	parlex::sequence({
						parlex::choice ({
							parlex::reference("TYPE_DEREFERENCE"),
							parlex::reference("IMPLICIT_TYPE_DEREFERENCE")
						}),
						parlex::repetition(	parlex::reference("IC")
						)
					})
				),
				parlex::reference("IDENTIFIER"),
				parlex::optional(	parlex::literal("...", U"...")
				),
				parlex::repetition(	parlex::reference("IC")
				),
				parlex::literal("=", U"="),
				parlex::repetition(	parlex::reference("IC")
				),
				parlex::reference("EXPRESSION"),
				parlex::optional(	parlex::literal("...", U"...")
				)
			})
		}),
		parlex::associativity::NONE, parlex::filter_function(), {"PARAMETER_ANALYTIC", }),
		parlex::production("PARENTHETICAL",
		parlex::sequence("PARENTHETICAL", {
			parlex::literal("(", U"("),
			parlex::repetition(	parlex::reference("IC")
			),
			parlex::reference("EXPRESSION"),
			parlex::repetition(	parlex::reference("IC")
			),
			parlex::literal(")", U")")
		})),
		parlex::production("PARENTHETICAL_INVOCATION",
		parlex::sequence("PARENTHETICAL_INVOCATION", {
			parlex::reference("target", "EXPRESSION"),
			parlex::repetition(	parlex::reference("IC")
			),
			parlex::literal("(", U"("),
			parlex::optional("argsHead", 	parlex::sequence({
					parlex::repetition(	parlex::reference("IC")
					),
					parlex::choice ({
						parlex::reference("ARGUMENT"),
						parlex::reference("ARGUMENT_PACK")
					})
				})
			),
			parlex::repetition("argsTail", 	parlex::sequence({
					parlex::repetition(	parlex::reference("IC")
					),
					parlex::literal(",", U","),
					parlex::optional(	parlex::sequence({
							parlex::repetition(	parlex::reference("IC")
							),
							parlex::choice ({
								parlex::reference("ARGUMENT"),
								parlex::reference("ARGUMENT_PACK")
							})
						})
					)
				})
			),
			parlex::repetition(	parlex::reference("IC")
			),
			parlex::literal(")", U")")
		})),
		parlex::production("PAYLOAD",
		parlex::sequence("PAYLOAD", {
			parlex::reference("all"),
			parlex::repetition(	parlex::reference("all")
			)
		})),
		parlex::production("PLATFORM",
		parlex::sequence("PLATFORM", {
			parlex::literal("_", U"_"),
			parlex::choice ({
				parlex::reference("letter"),
				parlex::reference("number")
			}),
			parlex::repetition(	parlex::choice ({
					parlex::reference("letter"),
					parlex::reference("number"),
					parlex::literal("_", U"_")
				})
			)
		}),
		parlex::associativity::NONE, parlex::longest()),
		parlex::production("POST_DEC",
		parlex::sequence("POST_DEC", {
			parlex::reference("EXPRESSION"),
			parlex::repetition(	parlex::reference("IC")
			),
			parlex::literal("--", U"--")
		}),
		parlex::associativity::NONE, parlex::filter_function(), {"BINARY_OP", "NEGATION", }),
		parlex::production("POST_INC",
		parlex::sequence("POST_INC", {
			parlex::reference("EXPRESSION"),
			parlex::repetition(	parlex::reference("IC")
			),
			parlex::literal("++", U"++")
		}),
		parlex::associativity::NONE, parlex::filter_function(), {"BINARY_OP", "NEGATION", }),
		parlex::production("PREPEND",
		parlex::sequence("PREPEND", {
			parlex::reference("EXPRESSION"),
			parlex::repetition(	parlex::reference("IC")
			),
			parlex::literal("&", U"&"),
			parlex::repetition(	parlex::reference("IC")
			),
			parlex::reference("EXPRESSION")
		}),
		parlex::associativity::RIGHT),
		parlex::production("PREPEND_ASSIGNMENT",
		parlex::sequence("PREPEND_ASSIGNMENT", {
			parlex::reference("EXPRESSION"),
			parlex::repetition(	parlex::reference("IC")
			),
			parlex::literal("&", U"&"),
			parlex::choice ({
				parlex::literal("<-", U"<-"),
				parlex::literal("←", U"←")
			}),
			parlex::repetition(	parlex::reference("IC")
			),
			parlex::reference("EXPRESSION")
		})),
		parlex::production("PRE_DEC",
		parlex::sequence("PRE_DEC", {
			parlex::literal("--", U"--"),
			parlex::repetition(	parlex::reference("IC")
			),
			parlex::reference("EXPRESSION")
		}),
		parlex::associativity::NONE, parlex::filter_function(), {"BINARY_OP", "NEGATION", }),
		parlex::production("PRE_INC",
		parlex::sequence("PRE_INC", {
			parlex::literal("++", U"++"),
			parlex::repetition(	parlex::reference("IC")
			),
			parlex::reference("EXPRESSION")
		}),
		parlex::associativity::NONE, parlex::filter_function(), {"BINARY_OP", "NEGATION", }),
		parlex::production("RADICAL",
		parlex::sequence("RADICAL", {
			parlex::choice ({
				parlex::literal("√", U"√"),
				parlex::literal("sqrt", U"sqrt")
			}),
			parlex::repetition(	parlex::reference("IC")
			),
			parlex::reference("EXPRESSION")
		}),
		parlex::associativity::NONE, parlex::filter_function(), {"ADDITION", "ADD_SUB", "DIVISION", "INTEGER_DIVISION", "MODULATION", "MULTIPLICATIVE_OP", "SUBTRACTION", }),
		parlex::production("RADICAL_ASSIGNMENT",
		parlex::sequence("RADICAL_ASSIGNMENT", {
			parlex::reference("EXPRESSION"),
			parlex::repetition(	parlex::reference("IC")
			),
			parlex::choice ({
				parlex::literal("√", U"√"),
				parlex::literal("sqrt", U"sqrt")
			}),
			parlex::choice ({
				parlex::literal("<-", U"<-"),
				parlex::literal("←", U"←")
			})
		})),
		parlex::production("RANGE",
		parlex::choice ("RANGE", {
			parlex::sequence({
				parlex::literal("(", U"("),
				parlex::repetition(	parlex::reference("IC")
				),
				parlex::literal("...", U"..."),
				parlex::repetition(	parlex::reference("IC")
				),
				parlex::reference("EXPRESSION"),
				parlex::repetition(	parlex::reference("IC")
				),
				parlex::choice ({
					parlex::literal("]", U"]"),
					parlex::literal(")", U")")
				})
			}),
			parlex::sequence({
				parlex::choice ({
					parlex::literal("[", U"["),
					parlex::literal("(", U"(")
				}),
				parlex::repetition(	parlex::reference("IC")
				),
				parlex::reference("EXPRESSION"),
				parlex::repetition(	parlex::reference("IC")
				),
				parlex::literal("...", U"..."),
				parlex::repetition(	parlex::reference("IC")
				),
				parlex::literal(")", U")")
			}),
			parlex::sequence({
				parlex::choice ({
					parlex::literal("(", U"("),
					parlex::literal("[", U"[")
				}),
				parlex::repetition(	parlex::reference("IC")
				),
				parlex::reference("EXPRESSION"),
				parlex::repetition(	parlex::reference("IC")
				),
				parlex::literal("...", U"..."),
				parlex::repetition(	parlex::reference("IC")
				),
				parlex::reference("EXPRESSION"),
				parlex::repetition(	parlex::reference("IC")
				),
				parlex::choice ({
					parlex::literal("]", U"]"),
					parlex::literal(")", U")")
				})
			})
		})),
		parlex::production("READ_LOCK",
		parlex::sequence("READ_LOCK", {
			parlex::literal("read_lock", U"read_lock"),
			parlex::repetition(	parlex::reference("IC")
			),
			parlex::reference("PARENTHETICAL"),
			parlex::repetition(	parlex::reference("IC")
			),
			parlex::reference("EXPRESSION")
		})),
		parlex::production("RECORD",
		parlex::sequence("RECORD", {
			parlex::literal("record", U"record"),
			parlex::reference("IC"),
			parlex::repetition(	parlex::reference("IC")
			),
			parlex::reference("TYPE")
		})),
		parlex::production("REGEX",
		parlex::sequence("REGEX", {
			parlex::literal("R", U"R"),
			parlex::reference("c_string")
		})),
		parlex::production("RELATIONAL_COLLECTION_OP",
		parlex::choice ("RELATIONAL_COLLECTION_OP", {
			parlex::reference("HAS"),
			parlex::reference("IN"),
			parlex::reference("NOT_HAS"),
			parlex::reference("NOT_IN")
		})),
		parlex::production("RELATIONAL_OP",
		parlex::choice ("RELATIONAL_OP", {
			parlex::reference("CASTS"),
			parlex::reference("DOWNCASTS"),
			parlex::reference("EXACTLY"),
			parlex::reference("IMPLEMENTS"),
			parlex::reference("INEQUALITY"),
			parlex::reference("INHERITS"),
			parlex::reference("IS"),
			parlex::reference("RELATIONAL_COLLECTION_OP"),
			parlex::reference("UPCASTS")
		}),
		parlex::associativity::NONE, parlex::filter_function(), {"BINARY_LOGICAL_OP", }),
		parlex::production("RETURN",
		parlex::sequence("RETURN", {
			parlex::literal("return", U"return"),
			parlex::optional(	parlex::sequence({
					parlex::repetition(	parlex::reference("IC")
					),
					parlex::literal("[", U"["),
					parlex::repetition(	parlex::reference("IC")
					),
					parlex::reference("EXPRESSION"),
					parlex::repetition(	parlex::reference("IC")
					),
					parlex::literal("]", U"]")
				})
			),
			parlex::optional(	parlex::sequence({
					parlex::repetition(	parlex::reference("IC")
					),
					parlex::reference("EXPRESSION")
				})
			)
		})),
		parlex::production("SET",
		parlex::sequence("SET", {
			parlex::literal("{|", U"{|"),
			parlex::repetition(	parlex::reference("IC")
			),
			parlex::optional("elements", 	parlex::sequence({
					parlex::reference("EXPRESSION"),
					parlex::repetition(	parlex::sequence({
							parlex::repetition(	parlex::reference("IC")
							),
							parlex::literal(",", U","),
							parlex::repetition(	parlex::reference("IC")
							),
							parlex::reference("EXPRESSION")
						})
					),
					parlex::repetition(	parlex::reference("IC")
					)
				})
			),
			parlex::literal("|}", U"|}")
		}),
		parlex::associativity::NONE, parlex::filter_function(), {"MAGNITUDE", }),
		parlex::production("SET_COMPREHENSION",
		parlex::sequence("SET_COMPREHENSION", {
			parlex::literal("{", U"{"),
			parlex::repetition(	parlex::reference("IC")
			),
			parlex::reference("EXPRESSION"),
			parlex::repetition(	parlex::reference("IC")
			),
			parlex::literal("|", U"|"),
			parlex::repetition(	parlex::reference("IC")
			),
			parlex::reference("EXPRESSION"),
			parlex::repetition(	parlex::reference("IC")
			),
			parlex::literal("}", U"}")
		})),
		parlex::production("SHIFTL",
		parlex::sequence("SHIFTL", {
			parlex::reference("EXPRESSION"),
			parlex::repetition(	parlex::reference("IC")
			),
			parlex::literal("<<", U"<<"),
			parlex::repetition(	parlex::reference("IC")
			),
			parlex::reference("EXPRESSION")
		}),
		parlex::associativity::LEFT),
		parlex::production("SHIFTL_ASSIGNMENT",
		parlex::sequence("SHIFTL_ASSIGNMENT", {
			parlex::reference("EXPRESSION"),
			parlex::repetition(	parlex::reference("IC")
			),
			parlex::literal("<<", U"<<"),
			parlex::choice ({
				parlex::literal("<-", U"<-"),
				parlex::literal("←", U"←")
			}),
			parlex::repetition(	parlex::reference("IC")
			),
			parlex::reference("EXPRESSION")
		})),
		parlex::production("SHIFTR",
		parlex::sequence("SHIFTR", {
			parlex::reference("EXPRESSION"),
			parlex::repetition(	parlex::reference("IC")
			),
			parlex::literal(">>", U">>"),
			parlex::repetition(	parlex::reference("IC")
			),
			parlex::reference("EXPRESSION")
		}),
		parlex::associativity::LEFT),
		parlex::production("SHIFTR_ASSIGNMENT",
		parlex::sequence("SHIFTR_ASSIGNMENT", {
			parlex::reference("EXPRESSION"),
			parlex::repetition(	parlex::reference("IC")
			),
			parlex::literal(">>", U">>"),
			parlex::choice ({
				parlex::literal("<-", U"<-"),
				parlex::literal("←", U"←")
			}),
			parlex::repetition(	parlex::reference("IC")
			),
			parlex::reference("EXPRESSION")
		})),
		parlex::production("SLICE",
		parlex::sequence("SLICE", {
			parlex::reference("EXPRESSION"),
			parlex::repetition(	parlex::reference("IC")
			),
			parlex::literal(":", U":"),
			parlex::repetition(	parlex::reference("IC")
			),
			parlex::reference("EXPRESSION")
		})),
		parlex::production("STATEMENT",
		parlex::sequence("STATEMENT", {
			parlex::choice ("value", {
				parlex::reference("ASSIGNMENT_CHAIN"),
				parlex::reference("BREAK"),
				parlex::reference("CONTINUE"),
				parlex::reference("DEFINITION"),
				parlex::reference("DO"),
				parlex::reference("EXPRESSION"),
				parlex::reference("FOR"),
				parlex::reference("FOR_COLLECTION"),
				parlex::reference("FREE"),
				parlex::reference("IMPORT"),
				parlex::reference("LOCK"),
				parlex::reference("LOOP"),
				parlex::reference("OP_ASSIGNMENT"),
				parlex::reference("READ_LOCK"),
				parlex::reference("RETURN"),
				parlex::reference("THROW"),
				parlex::reference("TRY"),
				parlex::reference("TYPE_CONSTRAINT"),
				parlex::reference("WRITE_LOCK"),
				parlex::reference("USING")
			}),
			parlex::repetition("ic", 	parlex::reference("IC")
			),
			parlex::literal(";", U";")
		})),
		parlex::production("STATEMENT_SCOPE",
		parlex::repetition("STATEMENT_SCOPE", 	parlex::choice ({
				parlex::reference("IC"),
				parlex::reference("STATEMENT")
			})
		)),
		parlex::production("STATIC",
		parlex::literal("STATIC", U"static"),
		parlex::associativity::NONE, parlex::filter_function(), {"IDENTIFIER", }),
		parlex::production("SUBSET_CHAIN",
		parlex::sequence("SUBSET_CHAIN", {
			parlex::reference("EXPRESSION"),
			parlex::repetition(	parlex::reference("IC")
			),
			parlex::reference("SUBSET_CHAIN_LOOP")
		})),
		parlex::production("SUBSET_CHAIN_LOOP",
		parlex::sequence("SUBSET_CHAIN_LOOP", {
			parlex::choice ({
				parlex::literal("=", U"="),
				parlex::literal("⊆", U"⊆"),
				parlex::literal("subs", U"subs"),
				parlex::literal("⊂", U"⊂"),
				parlex::literal("psubs", U"psubs")
			}),
			parlex::repetition(	parlex::reference("IC")
			),
			parlex::reference("EXPRESSION"),
			parlex::optional(	parlex::sequence({
					parlex::repetition(	parlex::reference("IC")
					),
					parlex::reference("SUBSET_CHAIN_LOOP")
				})
			)
		}),
		parlex::associativity::NONE, parlex::filter_function(), {"EXPRESSION", }),
		parlex::production("SUBTRACTION",
		parlex::sequence("SUBTRACTION", {
			parlex::reference("EXPRESSION"),
			parlex::repetition(	parlex::reference("IC")
			),
			parlex::literal("-", U"-"),
			parlex::repetition(	parlex::reference("IC")
			),
			parlex::reference("EXPRESSION")
		}),
		parlex::associativity::LEFT),
		parlex::production("SUBTRACTION_ASSIGNMENT",
		parlex::sequence("SUBTRACTION_ASSIGNMENT", {
			parlex::reference("EXPRESSION"),
			parlex::repetition(	parlex::reference("IC")
			),
			parlex::literal("-", U"-"),
			parlex::choice ({
				parlex::literal("<-", U"<-"),
				parlex::literal("←", U"←")
			}),
			parlex::repetition(	parlex::reference("IC")
			),
			parlex::reference("EXPRESSION")
		})),
		parlex::production("SUPERSET_CHAIN",
		parlex::sequence("SUPERSET_CHAIN", {
			parlex::reference("EXPRESSION"),
			parlex::repetition(	parlex::reference("IC")
			),
			parlex::reference("SUPERSET_CHAIN_LOOP")
		})),
		parlex::production("SUPERSET_CHAIN_LOOP",
		parlex::sequence("SUPERSET_CHAIN_LOOP", {
			parlex::choice ({
				parlex::literal("=", U"="),
				parlex::literal("⊇", U"⊇"),
				parlex::literal("sups", U"sups"),
				parlex::literal("⊃", U"⊃"),
				parlex::literal("psups", U"psups")
			}),
			parlex::repetition(	parlex::reference("IC")
			),
			parlex::reference("EXPRESSION"),
			parlex::optional(	parlex::sequence({
					parlex::repetition(	parlex::reference("IC")
					),
					parlex::reference("SUPERSET_CHAIN_LOOP")
				})
			)
		}),
		parlex::associativity::NONE, parlex::filter_function(), {"EXPRESSION", }),
		parlex::production("SWIZZLE",
		parlex::sequence("SWIZZLE", {
			parlex::reference("EXPRESSION"),
			parlex::repetition(	parlex::reference("IC")
			),
			parlex::choice ({
				parlex::literal("⋮", U"⋮"),
				parlex::literal("_swiz_", U"_swiz_")
			}),
			parlex::repetition(	parlex::reference("IC")
			),
			parlex::reference("EXPRESSION")
		})),
		parlex::production("SYMMETRIC_DIFFERENCE",
		parlex::sequence("SYMMETRIC_DIFFERENCE", {
			parlex::reference("EXPRESSION"),
			parlex::repetition(	parlex::reference("IC")
			),
			parlex::literal("⊖", U"⊖"),
			parlex::repetition(	parlex::reference("IC")
			),
			parlex::reference("EXPRESSION")
		}),
		parlex::associativity::LEFT),
		parlex::production("SYMMETRIC_DIFFERENCE_ASSIGNMENT",
		parlex::sequence("SYMMETRIC_DIFFERENCE_ASSIGNMENT", {
			parlex::reference("EXPRESSION"),
			parlex::repetition(	parlex::reference("IC")
			),
			parlex::literal("⊖", U"⊖"),
			parlex::choice ({
				parlex::literal("<-", U"<-"),
				parlex::literal("←", U"←")
			}),
			parlex::repetition(	parlex::reference("IC")
			),
			parlex::reference("EXPRESSION")
		})),
		parlex::production("THIS",
		parlex::sequence("THIS", {
			parlex::literal("this", U"this"),
			parlex::optional(	parlex::sequence({
					parlex::repetition(	parlex::reference("IC")
					),
					parlex::literal("[", U"["),
					parlex::repetition(	parlex::reference("IC")
					),
					parlex::reference("EXPRESSION"),
					parlex::repetition(	parlex::reference("IC")
					),
					parlex::literal("]", U"]")
				})
			)
		})),
		parlex::production("THIS_FUNC",
		parlex::sequence("THIS_FUNC", {
			parlex::literal("this_func", U"this_func"),
			parlex::optional(	parlex::sequence({
					parlex::repetition(	parlex::reference("IC")
					),
					parlex::literal("[", U"["),
					parlex::repetition(	parlex::reference("IC")
					),
					parlex::reference("EXPRESSION"),
					parlex::repetition(	parlex::reference("IC")
					),
					parlex::literal("]", U"]")
				})
			)
		})),
		parlex::production("THIS_TYPE",
		parlex::sequence("THIS_TYPE", {
			parlex::literal("this_type", U"this_type"),
			parlex::optional(	parlex::sequence({
					parlex::repetition(	parlex::reference("IC")
					),
					parlex::literal("[", U"["),
					parlex::repetition(	parlex::reference("IC")
					),
					parlex::reference("EXPRESSION"),
					parlex::repetition(	parlex::reference("IC")
					),
					parlex::literal("]", U"]")
				})
			)
		})),
		parlex::production("THROW",
		parlex::sequence("THROW", {
			parlex::literal("throw", U"throw"),
			parlex::optional(	parlex::sequence({
					parlex::repetition(	parlex::reference("IC")
					),
					parlex::literal("[", U"["),
					parlex::repetition(	parlex::reference("IC")
					),
					parlex::reference("EXPRESSION"),
					parlex::repetition(	parlex::reference("IC")
					),
					parlex::literal("]", U"]")
				})
			),
			parlex::optional(	parlex::sequence({
					parlex::repetition(	parlex::reference("IC")
					),
					parlex::reference("EXPRESSION")
				})
			)
		})),
		parlex::production("TIME",
		parlex::sequence("TIME", {
			parlex::optional(	parlex::literal("-", U"-")
			),
			parlex::reference("decimal_digit"),
			parlex::reference("decimal_digit"),
			parlex::literal(":", U":"),
			parlex::reference("decimal_digit"),
			parlex::reference("decimal_digit"),
			parlex::literal(":", U":"),
			parlex::reference("decimal_digit"),
			parlex::reference("decimal_digit"),
			parlex::optional(	parlex::sequence({
					parlex::literal(".", U"."),
					parlex::reference("decimal_digit"),
					parlex::repetition(	parlex::reference("decimal_digit")
					)
				})
			),
			parlex::optional(	parlex::choice ({
					parlex::literal("Z", U"Z"),
					parlex::sequence({
						parlex::choice ({
							parlex::literal("+", U"+"),
							parlex::literal("-", U"-")
						}),
						parlex::reference("decimal_digit"),
						parlex::reference("decimal_digit"),
						parlex::optional(	parlex::sequence({
								parlex::literal(":", U":"),
								parlex::reference("decimal_digit"),
								parlex::reference("decimal_digit")
							})
						)
					})
				})
			)
		})),
		parlex::production("TRY",
		parlex::sequence("TRY", {
			parlex::literal("try", U"try"),
			parlex::repetition(	parlex::reference("IC")
			),
			parlex::reference("EXPRESSION"),
			parlex::repetition(	parlex::reference("IC")
			),
			parlex::literal("catch", U"catch"),
			parlex::repetition(	parlex::reference("IC")
			),
			parlex::reference("EXPRESSION"),
			parlex::repetition(	parlex::sequence({
					parlex::literal("catch", U"catch"),
					parlex::repetition(	parlex::reference("IC")
					),
					parlex::reference("EXPRESSION")
				})
			),
			parlex::optional(	parlex::sequence({
					parlex::repetition(	parlex::reference("IC")
					),
					parlex::literal("finally", U"finally"),
					parlex::repetition(	parlex::reference("IC")
					),
					parlex::reference("EXPRESSION")
				})
			)
		})),
		parlex::production("TUPLE",
		parlex::sequence("TUPLE", {
			parlex::literal("(|", U"(|"),
			parlex::repetition(	parlex::reference("IC")
			),
			parlex::reference("EXPRESSION"),
			parlex::repetition(	parlex::sequence({
					parlex::repetition(	parlex::reference("IC")
					),
					parlex::literal(",", U","),
					parlex::repetition(	parlex::reference("IC")
					),
					parlex::reference("EXPRESSION")
				})
			),
			parlex::repetition(	parlex::reference("IC")
			),
			parlex::literal("|)", U"|)")
		}),
		parlex::associativity::NONE, parlex::filter_function(), {"MAGNITUDE", }),
		parlex::production("TYPE",
		parlex::sequence("TYPE", {
			parlex::literal("type", U"type"),
			parlex::repetition(	parlex::reference("IC")
			),
			parlex::optional(	parlex::sequence({
					parlex::literal("inheriting", U"inheriting"),
					parlex::repetition(	parlex::reference("IC")
					),
					parlex::reference("INHERITANCE_LIST"),
					parlex::repetition(	parlex::reference("IC")
					)
				})
			),
			parlex::optional(	parlex::sequence({
					parlex::literal("implementing", U"implementing"),
					parlex::repetition(	parlex::reference("IC")
					),
					parlex::reference("INHERITANCE_LIST"),
					parlex::repetition(	parlex::reference("IC")
					)
				})
			),
			parlex::literal("{", U"{"),
			parlex::reference("TYPE_SCOPE"),
			parlex::literal("}", U"}")
		})),
		parlex::production("TYPE_CONSTRAINT",
		parlex::sequence("TYPE_CONSTRAINT", {
			parlex::reference("TYPE_CONSTRAINT_HEAD"),
			parlex::repetition(	parlex::reference("IC")
			),
			parlex::reference("TYPE_CONSTRAINT_CHAIN")
		}),
		parlex::associativity::NONE, parlex::filter_function(), {"EXPRESSION", }),
		parlex::production("TYPE_CONSTRAINT_CHAIN",
		parlex::sequence("TYPE_CONSTRAINT_CHAIN", {
			parlex::choice ({
				parlex::reference("DECLARATION"),
				parlex::reference("ASSIGNMENT_CHAIN"),
				parlex::reference("DEFINITION")
			}),
			parlex::optional(	parlex::sequence({
					parlex::repetition(	parlex::reference("IC")
					),
					parlex::literal(",", U","),
					parlex::repetition(	parlex::reference("IC")
					),
					parlex::reference("TYPE_CONSTRAINT_CHAIN")
				})
			)
		})),
		parlex::production("TYPE_CONSTRAINT_HEAD",
		parlex::sequence("TYPE_CONSTRAINT_HEAD", {
			parlex::optional(	parlex::sequence({
					parlex::reference("xml_doc_string", "XML_DOC_STRING"),
					parlex::repetition(	parlex::reference("IC")
					)
				})
			),
			parlex::repetition(	parlex::sequence({
					parlex::reference("ATTRIBUTE"),
					parlex::repetition(	parlex::reference("IC")
					)
				})
			),
			parlex::optional(	parlex::sequence({
					parlex::reference("visibility_modifier", "VISIBILITY_MODIFIER"),
					parlex::repetition(	parlex::reference("IC")
					)
				})
			),
			parlex::optional(	parlex::sequence({
					parlex::reference("STATIC"),
					parlex::repetition(	parlex::reference("IC")
					)
				})
			),
			parlex::optional(	parlex::sequence({
					parlex::reference("EXTERN"),
					parlex::repetition(	parlex::reference("IC")
					)
				})
			),
			parlex::choice ("type_dereference", {
				parlex::reference("TYPE_DEREFERENCE"),
				parlex::reference("VOLATILE_TYPE_DEREFERENCE"),
				parlex::reference("IMPLICIT_TYPE_DEREFERENCE"),
				parlex::reference("VOLATILE_IMPLICIT_TYPE_DEREFERENCE")
			})
		})),
		parlex::production("TYPE_DEREFERENCE",
		parlex::sequence("TYPE_DEREFERENCE", {
			parlex::literal("<", U"<"),
			parlex::repetition(	parlex::reference("IC")
			),
			parlex::reference("EXPRESSION"),
			parlex::repetition(	parlex::reference("IC")
			),
			parlex::literal(">", U">")
		})),
		parlex::production("TYPE_INVOCATION",
		parlex::sequence("TYPE_INVOCATION", {
			parlex::reference("target", "EXPRESSION"),
			parlex::sequence({
				parlex::literal("<", U"<"),
				parlex::optional("argsHead", 	parlex::sequence({
						parlex::repetition(	parlex::reference("IC")
						),
						parlex::choice ({
							parlex::reference("ARGUMENT"),
							parlex::reference("ARGUMENT_PACK")
						})
					})
				),
				parlex::repetition("argsTail", 	parlex::sequence({
						parlex::repetition(	parlex::reference("IC")
						),
						parlex::literal(",", U","),
						parlex::optional(	parlex::sequence({
								parlex::repetition(	parlex::reference("IC")
								),
								parlex::choice ({
									parlex::reference("ARGUMENT"),
									parlex::reference("ARGUMENT_PACK")
								})
							})
						)
					})
				),
				parlex::repetition(	parlex::reference("IC")
				),
				parlex::literal(">", U">")
			})
		})),
		parlex::production("TYPE_SCOPE",
		parlex::sequence("TYPE_SCOPE", {
			parlex::repetition(	parlex::reference("IC")
			),
			parlex::repetition(	parlex::sequence({
					parlex::reference("TYPE_STATEMENT"),
					parlex::repetition(	parlex::reference("IC")
					)
				})
			)
		})),
		parlex::production("TYPE_SCOPE_ASSIGNMENT_CHAIN",
		parlex::sequence("TYPE_SCOPE_ASSIGNMENT_CHAIN", {
			parlex::optional(	parlex::sequence({
					parlex::reference("XML_DOC_STRING"),
					parlex::repetition(	parlex::reference("IC")
					)
				})
			),
			parlex::reference("IDENTIFIER"),
			parlex::optional(	parlex::sequence({
					parlex::repetition(	parlex::reference("IC")
					),
					parlex::reference("MEMBER_OFFSET")
				})
			),
			parlex::repetition(	parlex::reference("IC")
			),
			parlex::choice ({
				parlex::literal("←", U"←"),
				parlex::literal("<-", U"<-")
			}),
			parlex::repetition(	parlex::reference("IC")
			),
			parlex::choice ({
				parlex::reference("EXPRESSION"),
				parlex::reference("ASSIGNMENT_CHAIN")
			})
		}),
		parlex::associativity::NONE, parlex::filter_function(), {"EXPRESSION", }),
		parlex::production("TYPE_SCOPE_DECLARATION",
		parlex::sequence("TYPE_SCOPE_DECLARATION", {
			parlex::optional(	parlex::sequence({
					parlex::reference("XML_DOC_STRING"),
					parlex::repetition(	parlex::reference("IC")
					)
				})
			),
			parlex::reference("IDENTIFIER"),
			parlex::optional(	parlex::sequence({
					parlex::repetition(	parlex::reference("IC")
					),
					parlex::reference("MEMBER_OFFSET")
				})
			)
		})),
		parlex::production("TYPE_SCOPE_TYPE_CONSTRAINT",
		parlex::sequence("TYPE_SCOPE_TYPE_CONSTRAINT", {
			parlex::reference("TYPE_CONSTRAINT_HEAD"),
			parlex::repetition(	parlex::reference("IC")
			),
			parlex::reference("TYPE_SCOPE_TYPE_CONSTRAINT_CHAIN")
		}),
		parlex::associativity::NONE, parlex::filter_function(), {"TYPE_CONSTRAINT", }),
		parlex::production("TYPE_SCOPE_TYPE_CONSTRAINT_CHAIN",
		parlex::sequence("TYPE_SCOPE_TYPE_CONSTRAINT_CHAIN", {
			parlex::optional(	parlex::sequence({
					parlex::reference("XML_DOC_STRING"),
					parlex::repetition(	parlex::reference("IC")
					)
				})
			),
			parlex::choice ({
				parlex::reference("TYPE_SCOPE_DECLARATION"),
				parlex::reference("TYPE_SCOPE_ASSIGNMENT_CHAIN"),
				parlex::reference("DEFINITION")
			}),
			parlex::optional(	parlex::sequence({
					parlex::repetition(	parlex::reference("IC")
					),
					parlex::literal(",", U","),
					parlex::repetition(	parlex::reference("IC")
					),
					parlex::reference("TYPE_SCOPE_TYPE_CONSTRAINT_CHAIN")
				})
			)
		})),
		parlex::production("TYPE_STATEMENT",
		parlex::choice ("TYPE_STATEMENT", {
			parlex::sequence({
				parlex::reference("VISIBILITY_MODIFIER"),
				parlex::repetition(	parlex::reference("IC")
				),
				parlex::literal(":", U":")
			}),
			parlex::reference("TYPE_SCOPE_TYPE_CONSTRAINT"),
			parlex::reference("STATEMENT")
		})),
		parlex::production("UNARY_ARITHMETIC_OP",
		parlex::choice ("UNARY_ARITHMETIC_OP", {
			parlex::reference("FACTORIAL"),
			parlex::reference("NEGATION"),
			parlex::reference("RADICAL")
		})),
		parlex::production("UNARY_LOGICAL_OP",
		parlex::choice ("UNARY_LOGICAL_OP", {
			parlex::reference("ALL"),
			parlex::reference("EXISTS"),
			parlex::reference("EXISTS_ONE"),
			parlex::reference("NOT")
		}),
		parlex::associativity::NONE, parlex::filter_function(), {"BINARY_LOGICAL_OP", }),
		parlex::production("UNARY_OP",
		parlex::choice ("UNARY_OP", {
			parlex::reference("ALLOCATION"),
			parlex::reference("CARDINALITY"),
			parlex::reference("KLEENE_STAR"),
			parlex::reference("UNARY_ARITHMETIC_OP"),
			parlex::reference("UNARY_LOGICAL_OP")
		})),
		parlex::production("UNION",
		parlex::sequence("UNION", {
			parlex::reference("EXPRESSION"),
			parlex::repetition(	parlex::reference("IC")
			),
			parlex::literal("∪", U"∪"),
			parlex::repetition(	parlex::reference("IC")
			),
			parlex::reference("EXPRESSION")
		}),
		parlex::associativity::ANY),
		parlex::production("UNION_ASSIGNMENT",
		parlex::sequence("UNION_ASSIGNMENT", {
			parlex::reference("EXPRESSION"),
			parlex::repetition(	parlex::reference("IC")
			),
			parlex::literal("∪", U"∪"),
			parlex::choice ({
				parlex::literal("<-", U"<-"),
				parlex::literal("←", U"←")
			}),
			parlex::repetition(	parlex::reference("IC")
			),
			parlex::reference("EXPRESSION")
		})),
		parlex::production("UNIT_DIVISION",
		parlex::sequence("UNIT_DIVISION", {
			parlex::reference("DIMENSION"),
			parlex::literal("/", U"/"),
			parlex::reference("DIMENSION")
		}),
		parlex::associativity::LEFT),
		parlex::production("UNIT_EXPONENTIATION",
		parlex::sequence("UNIT_EXPONENTIATION", {
			parlex::reference("DIMENSION"),
			parlex::literal("^", U"^"),
			parlex::reference("NON_FRACTIONAL")
		}),
		parlex::associativity::RIGHT, parlex::filter_function(), {"UNIT_DIVISION", "UNIT_MULTIPLICATION", }),
		parlex::production("UNIT_MULTIPLICATION",
		parlex::sequence("UNIT_MULTIPLICATION", {
			parlex::reference("DIMENSION"),
			parlex::literal("*", U"*"),
			parlex::reference("DIMENSION")
		}),
		parlex::associativity::LEFT),
		parlex::production("UPCASTS",
		parlex::sequence("UPCASTS", {
			parlex::reference("EXPRESSION"),
			parlex::repetition(	parlex::reference("IC")
			),
			parlex::literal("upcasts", U"upcasts"),
			parlex::repetition(	parlex::reference("IC")
			),
			parlex::reference("EXPRESSION")
		})),
		parlex::production("USING",
		parlex::sequence("USING", {
			parlex::literal("using", U"using"),
			parlex::repetition(	parlex::reference("IC")
			),
			parlex::literal("(", U"("),
			parlex::repetition(	parlex::reference("IC")
			),
			parlex::reference("EXPRESSION"),
			parlex::repetition(	parlex::reference("IC")
			),
			parlex::literal(")", U")"),
			parlex::repetition(	parlex::reference("IC")
			),
			parlex::reference("BLOCK")
		})),
		parlex::production("VECTOR_NORM",
		parlex::sequence("VECTOR_NORM", {
			parlex::literal("||", U"||"),
			parlex::repetition(	parlex::reference("IC")
			),
			parlex::reference("EXPRESSION"),
			parlex::repetition(	parlex::reference("IC")
			),
			parlex::literal("||", U"||")
		})),
		parlex::production("VISIBILITY_MODIFIER",
		parlex::choice ("VISIBILITY_MODIFIER", {
			parlex::literal("public", U"public"),
			parlex::literal("protected", U"protected"),
			parlex::literal("protected internal", U"protected internal"),
			parlex::literal("internal", U"internal"),
			parlex::literal("private", U"private")
		})),
		parlex::production("VOLATILE_IMPLICIT_TYPE_DEREFERENCE",
		parlex::sequence("VOLATILE_IMPLICIT_TYPE_DEREFERENCE", {
			parlex::literal("<", U"<"),
			parlex::repetition(	parlex::reference("IC")
			),
			parlex::literal("volatile", U"volatile"),
			parlex::repetition(	parlex::reference("IC")
			),
			parlex::literal(">", U">")
		})),
		parlex::production("VOLATILE_TYPE_DEREFERENCE",
		parlex::sequence("VOLATILE_TYPE_DEREFERENCE", {
			parlex::literal("<", U"<"),
			parlex::repetition(	parlex::reference("IC")
			),
			parlex::literal("volatile", U"volatile"),
			parlex::repetition(	parlex::reference("IC")
			),
			parlex::reference("EXPRESSION"),
			parlex::repetition(	parlex::reference("IC")
			),
			parlex::literal(">", U">")
		})),
		parlex::production("WHOLE_NUMBER",
		parlex::sequence("WHOLE_NUMBER", {
			parlex::choice ({
				parlex::literal("1", U"1"),
				parlex::literal("2", U"2"),
				parlex::literal("3", U"3"),
				parlex::literal("4", U"4"),
				parlex::literal("5", U"5"),
				parlex::literal("6", U"6"),
				parlex::literal("7", U"7"),
				parlex::literal("8", U"8"),
				parlex::literal("9", U"9")
			}),
			parlex::repetition(	parlex::choice ({
					parlex::literal("0", U"0"),
					parlex::literal("1", U"1"),
					parlex::literal("2", U"2"),
					parlex::literal("3", U"3"),
					parlex::literal("4", U"4"),
					parlex::literal("5", U"5"),
					parlex::literal("6", U"6"),
					parlex::literal("7", U"7"),
					parlex::literal("8", U"8"),
					parlex::literal("9", U"9")
				})
			)
		})),
		parlex::production("WRITE_LOCK",
		parlex::sequence("WRITE_LOCK", {
			parlex::literal("write_lock", U"write_lock"),
			parlex::repetition(	parlex::reference("IC")
			),
			parlex::reference("PARENTHETICAL"),
			parlex::repetition(	parlex::reference("IC")
			),
			parlex::reference("EXPRESSION")
		})),
		parlex::production("WS",
		parlex::sequence("WS", {
			parlex::reference("white_space"),
			parlex::repetition(	parlex::reference("white_space")
			)
		}),
		parlex::associativity::NONE, parlex::longest()),
		parlex::production("XML_DOC_STRING",
		parlex::sequence("XML_DOC_STRING", {
			parlex::literal("```", U"```"),
			parlex::reference("XML_DOC_STRING_INTERIOR"),
			parlex::literal("```", U"```")
		})),
		parlex::production("XML_DOC_STRING_INTERIOR",
		parlex::choice ("XML_DOC_STRING_INTERIOR", {
			parlex::reference("payload", "PAYLOAD"),
			parlex::sequence({
				parlex::literal("`", U"`"),
				parlex::reference("XML_DOC_STRING_INTERIOR"),
				parlex::literal("`", U"`")
			})
		}),
		parlex::associativity::NONE, parlex::filter_function(), {"PAYLOAD", }),
		parlex::production("XOR",
		parlex::sequence("XOR", {
			parlex::reference("EXPRESSION"),
			parlex::repetition(	parlex::reference("IC")
			),
			parlex::choice ({
				parlex::literal("⊕", U"⊕"),
				parlex::literal("xor", U"xor")
			}),
			parlex::repetition(	parlex::reference("IC")
			),
			parlex::reference("EXPRESSION")
		}),
		parlex::associativity::LEFT),
		parlex::production("XOR_ASSIGNMENT",
		parlex::sequence("XOR_ASSIGNMENT", {
			parlex::reference("EXPRESSION"),
			parlex::repetition(	parlex::reference("IC")
			),
			parlex::choice ({
				parlex::literal("⊕", U"⊕"),
				parlex::literal("xor", U"xor")
			}),
			parlex::choice ({
				parlex::literal("<-", U"<-"),
				parlex::literal("←", U"←")
			}),
			parlex::repetition(	parlex::reference("IC")
			),
			parlex::reference("EXPRESSION")
		})),
	});
	return result;
}
