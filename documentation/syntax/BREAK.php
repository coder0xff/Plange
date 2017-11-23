<meta charset='utf-8'/>
<meta name="viewport" content="width=device-width, initial-scale=0.6">
<html>
	<head>
		<title>BREAK - Syntax Pages - Plange</title>
		<link rel=StyleSheet href='../../css/general.css' type='text/css' />
	</head>
	<body>
		<?php require('../../header.php') ?>


		<p>terminate the containing for, do, or while/until loop</p>

		<div class="syntax">
			<p>syntax</p>
			<div>"break" [({<a href="/documentation/syntax/IC.php">IC</a>} "[" {<a href="/documentation/syntax/IC.php">IC</a>} $<a href="/documentation/syntax/EXPRESSION.php">EXPRESSION</a> {<a href="/documentation/syntax/IC.php">IC</a>} "]") | ({<a href="/documentation/syntax/ICR.php">ICR</a>} $<a href="/documentation/syntax/IDENTIFIER.php">IDENTIFIER</a>)]</div>
		</div>
		<div class="code2">
			<p>Example</p>
			<pre>
for (i in X) {
    for (j in Y) {
        break i;
    }
}
</pre>
		</div>		<h2>Notes</h2>
				<p>If a square-bracketed value is appended to a the "break" keyword, that many scope levels plus one will terminate. "break" is the same as "break[0]". If a variable identifier follows the "break" keyword, the iterative flow-control primitive associated with that variable will be affected.
		</p>



		<?php require('../../footer.php') ?>
	</body>
</html>