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
			<div>"∃" {IC} EXPRESSION</div>
		</div>
		<div class="code">
			<p>Example</p>
			<pre></pre>
		</div><p>The values in the collection need not be Bool, so long as <code>Bool casts T</code> is true, where T is the type of each element.<p>
		<p>See:<a href="EXISTS_ONE.php">EXISTS_ONE</a><a href="ALL.php">ALL</a>
		</p>



		<?php require('../../footer.php') ?>
	</body>
</html>