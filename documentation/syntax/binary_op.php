<meta charset='utf-8'/>
<html>
	<head>
		<title>binary_op - Plange</title>
		<link rel=StyleSheet href='../../css/general.css' type='text/css' />
	</head>
	<body>
		<?php require('../../header.php') ?>


		<p>a sequence of one or more punctuation (and special) characters representing an infix operator</p>
		<div class="code">
			<p>Syntax</p>
			<div><a href="binary_arithmetic_op.php">binary_arithmetic_op</a> | <a href="bitwise_op.php">bitwise_op</a> | <a href="collection_op.php">collection_op</a> | <a href="constructive_op.php">constructive_op</a> | <a href="binary_logical_op.php">binary_logical_op</a> | <a href="multiplicative_op.php">multiplicative_op</a> | <a href="relational_op.php">relational_op</a></div>
		</div>

		<h2>Notes</h2>

		<h4>* (<a href="/documentation/cartesian-product">cartesian-product</a>)</h4>
		<ul>
			<li>as the arithmetic operator, multiplication: Number * Number → Number</li>
			<li>as the product of Types, making a tuple Type: Type * Type → Type</li>
			<li>as the the inner product of two vectors as an alternative to <a href="dot_product.php">dot_product</a>: Vector&lt;d, Number&gt; * Vector&lt;d, Number&gt; → Number</li>
			<li>See also: <a href="kleene_star.php">kleene_star</a></li>
		</ul>

		<h4>× (<a href="/documentation/syntax/cross_product.php">cross_product</a>)</h4>
		<p>The unicode character MULTIPLICATION SIGN (U+00D7) (not to be confused with x, the unicode character LATIN SMALL LETTER X (U+0078))
		may be typed as <code>_x_</code>.</p>
		<ul>
			<li>as the arithmetic operator "multiplication"</a>
				Function signature: Number * Number → Number
			</li>
			<li>as the cross product of two three component vectors <a href="cross_product.php">cross_product</a>
				Function signature: Vector&lt;3&gt; * Vector&lt;3&gt; → Vector&lt;3&gt;
			</li>
			<li>as the product of Types, making a tuple Type
				Function signature: Type * Type → Type
			</li>
		</ul>

		<h4>→ (arrow)</h4>
		<p>The unicode character RIGHTWARD ARROW (U+2192) may be typed as <code>-&gt;</code>.
		The arrow operator creates an object which is simultaneously a <b>function type</b>
		and a <a href="maps_to.php">maps_to</a> relation. The signature of a function is composed with the left hand side defining the function's domain (the input parameter types) and the right hand defining the codomain (the return type).</p>
		<ul>
			<li>as a factory of a function type
				Function signature: Type * Type → Type
			</li>
			<li>as a relation indicating a <a href="maps_to.php">maps_to</a> constraint
				Function signature: Set * Set → Relation
			</li>
		</ul>

		<h4>∘ (ring)</h4>
		<p>The unicode character RING OPERATOR (U+2218) may be typed as <code>_o_</code>.
			The ring operator composes functions such that <code>(f ○ g)(x)</code> is equivalent to
			<code>f(g(x))</code>.</p>
		<ul>
			<li>as the <a href="composition.php">composition</a> operator
				Function signature: (X → Y) * (Y → Z) → (X → Z)
			</li>
		</ul>

		<h4>& (prepend)</h4>
		<p>The prepend operator creates a new collection, putting the left hand operand at the beginning and then appending the collection in the right hand operand</p>
		<ul>
			<li>as the denumerable constructor <a href="prepend.php">prepend</a>
				Function signature: T * Collection&lt;T&gt; -&gt; Collection&lt;T&gt;
			</li>
		</ul>

		<h4>∪ (set_union)</h4>
		<p>The unicode character UNION (0x222A) may be typed as <code>_u_</code>. Not to be confused with 'U' (0x55).</p>
		<ul>
			<li>as the set union
				Function signature: Set * Set → Set
			</li>
		</ul>

		<h4>∩ (set_intersection)</h4>
		<p>The unicode character INTERSECTION (0x2229) may be typed as <code>_i_</code>.
		<ul>
			<li>as the set_intersection operator
				Function signature: Set * Set → Set
			</li>
		</ul>

		<h4>/ (slash)</h4>
		<ul>
			<li>as the collection_difference operator
				Function signature: Collection * Collection → Collection
			</li>
			<li>as the division operator
				Function signature: Number * Number → Number
			</li>
		</ul>

		<h4>⊕ (xor)</h4>
		<p>The unicode character CIRCLED PLUS (0x2295) may be typed as <code>_xor_</code>.</p>
		<ul>
			<li>as the set_symmetric_difference operator
				Function signature: Set * Set → Set
			</li>
			<li>as the xor operator
				Function signature: Bool * Bool → Bool
				Function signature: Integer * Integer → Integer
			</li>
		</ul>
		<p>See: <a href="/documentation/operators.php">Operators</a></p>


		<?php require('../../footer.php') ?>
	</body>
</html>