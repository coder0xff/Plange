<meta charset='utf-8'/>
<meta name="viewport" content="width=device-width, initial-scale=0.6">
<html>
	<head>
		<title>this_type - Plange</title>
		<link rel=StyleSheet href='../../css/general.css' type='text/css' />
	</head>
	<body>
		<?php require('../../header.php') ?>


		<p>an alias to the Type of the current type_scope, or the nearest ancestor type_scope, or an error if there is none</p>

		<div class="code2">
			<p>Example</p>
			<pre>
// A node for a K-Ary tree
KAryNode := (&lt;Int&gt; k, &lt;Type&gt; t) {
	return type {
		&lt;t&gt; value;
		&lt;this_type&gt; nullNode := this_type();
		Array&lt;k, this_type&gt; children = [nullNode]*k;
	};
};
			</pre>
		</div>

		<h2>Notes</h2>
		<p>Since the <code><a href="/documentation/keywords/this.php">this</a></code> keyword is only valid inside member functions of a type, <code><a href="/documentation/keywords/type_of.php">type_of</a>(this)</code> is not viable for some constructions, such as the above example.</p>


		<?php require('../../footer.php') ?>
	</body>
</html>