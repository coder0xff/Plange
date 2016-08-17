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
			<li><a href="/documentation/syntax/definition.php">definition</a><sup>†</sup><code>:=</code></li>
			<li><a href="/documentation/syntax/assignment.php">assignment</a><sup>†</sup><code>←</code></li>
			<li><a href="/documentation/syntax/conditional.php">conditional</a><sup>‡</sup><code>? :</code></li>
			<li><a href="/documentation/syntax/dimensional_analysis_op.php">dimensional_analysis_op</a><sup>†</sup>
				<ul>
					<li><a href="/documentation/syntax/unit_division.php">unit_division</a><sup>†</sup><code>/</code></li>
					<li><a href="/documentation/syntax/unit_multiplication.php">unit_multiplication</a><sup>†</sup><code>*</code></li>
					<li><a href="/documentation/syntax/unit_exponentiation.php">unit_exponentiation</a><sup>†</sup><code>^</code></li>
				</ul>
			</li>
			<li><a href="/documentation/syntax/unary_op.php">unary_op</a>
				<ul>
					<li><a href="/documentation/syntax/cardinality.php">cardinality</a><code>#</code></li>
					<li><a href="/documentation/syntax/kleene_star.php">kleene_star</a><sup>*</sup><code>*</code></li>
					<li><a href="/documentation/syntax/unary_arithmetic_op.php">unary_arithmetic_op</a>
						<ul>
							<li><a href="/documentation/syntax/negation.php">negation</a><code>-</code></li>
							<li><a href="/documentation/syntax/radical.php">radical</a><code>√</code></li>
							<li><a href="/documentation/syntax/factorial.php">factorial</a><sup>*</sup><code>!</code></li>
							<li><a href="/documentation/syntax/post_inc.php">post_inc</a><sup>*</sup><code>++</code></li>
							<li><a href="/documentation/syntax/pre_inc.php">pre_inc</a><code>++</code></li>
							<li><a href="/documentation/syntax/post_dec.php">post_dec</a><sup>*</sup><code>--</code></li>
							<li><a href="/documentation/syntax/pre_dec.php">pre_dec</a><code>--</code></li>
						</ul>
					</li>
					<li><a href="/documentation/syntax/unary_logical_op.php">unary_logical_op</a>
						<ul>
							<li><a href="/documentation/syntax/not.php">not</a><code>¬</code></li>
							<li><a href="/documentation/syntax/all.php">all</a><code>∀</code></li>
							<li><a href="/documentation/syntax/exists.php">exists</a><code>∃</code></li>
							<li><a href="/documentation/syntax/exists_one.php">exists_one</a><code>∃!</code></li>
						</ul>
					</li>
				</ul>
			</li>
			<li><a href="/documentation/syntax/binary_op.php">binary_op</a>
				<ul>
					<li><a href="/documentation/syntax/binary_arithmetic_op.php">binary_arithmetic_op</a>
						<ul>
							<li><a href="/documentation/syntax/addition.php">addition</a><code>+</code></li>
							<li><a href="/documentation/syntax/subtraction.php">subtraction</a><code>-</code></li>
							<li><a href="/documentation/syntax/add_sub.php">add_sub</a><code>±</code></li>
							<li><a href="/documentation/syntax/multiplicative_op.php">multiplicative_op</a>
								<ul>
									<li><a href="/documentation/syntax/multiplication.php">multiplication</a><code>*</code></li>
									<li><a href="/documentation/syntax/dot_product.php">dot_product</a><code>⋅</code></li>
									<li><a href="/documentation/syntax/cross_product.php">cross_product</a><code>×</code></li>
								</ul>
							</li>
							<li><a href="/documentation/syntax/division.php">division</a><code>/</code></li>
							<li><a href="/documentation/syntax/integer_division.php">integer_division</a><code>\</code></li>
							<li><a href="/documentation/syntax/exponentiation.php">exponentiation</a><code>^</code></li>
							<li><a href="/documentation/syntax/modulation.php">modulation</a><code>%</code></li>
							<li><a href="/documentation/syntax/shiftl.php">shiftl</a><code>&lt;&lt;</code></li>
							<li><a href="/documentation/syntax/shiftr.php">shiftr</a><code>&gt;&gt;</code></li>
						</ul>
					</li>
					<li><a href="/documentation/syntax/bitwise_op.php">bitwise_op</a>
						<ul>
							<li><a href="/documentation/syntax/bit_and.php">bit_and</a><code>∧</code></li>
							<li><a href="/documentation/syntax/bit_or.php">bit_or</a><code>∨</code></li>
							<li><a href="/documentation/syntax/bit_xor.php">bit_xor</a><code>⊕</code></li>
						</ul>
					</li>
					<li><a href="/documentation/syntax/collection_op.php">collection_op</a>
						<ul>
							<li><a href="/documentation/syntax/intersection.php">intersection</a><code>∩</code></li>
							<li><a href="/documentation/syntax/union.php">union</a><code>∪</code></li>
							<li><a href="/documentation/syntax/symmetric_disjunction.php">symmetric_disjunction</a><code>⊕</code></li>
							<li><a href="/documentation/syntax/difference.php">difference</a><code>\</code></li>
							<li><a href="/documentation/syntax/chunk.php">chunk</a><code>/</code></li>
							<li><a href="/documentation/syntax/chunk_modulo.php">chunk_modulo</a><code>%</code></li>
						</ul>
					</li>
					<li><a href="/documentation/syntax/constructive_op.php">constructive_op</a>
						<ul>
							<li><a href="/documentation/syntax/composition.php">composition</a><code>∘</code></li>
							<li><a href="/documentation/syntax/prepend.php">prepend</a><code>:</code></li>
							<li><a href="/documentation/syntax/null_coalesce.php">null_coalesce</a><code>??</code></li>
						</ul>
					</li>
					<li><a href="/documentation/syntax/binary_logical_op.php">binary_logical_op</a>
						<ul>
							<li><a href="/documentation/syntax/and.php">and</a><code>∧</code></li>
							<li><a href="/documentation/syntax/or.php">or</a><code>∨</code></li>
							<li><a href="/documentation/syntax/xor.php">xor</a><code>⊕</code></li>
							<li><a href="/documentation/syntax/implication.php">implication</a><code>⇒</code></li>
							<li><a href="/documentation/syntax/iff.php">iff</a><code>⇔</code></li>
							<li><a href="/documentation/syntax/maps_to.php">maps_to</a><code>→</code></li>
							<li><a href="/documentation/syntax/bijection.php">bijection</a><code>↔</code></li>
						</ul>
					</li>
					<li><a href="/documentation/syntax/relational_op.php">relational_op</a>
						<ul>
							<li><a href="/documentation/syntax/equality.php">equality</a><code>=</code></li>
							<li><a href="/documentation/syntax/inequality.php">inequality</a><code>≠</code></li>
							<li><a href="/documentation/syntax/lesser_than.php">lesser_than</a><code>&lt;</code></li>
							<li><a href="/documentation/syntax/greater_than.php">greater_than</a><code>&gt;</code></li>
							<li><a href="/documentation/syntax/not_greater_than.php">not_greater_than</a><code>≤</code></li>
							<li><a href="/documentation/syntax/not_lesser_than.php">not_lesser_than</a><code>≥</code></li>
							<li><a href="/documentation/syntax/relational_collection_op.php">relational_collection_op</a>
								<ul>
									<li><a href="/documentation/syntax/subset.php">subset</a><code>⊆</code></li>
									<li><a href="/documentation/syntax/proper_subset.php">proper_subset</a><code>⊂</code></li>
									<li><a href="/documentation/syntax/superset.php">superset</a><code>⊇</code></li>
									<li><a href="/documentation/syntax/superset.php">proper_superset</a><code>⊃</code></li>
									<li><a href="/documentation/syntax/in.php">in</a><code>∈</code></li>
									<li><a href="/documentation/syntax/not_in.php">not_in</a><code>∉</code></li>
									<li><a href="/documentation/syntax/has.php">has</a><code>∋</code></li>
									<li><a href="/documentation/syntax/not_has.php">not_has</a><code>∌</code></li>
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
					<td>†</td><td>These operators are not used in the syntax of an <a href="/documentation/syntax/expression.php">expression</a></td>
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
