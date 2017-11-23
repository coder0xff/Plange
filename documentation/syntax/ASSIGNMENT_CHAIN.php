<meta charset='utf-8'/>
<meta name="viewport" content="width=device-width, initial-scale=0.6">
<html>
	<head>
		<title>ASSIGNMENT_CHAIN - Syntax Pages - Plange</title>
		<link rel=StyleSheet href='../../css/general.css' type='text/css' />
	</head>
	<body>
		<?php require('../../header.php') ?>


		<p>place the given value(s) into the given variable(s)</p>

		<div class="syntax">
			<p>syntax</p>
			<div>[$<a href="/documentation/syntax/XML_DOC_STRING.php">XML_DOC_STRING</a> {<a href="/documentation/syntax/IC.php">IC</a>}] $<a href="/documentation/syntax/IDENTIFIER.php">IDENTIFIER</a> {<a href="/documentation/syntax/IC.php">IC</a>} ("←"|"&lt;-") {<a href="/documentation/syntax/IC.php">IC</a>} ($<a href="/documentation/syntax/EXPRESSION.php">EXPRESSION</a>|ASSIGNMENT_CHAIN)</div>
		</div>
		<div class="code2">
			<p>Example</p>
			<pre>
iPow2 ← -1;
</pre>
		</div>		<h2>Notes</h2>
		<p>The left hand side may not be an lvalue (in C parlance). Rather, some algebras and solvers reduce free variables.</p>
<div class="code">
    <p>Example</p>
    <pre>x + 1 ← 0;</pre>
</div>
<p>Assignment operations can be chained together</p>
<div class="code">
    <p>Example</p>
    <pre>a ← b ← c;</pre>
</div>



		<?php require('../../footer.php') ?>
	</body>
</html>