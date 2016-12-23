<meta charset='utf-8'/>
<meta name="viewport" content="width=device-width, initial-scale=0.6">
<html>
	<head>
		<title>LIST - Syntax Pages - Plange</title>
		<link rel=StyleSheet href='../../css/general.css' type='text/css' />
	</head>
	<body>
		<?php require('../../header.php') ?>


		<p>a Collection of items</p>

		<div class="syntax">
			<p>syntax</p>
			<div>"[|" {<a href="/documentation/syntax/IC.php">IC</a>} [<a href="/documentation/syntax/EXPRESSION.php">EXPRESSION</a> {{<a href="/documentation/syntax/IC.php">IC</a>} ", " {<a href="/documentation/syntax/IC.php">IC</a>} <a href="/documentation/syntax/EXPRESSION.php">EXPRESSION</a>} {<a href="/documentation/syntax/IC.php">IC</a>} ] "|]"</div>
		</div>
		<p>the empty list
		</p>
		<div class="code2">
			<p>Example</p>
			<pre>
[| |]
</pre>
		</div>		<div class="code2">
			<p>Example</p>
			<pre>
[|1, 5, 2, 2, 2|]
</pre>
		</div>		<div class="code2">
			<p>Example</p>
			<pre>
short_days_of_week := ["Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"];
</pre>
		</div>


		<?php require('../../footer.php') ?>
	</body>
</html>