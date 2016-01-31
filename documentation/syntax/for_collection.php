<meta charset='utf-8'/>
<html>
	<head>
		<title>for_collection - Plange</title>
		<link rel=StyleSheet href='../../css/general.css' type='text/css' />
	</head>
	<body>
		<?php require('../../header.php') ?>


		<p>creates a nullary void function that executes a given code block repeatedly, over the elements of the specified denumerable</p>
		<div class="code">
			<p>Syntax</p>
			<pre>"for" "(" (([ <a href="type_dereference.php">type_dereference</a> | <a href="implicit_type_dereference.php">implicit_type_dereference</a> ] <a href="symbol.php">identifier</a> ) | <a href="expression.php">expression</a> ) ("in"|"∈") <a href="expression.php">expression</a> ")" <a href="statement_scope.php">statement_scope</a></pre>
		</div>

		<div class="code">
			<p>Example</p>
<pre><> fibArray = [ 0, 1, 1, 2, 3, 5, 8, 13 ];
for (element ∈ fibArray) {
	print(element);
}</pre>
		</div>
		
		<div class="code">
			<p>Example</p>
<pre>for ((key, value) ∈ myMap) {
	//do something
}</pre>
		</div>

		<?php require('../../footer.php') ?>
	</body>
</html>