<meta charset='utf-8'/>
<meta name="viewport" content="width=device-width, initial-scale=0.6">
<html>
	<head>
		<title>THROW - Syntax Pages - Plange</title>
		<link rel=StyleSheet href='../../css/general.css' type='text/css' />
	</head>
	<body>
		<?php require('../../header.php') ?>


		<p>raise an exception with an optional value which must implement Exception if specified</p>

		<div class="syntax">
			<p>syntax</p>
			<div>"throw" [{<a href="/documentation/syntax/IC.php">IC</a>} "[" <a href="/documentation/syntax/EXPRESSION.php">EXPRESSION</a> "]" ] [{<a href="/documentation/syntax/IC.php">IC</a>} <a href="/documentation/syntax/EXPRESSION.php">EXPRESSION</a>]</div>
		</div>
		<h2>Notes</h2>
				<p>if throw is followed by a square-bracketed expression, that many stack frames will unwind before throwing the exception. "throw" is the same as "throw[0]".
		</p>
		<p>See: <a href="TRY.php">TRY</a>
		</p>



		<?php require('../../footer.php') ?>
	</body>
</html>