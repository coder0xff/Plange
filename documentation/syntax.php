<meta charset='utf-8'/>
<meta name="viewport" content="width=device-width, initial-scale=0.6">
<html>
	<head>
		<title>Syntax Listing - Plange</title>
		<link rel=StyleSheet href='../css/general.css' type='text/css' />
	</head>
	<body>
		<?php require('../header.php') ?>


		<p>This page is generated from the <a href='/source/syntax.yml'>syntax specification</a>. Tags, identities, and all {IC} (optional whitespace and comment regions) are filtered from the syntax display to improve readability. See the specification for the full grammar specification. The root production of the grammar is "STATEMENT_SCOPE".</p>
		<h2>Subpage Listing</h2>
		<table>
			<tr>
				<td><a id="ADDITION" href="/documentation/syntax/ADDITION.php">ADDITION</a></td>
				<td>no doc string</td>
				<td><a href="/documentation/syntax.php#EXPRESSION">EXPRESSION</a>  "+"  <a href="/documentation/syntax.php#EXPRESSION">EXPRESSION</a></td>
			</tr>
			<tr>
				<td><a id="ADD_SUB" href="/documentation/syntax/ADD_SUB.php">ADD_SUB</a></td>
				<td>creates an analytic value storing the simultaneous results of addition and subtraction</td>
				<td><a href="/documentation/syntax.php#EXPRESSION">EXPRESSION</a>  ("±"|"+-")  <a href="/documentation/syntax.php#EXPRESSION">EXPRESSION</a></td>
			</tr>
			<tr>
				<td><a id="ALL" href="/documentation/syntax/ALL.php">ALL</a></td>
				<td>constrain ALL elements of a Collection to be true</td>
				<td>("∀"|"all")  <a href="/documentation/syntax.php#EXPRESSION">EXPRESSION</a></td>
			</tr>
			<tr>
				<td><a id="ALLOCATION" href="/documentation/syntax/ALLOCATION.php">ALLOCATION</a></td>
				<td>create an object on the heap</td>
				<td>"alloc"  <a href="/documentation/syntax.php#PARENTHETICAL_INVOCATION">PARENTHETICAL_INVOCATION</a></td>
			</tr>
			<tr>
				<td><a id="AND" href="/documentation/syntax/AND.php">AND</a></td>
				<td>no doc string</td>
				<td><a href="/documentation/syntax.php#EXPRESSION">EXPRESSION</a>  ("∧"|"and")  <a href="/documentation/syntax.php#EXPRESSION">EXPRESSION</a></td>
			</tr>
			<tr>
				<td><a id="ARGUMENT" href="/documentation/syntax/ARGUMENT.php">ARGUMENT</a></td>
				<td>no doc string</td>
				<td><a href="/documentation/syntax.php#EXPRESSION">EXPRESSION</a></td>
			</tr>
			<tr>
				<td><a id="ARGUMENT_PACK" href="/documentation/syntax/ARGUMENT_PACK.php">ARGUMENT_PACK</a></td>
				<td>no doc string</td>
				<td><a href="/documentation/syntax.php#EXPRESSION">EXPRESSION</a>  "..."</td>
			</tr>
			<tr>
				<td><a id="ARRAY" href="/documentation/syntax/ARRAY.php">ARRAY</a></td>
				<td>no doc string</td>
				<td>"["  [<a href="/documentation/syntax.php#EXPRESSION">EXPRESSION</a> {","  <a href="/documentation/syntax.php#EXPRESSION">EXPRESSION</a>}] "]"</td>
			</tr>
			<tr>
				<td><a id="ARRAY_INDEXER" href="/documentation/syntax/ARRAY_INDEXER.php">ARRAY_INDEXER</a></td>
				<td>no doc string</td>
				<td> (<a href="/documentation/syntax.php#ARGUMENT">ARGUMENT</a>|<a href="/documentation/syntax.php#ARGUMENT_PACK">ARGUMENT_PACK</a>|<a href="/documentation/syntax.php#SLICE">SLICE</a>)</td>
			</tr>
			<tr>
				<td><a id="ARRAY_INVOCATION" href="/documentation/syntax/ARRAY_INVOCATION.php">ARRAY_INVOCATION</a></td>
				<td>no doc string</td>
				<td>(<a href="/documentation/syntax.php#EXPRESSION">EXPRESSION</a>) "[" [<a href="/documentation/syntax.php#ARRAY_INDEXER">ARRAY_INDEXER</a>] {"," [<a href="/documentation/syntax.php#ARRAY_INDEXER">ARRAY_INDEXER</a>]}  "]"</td>
			</tr>
			<tr>
				<td><a id="ASM_EXPRESSION" href="/documentation/syntax/ASM_EXPRESSION.php">ASM_EXPRESSION</a></td>
				<td>no doc string</td>
				<td><a href="/documentation/syntax.php#ASM_IDENTIFIER">ASM_IDENTIFIER</a> | <a href="/documentation/syntax.php#ASM_PTR_ARITHMETIC_ATT">ASM_PTR_ARITHMETIC_ATT</a> | <a href="/documentation/syntax.php#ASM_PTR_ARITHMETIC_INTEL">ASM_PTR_ARITHMETIC_INTEL</a> | <a href="/documentation/syntax.php#NON_FRACTIONAL">NON_FRACTIONAL</a></td>
			</tr>
			<tr>
				<td><a id="ASM_FUNCTION" href="/documentation/syntax/ASM_FUNCTION.php">ASM_FUNCTION</a></td>
				<td>no doc string</td>
				<td>["("  [<a href="/documentation/syntax.php#PARAMETER">PARAMETER</a> {","  <a href="/documentation/syntax.php#PARAMETER">PARAMETER</a>}] ")"] [<a href="/documentation/syntax.php#FUNCTION_MODIFIER_0">FUNCTION_MODIFIER_0</a>] "asm"  "{" <a href="/documentation/syntax.php#ASM_SCOPE">ASM_SCOPE</a> "}"</td>
			</tr>
			<tr>
				<td><a id="ASM_IDENTIFIER" href="/documentation/syntax/ASM_IDENTIFIER.php">ASM_IDENTIFIER</a></td>
				<td>no doc string</td>
				<td>["%"] <a href="/documentation/syntax.php#IDENTIFIER">IDENTIFIER</a></td>
			</tr>
			<tr>
				<td><a id="ASM_OP" href="/documentation/syntax/ASM_OP.php">ASM_OP</a></td>
				<td>no doc string</td>
				<td>(lowercase_letter) {lowercase_letter}</td>
			</tr>
			<tr>
				<td><a id="ASM_PTR_ARITHMETIC_ATT" href="/documentation/syntax/ASM_PTR_ARITHMETIC_ATT.php">ASM_PTR_ARITHMETIC_ATT</a></td>
				<td>no doc string</td>
				<td>(<a href="/documentation/syntax.php#ASM_IDENTIFIER">ASM_IDENTIFIER</a> ":" <a href="/documentation/syntax.php#NON_FRACTIONAL">NON_FRACTIONAL</a>) | (<a href="/documentation/syntax.php#ASM_IDENTIFIER">ASM_IDENTIFIER</a> ":" <a href="/documentation/syntax.php#NON_FRACTIONAL">NON_FRACTIONAL</a> <a href="/documentation/syntax.php#ASM_PTR_ARITHMETIC_ATT_REG">ASM_PTR_ARITHMETIC_ATT_REG</a>) | (<a href="/documentation/syntax.php#NON_FRACTIONAL">NON_FRACTIONAL</a> <a href="/documentation/syntax.php#ASM_PTR_ARITHMETIC_ATT_REG">ASM_PTR_ARITHMETIC_ATT_REG</a>)</td>
			</tr>
			<tr>
				<td><a id="ASM_PTR_ARITHMETIC_ATT_REG" href="/documentation/syntax/ASM_PTR_ARITHMETIC_ATT_REG.php">ASM_PTR_ARITHMETIC_ATT_REG</a></td>
				<td>no doc string</td>
				<td>"(" [<a href="/documentation/syntax.php#ASM_IDENTIFIER">ASM_IDENTIFIER</a>] ["," <a href="/documentation/syntax.php#ASM_IDENTIFIER">ASM_IDENTIFIER</a> ["," <a href="/documentation/syntax.php#NON_NEG_NON_FRACTIONAL">NON_NEG_NON_FRACTIONAL</a>]] ")"</td>
			</tr>
			<tr>
				<td><a id="ASM_PTR_ARITHMETIC_INTEL" href="/documentation/syntax/ASM_PTR_ARITHMETIC_INTEL.php">ASM_PTR_ARITHMETIC_INTEL</a></td>
				<td>no doc string</td>
				<td>[("BYTE"|"WORD"|"DWORD"|"QWORD") " PTR"] "[" [<a href="/documentation/syntax.php#ASM_IDENTIFIER">ASM_IDENTIFIER</a> ":"] <a href="/documentation/syntax.php#ASM_IDENTIFIER">ASM_IDENTIFIER</a> ["+" <a href="/documentation/syntax.php#ASM_IDENTIFIER">ASM_IDENTIFIER</a> ["*" <a href="/documentation/syntax.php#NON_NEG_NON_FRACTIONAL">NON_NEG_NON_FRACTIONAL</a>]] [("+"|"-") <a href="/documentation/syntax.php#NON_NEG_INTEGER">NON_NEG_INTEGER</a>] "]"</td>
			</tr>
			<tr>
				<td><a id="ASM_SCOPE" href="/documentation/syntax/ASM_SCOPE.php">ASM_SCOPE</a></td>
				<td>no doc string</td>
				<td>{<a href="/documentation/syntax.php#IC">IC</a> | <a href="/documentation/syntax.php#ASM_STATEMENT">ASM_STATEMENT</a>}</td>
			</tr>
			<tr>
				<td><a id="ASM_STATEMENT" href="/documentation/syntax/ASM_STATEMENT.php">ASM_STATEMENT</a></td>
				<td>no doc string</td>
				<td><a href="/documentation/syntax.php#ASM_OP">ASM_OP</a> [<a href="/documentation/syntax.php#ASM_EXPRESSION">ASM_EXPRESSION</a> {"," [<a href="/documentation/syntax.php#ASM_EXPRESSION">ASM_EXPRESSION</a>]}]  "\n"</td>
			</tr>
			<tr>
				<td><a id="ASSIGNMENT_CHAIN" href="/documentation/syntax/ASSIGNMENT_CHAIN.php">ASSIGNMENT_CHAIN</a></td>
				<td>place the given value(s) into the given variable(s)</td>
				<td>[<a href="/documentation/syntax.php#XML_DOC_STRING">XML_DOC_STRING</a>] <a href="/documentation/syntax.php#IDENTIFIER">IDENTIFIER</a>  ("←"|"&lt;-")  (<a href="/documentation/syntax.php#EXPRESSION">EXPRESSION</a>|ASSIGNMENT_CHAIN)</td>
			</tr>
			<tr>
				<td><a id="ATTRIBUTE" href="/documentation/syntax/ATTRIBUTE.php">ATTRIBUTE</a></td>
				<td>no doc string</td>
				<td>"@"  <a href="/documentation/syntax.php#EXPRESSION">EXPRESSION</a>  "@"</td>
			</tr>
			<tr>
				<td><a id="BIJECTION" href="/documentation/syntax/BIJECTION.php">BIJECTION</a></td>
				<td>a bijection exists between the left and right hand operands</td>
				<td><a href="/documentation/syntax.php#EXPRESSION">EXPRESSION</a>  ("↔"|"&lt;-&gt;")  <a href="/documentation/syntax.php#EXPRESSION">EXPRESSION</a></td>
			</tr>
			<tr>
				<td><a id="BINARY_ARITHMETIC_OP" href="/documentation/syntax/BINARY_ARITHMETIC_OP.php">BINARY_ARITHMETIC_OP</a></td>
				<td>the collection of binary operators that work on numbers (among other things)</td>
				<td><a href="/documentation/syntax.php#ADD_SUB">ADD_SUB</a> | <a href="/documentation/syntax.php#ADDITION">ADDITION</a> | <a href="/documentation/syntax.php#DIVISION">DIVISION</a> | <a href="/documentation/syntax.php#EXPONENTIATION">EXPONENTIATION</a> | <a href="/documentation/syntax.php#INTEGER_DIVISION">INTEGER_DIVISION</a> | <a href="/documentation/syntax.php#MODULATION">MODULATION</a> | <a href="/documentation/syntax.php#MULTIPLICATIVE_OP">MULTIPLICATIVE_OP</a> | <a href="/documentation/syntax.php#SHIFTL">SHIFTL</a> | <a href="/documentation/syntax.php#SHIFTR">SHIFTR</a> | <a href="/documentation/syntax.php#SUBTRACTION">SUBTRACTION</a></td>
			</tr>
			<tr>
				<td><a id="BINARY_COLLECTION_OP" href="/documentation/syntax/BINARY_COLLECTION_OP.php">BINARY_COLLECTION_OP</a></td>
				<td>binary operators on collections</td>
				<td><a href="/documentation/syntax.php#BIJECTION">BIJECTION</a> | <a href="/documentation/syntax.php#INTERSECTION">INTERSECTION</a> | <a href="/documentation/syntax.php#SYMMETRIC_DIFFERENCE">SYMMETRIC_DIFFERENCE</a> | <a href="/documentation/syntax.php#UNION">UNION</a></td>
			</tr>
			<tr>
				<td><a id="BINARY_LOGICAL_OP" href="/documentation/syntax/BINARY_LOGICAL_OP.php">BINARY_LOGICAL_OP</a></td>
				<td>no doc string</td>
				<td><a href="/documentation/syntax.php#AND">AND</a> | <a href="/documentation/syntax.php#IFF">IFF</a> | <a href="/documentation/syntax.php#IMPLICATION">IMPLICATION</a> | <a href="/documentation/syntax.php#MAPS_TO">MAPS_TO</a> | <a href="/documentation/syntax.php#NAND">NAND</a> | <a href="/documentation/syntax.php#NOR">NOR</a> | <a href="/documentation/syntax.php#OR">OR</a> | <a href="/documentation/syntax.php#XOR">XOR</a></td>
			</tr>
			<tr>
				<td><a id="BINARY_OP" href="/documentation/syntax/BINARY_OP.php">BINARY_OP</a></td>
				<td>a sequence of one or more punctuation (and special) characters representing an infix operator</td>
				<td><a href="/documentation/syntax.php#BINARY_ARITHMETIC_OP">BINARY_ARITHMETIC_OP</a> | <a href="/documentation/syntax.php#BINARY_COLLECTION_OP">BINARY_COLLECTION_OP</a> | <a href="/documentation/syntax.php#BINARY_LOGICAL_OP">BINARY_LOGICAL_OP</a> | <a href="/documentation/syntax.php#BITWISE_OP">BITWISE_OP</a> | <a href="/documentation/syntax.php#CONSTRUCTIVE_OP">CONSTRUCTIVE_OP</a> | <a href="/documentation/syntax.php#RELATIONAL_OP">RELATIONAL_OP</a></td>
			</tr>
			<tr>
				<td><a id="BITWISE_OP" href="/documentation/syntax/BITWISE_OP.php">BITWISE_OP</a></td>
				<td>no doc string</td>
				<td><a href="/documentation/syntax.php#BIT_AND">BIT_AND</a> | <a href="/documentation/syntax.php#BIT_OR">BIT_OR</a> | <a href="/documentation/syntax.php#BIT_XOR">BIT_XOR</a></td>
			</tr>
			<tr>
				<td><a id="BIT_AND" href="/documentation/syntax/BIT_AND.php">BIT_AND</a></td>
				<td>no doc string</td>
				<td><a href="/documentation/syntax.php#EXPRESSION">EXPRESSION</a>  "&amp;&amp;"  <a href="/documentation/syntax.php#EXPRESSION">EXPRESSION</a></td>
			</tr>
			<tr>
				<td><a id="BIT_NOT" href="/documentation/syntax/BIT_NOT.php">BIT_NOT</a></td>
				<td>no doc string</td>
				<td>"~~"  <a href="/documentation/syntax.php#EXPRESSION">EXPRESSION</a></td>
			</tr>
			<tr>
				<td><a id="BIT_OR" href="/documentation/syntax/BIT_OR.php">BIT_OR</a></td>
				<td>no doc string</td>
				<td><a href="/documentation/syntax.php#EXPRESSION">EXPRESSION</a>  "||"  <a href="/documentation/syntax.php#EXPRESSION">EXPRESSION</a></td>
			</tr>
			<tr>
				<td><a id="BIT_XOR" href="/documentation/syntax/BIT_XOR.php">BIT_XOR</a></td>
				<td>no doc string</td>
				<td><a href="/documentation/syntax.php#EXPRESSION">EXPRESSION</a>  "^^"  <a href="/documentation/syntax.php#EXPRESSION">EXPRESSION</a></td>
			</tr>
			<tr>
				<td><a id="BLOCK" href="/documentation/syntax/BLOCK.php">BLOCK</a></td>
				<td>no doc string</td>
				<td>"{" <a href="/documentation/syntax.php#STATEMENT_SCOPE">STATEMENT_SCOPE</a> "}"</td>
			</tr>
			<tr>
				<td><a id="BOOL" href="/documentation/syntax/BOOL.php">BOOL</a></td>
				<td>the two ordinals of the Bool type</td>
				<td>"true" | "false"</td>
			</tr>
			<tr>
				<td><a id="BREAK" href="/documentation/syntax/BREAK.php">BREAK</a></td>
				<td>terminate the containing for, do, or while/until loop</td>
				<td>"break" [("["  <a href="/documentation/syntax.php#EXPRESSION">EXPRESSION</a>  "]") | (<a href="/documentation/syntax.php#IC">IC</a>  <a href="/documentation/syntax.php#IDENTIFIER">IDENTIFIER</a>)]</td>
			</tr>
			<tr>
				<td><a id="CARDINALITY" href="/documentation/syntax/CARDINALITY.php">CARDINALITY</a></td>
				<td>no doc string</td>
				<td>"#"  <a href="/documentation/syntax.php#EXPRESSION">EXPRESSION</a></td>
			</tr>
			<tr>
				<td><a id="CAST" href="/documentation/syntax/CAST.php">CAST</a></td>
				<td>change the type of the specified expression to the parenthesized type</td>
				<td><a href="/documentation/syntax.php#PARENTHETICAL">PARENTHETICAL</a>  <a href="/documentation/syntax.php#EXPRESSION">EXPRESSION</a></td>
			</tr>
			<tr>
				<td><a id="CASTS" href="/documentation/syntax/CASTS.php">CASTS</a></td>
				<td>no doc string</td>
				<td><a href="/documentation/syntax.php#EXPRESSION">EXPRESSION</a>  "casts"  <a href="/documentation/syntax.php#EXPRESSION">EXPRESSION</a></td>
			</tr>
			<tr>
				<td><a id="CEILING" href="/documentation/syntax/CEILING.php">CEILING</a></td>
				<td>no doc string</td>
				<td>("⌈"  <a href="/documentation/syntax.php#EXPRESSION">EXPRESSION</a>  "⌉") | ("|'"  <a href="/documentation/syntax.php#EXPRESSION">EXPRESSION</a>  "'|")</td>
			</tr>
			<tr>
				<td><a id="COMMENT" href="/documentation/syntax/COMMENT.php">COMMENT</a></td>
				<td>an inline comment</td>
				<td>"/*" {all} "*/"</td>
			</tr>
			<tr>
				<td><a id="COMPLEMENT" href="/documentation/syntax/COMPLEMENT.php">COMPLEMENT</a></td>
				<td>the universal set excluding the elements of the collection</td>
				<td><a href="/documentation/syntax.php#EXPRESSION">EXPRESSION</a>  "ᶜ"</td>
			</tr>
			<tr>
				<td><a id="COMPOSITION" href="/documentation/syntax/COMPOSITION.php">COMPOSITION</a></td>
				<td>function composition operator</td>
				<td><a href="/documentation/syntax.php#EXPRESSION">EXPRESSION</a>  ("∘"|"_o_")  <a href="/documentation/syntax.php#EXPRESSION">EXPRESSION</a></td>
			</tr>
			<tr>
				<td><a id="COMPOUND" href="/documentation/syntax/COMPOUND.php">COMPOUND</a></td>
				<td>no doc string</td>
				<td><a href="/documentation/syntax.php#EXPRESSION">EXPRESSION</a>  "|"  <a href="/documentation/syntax.php#EXPRESSION">EXPRESSION</a></td>
			</tr>
			<tr>
				<td><a id="CONDITIONAL" href="/documentation/syntax/CONDITIONAL.php">CONDITIONAL</a></td>
				<td>ternary conditional</td>
				<td>(<a href="/documentation/syntax.php#EXPRESSION">EXPRESSION</a>)  "?"  (<a href="/documentation/syntax.php#EXPRESSION">EXPRESSION</a>)  ":"  (<a href="/documentation/syntax.php#EXPRESSION">EXPRESSION</a>)</td>
			</tr>
			<tr>
				<td><a id="CONSTRUCTIVE_OP" href="/documentation/syntax/CONSTRUCTIVE_OP.php">CONSTRUCTIVE_OP</a></td>
				<td>operators that are constructive for making values</td>
				<td><a href="/documentation/syntax.php#COMPOSITION">COMPOSITION</a> | <a href="/documentation/syntax.php#COMPOUND">COMPOUND</a> | <a href="/documentation/syntax.php#PREPEND">PREPEND</a> | <a href="/documentation/syntax.php#NULL_COALESCE">NULL_COALESCE</a></td>
			</tr>
			<tr>
				<td><a id="CONTINUE" href="/documentation/syntax/CONTINUE.php">CONTINUE</a></td>
				<td>begin the next iteration in the containing for, do, or while/until loop</td>
				<td>"continue" [("["  <a href="/documentation/syntax.php#EXPRESSION">EXPRESSION</a>  "]") | (<a href="/documentation/syntax.php#IC">IC</a>  <a href="/documentation/syntax.php#IDENTIFIER">IDENTIFIER</a>)]</td>
			</tr>
			<tr>
				<td><a id="CROSS_PRODUCT" href="/documentation/syntax/CROSS_PRODUCT.php">CROSS_PRODUCT</a></td>
				<td>scalar multiplication or Vector<3, N> cross product</td>
				<td><a href="/documentation/syntax.php#EXPRESSION">EXPRESSION</a>  ("×"|"_x_")  <a href="/documentation/syntax.php#EXPRESSION">EXPRESSION</a></td>
			</tr>
			<tr>
				<td><a id="DATE" href="/documentation/syntax/DATE.php">DATE</a></td>
				<td>no doc string</td>
				<td><a href="/documentation/syntax.php#DATE_YEAR_MONTH_DAY">DATE_YEAR_MONTH_DAY</a> | <a href="/documentation/syntax.php#DATE_YEAR_DAY">DATE_YEAR_DAY</a></td>
			</tr>
			<tr>
				<td><a id="DATE_TIME" href="/documentation/syntax/DATE_TIME.php">DATE_TIME</a></td>
				<td>no doc string</td>
				<td><a href="/documentation/syntax.php#DATE">DATE</a> "T" <a href="/documentation/syntax.php#TIME">TIME</a></td>
			</tr>
			<tr>
				<td><a id="DATE_YEAR_DAY" href="/documentation/syntax/DATE_YEAR_DAY.php">DATE_YEAR_DAY</a></td>
				<td>no doc string</td>
				<td>decimal_digit decimal_digit decimal_digit decimal_digit "-" decimal_digit decimal_digit decimal_digit</td>
			</tr>
			<tr>
				<td><a id="DATE_YEAR_MONTH_DAY" href="/documentation/syntax/DATE_YEAR_MONTH_DAY.php">DATE_YEAR_MONTH_DAY</a></td>
				<td>a date literal</td>
				<td>decimal_digit decimal_digit decimal_digit decimal_digit "-" decimal_digit decimal_digit "-" decimal_digit decimal_digit</td>
			</tr>
			<tr>
				<td><a id="DECLARATION" href="/documentation/syntax/DECLARATION.php">DECLARATION</a></td>
				<td>declare a variable and optionally assign a value to it</td>
				<td>[<a href="/documentation/syntax.php#XML_DOC_STRING">XML_DOC_STRING</a>] <a href="/documentation/syntax.php#IDENTIFIER">IDENTIFIER</a></td>
			</tr>
			<tr>
				<td><a id="DEFINITION" href="/documentation/syntax/DEFINITION.php">DEFINITION</a></td>
				<td>define a constant, an alias for the valuation of a specified expression</td>
				<td>[<a href="/documentation/syntax.php#XML_DOC_STRING">XML_DOC_STRING</a>] <a href="/documentation/syntax.php#IDENTIFIER">IDENTIFIER</a>  ":="  <a href="/documentation/syntax.php#EXPRESSION">EXPRESSION</a></td>
			</tr>
			<tr>
				<td><a id="DELTA" href="/documentation/syntax/DELTA.php">DELTA</a></td>
				<td>no doc string</td>
				<td>("Δ"|"_delta_") ["^" <a href="/documentation/syntax.php#WHOLE_NUMBER">WHOLE_NUMBER</a>] <a href="/documentation/syntax.php#EXPRESSION">EXPRESSION</a></td>
			</tr>
			<tr>
				<td><a id="DIMENSION" href="/documentation/syntax/DIMENSION.php">DIMENSION</a></td>
				<td>a dimension used in dimensional analysis</td>
				<td><a href="/documentation/syntax.php#IDENTIFIER">IDENTIFIER</a> | <a href="/documentation/syntax.php#DIMENSIONAL_ANALYSIS_OP">DIMENSIONAL_ANALYSIS_OP</a></td>
			</tr>
			<tr>
				<td><a id="DIMENSIONAL_ANALYSIS_OP" href="/documentation/syntax/DIMENSIONAL_ANALYSIS_OP.php">DIMENSIONAL_ANALYSIS_OP</a></td>
				<td>operators in a dimension</td>
				<td><a href="/documentation/syntax.php#UNIT_DIVISION">UNIT_DIVISION</a> | <a href="/documentation/syntax.php#UNIT_EXPONENTIATION">UNIT_EXPONENTIATION</a> | <a href="/documentation/syntax.php#UNIT_MULTIPLICATION">UNIT_MULTIPLICATION</a></td>
			</tr>
			<tr>
				<td><a id="DIMENSIONAL_NUMBER" href="/documentation/syntax/DIMENSIONAL_NUMBER.php">DIMENSIONAL_NUMBER</a></td>
				<td>a number with a trailing dimension</td>
				<td><a href="/documentation/syntax.php#NON_NEG_NUMBER">NON_NEG_NUMBER</a> <a href="/documentation/syntax.php#DIMENSION">DIMENSION</a></td>
			</tr>
			<tr>
				<td><a id="DIVISION" href="/documentation/syntax/DIVISION.php">DIVISION</a></td>
				<td>division or splits the left hand side collection into a collection of collections each the size of the right hand side</td>
				<td><a href="/documentation/syntax.php#EXPRESSION">EXPRESSION</a>  ("÷"|"/")  <a href="/documentation/syntax.php#EXPRESSION">EXPRESSION</a></td>
			</tr>
			<tr>
				<td><a id="DO" href="/documentation/syntax/DO.php">DO</a></td>
				<td>invoke a specified nullary void function (expression) once and then repeatedly while or until the parenthetical evaluates to true (when coerced to bool), unless the optional portion is omitted, in which case the function is invoked indefinitely</td>
				<td>"do"  <a href="/documentation/syntax.php#EXPRESSION">EXPRESSION</a> [ ("while"|"until")  (<a href="/documentation/syntax.php#PARENTHETICAL">PARENTHETICAL</a>)]</td>
			</tr>
			<tr>
				<td><a id="DOT_PRODUCT" href="/documentation/syntax/DOT_PRODUCT.php">DOT_PRODUCT</a></td>
				<td>scalar multiplication or Vector<D, N> inner product</td>
				<td><a href="/documentation/syntax.php#EXPRESSION">EXPRESSION</a>  ("⋅"|"_dot_")  <a href="/documentation/syntax.php#EXPRESSION">EXPRESSION</a></td>
			</tr>
			<tr>
				<td><a id="DOWNCASTS" href="/documentation/syntax/DOWNCASTS.php">DOWNCASTS</a></td>
				<td>no doc string</td>
				<td><a href="/documentation/syntax.php#EXPRESSION">EXPRESSION</a>  "downcasts"  <a href="/documentation/syntax.php#EXPRESSION">EXPRESSION</a></td>
			</tr>
			<tr>
				<td><a id="EMBEDDED_COMMENT" href="/documentation/syntax/EMBEDDED_COMMENT.php">EMBEDDED_COMMENT</a></td>
				<td>a comment bounded by arbirtrarily-sized delimiters</td>
				<td>"/***" <a href="/documentation/syntax.php#EMBEDDED_COMMENT_INTERIOR">EMBEDDED_COMMENT_INTERIOR</a> "***/"</td>
			</tr>
			<tr>
				<td><a id="EMBEDDED_COMMENT_INTERIOR" href="/documentation/syntax/EMBEDDED_COMMENT_INTERIOR.php">EMBEDDED_COMMENT_INTERIOR</a></td>
				<td>no doc string</td>
				<td><a href="/documentation/syntax.php#PAYLOAD">PAYLOAD</a> | "*" EMBEDDED_COMMENT_INTERIOR "*"</td>
			</tr>
			<tr>
				<td><a id="EMBEDDED_NEWLINE_STRING" href="/documentation/syntax/EMBEDDED_NEWLINE_STRING.php">EMBEDDED_NEWLINE_STRING</a></td>
				<td>no doc string</td>
				<td>"\"\"\"" <a href="/documentation/syntax.php#EMBEDDED_NEWLINE_STRING_INTERIOR">EMBEDDED_NEWLINE_STRING_INTERIOR</a> "\"\"\""</td>
			</tr>
			<tr>
				<td><a id="EMBEDDED_NEWLINE_STRING_INTERIOR" href="/documentation/syntax/EMBEDDED_NEWLINE_STRING_INTERIOR.php">EMBEDDED_NEWLINE_STRING_INTERIOR</a></td>
				<td>no doc string</td>
				<td>("\n" <a href="/documentation/syntax.php#PAYLOAD">PAYLOAD</a> "\n") | ("\"" EMBEDDED_NEWLINE_STRING_INTERIOR "\"")</td>
			</tr>
			<tr>
				<td><a id="EMBEDDED_STRING" href="/documentation/syntax/EMBEDDED_STRING.php">EMBEDDED_STRING</a></td>
				<td>a string bounded by arbirtrarily-sized delimiters</td>
				<td>"\"\"\"" <a href="/documentation/syntax.php#EMBEDDED_STRING_INTERIOR">EMBEDDED_STRING_INTERIOR</a> "\"\"\""</td>
			</tr>
			<tr>
				<td><a id="EMBEDDED_STRING_INTERIOR" href="/documentation/syntax/EMBEDDED_STRING_INTERIOR.php">EMBEDDED_STRING_INTERIOR</a></td>
				<td>no doc string</td>
				<td><a href="/documentation/syntax.php#PAYLOAD">PAYLOAD</a> | ("\"" EMBEDDED_STRING_INTERIOR "\"")</td>
			</tr>
			<tr>
				<td><a id="END_OF_LINE_COMMENT" href="/documentation/syntax/END_OF_LINE_COMMENT.php">END_OF_LINE_COMMENT</a></td>
				<td>no doc string</td>
				<td>"//" {not_newline} "\n"</td>
			</tr>
			<tr>
				<td><a id="ENUM" href="/documentation/syntax/ENUM.php">ENUM</a></td>
				<td>makes a compound type with static members for each of the elements, and each of those elements inherit/implement those specified inheritance list</td>
				<td>"enum"  ["inheriting"  <a href="/documentation/syntax.php#INHERITANCE_LIST">INHERITANCE_LIST</a>] ["implementing"  <a href="/documentation/syntax.php#INHERITANCE_LIST">INHERITANCE_LIST</a>] "{" [<a href="/documentation/syntax.php#ENUM_ELEMENT">ENUM_ELEMENT</a> {";"  <a href="/documentation/syntax.php#ENUM_ELEMENT">ENUM_ELEMENT</a>}] "}"</td>
			</tr>
			<tr>
				<td><a id="ENUM_ELEMENT" href="/documentation/syntax/ENUM_ELEMENT.php">ENUM_ELEMENT</a></td>
				<td>no doc string</td>
				<td><a href="/documentation/syntax.php#IDENTIFIER">IDENTIFIER</a> [":="  <a href="/documentation/syntax.php#EXPRESSION">EXPRESSION</a>]</td>
			</tr>
			<tr>
				<td><a id="EQUALITY_CHAIN" href="/documentation/syntax/EQUALITY_CHAIN.php">EQUALITY_CHAIN</a></td>
				<td>one or more equality relations</td>
				<td><a href="/documentation/syntax.php#EXPRESSION">EXPRESSION</a>  <a href="/documentation/syntax.php#EQUALITY_CHAIN_LOOP">EQUALITY_CHAIN_LOOP</a></td>
			</tr>
			<tr>
				<td><a id="EQUALITY_CHAIN_LOOP" href="/documentation/syntax/EQUALITY_CHAIN_LOOP.php">EQUALITY_CHAIN_LOOP</a></td>
				<td>no doc string</td>
				<td>"="  <a href="/documentation/syntax.php#EXPRESSION">EXPRESSION</a> [EQUALITY_CHAIN_LOOP]</td>
			</tr>
			<tr>
				<td><a id="EXACTLY" href="/documentation/syntax/EXACTLY.php">EXACTLY</a></td>
				<td>no doc string</td>
				<td><a href="/documentation/syntax.php#EXPRESSION">EXPRESSION</a>  "exactly"  <a href="/documentation/syntax.php#EXPRESSION">EXPRESSION</a></td>
			</tr>
			<tr>
				<td><a id="EXISTS" href="/documentation/syntax/EXISTS.php">EXISTS</a></td>
				<td>a constraint asserting that at least one element of the specified Collection is true</td>
				<td>("∃"|"exists")  <a href="/documentation/syntax.php#EXPRESSION">EXPRESSION</a></td>
			</tr>
			<tr>
				<td><a id="EXISTS_ONE" href="/documentation/syntax/EXISTS_ONE.php">EXISTS_ONE</a></td>
				<td>a constraint asserting that exactly one element of the specified Collection is true</td>
				<td>("∃!"|"exists!")  <a href="/documentation/syntax.php#EXPRESSION">EXPRESSION</a></td>
			</tr>
			<tr>
				<td><a id="EXPONENTIATION" href="/documentation/syntax/EXPONENTIATION.php">EXPONENTIATION</a></td>
				<td>no doc string</td>
				<td><a href="/documentation/syntax.php#EXPRESSION">EXPRESSION</a>  "^"  <a href="/documentation/syntax.php#EXPRESSION">EXPRESSION</a></td>
			</tr>
			<tr>
				<td><a id="EXPRESSION" href="/documentation/syntax/EXPRESSION.php">EXPRESSION</a></td>
				<td>a linearization of an evaluation tree containing constants, variables, operators, invocations, and sub expressions</td>
				<td><a href="/documentation/syntax.php#ARRAY">ARRAY</a> | <a href="/documentation/syntax.php#ASM_FUNCTION">ASM_FUNCTION</a> | <a href="/documentation/syntax.php#BINARY_OP">BINARY_OP</a> | <a href="/documentation/syntax.php#BOOL">BOOL</a> | <a href="/documentation/syntax.php#CAST">CAST</a> | <a href="/documentation/syntax.php#CEILING">CEILING</a> | <a href="/documentation/syntax.php#COMPLEMENT">COMPLEMENT</a> | <a href="/documentation/syntax.php#CONDITIONAL">CONDITIONAL</a> | <a href="/documentation/syntax.php#DATE">DATE</a> | <a href="/documentation/syntax.php#DATE_TIME">DATE_TIME</a> | <a href="/documentation/syntax.php#DELTA">DELTA</a> | <a href="/documentation/syntax.php#DIMENSIONAL_NUMBER">DIMENSIONAL_NUMBER</a> | <a href="/documentation/syntax.php#EMBEDDED_STRING">EMBEDDED_STRING</a> | <a href="/documentation/syntax.php#ENUM">ENUM</a> | <a href="/documentation/syntax.php#EQUALITY_CHAIN">EQUALITY_CHAIN</a> | <a href="/documentation/syntax.php#FLOOR">FLOOR</a> | <a href="/documentation/syntax.php#FUNCTION">FUNCTION</a> | <a href="/documentation/syntax.php#GREATER_CHAIN">GREATER_CHAIN</a> | <a href="/documentation/syntax.php#IDENTIFIER">IDENTIFIER</a> | <a href="/documentation/syntax.php#IF">IF</a> | <a href="/documentation/syntax.php#INVOCATION">INVOCATION</a> | <a href="/documentation/syntax.php#LESSER_CHAIN">LESSER_CHAIN</a> | <a href="/documentation/syntax.php#LIST">LIST</a> | <a href="/documentation/syntax.php#MAGNITUDE">MAGNITUDE</a> | <a href="/documentation/syntax.php#MAP">MAP</a> | <a href="/documentation/syntax.php#MEMBER_ACCESS">MEMBER_ACCESS</a> | <a href="/documentation/syntax.php#NEAREST_INTEGER">NEAREST_INTEGER</a> | <a href="/documentation/syntax.php#NON_NEG_NUMBER">NON_NEG_NUMBER</a> | <a href="/documentation/syntax.php#OBJECT">OBJECT</a> | <a href="/documentation/syntax.php#PARENTHETICAL">PARENTHETICAL</a> | <a href="/documentation/syntax.php#RANGE">RANGE</a> | <a href="/documentation/syntax.php#REGEX">REGEX</a> | <a href="/documentation/syntax.php#SET">SET</a> | <a href="/documentation/syntax.php#SET_COMPREHENSION">SET_COMPREHENSION</a> | <a href="/documentation/syntax.php#SUBSET_CHAIN">SUBSET_CHAIN</a> | <a href="/documentation/syntax.php#SUPERSET_CHAIN">SUPERSET_CHAIN</a> | <a href="/documentation/syntax.php#SWIZZLE">SWIZZLE</a> | <a href="/documentation/syntax.php#THIS">THIS</a> | <a href="/documentation/syntax.php#THIS_FUNC">THIS_FUNC</a> | <a href="/documentation/syntax.php#THIS_TYPE">THIS_TYPE</a> | <a href="/documentation/syntax.php#TIME">TIME</a> | <a href="/documentation/syntax.php#TUPLE">TUPLE</a> | <a href="/documentation/syntax.php#TYPE">TYPE</a> | <a href="/documentation/syntax.php#UNARY_OP">UNARY_OP</a> | <a href="/documentation/syntax.php#VECTOR_NORM">VECTOR_NORM</a> | "context" | "null" | c_string</td>
			</tr>
			<tr>
				<td><a id="EXTERN" href="/documentation/syntax/EXTERN.php">EXTERN</a></td>
				<td>no doc string</td>
				<td>"extern"</td>
			</tr>
			<tr>
				<td><a id="FACTORIAL" href="/documentation/syntax/FACTORIAL.php">FACTORIAL</a></td>
				<td>no doc string</td>
				<td><a href="/documentation/syntax.php#EXPRESSION">EXPRESSION</a>  "!"</td>
			</tr>
			<tr>
				<td><a id="FLOOR" href="/documentation/syntax/FLOOR.php">FLOOR</a></td>
				<td>no doc string</td>
				<td>("⌊"  <a href="/documentation/syntax.php#EXPRESSION">EXPRESSION</a>  "⌋") | ("|_"  <a href="/documentation/syntax.php#EXPRESSION">EXPRESSION</a>  "_|")</td>
			</tr>
			<tr>
				<td><a id="FOR" href="/documentation/syntax/FOR.php">FOR</a></td>
				<td>evaluate the last expression repeatedly while the second expression is true, all after evaluating the optional STATEMENT_SCOPE</td>
				<td>"for"  "("  [(<a href="/documentation/syntax.php#STATEMENT_SCOPE">STATEMENT_SCOPE</a>)] (<a href="/documentation/syntax.php#EXPRESSION">EXPRESSION</a>)  ";"  [<a href="/documentation/syntax.php#ASSIGNMENT_CHAIN">ASSIGNMENT_CHAIN</a> {","  <a href="/documentation/syntax.php#ASSIGNMENT_CHAIN">ASSIGNMENT_CHAIN</a>}] ")"  <a href="/documentation/syntax.php#EXPRESSION">EXPRESSION</a></td>
			</tr>
			<tr>
				<td><a id="FOR_COLLECTION" href="/documentation/syntax/FOR_COLLECTION.php">FOR_COLLECTION</a></td>
				<td>evaluate the last expression repeatedly while iterating over the elements of the specified Collection</td>
				<td>"for"  "("  (([(<a href="/documentation/syntax.php#TYPE_DEREFERENCE">TYPE_DEREFERENCE</a> | <a href="/documentation/syntax.php#IMPLICIT_TYPE_DEREFERENCE">IMPLICIT_TYPE_DEREFERENCE</a>)] <a href="/documentation/syntax.php#IDENTIFIER">IDENTIFIER</a>) | <a href="/documentation/syntax.php#EXPRESSION">EXPRESSION</a>)  ("in"|"∈")  (<a href="/documentation/syntax.php#EXPRESSION">EXPRESSION</a>)  ")"  (<a href="/documentation/syntax.php#EXPRESSION">EXPRESSION</a>)</td>
			</tr>
			<tr>
				<td><a id="FREE" href="/documentation/syntax/FREE.php">FREE</a></td>
				<td>no doc string</td>
				<td>"free"  <a href="/documentation/syntax.php#EXPRESSION">EXPRESSION</a></td>
			</tr>
			<tr>
				<td><a id="FUNCTION" href="/documentation/syntax/FUNCTION.php">FUNCTION</a></td>
				<td>creates a function</td>
				<td>["("  [<a href="/documentation/syntax.php#PARAMETER">PARAMETER</a> {","  <a href="/documentation/syntax.php#PARAMETER">PARAMETER</a>}] ")"] [<a href="/documentation/syntax.php#FUNCTION_MODIFIER_0">FUNCTION_MODIFIER_0</a>] <a href="/documentation/syntax.php#BLOCK">BLOCK</a></td>
			</tr>
			<tr>
				<td><a id="FUNCTION_MODIFIER_0" href="/documentation/syntax/FUNCTION_MODIFIER_0.php">FUNCTION_MODIFIER_0</a></td>
				<td>no doc string</td>
				<td><a href="/documentation/syntax.php#FUNCTION_MODIFIER_STABILITY">FUNCTION_MODIFIER_STABILITY</a>|<a href="/documentation/syntax.php#FUNCTION_MODIFIER_1">FUNCTION_MODIFIER_1</a></td>
			</tr>
			<tr>
				<td><a id="FUNCTION_MODIFIER_1" href="/documentation/syntax/FUNCTION_MODIFIER_1.php">FUNCTION_MODIFIER_1</a></td>
				<td>no doc string</td>
				<td><a href="/documentation/syntax.php#FUNCTION_MODIFIER_THROWING">FUNCTION_MODIFIER_THROWING</a>|<a href="/documentation/syntax.php#FUNCTION_MODIFIER_2">FUNCTION_MODIFIER_2</a></td>
			</tr>
			<tr>
				<td><a id="FUNCTION_MODIFIER_2" href="/documentation/syntax/FUNCTION_MODIFIER_2.php">FUNCTION_MODIFIER_2</a></td>
				<td>no doc string</td>
				<td><a href="/documentation/syntax.php#FUNCTION_MODIFIER_ATOMIC">FUNCTION_MODIFIER_ATOMIC</a>|<a href="/documentation/syntax.php#FUNCTION_MODIFIER_3">FUNCTION_MODIFIER_3</a></td>
			</tr>
			<tr>
				<td><a id="FUNCTION_MODIFIER_3" href="/documentation/syntax/FUNCTION_MODIFIER_3.php">FUNCTION_MODIFIER_3</a></td>
				<td>no doc string</td>
				<td><a href="/documentation/syntax.php#FUNCTION_MODIFIER_PLATFORM">FUNCTION_MODIFIER_PLATFORM</a>|<a href="/documentation/syntax.php#FUNCTION_MODIFIER_4">FUNCTION_MODIFIER_4</a></td>
			</tr>
			<tr>
				<td><a id="FUNCTION_MODIFIER_4" href="/documentation/syntax/FUNCTION_MODIFIER_4.php">FUNCTION_MODIFIER_4</a></td>
				<td>no doc string</td>
				<td><a href="/documentation/syntax.php#FUNCTION_MODIFIER_MODEL">FUNCTION_MODIFIER_MODEL</a>|<a href="/documentation/syntax.php#FUNCTION_MODIFIER_CALLING_CONVENTION">FUNCTION_MODIFIER_CALLING_CONVENTION</a></td>
			</tr>
			<tr>
				<td><a id="FUNCTION_MODIFIER_ATOMIC" href="/documentation/syntax/FUNCTION_MODIFIER_ATOMIC.php">FUNCTION_MODIFIER_ATOMIC</a></td>
				<td>no doc string</td>
				<td>"atomic" [<a href="/documentation/syntax.php#IC">IC</a>  <a href="/documentation/syntax.php#FUNCTION_MODIFIER_3">FUNCTION_MODIFIER_3</a>]</td>
			</tr>
			<tr>
				<td><a id="FUNCTION_MODIFIER_CALLING_CONVENTION" href="/documentation/syntax/FUNCTION_MODIFIER_CALLING_CONVENTION.php">FUNCTION_MODIFIER_CALLING_CONVENTION</a></td>
				<td>no doc string</td>
				<td>"c_call" | "fast_call" | "cold_call" | "ghc_call" | "hipe_call" | "webkit_js_call" | "any_reg_call" | "preserve_most_call" | "preserve_all_call" | "swift_call" | "cxx_fast_tls_call" | "first_target_call" | "x86_std_call" | "X86_fast_call" | "arm_apcs_call" | "arm_aapcs_call" | "arm_aapcs_vfp_call" | "msp430_intr_call" | "x86_this_call" | "ptx_kernel_call" | "ptx_device_call" | "spir_func_call" | "spir_kernel_call" | "intel_ocl_bi_call" | "x86_64_sysv_call" | "x86_64_win64_call" | "x86_vector_call" | "hhvm_call" | "x86_intr_call" | "avr_intr_call" | "avr_signal_call" | "avr_builtin_call"</td>
			</tr>
			<tr>
				<td><a id="FUNCTION_MODIFIER_MODEL" href="/documentation/syntax/FUNCTION_MODIFIER_MODEL.php">FUNCTION_MODIFIER_MODEL</a></td>
				<td>no doc string</td>
				<td>("pure" | "imperative" | "opaque") [<a href="/documentation/syntax.php#IC">IC</a>  <a href="/documentation/syntax.php#FUNCTION_MODIFIER_CALLING_CONVENTION">FUNCTION_MODIFIER_CALLING_CONVENTION</a>]</td>
			</tr>
			<tr>
				<td><a id="FUNCTION_MODIFIER_PLATFORM" href="/documentation/syntax/FUNCTION_MODIFIER_PLATFORM.php">FUNCTION_MODIFIER_PLATFORM</a></td>
				<td>no doc string</td>
				<td><a href="/documentation/syntax.php#PLATFORM">PLATFORM</a> {<a href="/documentation/syntax.php#IC">IC</a>  <a href="/documentation/syntax.php#PLATFORM">PLATFORM</a>} [<a href="/documentation/syntax.php#IC">IC</a>  <a href="/documentation/syntax.php#FUNCTION_MODIFIER_4">FUNCTION_MODIFIER_4</a>]</td>
			</tr>
			<tr>
				<td><a id="FUNCTION_MODIFIER_STABILITY" href="/documentation/syntax/FUNCTION_MODIFIER_STABILITY.php">FUNCTION_MODIFIER_STABILITY</a></td>
				<td>no doc string</td>
				<td>("stable" | "unstable") [<a href="/documentation/syntax.php#IC">IC</a>  <a href="/documentation/syntax.php#FUNCTION_MODIFIER_1">FUNCTION_MODIFIER_1</a>]</td>
			</tr>
			<tr>
				<td><a id="FUNCTION_MODIFIER_THROWING" href="/documentation/syntax/FUNCTION_MODIFIER_THROWING.php">FUNCTION_MODIFIER_THROWING</a></td>
				<td>no doc string</td>
				<td>"throwing" [<a href="/documentation/syntax.php#ARRAY">ARRAY</a>] [<a href="/documentation/syntax.php#IC">IC</a>  <a href="/documentation/syntax.php#FUNCTION_MODIFIER_2">FUNCTION_MODIFIER_2</a>]</td>
			</tr>
			<tr>
				<td><a id="GREATER_CHAIN" href="/documentation/syntax/GREATER_CHAIN.php">GREATER_CHAIN</a></td>
				<td>one or more greater, greater or equals, or equals relations</td>
				<td><a href="/documentation/syntax.php#EXPRESSION">EXPRESSION</a>  <a href="/documentation/syntax.php#GREATER_CHAIN_LOOP">GREATER_CHAIN_LOOP</a></td>
			</tr>
			<tr>
				<td><a id="GREATER_CHAIN_LOOP" href="/documentation/syntax/GREATER_CHAIN_LOOP.php">GREATER_CHAIN_LOOP</a></td>
				<td>no doc string</td>
				<td>("="|"&gt;"|"=&gt;"|"≥")  <a href="/documentation/syntax.php#EXPRESSION">EXPRESSION</a> [GREATER_CHAIN_LOOP]</td>
			</tr>
			<tr>
				<td><a id="HAS" href="/documentation/syntax/HAS.php">HAS</a></td>
				<td>the in operator, backward</td>
				<td><a href="/documentation/syntax.php#EXPRESSION">EXPRESSION</a>  ("∋"|"has")  <a href="/documentation/syntax.php#EXPRESSION">EXPRESSION</a></td>
			</tr>
			<tr>
				<td><a id="HEX" href="/documentation/syntax/HEX.php">HEX</a></td>
				<td>a hexidecimal number</td>
				<td>"0x" hexadecimal_digit {hexadecimal_digit}</td>
			</tr>
			<tr>
				<td><a id="IC" href="/documentation/syntax/IC.php">IC</a></td>
				<td>intermediary content - regions that whitespaces and comments can go</td>
				<td><a href="/documentation/syntax.php#COMMENT">COMMENT</a> | <a href="/documentation/syntax.php#EMBEDDED_COMMENT">EMBEDDED_COMMENT</a> | <a href="/documentation/syntax.php#END_OF_LINE_COMMENT">END_OF_LINE_COMMENT</a> | <a href="/documentation/syntax.php#WS">WS</a></td>
			</tr>
			<tr>
				<td><a id="IDENTIFIER" href="/documentation/syntax/IDENTIFIER.php">IDENTIFIER</a></td>
				<td>text that uniquely identifies a constant or variable within a scope</td>
				<td>(letter | "_") {letter | number | "_"}</td>
			</tr>
			<tr>
				<td><a id="IF" href="/documentation/syntax/IF.php">IF</a></td>
				<td>returns the expression corresponding to the first parenthetical that evaluates to true when coerced to a boolean, or the else case if none of them evaluate to true, assuming that the else case is present, otherwise returning void</td>
				<td>"if"  (<a href="/documentation/syntax.php#PARENTHETICAL">PARENTHETICAL</a>)  (<a href="/documentation/syntax.php#EXPRESSION">EXPRESSION</a>) {"elif"  (<a href="/documentation/syntax.php#PARENTHETICAL">PARENTHETICAL</a>)  (<a href="/documentation/syntax.php#EXPRESSION">EXPRESSION</a>)} [ "else"  (<a href="/documentation/syntax.php#EXPRESSION">EXPRESSION</a>)]</td>
			</tr>
			<tr>
				<td><a id="IFF" href="/documentation/syntax/IFF.php">IFF</a></td>
				<td>semantic equivalence</td>
				<td><a href="/documentation/syntax.php#EXPRESSION">EXPRESSION</a>  ("⇔"|"&lt;=&gt;")  <a href="/documentation/syntax.php#EXPRESSION">EXPRESSION</a></td>
			</tr>
			<tr>
				<td><a id="IMPLEMENTS" href="/documentation/syntax/IMPLEMENTS.php">IMPLEMENTS</a></td>
				<td>no doc string</td>
				<td><a href="/documentation/syntax.php#EXPRESSION">EXPRESSION</a>  "implements"  <a href="/documentation/syntax.php#EXPRESSION">EXPRESSION</a></td>
			</tr>
			<tr>
				<td><a id="IMPLICATION" href="/documentation/syntax/IMPLICATION.php">IMPLICATION</a></td>
				<td>implication</td>
				<td><a href="/documentation/syntax.php#EXPRESSION">EXPRESSION</a>  ("⇒"|"=&gt;")  <a href="/documentation/syntax.php#EXPRESSION">EXPRESSION</a></td>
			</tr>
			<tr>
				<td><a id="IMPLICIT_TYPE_DEREFERENCE" href="/documentation/syntax/IMPLICIT_TYPE_DEREFERENCE.php">IMPLICIT_TYPE_DEREFERENCE</a></td>
				<td>use the type inferred on the right hand side</td>
				<td>"&lt;"  "&gt;"</td>
			</tr>
			<tr>
				<td><a id="IMPORT" href="/documentation/syntax/IMPORT.php">IMPORT</a></td>
				<td>bring the specified</td>
				<td>"import"  <a href="/documentation/syntax.php#EXPRESSION">EXPRESSION</a></td>
			</tr>
			<tr>
				<td><a id="IN" href="/documentation/syntax/IN.php">IN</a></td>
				<td>Collection membership</td>
				<td><a href="/documentation/syntax.php#EXPRESSION">EXPRESSION</a>  ("∈"|"in")  <a href="/documentation/syntax.php#EXPRESSION">EXPRESSION</a></td>
			</tr>
			<tr>
				<td><a id="INEQUALITY" href="/documentation/syntax/INEQUALITY.php">INEQUALITY</a></td>
				<td>no doc string</td>
				<td><a href="/documentation/syntax.php#EXPRESSION">EXPRESSION</a>  ("≠"|"/=")  <a href="/documentation/syntax.php#EXPRESSION">EXPRESSION</a></td>
			</tr>
			<tr>
				<td><a id="INHERITANCE_ITEM_PREFIX" href="/documentation/syntax/INHERITANCE_ITEM_PREFIX.php">INHERITANCE_ITEM_PREFIX</a></td>
				<td>no doc string</td>
				<td>(<a href="/documentation/syntax.php#VISIBILITY_MODIFIER">VISIBILITY_MODIFIER</a> | <a href="/documentation/syntax.php#VISIBILITY_MODIFIER">VISIBILITY_MODIFIER</a> <a href="/documentation/syntax.php#IC">IC</a>  "diamond" | "diamond") <a href="/documentation/syntax.php#IC">IC</a> </td>
			</tr>
			<tr>
				<td><a id="INHERITANCE_LIST" href="/documentation/syntax/INHERITANCE_LIST.php">INHERITANCE_LIST</a></td>
				<td>see: type</td>
				<td>[<a href="/documentation/syntax.php#INHERITANCE_ITEM_PREFIX">INHERITANCE_ITEM_PREFIX</a>] <a href="/documentation/syntax.php#EXPRESSION">EXPRESSION</a> {","  [<a href="/documentation/syntax.php#INHERITANCE_ITEM_PREFIX">INHERITANCE_ITEM_PREFIX</a>] <a href="/documentation/syntax.php#EXPRESSION">EXPRESSION</a>}</td>
			</tr>
			<tr>
				<td><a id="INHERITS" href="/documentation/syntax/INHERITS.php">INHERITS</a></td>
				<td>no doc string</td>
				<td><a href="/documentation/syntax.php#EXPRESSION">EXPRESSION</a>  "inherits"  <a href="/documentation/syntax.php#EXPRESSION">EXPRESSION</a></td>
			</tr>
			<tr>
				<td><a id="INTEGER_DIVISION" href="/documentation/syntax/INTEGER_DIVISION.php">INTEGER_DIVISION</a></td>
				<td>same as ⌊x/y⌋ or collection difference (similar to set difference)</td>
				<td><a href="/documentation/syntax.php#EXPRESSION">EXPRESSION</a>  "\\"  <a href="/documentation/syntax.php#EXPRESSION">EXPRESSION</a></td>
			</tr>
			<tr>
				<td><a id="INTERSECTION" href="/documentation/syntax/INTERSECTION.php">INTERSECTION</a></td>
				<td>Collection intersection</td>
				<td><a href="/documentation/syntax.php#EXPRESSION">EXPRESSION</a>  "∩"  <a href="/documentation/syntax.php#EXPRESSION">EXPRESSION</a></td>
			</tr>
			<tr>
				<td><a id="INVOCATION" href="/documentation/syntax/INVOCATION.php">INVOCATION</a></td>
				<td>invoke a function, type-function or array-function</td>
				<td><a href="/documentation/syntax.php#PARENTHETICAL_INVOCATION">PARENTHETICAL_INVOCATION</a> | <a href="/documentation/syntax.php#ARRAY_INVOCATION">ARRAY_INVOCATION</a> | <a href="/documentation/syntax.php#TYPE_INVOCATION">TYPE_INVOCATION</a></td>
			</tr>
			<tr>
				<td><a id="IS" href="/documentation/syntax/IS.php">IS</a></td>
				<td>no doc string</td>
				<td><a href="/documentation/syntax.php#EXPRESSION">EXPRESSION</a>  "is"  <a href="/documentation/syntax.php#EXPRESSION">EXPRESSION</a></td>
			</tr>
			<tr>
				<td><a id="KLEENE_STAR" href="/documentation/syntax/KLEENE_STAR.php">KLEENE_STAR</a></td>
				<td>the free monoid operator</td>
				<td><a href="/documentation/syntax.php#EXPRESSION">EXPRESSION</a>  "*"</td>
			</tr>
			<tr>
				<td><a id="LESSER_CHAIN" href="/documentation/syntax/LESSER_CHAIN.php">LESSER_CHAIN</a></td>
				<td>one or more lesser, lesser or equals, or equals relations</td>
				<td><a href="/documentation/syntax.php#EXPRESSION">EXPRESSION</a>  <a href="/documentation/syntax.php#LESSER_CHAIN_LOOP">LESSER_CHAIN_LOOP</a></td>
			</tr>
			<tr>
				<td><a id="LESSER_CHAIN_LOOP" href="/documentation/syntax/LESSER_CHAIN_LOOP.php">LESSER_CHAIN_LOOP</a></td>
				<td>no doc string</td>
				<td>("="|"&lt;"|"=&lt;"|"≤")  <a href="/documentation/syntax.php#EXPRESSION">EXPRESSION</a> [LESSER_CHAIN_LOOP]</td>
			</tr>
			<tr>
				<td><a id="LIST" href="/documentation/syntax/LIST.php">LIST</a></td>
				<td>a Collection of items</td>
				<td>"[|"  [<a href="/documentation/syntax.php#EXPRESSION">EXPRESSION</a> {", "  <a href="/documentation/syntax.php#EXPRESSION">EXPRESSION</a>}] "|]"</td>
			</tr>
			<tr>
				<td><a id="LOCK" href="/documentation/syntax/LOCK.php">LOCK</a></td>
				<td>no doc string</td>
				<td>"lock"  <a href="/documentation/syntax.php#PARENTHETICAL">PARENTHETICAL</a>  <a href="/documentation/syntax.php#BLOCK">BLOCK</a></td>
			</tr>
			<tr>
				<td><a id="LOOP" href="/documentation/syntax/LOOP.php">LOOP</a></td>
				<td>evaluate an expression repeatedly while or until a parenthetical evaluates to true</td>
				<td>("while" | "until")  <a href="/documentation/syntax.php#PARENTHETICAL">PARENTHETICAL</a>  <a href="/documentation/syntax.php#EXPRESSION">EXPRESSION</a></td>
			</tr>
			<tr>
				<td><a id="MAGNITUDE" href="/documentation/syntax/MAGNITUDE.php">MAGNITUDE</a></td>
				<td>absolute value, vector magnitude, cardinality</td>
				<td>"|"  <a href="/documentation/syntax.php#EXPRESSION">EXPRESSION</a>  "|"</td>
			</tr>
			<tr>
				<td><a id="MAP" href="/documentation/syntax/MAP.php">MAP</a></td>
				<td>create an associative Collection implementing Map<a → b></td>
				<td>"{" [<a href="/documentation/syntax.php#EXPRESSION">EXPRESSION</a>  ":"  <a href="/documentation/syntax.php#EXPRESSION">EXPRESSION</a> {","  <a href="/documentation/syntax.php#EXPRESSION">EXPRESSION</a>  ":"  <a href="/documentation/syntax.php#EXPRESSION">EXPRESSION</a>}]  "}"</td>
			</tr>
			<tr>
				<td><a id="MAPS_TO" href="/documentation/syntax/MAPS_TO.php">MAPS_TO</a></td>
				<td>function type builder</td>
				<td><a href="/documentation/syntax.php#EXPRESSION">EXPRESSION</a>  ("→"|"-&gt;")  <a href="/documentation/syntax.php#EXPRESSION">EXPRESSION</a></td>
			</tr>
			<tr>
				<td><a id="MEMBER_ACCESS" href="/documentation/syntax/MEMBER_ACCESS.php">MEMBER_ACCESS</a></td>
				<td>no doc string</td>
				<td><a href="/documentation/syntax.php#EXPRESSION">EXPRESSION</a>  "."  <a href="/documentation/syntax.php#IDENTIFIER">IDENTIFIER</a></td>
			</tr>
			<tr>
				<td><a id="MEMBER_OFFSET" href="/documentation/syntax/MEMBER_OFFSET.php">MEMBER_OFFSET</a></td>
				<td>no doc string</td>
				<td>"@"  <a href="/documentation/syntax.php#WHOLE_NUMBER">WHOLE_NUMBER</a></td>
			</tr>
			<tr>
				<td><a id="MODULATION" href="/documentation/syntax/MODULATION.php">MODULATION</a></td>
				<td>mod operator or returns a collection containing the elements that would not be consumed from the end of the left hand side by taking the chunk of the right hand side</td>
				<td><a href="/documentation/syntax.php#EXPRESSION">EXPRESSION</a>  "%"  <a href="/documentation/syntax.php#EXPRESSION">EXPRESSION</a></td>
			</tr>
			<tr>
				<td><a id="MULTIPLICATION" href="/documentation/syntax/MULTIPLICATION.php">MULTIPLICATION</a></td>
				<td>scalar multiplication, cartesian product</td>
				<td><a href="/documentation/syntax.php#EXPRESSION">EXPRESSION</a>  "*"  <a href="/documentation/syntax.php#EXPRESSION">EXPRESSION</a></td>
			</tr>
			<tr>
				<td><a id="MULTIPLICATIVE_OP" href="/documentation/syntax/MULTIPLICATIVE_OP.php">MULTIPLICATIVE_OP</a></td>
				<td>no doc string</td>
				<td><a href="/documentation/syntax.php#CROSS_PRODUCT">CROSS_PRODUCT</a> | <a href="/documentation/syntax.php#DOT_PRODUCT">DOT_PRODUCT</a> | <a href="/documentation/syntax.php#MULTIPLICATION">MULTIPLICATION</a></td>
			</tr>
			<tr>
				<td><a id="NAND" href="/documentation/syntax/NAND.php">NAND</a></td>
				<td>no doc string</td>
				<td><a href="/documentation/syntax.php#EXPRESSION">EXPRESSION</a>  "↑"  <a href="/documentation/syntax.php#EXPRESSION">EXPRESSION</a></td>
			</tr>
			<tr>
				<td><a id="NEAREST_INTEGER" href="/documentation/syntax/NEAREST_INTEGER.php">NEAREST_INTEGER</a></td>
				<td>round to the nearest integer</td>
				<td>("⌊"  <a href="/documentation/syntax.php#EXPRESSION">EXPRESSION</a>  "⌉") | ("|_"  <a href="/documentation/syntax.php#EXPRESSION">EXPRESSION</a>  "'|")</td>
			</tr>
			<tr>
				<td><a id="NEGATION" href="/documentation/syntax/NEGATION.php">NEGATION</a></td>
				<td>no doc string</td>
				<td>"-"  <a href="/documentation/syntax.php#EXPRESSION">EXPRESSION</a></td>
			</tr>
			<tr>
				<td><a id="NON_FRACTIONAL" href="/documentation/syntax/NON_FRACTIONAL.php">NON_FRACTIONAL</a></td>
				<td>no doc string</td>
				<td>["-"] <a href="/documentation/syntax.php#NON_NEG_NON_FRACTIONAL">NON_NEG_NON_FRACTIONAL</a></td>
			</tr>
			<tr>
				<td><a id="NON_NEG_FRACTIONAL" href="/documentation/syntax/NON_NEG_FRACTIONAL.php">NON_NEG_FRACTIONAL</a></td>
				<td>a number with a decimal point</td>
				<td>(decimal_digit {decimal_digit} "." {decimal_digit}) | ("." decimal_digit {decimal_digit})</td>
			</tr>
			<tr>
				<td><a id="NON_NEG_INTEGER" href="/documentation/syntax/NON_NEG_INTEGER.php">NON_NEG_INTEGER</a></td>
				<td>no doc string</td>
				<td>(<a href="/documentation/syntax.php#NON_ZERO_DECIMAL_DIGIT">NON_ZERO_DECIMAL_DIGIT</a> {decimal_digit}) | "0"</td>
			</tr>
			<tr>
				<td><a id="NON_NEG_NON_FRACTIONAL" href="/documentation/syntax/NON_NEG_NON_FRACTIONAL.php">NON_NEG_NON_FRACTIONAL</a></td>
				<td>no doc string</td>
				<td><a href="/documentation/syntax.php#NON_NEG_INTEGER">NON_NEG_INTEGER</a> | <a href="/documentation/syntax.php#HEX">HEX</a> | <a href="/documentation/syntax.php#OCTAL">OCTAL</a></td>
			</tr>
			<tr>
				<td><a id="NON_NEG_NUMBER" href="/documentation/syntax/NON_NEG_NUMBER.php">NON_NEG_NUMBER</a></td>
				<td>no doc string</td>
				<td><a href="/documentation/syntax.php#NON_NEG_NON_FRACTIONAL">NON_NEG_NON_FRACTIONAL</a> | <a href="/documentation/syntax.php#NON_NEG_FRACTIONAL">NON_NEG_FRACTIONAL</a></td>
			</tr>
			<tr>
				<td><a id="NON_ZERO_DECIMAL_DIGIT" href="/documentation/syntax/NON_ZERO_DECIMAL_DIGIT.php">NON_ZERO_DECIMAL_DIGIT</a></td>
				<td>used for constructing number</td>
				<td>"1"|"2"|"3"|"4"|"5"|"6"|"7"|"8"|"9"</td>
			</tr>
			<tr>
				<td><a id="NOR" href="/documentation/syntax/NOR.php">NOR</a></td>
				<td>no doc string</td>
				<td><a href="/documentation/syntax.php#EXPRESSION">EXPRESSION</a>  ("↓")  <a href="/documentation/syntax.php#EXPRESSION">EXPRESSION</a></td>
			</tr>
			<tr>
				<td><a id="NOT" href="/documentation/syntax/NOT.php">NOT</a></td>
				<td>boolean not</td>
				<td>("¬"|"~")  <a href="/documentation/syntax.php#EXPRESSION">EXPRESSION</a></td>
			</tr>
			<tr>
				<td><a id="NOT_HAS" href="/documentation/syntax/NOT_HAS.php">NOT_HAS</a></td>
				<td>not_in, backward</td>
				<td><a href="/documentation/syntax.php#EXPRESSION">EXPRESSION</a>  ("∌"|"/has")  <a href="/documentation/syntax.php#EXPRESSION">EXPRESSION</a></td>
			</tr>
			<tr>
				<td><a id="NOT_IN" href="/documentation/syntax/NOT_IN.php">NOT_IN</a></td>
				<td>Collection anti-membership</td>
				<td><a href="/documentation/syntax.php#EXPRESSION">EXPRESSION</a>  ("∉"|"/in")  <a href="/documentation/syntax.php#EXPRESSION">EXPRESSION</a></td>
			</tr>
			<tr>
				<td><a id="NULL_COALESCE" href="/documentation/syntax/NULL_COALESCE.php">NULL_COALESCE</a></td>
				<td>return the first expression if non-null otherwise return the second expression</td>
				<td><a href="/documentation/syntax.php#EXPRESSION">EXPRESSION</a>  "??"  <a href="/documentation/syntax.php#EXPRESSION">EXPRESSION</a></td>
			</tr>
			<tr>
				<td><a id="OBJECT" href="/documentation/syntax/OBJECT.php">OBJECT</a></td>
				<td>no doc string</td>
				<td>"object"  ["inheriting"  <a href="/documentation/syntax.php#INHERITANCE_LIST">INHERITANCE_LIST</a>] ["implementing"  <a href="/documentation/syntax.php#INHERITANCE_LIST">INHERITANCE_LIST</a>] "{" <a href="/documentation/syntax.php#TYPE_SCOPE">TYPE_SCOPE</a> "}"</td>
			</tr>
			<tr>
				<td><a id="OCTAL" href="/documentation/syntax/OCTAL.php">OCTAL</a></td>
				<td>octal number</td>
				<td>"0" octal_digit {octal_digit}</td>
			</tr>
			<tr>
				<td><a id="OR" href="/documentation/syntax/OR.php">OR</a></td>
				<td>no doc string</td>
				<td><a href="/documentation/syntax.php#EXPRESSION">EXPRESSION</a>  ("∨"|"or")  <a href="/documentation/syntax.php#EXPRESSION">EXPRESSION</a></td>
			</tr>
			<tr>
				<td><a id="PARAMETER" href="/documentation/syntax/PARAMETER.php">PARAMETER</a></td>
				<td>declares a formal argument of a function</td>
				<td><a href="/documentation/syntax.php#PARAMETER_NATURAL">PARAMETER_NATURAL</a> | <a href="/documentation/syntax.php#PARAMETER_ANALYTIC">PARAMETER_ANALYTIC</a></td>
			</tr>
			<tr>
				<td><a id="PARAMETER_ANALYTIC" href="/documentation/syntax/PARAMETER_ANALYTIC.php">PARAMETER_ANALYTIC</a></td>
				<td>no doc string</td>
				<td><a href="/documentation/syntax.php#EXPRESSION">EXPRESSION</a> [ "="  <a href="/documentation/syntax.php#EXPRESSION">EXPRESSION</a>]</td>
			</tr>
			<tr>
				<td><a id="PARAMETER_NATURAL" href="/documentation/syntax/PARAMETER_NATURAL.php">PARAMETER_NATURAL</a></td>
				<td>no doc string</td>
				<td>([<a href="/documentation/syntax.php#TYPE_DEREFERENCE">TYPE_DEREFERENCE</a>] <a href="/documentation/syntax.php#IDENTIFIER">IDENTIFIER</a> ["..."]) | ([(<a href="/documentation/syntax.php#TYPE_DEREFERENCE">TYPE_DEREFERENCE</a> | <a href="/documentation/syntax.php#IMPLICIT_TYPE_DEREFERENCE">IMPLICIT_TYPE_DEREFERENCE</a>)] <a href="/documentation/syntax.php#IDENTIFIER">IDENTIFIER</a> ["..."]  "="  <a href="/documentation/syntax.php#EXPRESSION">EXPRESSION</a> ["..."])</td>
			</tr>
			<tr>
				<td><a id="PARENTHETICAL" href="/documentation/syntax/PARENTHETICAL.php">PARENTHETICAL</a></td>
				<td>an expression in parenthesis</td>
				<td>"("  <a href="/documentation/syntax.php#EXPRESSION">EXPRESSION</a>  ")"</td>
			</tr>
			<tr>
				<td><a id="PARENTHETICAL_INVOCATION" href="/documentation/syntax/PARENTHETICAL_INVOCATION.php">PARENTHETICAL_INVOCATION</a></td>
				<td>no doc string</td>
				<td>(<a href="/documentation/syntax.php#EXPRESSION">EXPRESSION</a>)  "(" [(<a href="/documentation/syntax.php#ARGUMENT">ARGUMENT</a>|<a href="/documentation/syntax.php#ARGUMENT_PACK">ARGUMENT_PACK</a>)] {"," [(<a href="/documentation/syntax.php#ARGUMENT">ARGUMENT</a>|<a href="/documentation/syntax.php#ARGUMENT_PACK">ARGUMENT_PACK</a>)]}  ")"</td>
			</tr>
			<tr>
				<td><a id="PAYLOAD" href="/documentation/syntax/PAYLOAD.php">PAYLOAD</a></td>
				<td>no doc string</td>
				<td>all {all}</td>
			</tr>
			<tr>
				<td><a id="PLATFORM" href="/documentation/syntax/PLATFORM.php">PLATFORM</a></td>
				<td>no doc string</td>
				<td>"_" (letter | number) {letter | number | "_"}</td>
			</tr>
			<tr>
				<td><a id="POST_DEC" href="/documentation/syntax/POST_DEC.php">POST_DEC</a></td>
				<td>no doc string</td>
				<td><a href="/documentation/syntax.php#EXPRESSION">EXPRESSION</a>  "--"</td>
			</tr>
			<tr>
				<td><a id="POST_INC" href="/documentation/syntax/POST_INC.php">POST_INC</a></td>
				<td>no doc string</td>
				<td><a href="/documentation/syntax.php#EXPRESSION">EXPRESSION</a>  "++"</td>
			</tr>
			<tr>
				<td><a id="PREPEND" href="/documentation/syntax/PREPEND.php">PREPEND</a></td>
				<td>create a new Collection starting with the left hand side followed by the elements of the right hand side Collection</td>
				<td><a href="/documentation/syntax.php#EXPRESSION">EXPRESSION</a>  "&amp;"  <a href="/documentation/syntax.php#EXPRESSION">EXPRESSION</a></td>
			</tr>
			<tr>
				<td><a id="PRE_DEC" href="/documentation/syntax/PRE_DEC.php">PRE_DEC</a></td>
				<td>no doc string</td>
				<td>"--"  <a href="/documentation/syntax.php#EXPRESSION">EXPRESSION</a></td>
			</tr>
			<tr>
				<td><a id="PRE_INC" href="/documentation/syntax/PRE_INC.php">PRE_INC</a></td>
				<td>no doc string</td>
				<td>"++"  <a href="/documentation/syntax.php#EXPRESSION">EXPRESSION</a></td>
			</tr>
			<tr>
				<td><a id="RADICAL" href="/documentation/syntax/RADICAL.php">RADICAL</a></td>
				<td>no doc string</td>
				<td>"√"  <a href="/documentation/syntax.php#EXPRESSION">EXPRESSION</a></td>
			</tr>
			<tr>
				<td><a id="RANGE" href="/documentation/syntax/RANGE.php">RANGE</a></td>
				<td>create a totally-ordered open/closed/half-open discreet/continuous Collection</td>
				<td>"("  "..."  <a href="/documentation/syntax.php#EXPRESSION">EXPRESSION</a>  ("]" | ")") | ("[" | "(")  <a href="/documentation/syntax.php#EXPRESSION">EXPRESSION</a>  "..."  ")" | ("(" | "[")  <a href="/documentation/syntax.php#EXPRESSION">EXPRESSION</a>  "..."  <a href="/documentation/syntax.php#EXPRESSION">EXPRESSION</a>  ("]" | ")")</td>
			</tr>
			<tr>
				<td><a id="READ_LOCK" href="/documentation/syntax/READ_LOCK.php">READ_LOCK</a></td>
				<td>no doc string</td>
				<td>"read_lock"  <a href="/documentation/syntax.php#PARENTHETICAL">PARENTHETICAL</a>  <a href="/documentation/syntax.php#EXPRESSION">EXPRESSION</a></td>
			</tr>
			<tr>
				<td><a id="RECORD" href="/documentation/syntax/RECORD.php">RECORD</a></td>
				<td>no doc string</td>
				<td>"record" <a href="/documentation/syntax.php#IC">IC</a>  <a href="/documentation/syntax.php#TYPE">TYPE</a></td>
			</tr>
			<tr>
				<td><a id="REGEX" href="/documentation/syntax/REGEX.php">REGEX</a></td>
				<td>no doc string</td>
				<td>"R" c_string</td>
			</tr>
			<tr>
				<td><a id="RELATIONAL_COLLECTION_OP" href="/documentation/syntax/RELATIONAL_COLLECTION_OP.php">RELATIONAL_COLLECTION_OP</a></td>
				<td>relational operators on collections</td>
				<td><a href="/documentation/syntax.php#HAS">HAS</a> | <a href="/documentation/syntax.php#IN">IN</a> | <a href="/documentation/syntax.php#NOT_HAS">NOT_HAS</a> | <a href="/documentation/syntax.php#NOT_IN">NOT_IN</a></td>
			</tr>
			<tr>
				<td><a id="RELATIONAL_OP" href="/documentation/syntax/RELATIONAL_OP.php">RELATIONAL_OP</a></td>
				<td>no doc string</td>
				<td><a href="/documentation/syntax.php#CASTS">CASTS</a> | <a href="/documentation/syntax.php#DOWNCASTS">DOWNCASTS</a> | <a href="/documentation/syntax.php#EXACTLY">EXACTLY</a> | <a href="/documentation/syntax.php#IMPLEMENTS">IMPLEMENTS</a> | <a href="/documentation/syntax.php#INEQUALITY">INEQUALITY</a> | <a href="/documentation/syntax.php#INHERITS">INHERITS</a> | <a href="/documentation/syntax.php#IS">IS</a> | <a href="/documentation/syntax.php#RELATIONAL_COLLECTION_OP">RELATIONAL_COLLECTION_OP</a> | <a href="/documentation/syntax.php#UPCASTS">UPCASTS</a></td>
			</tr>
			<tr>
				<td><a id="RETURN" href="/documentation/syntax/RETURN.php">RETURN</a></td>
				<td>exit the current function, optionally returning a value</td>
				<td>"return" ["["  <a href="/documentation/syntax.php#EXPRESSION">EXPRESSION</a>  "]"] [ <a href="/documentation/syntax.php#EXPRESSION">EXPRESSION</a>]</td>
			</tr>
			<tr>
				<td><a id="SET" href="/documentation/syntax/SET.php">SET</a></td>
				<td>no doc string</td>
				<td>"{|"  [<a href="/documentation/syntax.php#EXPRESSION">EXPRESSION</a> {","  <a href="/documentation/syntax.php#EXPRESSION">EXPRESSION</a>}] "|}"</td>
			</tr>
			<tr>
				<td><a id="SET_COMPREHENSION" href="/documentation/syntax/SET_COMPREHENSION.php">SET_COMPREHENSION</a></td>
				<td>create a Collection, substituting variables bound in the right hand side into the left hand side</td>
				<td>"{"  <a href="/documentation/syntax.php#EXPRESSION">EXPRESSION</a>  "|"  <a href="/documentation/syntax.php#EXPRESSION">EXPRESSION</a>  "}"</td>
			</tr>
			<tr>
				<td><a id="SHIFTL" href="/documentation/syntax/SHIFTL.php">SHIFTL</a></td>
				<td>shift left</td>
				<td><a href="/documentation/syntax.php#EXPRESSION">EXPRESSION</a>  "&lt;&lt;"  <a href="/documentation/syntax.php#EXPRESSION">EXPRESSION</a></td>
			</tr>
			<tr>
				<td><a id="SHIFTR" href="/documentation/syntax/SHIFTR.php">SHIFTR</a></td>
				<td>shift right</td>
				<td><a href="/documentation/syntax.php#EXPRESSION">EXPRESSION</a>  "&gt;&gt;"  <a href="/documentation/syntax.php#EXPRESSION">EXPRESSION</a></td>
			</tr>
			<tr>
				<td><a id="SLICE" href="/documentation/syntax/SLICE.php">SLICE</a></td>
				<td>used in ARRAY_INVOCATION</td>
				<td><a href="/documentation/syntax.php#EXPRESSION">EXPRESSION</a>  ":"  <a href="/documentation/syntax.php#EXPRESSION">EXPRESSION</a></td>
			</tr>
			<tr>
				<td><a id="STATEMENT" href="/documentation/syntax/STATEMENT.php">STATEMENT</a></td>
				<td>top-level statement syntax</td>
				<td>(<a href="/documentation/syntax.php#ASSIGNMENT_CHAIN">ASSIGNMENT_CHAIN</a> | <a href="/documentation/syntax.php#BREAK">BREAK</a> | <a href="/documentation/syntax.php#CONTINUE">CONTINUE</a> | <a href="/documentation/syntax.php#DEFINITION">DEFINITION</a> | <a href="/documentation/syntax.php#DO">DO</a> | <a href="/documentation/syntax.php#EXPRESSION">EXPRESSION</a> | <a href="/documentation/syntax.php#FOR">FOR</a> | <a href="/documentation/syntax.php#FOR_COLLECTION">FOR_COLLECTION</a> | <a href="/documentation/syntax.php#FREE">FREE</a> | <a href="/documentation/syntax.php#IMPORT">IMPORT</a> | <a href="/documentation/syntax.php#LOCK">LOCK</a> | <a href="/documentation/syntax.php#LOOP">LOOP</a> | <a href="/documentation/syntax.php#READ_LOCK">READ_LOCK</a> | <a href="/documentation/syntax.php#RETURN">RETURN</a> | <a href="/documentation/syntax.php#THROW">THROW</a> | <a href="/documentation/syntax.php#TRY">TRY</a> | <a href="/documentation/syntax.php#TYPE_CONSTRAINT">TYPE_CONSTRAINT</a> | <a href="/documentation/syntax.php#WRITE_LOCK">WRITE_LOCK</a> | <a href="/documentation/syntax.php#USING">USING</a>)  ";"</td>
			</tr>
			<tr>
				<td><a id="STATEMENT_SCOPE" href="/documentation/syntax/STATEMENT_SCOPE.php">STATEMENT_SCOPE</a></td>
				<td>zero or more statements, the top level syntax rule for source files</td>
				<td>{<a href="/documentation/syntax.php#IC">IC</a> | <a href="/documentation/syntax.php#STATEMENT">STATEMENT</a>}</td>
			</tr>
			<tr>
				<td><a id="STATIC" href="/documentation/syntax/STATIC.php">STATIC</a></td>
				<td>no doc string</td>
				<td>"static"</td>
			</tr>
			<tr>
				<td><a id="SUBSET_CHAIN" href="/documentation/syntax/SUBSET_CHAIN.php">SUBSET_CHAIN</a></td>
				<td>One or more subset, proper subset, or equality relations</td>
				<td><a href="/documentation/syntax.php#EXPRESSION">EXPRESSION</a>  <a href="/documentation/syntax.php#SUBSET_CHAIN_LOOP">SUBSET_CHAIN_LOOP</a></td>
			</tr>
			<tr>
				<td><a id="SUBSET_CHAIN_LOOP" href="/documentation/syntax/SUBSET_CHAIN_LOOP.php">SUBSET_CHAIN_LOOP</a></td>
				<td>no doc string</td>
				<td>("="|"⊆"|"subs"|"⊂"|"psubs")  <a href="/documentation/syntax.php#EXPRESSION">EXPRESSION</a> [SUBSET_CHAIN_LOOP]</td>
			</tr>
			<tr>
				<td><a id="SUBTRACTION" href="/documentation/syntax/SUBTRACTION.php">SUBTRACTION</a></td>
				<td>no doc string</td>
				<td><a href="/documentation/syntax.php#EXPRESSION">EXPRESSION</a>  "-"  <a href="/documentation/syntax.php#EXPRESSION">EXPRESSION</a></td>
			</tr>
			<tr>
				<td><a id="SUPERSET_CHAIN" href="/documentation/syntax/SUPERSET_CHAIN.php">SUPERSET_CHAIN</a></td>
				<td>One or more superset, proper superset, or equality relations</td>
				<td><a href="/documentation/syntax.php#EXPRESSION">EXPRESSION</a>  <a href="/documentation/syntax.php#SUPERSET_CHAIN_LOOP">SUPERSET_CHAIN_LOOP</a></td>
			</tr>
			<tr>
				<td><a id="SUPERSET_CHAIN_LOOP" href="/documentation/syntax/SUPERSET_CHAIN_LOOP.php">SUPERSET_CHAIN_LOOP</a></td>
				<td>no doc string</td>
				<td>("="|"⊇"|"sups"|"⊃"|"psups")  <a href="/documentation/syntax.php#EXPRESSION">EXPRESSION</a> [SUPERSET_CHAIN_LOOP]</td>
			</tr>
			<tr>
				<td><a id="SWIZZLE" href="/documentation/syntax/SWIZZLE.php">SWIZZLE</a></td>
				<td>no doc string</td>
				<td><a href="/documentation/syntax.php#EXPRESSION">EXPRESSION</a>  ("⋮" | "_swiz_")  <a href="/documentation/syntax.php#EXPRESSION">EXPRESSION</a></td>
			</tr>
			<tr>
				<td><a id="SYMMETRIC_DIFFERENCE" href="/documentation/syntax/SYMMETRIC_DIFFERENCE.php">SYMMETRIC_DIFFERENCE</a></td>
				<td>the set-theoretic symmetric disjunction (Collection xor)</td>
				<td><a href="/documentation/syntax.php#EXPRESSION">EXPRESSION</a>  "⊖"  <a href="/documentation/syntax.php#EXPRESSION">EXPRESSION</a></td>
			</tr>
			<tr>
				<td><a id="THIS" href="/documentation/syntax/THIS.php">THIS</a></td>
				<td>no doc string</td>
				<td>"this" ["["  <a href="/documentation/syntax.php#EXPRESSION">EXPRESSION</a>  "]"]</td>
			</tr>
			<tr>
				<td><a id="THIS_FUNC" href="/documentation/syntax/THIS_FUNC.php">THIS_FUNC</a></td>
				<td>no doc string</td>
				<td>"this_func" ["["  <a href="/documentation/syntax.php#EXPRESSION">EXPRESSION</a>  "]"]</td>
			</tr>
			<tr>
				<td><a id="THIS_TYPE" href="/documentation/syntax/THIS_TYPE.php">THIS_TYPE</a></td>
				<td>no doc string</td>
				<td>"this_type" ["["  <a href="/documentation/syntax.php#EXPRESSION">EXPRESSION</a>  "]"]</td>
			</tr>
			<tr>
				<td><a id="THROW" href="/documentation/syntax/THROW.php">THROW</a></td>
				<td>raise an exception with an optional value which must implement Exception if specified</td>
				<td>"throw" ["["  <a href="/documentation/syntax.php#EXPRESSION">EXPRESSION</a>  "]"] [<a href="/documentation/syntax.php#EXPRESSION">EXPRESSION</a>]</td>
			</tr>
			<tr>
				<td><a id="TIME" href="/documentation/syntax/TIME.php">TIME</a></td>
				<td>no doc string</td>
				<td>["-"] decimal_digit decimal_digit ":" decimal_digit decimal_digit ":" decimal_digit decimal_digit ["." decimal_digit {decimal_digit}] ["Z" | (("+"|"-") decimal_digit decimal_digit [":" decimal_digit decimal_digit])]</td>
			</tr>
			<tr>
				<td><a id="TRY" href="/documentation/syntax/TRY.php">TRY</a></td>
				<td>executes the specified nullary void function of the first expression, catching exceptions that pattern match the function(s) of the second expression, and then executes the third expression unconditionally</td>
				<td>"try"  <a href="/documentation/syntax.php#EXPRESSION">EXPRESSION</a>  "catch"  <a href="/documentation/syntax.php#EXPRESSION">EXPRESSION</a> {"catch"  <a href="/documentation/syntax.php#EXPRESSION">EXPRESSION</a>} ["finally"  <a href="/documentation/syntax.php#EXPRESSION">EXPRESSION</a>]</td>
			</tr>
			<tr>
				<td><a id="TUPLE" href="/documentation/syntax/TUPLE.php">TUPLE</a></td>
				<td>create a finite, ordered tuple of elements</td>
				<td>"(|"  <a href="/documentation/syntax.php#EXPRESSION">EXPRESSION</a> {","  <a href="/documentation/syntax.php#EXPRESSION">EXPRESSION</a>}  "|)"</td>
			</tr>
			<tr>
				<td><a id="TYPE" href="/documentation/syntax/TYPE.php">TYPE</a></td>
				<td>create a type</td>
				<td>"type"  ["inheriting"  <a href="/documentation/syntax.php#INHERITANCE_LIST">INHERITANCE_LIST</a>] ["implementing"  <a href="/documentation/syntax.php#INHERITANCE_LIST">INHERITANCE_LIST</a>] "{" <a href="/documentation/syntax.php#TYPE_SCOPE">TYPE_SCOPE</a> "}"</td>
			</tr>
			<tr>
				<td><a id="TYPE_CONSTRAINT" href="/documentation/syntax/TYPE_CONSTRAINT.php">TYPE_CONSTRAINT</a></td>
				<td>no doc string</td>
				<td><a href="/documentation/syntax.php#TYPE_CONSTRAINT_HEAD">TYPE_CONSTRAINT_HEAD</a>  <a href="/documentation/syntax.php#TYPE_CONSTRAINT_CHAIN">TYPE_CONSTRAINT_CHAIN</a></td>
			</tr>
			<tr>
				<td><a id="TYPE_CONSTRAINT_CHAIN" href="/documentation/syntax/TYPE_CONSTRAINT_CHAIN.php">TYPE_CONSTRAINT_CHAIN</a></td>
				<td>no doc string</td>
				<td>(<a href="/documentation/syntax.php#DECLARATION">DECLARATION</a>|<a href="/documentation/syntax.php#ASSIGNMENT_CHAIN">ASSIGNMENT_CHAIN</a>|<a href="/documentation/syntax.php#DEFINITION">DEFINITION</a>) [","  TYPE_CONSTRAINT_CHAIN]</td>
			</tr>
			<tr>
				<td><a id="TYPE_CONSTRAINT_HEAD" href="/documentation/syntax/TYPE_CONSTRAINT_HEAD.php">TYPE_CONSTRAINT_HEAD</a></td>
				<td>no doc string</td>
				<td>[<a href="/documentation/syntax.php#XML_DOC_STRING">XML_DOC_STRING</a>] {<a href="/documentation/syntax.php#ATTRIBUTE">ATTRIBUTE</a>} [<a href="/documentation/syntax.php#VISIBILITY_MODIFIER">VISIBILITY_MODIFIER</a>] [<a href="/documentation/syntax.php#STATIC">STATIC</a>] [<a href="/documentation/syntax.php#EXTERN">EXTERN</a>] (<a href="/documentation/syntax.php#TYPE_DEREFERENCE">TYPE_DEREFERENCE</a> | <a href="/documentation/syntax.php#VOLATILE_TYPE_DEREFERENCE">VOLATILE_TYPE_DEREFERENCE</a> | <a href="/documentation/syntax.php#IMPLICIT_TYPE_DEREFERENCE">IMPLICIT_TYPE_DEREFERENCE</a> | <a href="/documentation/syntax.php#VOLATILE_IMPLICIT_TYPE_DEREFERENCE">VOLATILE_IMPLICIT_TYPE_DEREFERENCE</a>)</td>
			</tr>
			<tr>
				<td><a id="TYPE_DEREFERENCE" href="/documentation/syntax/TYPE_DEREFERENCE.php">TYPE_DEREFERENCE</a></td>
				<td>use a variable/constant as a typename</td>
				<td>"&lt;"  <a href="/documentation/syntax.php#EXPRESSION">EXPRESSION</a>  "&gt;"</td>
			</tr>
			<tr>
				<td><a id="TYPE_INVOCATION" href="/documentation/syntax/TYPE_INVOCATION.php">TYPE_INVOCATION</a></td>
				<td>no doc string</td>
				<td>(<a href="/documentation/syntax.php#EXPRESSION">EXPRESSION</a>) ("&lt;" [(<a href="/documentation/syntax.php#ARGUMENT">ARGUMENT</a>|<a href="/documentation/syntax.php#ARGUMENT_PACK">ARGUMENT_PACK</a>)] {"," [(<a href="/documentation/syntax.php#ARGUMENT">ARGUMENT</a>|<a href="/documentation/syntax.php#ARGUMENT_PACK">ARGUMENT_PACK</a>)]}  "&gt;")</td>
			</tr>
			<tr>
				<td><a id="TYPE_SCOPE" href="/documentation/syntax/TYPE_SCOPE.php">TYPE_SCOPE</a></td>
				<td>zero or more statements or member declarations/definitions, used strictly in the TYPE syntax only</td>
				<td> {<a href="/documentation/syntax.php#TYPE_STATEMENT">TYPE_STATEMENT</a>}</td>
			</tr>
			<tr>
				<td><a id="TYPE_SCOPE_ASSIGNMENT_CHAIN" href="/documentation/syntax/TYPE_SCOPE_ASSIGNMENT_CHAIN.php">TYPE_SCOPE_ASSIGNMENT_CHAIN</a></td>
				<td>no doc string</td>
				<td>[<a href="/documentation/syntax.php#XML_DOC_STRING">XML_DOC_STRING</a>] <a href="/documentation/syntax.php#IDENTIFIER">IDENTIFIER</a> [<a href="/documentation/syntax.php#MEMBER_OFFSET">MEMBER_OFFSET</a>]  ("←"|"&lt;-")  (<a href="/documentation/syntax.php#EXPRESSION">EXPRESSION</a>|<a href="/documentation/syntax.php#ASSIGNMENT_CHAIN">ASSIGNMENT_CHAIN</a>)</td>
			</tr>
			<tr>
				<td><a id="TYPE_SCOPE_DECLARATION" href="/documentation/syntax/TYPE_SCOPE_DECLARATION.php">TYPE_SCOPE_DECLARATION</a></td>
				<td>no doc string</td>
				<td>[<a href="/documentation/syntax.php#XML_DOC_STRING">XML_DOC_STRING</a>] <a href="/documentation/syntax.php#IDENTIFIER">IDENTIFIER</a> [<a href="/documentation/syntax.php#MEMBER_OFFSET">MEMBER_OFFSET</a>]</td>
			</tr>
			<tr>
				<td><a id="TYPE_SCOPE_TYPE_CONSTRAINT" href="/documentation/syntax/TYPE_SCOPE_TYPE_CONSTRAINT.php">TYPE_SCOPE_TYPE_CONSTRAINT</a></td>
				<td>no doc string</td>
				<td><a href="/documentation/syntax.php#TYPE_CONSTRAINT_HEAD">TYPE_CONSTRAINT_HEAD</a>  <a href="/documentation/syntax.php#TYPE_SCOPE_TYPE_CONSTRAINT_CHAIN">TYPE_SCOPE_TYPE_CONSTRAINT_CHAIN</a></td>
			</tr>
			<tr>
				<td><a id="TYPE_SCOPE_TYPE_CONSTRAINT_CHAIN" href="/documentation/syntax/TYPE_SCOPE_TYPE_CONSTRAINT_CHAIN.php">TYPE_SCOPE_TYPE_CONSTRAINT_CHAIN</a></td>
				<td>no doc string</td>
				<td>[<a href="/documentation/syntax.php#XML_DOC_STRING">XML_DOC_STRING</a>] (<a href="/documentation/syntax.php#TYPE_SCOPE_DECLARATION">TYPE_SCOPE_DECLARATION</a>|<a href="/documentation/syntax.php#TYPE_SCOPE_ASSIGNMENT_CHAIN">TYPE_SCOPE_ASSIGNMENT_CHAIN</a>|<a href="/documentation/syntax.php#DEFINITION">DEFINITION</a>) [","  TYPE_SCOPE_TYPE_CONSTRAINT_CHAIN]</td>
			</tr>
			<tr>
				<td><a id="TYPE_STATEMENT" href="/documentation/syntax/TYPE_STATEMENT.php">TYPE_STATEMENT</a></td>
				<td>top-level type syntax</td>
				<td>(<a href="/documentation/syntax.php#VISIBILITY_MODIFIER">VISIBILITY_MODIFIER</a>  ":") | <a href="/documentation/syntax.php#TYPE_SCOPE_TYPE_CONSTRAINT">TYPE_SCOPE_TYPE_CONSTRAINT</a> | <a href="/documentation/syntax.php#STATEMENT">STATEMENT</a></td>
			</tr>
			<tr>
				<td><a id="UNARY_ARITHMETIC_OP" href="/documentation/syntax/UNARY_ARITHMETIC_OP.php">UNARY_ARITHMETIC_OP</a></td>
				<td>no doc string</td>
				<td><a href="/documentation/syntax.php#FACTORIAL">FACTORIAL</a> | <a href="/documentation/syntax.php#NEGATION">NEGATION</a> | <a href="/documentation/syntax.php#POST_DEC">POST_DEC</a> | <a href="/documentation/syntax.php#POST_INC">POST_INC</a> | <a href="/documentation/syntax.php#PRE_DEC">PRE_DEC</a> | <a href="/documentation/syntax.php#PRE_INC">PRE_INC</a> | <a href="/documentation/syntax.php#RADICAL">RADICAL</a></td>
			</tr>
			<tr>
				<td><a id="UNARY_LOGICAL_OP" href="/documentation/syntax/UNARY_LOGICAL_OP.php">UNARY_LOGICAL_OP</a></td>
				<td>no doc string</td>
				<td><a href="/documentation/syntax.php#ALL">ALL</a> | <a href="/documentation/syntax.php#EXISTS">EXISTS</a> | <a href="/documentation/syntax.php#EXISTS_ONE">EXISTS_ONE</a> | <a href="/documentation/syntax.php#NOT">NOT</a></td>
			</tr>
			<tr>
				<td><a id="UNARY_OP" href="/documentation/syntax/UNARY_OP.php">UNARY_OP</a></td>
				<td>no doc string</td>
				<td><a href="/documentation/syntax.php#ALLOCATION">ALLOCATION</a> | <a href="/documentation/syntax.php#CARDINALITY">CARDINALITY</a> | <a href="/documentation/syntax.php#KLEENE_STAR">KLEENE_STAR</a> | <a href="/documentation/syntax.php#UNARY_ARITHMETIC_OP">UNARY_ARITHMETIC_OP</a> | <a href="/documentation/syntax.php#UNARY_LOGICAL_OP">UNARY_LOGICAL_OP</a></td>
			</tr>
			<tr>
				<td><a id="UNION" href="/documentation/syntax/UNION.php">UNION</a></td>
				<td>the set-theoretic union</td>
				<td><a href="/documentation/syntax.php#EXPRESSION">EXPRESSION</a>  "∪"  <a href="/documentation/syntax.php#EXPRESSION">EXPRESSION</a></td>
			</tr>
			<tr>
				<td><a id="UNIT_DIVISION" href="/documentation/syntax/UNIT_DIVISION.php">UNIT_DIVISION</a></td>
				<td>dimensional analysis "per"</td>
				<td><a href="/documentation/syntax.php#DIMENSION">DIMENSION</a> "/" <a href="/documentation/syntax.php#DIMENSION">DIMENSION</a></td>
			</tr>
			<tr>
				<td><a id="UNIT_EXPONENTIATION" href="/documentation/syntax/UNIT_EXPONENTIATION.php">UNIT_EXPONENTIATION</a></td>
				<td>dimensional analysis square units, cubed units, etc</td>
				<td><a href="/documentation/syntax.php#DIMENSION">DIMENSION</a> "^" <a href="/documentation/syntax.php#NON_FRACTIONAL">NON_FRACTIONAL</a></td>
			</tr>
			<tr>
				<td><a id="UNIT_MULTIPLICATION" href="/documentation/syntax/UNIT_MULTIPLICATION.php">UNIT_MULTIPLICATION</a></td>
				<td>dimensional analysis "by"</td>
				<td><a href="/documentation/syntax.php#DIMENSION">DIMENSION</a> "*" <a href="/documentation/syntax.php#DIMENSION">DIMENSION</a></td>
			</tr>
			<tr>
				<td><a id="UPCASTS" href="/documentation/syntax/UPCASTS.php">UPCASTS</a></td>
				<td>no doc string</td>
				<td><a href="/documentation/syntax.php#EXPRESSION">EXPRESSION</a>  "upcasts"  <a href="/documentation/syntax.php#EXPRESSION">EXPRESSION</a></td>
			</tr>
			<tr>
				<td><a id="USING" href="/documentation/syntax/USING.php">USING</a></td>
				<td>values in the specified value are visible, and any value constructed inside the expression that is not visible from outside scopes, is destructed when the scope exits</td>
				<td>"using"  "("  <a href="/documentation/syntax.php#EXPRESSION">EXPRESSION</a>  ")"  <a href="/documentation/syntax.php#BLOCK">BLOCK</a></td>
			</tr>
			<tr>
				<td><a id="VECTOR_NORM" href="/documentation/syntax/VECTOR_NORM.php">VECTOR_NORM</a></td>
				<td>create a Vector<D, N> normalized to unit length</td>
				<td>"||"  <a href="/documentation/syntax.php#EXPRESSION">EXPRESSION</a>  "||"</td>
			</tr>
			<tr>
				<td><a id="VISIBILITY_MODIFIER" href="/documentation/syntax/VISIBILITY_MODIFIER.php">VISIBILITY_MODIFIER</a></td>
				<td>no doc string</td>
				<td>("public"|"protected"|"protected internal"|"internal"|"private")</td>
			</tr>
			<tr>
				<td><a id="VOLATILE_IMPLICIT_TYPE_DEREFERENCE" href="/documentation/syntax/VOLATILE_IMPLICIT_TYPE_DEREFERENCE.php">VOLATILE_IMPLICIT_TYPE_DEREFERENCE</a></td>
				<td>no doc string</td>
				<td>"&lt;"  "volatile"  "&gt;"</td>
			</tr>
			<tr>
				<td><a id="VOLATILE_TYPE_DEREFERENCE" href="/documentation/syntax/VOLATILE_TYPE_DEREFERENCE.php">VOLATILE_TYPE_DEREFERENCE</a></td>
				<td>no doc string</td>
				<td>"&lt;"  "volatile"  <a href="/documentation/syntax.php#EXPRESSION">EXPRESSION</a>  "&gt;"</td>
			</tr>
			<tr>
				<td><a id="WHOLE_NUMBER" href="/documentation/syntax/WHOLE_NUMBER.php">WHOLE_NUMBER</a></td>
				<td>no doc string</td>
				<td>("1"|"2"|"3"|"4"|"5"|"6"|"7"|"8"|"9") {"0"|"1"|"2"|"3"|"4"|"5"|"6"|"7"|"8"|"9"}</td>
			</tr>
			<tr>
				<td><a id="WRITE_LOCK" href="/documentation/syntax/WRITE_LOCK.php">WRITE_LOCK</a></td>
				<td>no doc string</td>
				<td>"write_lock"  <a href="/documentation/syntax.php#PARENTHETICAL">PARENTHETICAL</a>  <a href="/documentation/syntax.php#EXPRESSION">EXPRESSION</a></td>
			</tr>
			<tr>
				<td><a id="WS" href="/documentation/syntax/WS.php">WS</a></td>
				<td>consumes whitespaces between other tokens</td>
				<td>white_space {white_space}</td>
			</tr>
			<tr>
				<td><a id="XML_DOC_STRING" href="/documentation/syntax/XML_DOC_STRING.php">XML_DOC_STRING</a></td>
				<td>documentation string bounded by arbirtrarily-sized delimiters</td>
				<td>"```" <a href="/documentation/syntax.php#XML_DOC_STRING_INTERIOR">XML_DOC_STRING_INTERIOR</a> "```"</td>
			</tr>
			<tr>
				<td><a id="XML_DOC_STRING_INTERIOR" href="/documentation/syntax/XML_DOC_STRING_INTERIOR.php">XML_DOC_STRING_INTERIOR</a></td>
				<td>no doc string</td>
				<td><a href="/documentation/syntax.php#PAYLOAD">PAYLOAD</a> | ("`" XML_DOC_STRING_INTERIOR "`")</td>
			</tr>
			<tr>
				<td><a id="XOR" href="/documentation/syntax/XOR.php">XOR</a></td>
				<td>no doc string</td>
				<td><a href="/documentation/syntax.php#EXPRESSION">EXPRESSION</a>  ("⊕" |"xor")  <a href="/documentation/syntax.php#EXPRESSION">EXPRESSION</a></td>
			</tr>
		</table>

		<?php require('../footer.php') ?>
	</body>
</html>