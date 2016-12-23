<meta charset='utf-8'/>
<meta name="viewport" content="width=device-width, initial-scale=0.6">
<html>
	<head>
		<title>implementing - Plange</title>
		<link rel=StyleSheet href='../../css/general.css' type='text/css' />
	</head>
	<body>
		<?php require('../../header.php') ?>


		<p>used with the type keyword to inherit the interface of the specified Type</p>
		<div class="code2">
			<p>Example</p>
			<pre>
TextBox = type implementing Widget {
	&lt;Image&gt; draw;
}
			</pre>
		</div>
		<h2>Notes</h2>
		<p>The implementing keyword is similar to inheriting, but only the external interface is inherited. 
		The external interface is all of the publicly accessible members of the base type and all the base types ancestors. The derived type must implement this interface.
		This feature removes the need for explicit interfaces. All types have an interface. Like the inheriting keyword, implementing permits covariant return types, contravariant argument types, and covariant argument types (pattern matching).</p>

		<p>Implementers can be used for code injection. Altering an Scope to override an existing base type, using a derived implementing type, ensures that the external interface is preserved. This does not, however, guarantee that either 1) the same pre/postconditions exist on each method, or 2) that fields will remain as native scalars or non-volatile. Due to the second, there may be cases where a field becomes a
		<a href="../properties.php">property</a>. If the affected code is being interpreted, no additional modifications are needed. Otherwise, if it is possible to recompile or switch to interpreting (the source code is available), then do either. If the source code is not available (it was stripped), then an exception is thrown.</p>


		<?php require('../../footer.php') ?>
	</body>
</html>