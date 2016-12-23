<meta charset='utf-8'/>
<meta name="viewport" content="width=device-width, initial-scale=0.6">
<html>
	<head>
		<title>Operators - Plange</title>
		<link rel=StyleSheet href='../css/general.css' type='text/css' />
		<style>code { margin-left:20px; }</style>
	</head>
	<body>
		<?php require('../header.php') ?>


		<p>The following properties may be used to categorize operators</p>
		<ul>
			<li><a href="https://en.wikipedia.org/wiki/Arity">arity</a></li>
			<li><a href="https://en.wikipedia.org/wiki/Operator_associativity">associativity</a></li>
			<li><a href="https://en.wikipedia.org/wiki/Operator_precedence">precedence</a></li>
			<li>result type - numeric, Boolean, enumerable, arbitrary</li>
			<li>operand types - numeric, Boolean, enumerable, arbitrary</li>
			<li>transitive, commutative, distributive, etc properties</li>
		</ul>
		<p>A categorical hierarchy is constructed for interpretation as <a href="/documentation/syntax.php">grammar rules</a>. Note that select symbols appear multiple times. These are interpreted in multiple possible ways. For example, - is both "negation" and "subtraction".</p>

		<ul>
			<li><a href="/documentation/syntax/DEFINITION.php">definition</a><sup>†</sup><code>:=</code></li>
			<li><a href="/documentation/syntax/ASSIGNMENT.php">assignment</a><sup>†</sup><code>←</code></li>
			<li><a href="/documentation/syntax/CONDITIONAL.php">conditional</a><sup>‡</sup><code>? :</code></li>
			<li><a href="/documentation/syntax/DIMENSIONAL_ANALYSIS_OP.php">dimensional_analysis_op</a><sup>†</sup>
				<ul>
					<li><a href="/documentation/syntax/UNIT_DIVISION.php">unit_division</a><sup>†</sup><code>/</code></li>
					<li><a href="/documentation/syntax/UNIT_MULTIPLICATION.php">unit_multiplication</a><sup>†</sup><code>*</code></li>
					<li><a href="/documentation/syntax/UNIT_EXPONENTIATION.php">unit_exponentiation</a><sup>†</sup><code>^</code></li>
				</ul>
			</li>
			<li><a href="/documentation/syntax/UNARY_OP.php">unary_op</a>
				<ul>
					<li><a href="/documentation/syntax/CARDINALITY.php">cardinality</a><code>#</code></li>
					<li><a href="/documentation/syntax/KLEENE_STAR.php">kleene_star</a><sup>*</sup><code>*</code></li>
					<li><a href="/documentation/syntax/UNARY_ARITHMETIC_OP.php">unary_arithmetic_op</a>
						<ul>
							<li><a href="/documentation/syntax/NEGATION.php">negation</a><code>-</code></li>
							<li><a href="/documentation/syntax/RADICAL.php">radical</a><code>√</code></li>
							<li><a href="/documentation/syntax/FACTORIAL.php">factorial</a><sup>*</sup><code>!</code></li>
							<li><a href="/documentation/syntax/POST_INC.php">post_inc</a><sup>*</sup><code>++</code></li>
							<li><a href="/documentation/syntax/PRE_INC.php">pre_inc</a><code>++</code></li>
							<li><a href="/documentation/syntax/POST_DEC.php">post_dec</a><sup>*</sup><code>--</code></li>
							<li><a href="/documentation/syntax/PRE_DEC.php">pre_dec</a><code>--</code></li>
						</ul>
					</li>
					<li><a href="/documentation/syntax/UNARY_LOGICAL_OP.php">unary_logical_op</a>
						<ul>
							<li><a href="/documentation/syntax/NOT.php">not</a><code>¬</code></li>
							<li><a href="/documentation/syntax/ALL.php">all</a><code>∀</code></li>
							<li><a href="/documentation/syntax/EXISTS.php">exists</a><code>∃</code></li>
							<li><a href="/documentation/syntax/EXISTS_ONE.php">exists_one</a><code>∃!</code></li>
						</ul>
					</li>
				</ul>
			</li>
			<li><a href="/documentation/syntax/BINARY_OP.php">binary_op</a>
				<ul>
					<li><a href="/documentation/syntax/BINARY_ARITHMETIC_OP.php">binary_arithmetic_op</a>
						<ul>
							<li><a href="/documentation/syntax/ADDITION.php">addition</a><code>+</code></li>
							<li><a href="/documentation/syntax/SUBTRACTION.php">subtraction</a><code>-</code></li>
							<li><a href="/documentation/syntax/ADD_SUB.php">add_sub</a><code>±</code></li>
							<li><a href="/documentation/syntax/MULTIPLICATIVE_OP.php">multiplicative_op</a>
								<ul>
									<li><a href="/documentation/syntax/MULTIPLICATION.php">multiplication</a><code>*</code></li>
									<li><a href="/documentation/syntax/DOT_PRODUCT.php">dot_product</a><code>⋅</code></li>
									<li><a href="/documentation/syntax/CROSS_PRODUCT.php">cross_product</a><code>×</code></li>
								</ul>
							</li>
							<li><a href="/documentation/syntax/DIVISION.php">division</a><code>/</code></li>
							<li><a href="/documentation/syntax/INTEGER_DIVISION.php">integer_division</a><code>\</code></li>
							<li><a href="/documentation/syntax/EXPONENTIATION.php">exponentiation</a><code>^</code></li>
							<li><a href="/documentation/syntax/MODULATION.php">modulation</a><code>%</code></li>
							<li><a href="/documentation/syntax/SHIFTL.php">shiftl</a><code>&lt;&lt;</code></li>
							<li><a href="/documentation/syntax/SHIFTR.php">shiftr</a><code>&gt;&gt;</code></li>
						</ul>
					</li>
					<li><a href="/documentation/syntax/BITWISE_OP.php">bitwise_op</a>
						<ul>
							<li><a href="/documentation/syntax/BIT_AND.php">bit_and</a><code>∧</code></li>
							<li><a href="/documentation/syntax/BIT_OR.php">bit_or</a><code>∨</code></li>
							<li><a href="/documentation/syntax/BIT_XOR.php">bit_xor</a><code>⊕</code></li>
						</ul>
					</li>
					<li><a href="/documentation/syntax/COLLECTION_OP.php">collection_op</a>
						<ul>
							<li><a href="/documentation/syntax/INTERSECTION.php">intersection</a><code>∩</code></li>
							<li><a href="/documentation/syntax/UNION.php">union</a><code>∪</code></li>
							<li><a href="/documentation/syntax/SYMMETRIC_DISJUNCTION.php">symmetric_disjunction</a><code>⊕</code></li>
							<li><a href="/documentation/syntax/DIFFERENCE.php">difference</a><code>\</code></li>
							<li><a href="/documentation/syntax/CHUNK.php">chunk</a><code>/</code></li>
							<li><a href="/documentation/syntax/CHUNK_MODULO.php">chunk_modulo</a><code>%</code></li>
						</ul>
					</li>
					<li><a href="/documentation/syntax/CONSTRUCTIVE_OP.php">constructive_op</a>
						<ul>
							<li><a href="/documentation/syntax/COMPOSITION.php">composition</a><code>∘</code></li>
							<li><a href="/documentation/syntax/PREPEND.php">prepend</a><code>:</code></li>
							<li><a href="/documentation/syntax/NULL_COALESCE.php">null_coalesce</a><code>??</code></li>
						</ul>
					</li>
					<li><a href="/documentation/syntax/BINARY_LOGICAL_OP.php">binary_logical_op</a>
						<ul>
							<li><a href="/documentation/syntax/AND.php">and</a><code>∧</code></li>
							<li><a href="/documentation/syntax/OR.php">or</a><code>∨</code></li>
							<li><a href="/documentation/syntax/XOR.php">xor</a><code>⊕</code></li>
							<li><a href="/documentation/syntax/IMPLICATION.php">implication</a><code>⇒</code></li>
							<li><a href="/documentation/syntax/IFF.php">iff</a><code>⇔</code></li>
							<li><a href="/documentation/syntax/MAPS_TO.php">maps_to</a><code>→</code></li>
							<li><a href="/documentation/syntax/BIJECTION.php">bijection</a><code>↔</code></li>
						</ul>
					</li>
					<li><a href="/documentation/syntax/RELATIONAL_OP.php">relational_op</a>
						<ul>
							<li><a href="/documentation/syntax/EQUALITY.php">equality</a><code>=</code></li>
							<li><a href="/documentation/syntax/INEQUALITY.php">inequality</a><code>≠</code></li>
							<li><a href="/documentation/syntax/LESSER_THAN.php">lesser_than</a><code>&lt;</code></li>
							<li><a href="/documentation/syntax/GREATER_THAN.php">greater_than</a><code>&gt;</code></li>
							<li><a href="/documentation/syntax/NOT_GREATER_THAN.php">not_greater_than</a><code>≤</code></li>
							<li><a href="/documentation/syntax/NOT_LESSER_THAN.php">not_lesser_than</a><code>≥</code></li>
							<li><a href="/documentation/syntax/RELATIONAL_COLLECTION_OP.php">relational_collection_op</a>
								<ul>
									<li><a href="/documentation/syntax/SUBSET.php">subset</a><code>⊆</code></li>
									<li><a href="/documentation/syntax/PROPER_SUBSET.php">proper_subset</a><code>⊂</code></li>
									<li><a href="/documentation/syntax/SUPERSET.php">superset</a><code>⊇</code></li>
									<li><a href="/documentation/syntax/SUPERSET.php">proper_superset</a><code>⊃</code></li>
									<li><a href="/documentation/syntax/IN.php">in</a><code>∈</code></li>
									<li><a href="/documentation/syntax/NOT_IN.php">not_in</a><code>∉</code></li>
									<li><a href="/documentation/syntax/HAS.php">has</a><code>∋</code></li>
									<li><a href="/documentation/syntax/NOT_HAS.php">not_has</a><code>∌</code></li>
								</ul>
							</li>
						</ul>
					</li>
				</ul>
			</li>
		</ul>
		<table>
			<tbody>
				<tr>
					<td>†</td><td>These operators are not used in the syntax of an <a href="/documentation/syntax/EXPRESSION.php">expression</a></td>
				</tr>
				<tr>
					<td>‡</td><td>These operators are turnary</td>
				</tr>
				<tr>
					<td>*</td><td>These unary operators are postfix</td>
				</tr>
			</tbody>
		</table>


		<?php require('../footer.php') ?>
	</body>
</html>
