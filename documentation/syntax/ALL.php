<meta charset='utf-8'/>
<meta name="viewport" content="width=device-width, initial-scale=0.6">
<html>
	<head>
		<title>ALL - Syntax Pages - Plange</title>
		<link rel=StyleSheet href='../../css/general.css' type='text/css' />
	</head>
	<body>
		<?php require('../../header.php') ?>


		<p>constrain ALL elements of a Collection to be true</p>

		<div class="syntax">
			<p>syntax</p>
			<div>"∀" {<a href="/documentation/syntax/IC.php">IC</a>} <a href="/documentation/syntax/EXPRESSION.php">EXPRESSION</a></div>
		</div>
		<div class="code">
			<p>Example</p>
			<pre>someNumbers := {| -100, 1, 100 |};

if (∀ { x &gt;= 0 where x ∈ someNumbers}) {
    print("None of the numbers are negative");
} else {
    print("Some of the numbers are negative");
}</pre>
		</div>		<h2>Notes</h2>
				<p>The values in the collection need not be Bool, so long as Bool casts T is true, where T is the type of each element.
		</p>
		<p>See: <a href="EXISTS.php">EXISTS</a> <a href="EXISTS_ONE.php">EXISTS_ONE</a>
		</p>



		<?php require('../../footer.php') ?>
	</body>
</html>