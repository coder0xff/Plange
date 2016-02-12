<meta charset='utf-8'/>
<html>
	<head>
		<title>set_comprehension - Plange</title>
		<link rel=StyleSheet href='../../css/general.css' type='text/css' />
	</head>
	<body>
		<?php require('../../header.php') ?>


		<div class="syntax">
			<p>syntax</p>
			<div>"{" <a href="/documentation/syntax/expression.php">expression</a> "where" <a href="/documentation/syntax/expression.php">expression</a> "}"</div>
		</div>
		<div class="code">
			<p>Example</p>
			<pre>{ x where x ∈ ℝ ∧ x &lt; 3 }</pre>
		</div>
		<div class="code">
			<p>Example</p>
			<pre>{ x where x in RR and x &lt; 3}</pre>
		</div>


		<?php require('../../footer.php') ?>
	</body>
</html>