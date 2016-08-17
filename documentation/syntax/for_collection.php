<meta charset='utf-8'/>
<meta name="viewport" content="width=device-width, initial-scale=0.6">
<html>
	<head>
		<title>for_collection - Plange</title>
		<link rel=StyleSheet href='../../css/general.css' type='text/css' />
	</head>
	<body>
		<?php require('../../header.php') ?>


		<p>creates a nullary void function that executes a given code block repeatedly, over the elements of the specified denumerable</p>
		<div class="syntax">
			<p>syntax</p>
			<div>"for" "(" (([ <a href="/documentation/syntax/type_dereference.php">type_dereference</a> | <a href="/documentation/syntax/implicit_type_dereference.php">implicit_type_dereference</a> ] <a href="/documentation/syntax/identifier.php">identifier</a> ) | <a href="/documentation/syntax/expression.php">expression</a> ) ("in"|"∈") <a href="/documentation/syntax/expression.php">expression</a> ")" <a href="/documentation/syntax/statement_scope.php">statement_scope</a></div>
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