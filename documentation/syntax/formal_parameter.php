<meta charset='utf-8'/>
<html>
	<head>
		<title>parameter - Plange</title>
		<link rel=StyleSheet href='../../css/general.css' type='text/css' />
	</head>
	<body>
		<?php require('../../header.php') ?>


		<p>a formal parameter of a function</p>
		<div class="code">
			<p>Syntax</p>
			<pre>[ <a href="type_dereference.php">type_dereference</a> ] <a href="symbol.php">identifier</a> | [ <a href="type_dereference.php">type_dereference</a> | <a href="implicit_type_dereference.php">implicit_type_dereference</a> ] <a href="symbol.php">identifier</a> "=" <a href="expression.php">expression</a> | <a href="expression.php">expression</a> ["=" <a href="expression.php">expression</a> ]</pre>
		</div>
		<h2>Notes</h2>
		<p>The last variation accepts an expression, which is then set to be equivalent to the passed in value. This enables pattern matching and solving on parameters.</p>
		<p>See also: <a href="function.php">function (syntax)</a></p>


		<?php require('../../footer.php') ?>
	</body>
</html>