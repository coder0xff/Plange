<meta charset='utf-8'/>
<meta name="viewport" content="width=device-width, initial-scale=0.6">
<html>
	<head>
		<title>exists - Plange</title>
		<link rel=StyleSheet href='../../css/general.css' type='text/css' />
	</head>
	<body>
		<?php require('../../header.php') ?>


		<p>creates a constraint asserting that one or more elements of the Collection, specified by the expression, are true</p>
		<div class="syntax">
			<p>syntax</p>
			<div>"∃" <a href="expression.php">expression</a></div>
		</div>


		<div class="code">
			<p>Example</p>
			<pre>shouldRejectLiquorPurchase := (List&lt;Date&gt; patronBirthdates) {
	return ∃ { x &lt; today() - 21 yr where x ∈ patronBirthdates };
}</pre>
		</div>

		<h2>Notes</h2>
		<p>The values in the collection need not be Bool, so long as <code>Bool casts T</code> is true, where T is the type of each element.<p>
		<p>See also: <a href="/documentation/syntax/exists_one.php">∃! (exists_one)</a> <a href="/documentation/syntax/all.php">∀ (all)</p>

		<?php require('../../footer.php') ?>
	</body>
</html>