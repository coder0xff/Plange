<meta charset='utf-8'/>
<meta name="viewport" content="width=device-width, initial-scale=0.6">
<html>
	<head>
		<title>CONTINUE - Syntax Pages - Plange</title>
		<link rel=StyleSheet href='../../css/general.css' type='text/css' />
	</head>
	<body>
		<?php require('../../header.php') ?>


		<p>begin the next iteration in the containing for, do, or while/until loop</p>

		<div class="syntax">
			<p>syntax</p>
			<div>"continue" [({<a href="/documentation/syntax/IC.php">IC</a>} "[" {<a href="/documentation/syntax/IC.php">IC</a>} $<a href="/documentation/syntax/EXPRESSION.php">EXPRESSION</a> {<a href="/documentation/syntax/IC.php">IC</a>} "]") | ({<a href="/documentation/syntax/ICR.php">ICR</a>} $<a href="/documentation/syntax/IDENTIFIER.php">IDENTIFIER</a>)]</div>
		</div>
		<div class="code2">
			<p>Example</p>
			<pre>
for (i in X) {
    for (j in Y) {
        continue i;
    }
}
</pre>
		</div>		<h2>Notes</h2>
				<p>If a square-bracketed value is appended to the "continue" keyword, that many scope levels plus one will continue. "continue" is the same as "continue[0]". If a variable identifier follows to the continue keyword, the iterative flow-control primitive associated with that variable is affected.
		</p>



		<?php require('../../footer.php') ?>
	</body>
</html>