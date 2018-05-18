<meta charset='utf-8'/>
<meta name="viewport" content="width=device-width, initial-scale=0.6">
<html>
	<head>
		<title>SET_COMPREHENSION - Syntax Pages - Plange</title>
		<link rel=StyleSheet href='../../css/general.css' type='text/css' />
	</head>
	<body>
		<?php require('../../header.php') ?>


		<p>create a Collection, substituting variables bound in the right hand side into the left hand side</p>

		<div class="syntax">
			<p>syntax</p>
			<div>"{" <a href="/documentation/syntax/EXPRESSION.php">EXPRESSION</a> "|" <a href="/documentation/syntax/EXPRESSION.php">EXPRESSION</a> "}"</div>
		</div>
		<div class="code2">
			<p>Example</p>
			<pre>
{ x | x ∈ ℝ ∧ x &lt; 3 }
</pre>
		</div>


		<?php require('../../footer.php') ?>
	</body>
</html>