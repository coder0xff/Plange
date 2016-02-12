<meta charset='utf-8'/>
<html>
	<head>
		<title>range - Plange</title>
		<link rel=StyleSheet href='../../css/general.css' type='text/css' />
	</head>
	<body>
		<?php require('../../header.php') ?>


		<p>creates an open, closed, or half open Set containing a range. It may be either discreet or continuous.</p>
		<div class="syntax">
			<p>syntax</p>
			<div>"(" "..." <a href="expression.php">expression</a> ("]"|")") | ("["|"(") <a href="expression.php">expression</a> "..." ")" | ("("|"[") <a href="expression.php">expression</a> "..." <a href="expression.php">expression</a> ("]"|")")</div>
		</div>
		<div class="code">
			<p>Example</p>
			<pre>[ 0 ... ) // the non negative integers - the set is infinite and denumerable</pre>
		</div>
		<div>
			<p>Example</p>
			<pre>[ 1 ... n ] // the integers 1 to n inclusive - the set is finite and denumerable</pre>
		</div>
		<div>
			<p>Example</p>
			<pre>( ... 0.0 ) // the negative real numbers - the set is infinite and nondenumerable</pre>
		</div>


		<?php require('../../footer.php') ?>
	</body>
</html>