<meta charset='utf-8'/>
<meta name="viewport" content="width=device-width, initial-scale=0.6">
<html>
	<head>
		<title>RANGE - Syntax Pages - Plange</title>
		<link rel=StyleSheet href='../../css/general.css' type='text/css' />
	</head>
	<body>
		<?php require('../../header.php') ?>


		<p>create a totally-ordered open/closed/half-open discreet/continuous Collection</p>

		<div class="syntax">
			<p>syntax</p>
			<div>"(" {<a href="/documentation/syntax/IC.php">IC</a>} "..." {<a href="/documentation/syntax/IC.php">IC</a>} <a href="/documentation/syntax/EXPRESSION.php">EXPRESSION</a> {<a href="/documentation/syntax/IC.php">IC</a>} ("]"|")") | ("["|"(") {<a href="/documentation/syntax/IC.php">IC</a>} <a href="/documentation/syntax/EXPRESSION.php">EXPRESSION</a> {<a href="/documentation/syntax/IC.php">IC</a>} "..." {<a href="/documentation/syntax/IC.php">IC</a>} ")" | ("("|"[") {<a href="/documentation/syntax/IC.php">IC</a>} <a href="/documentation/syntax/EXPRESSION.php">EXPRESSION</a> {<a href="/documentation/syntax/IC.php">IC</a>} "..." {<a href="/documentation/syntax/IC.php">IC</a>} <a href="/documentation/syntax/EXPRESSION.php">EXPRESSION</a> {<a href="/documentation/syntax/IC.php">IC</a>} ("]"|")")</div>
		</div>
		<div class="code">
			<p>Example</p>
			<pre>wholeNumbers := [ 0 ... ); // the non negative integers - the set is infinite and denumerable</pre>
		</div>		<div class="code">
			<p>Example</p>
			<pre>positivesIntsToN := [ 1 ... n ]; // the integers 1 to n inclusive - the set is finite and denumerable</pre>
		</div>		<div class="code">
			<p>Example</p>
			<pre>negativeReals := ( ... 0.0 ) // the negative real numbers - the set is infinite and nondenumerable</pre>
		</div>


		<?php require('../../footer.php') ?>
	</body>
</html>