<meta charset='utf-8'/>
<html>
	<head>
		<title>all - Plange</title>
		<link rel=StyleSheet href='../../css/general.css' type='text/css' />
	</head>
	<body>
		<?php require('../../header.php') ?>


		<p>creates a constraint asserting that all elements of the Collection, specified by the expression, are true</p>
		<div class="code">
			<p>Syntax</p>
			<pre>"∀" <a href="expression.php">expression</a></pre>
		</div>

		<div class="code">
			<p>Example</p>
			<pre>someNumbers := {| -100, 1, 100 |};

if (∀ { x >= 0 where x ∈ someNumbers}) {
	print("None of the numbers are negative");
} else {
	print("Some of the numbers are negative");
}</p>
		</div>

		<div class="code">
			<p>Example</p>
			<pre></pre>
		</div>

		<h2>Notes</h2>
		<p>The values in the collection need not be Bool, so long as <code>Bool casts T</code> is true, where T is the type of each element.<p>
		<p>See also: <a href="/documentation/syntax/exists.php">∃ (exists)</a>, <a href="/documentation/syntax/exists_one.php">∃! (exists_one)</a></p>

		<?php require('../../footer.php') ?>
	</body>
</html>