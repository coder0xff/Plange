<meta charset='utf-8'/>
<meta name="viewport" content="width=device-width, initial-scale=0.6">
<html>
	<head>
		<title>EXISTS - Syntax Pages - Plange</title>
		<link rel=StyleSheet href='../../css/general.css' type='text/css' />
	</head>
	<body>
		<?php require('../../header.php') ?>


		<p>a constraint asserting that at least one element of the specified Collection is true</p>

		<div class="syntax">
			<p>syntax</p>
			<div>"∃" {<a href="/documentation/syntax/IC.php">IC</a>} <a href="/documentation/syntax/EXPRESSION.php">EXPRESSION</a></div>
		</div>
		<div class="code">
			<p>Example</p>
			<pre>shouldRejectLiquorPurchase := (List&lt;Date&gt; patronBirthdates) {
    return ∃{ x &lt; today() - 21yr | x ∈ patronBirthdates };
}</pre>
		</div>		<h2>Notes</h2>
		<p>The values in the collection need not be Bool, so long as <code>Bool casts T</code> is true, where T is the type of each element.<p>
		<p>See: <a href="EXISTS_ONE.php">EXISTS_ONE</a> <a href="ALL.php">ALL</a>
		</p>



		<?php require('../../footer.php') ?>
	</body>
</html>