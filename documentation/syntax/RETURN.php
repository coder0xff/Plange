<meta charset='utf-8'/>
<meta name="viewport" content="width=device-width, initial-scale=0.6">
<html>
	<head>
		<title>RETURN - Syntax Pages - Plange</title>
		<link rel=StyleSheet href='../../css/general.css' type='text/css' />
	</head>
	<body>
		<?php require('../../header.php') ?>


		<p>exit the current function, optionally returning a value</p>

		<div class="syntax">
			<p>syntax</p>
			<div>"return" [{<a href="/documentation/syntax/IC.php">IC</a>} "[" {<a href="/documentation/syntax/IC.php">IC</a>} <a href="/documentation/syntax/EXPRESSION.php">EXPRESSION</a> {<a href="/documentation/syntax/IC.php">IC</a>} "]"] [ {<a href="/documentation/syntax/IC.php">IC</a>} <a href="/documentation/syntax/EXPRESSION.php">EXPRESSION</a> ]</div>
		</div>
		<h2>Notes</h2>
				<p>if a square-bracketed value is appended to a the "return" keyword, that many scope levels plus one will return. "return" is the same as "return[0]".
		</p>



		<?php require('../../footer.php') ?>
	</body>
</html>