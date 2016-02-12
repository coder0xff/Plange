<meta charset='utf-8'/>
<html>
	<head>
		<title>if - Plange</title>
		<link rel=StyleSheet href='../../css/general.css' type='text/css' />
	</head>
	<body>
		<?php require('../../header.php') ?>


		<p>returns the <a href="expression.php">expression</a> corresponding to the first <a href="parenthetical.php">parenthetical</a> that evaluates to true when coerced to a boolean, or the else case if none of them evaluate to true, assuming that the else case is present, otherwise returning void</p>

		<div class="syntax">
			<p>syntax</p>
			<div>"<a href="../keywords/if.php">if</a>" <a href="parenthetical.php">parenthetical</a> <a href="expression.php">expression</a> ( "<a href="../keywords/if.php">elif</a>" <a href="parenthetical.php">parenthetical</a> <a href="expression.php">expression</a> )* [ "<a href="../keywords/if.php">else</a>" <a href="expression.php">expression</a> ]</div>
		</div>

		<div class="code">
			<p>Example</p>
			<pre>if (input("What is 1 + 1 ? ") = "2") {
	print("You are correct!");
} else {
	print("Sorry, you are incorrect.");
}</pre>
		</div>

		<h2>Notes</h2>


		<?php require('../../footer.php') ?>
	</body>
</html>