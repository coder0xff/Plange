<meta charset='utf-8'/>
<meta name="viewport" content="width=device-width, initial-scale=0.6">
<html>
	<head>
		<title>EXPRESSION - Syntax Pages - Plange</title>
		<link rel=StyleSheet href='../../css/general.css' type='text/css' />
	</head>
	<body>
		<?php require('../../header.php') ?>


		<p>a linearization of an evaluation tree containing constants, variables, operators, invocations, and sub expressions</p>

		<div class="syntax">
			<p>syntax</p>
			<div>ALLOCATION | ARRAY | ASM_FUNCTION | BINARY_OP | BOOL | c_string | CAST | CEILING | CONDITIONAL | DELTA | DIMENSIONAL_NUMBER | EMBEDDED_STRING | FACTORIAL | FLOOR | FUNCTION | IDENTIFIER | IF | INVOCATION | LIST | MAGNITUDE | MAP | MEMBER_ACCESS | NEAREST_INTEGER | NON_NEG_NUMBER | PARENTHETICAL | PROPERTY | RADICAL | RANGE | SET | SET_COMPREHENSION | TUPLE | TYPE | UNARY_OP | VECTOR_NORM | "null" | "this" | "this_type"</div>
		</div>
		<h2>Notes</h2>
				<p>null is a literal and so is included in the syntax similarly to true, false and numberic literals (and unlike constants)
		</p>



		<?php require('../../footer.php') ?>
	</body>
</html>