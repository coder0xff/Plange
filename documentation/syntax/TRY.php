<meta charset='utf-8'/>
<meta name="viewport" content="width=device-width, initial-scale=0.6">
<html>
	<head>
		<title>TRY - Syntax Pages - Plange</title>
		<link rel=StyleSheet href='../../css/general.css' type='text/css' />
	</head>
	<body>
		<?php require('../../header.php') ?>


		<p>executes the specified nullary void function of the first expression, catching exceptions that pattern match the function(s) of the second expression, and then executes the third expression unconditionally</p>

		<div class="syntax">
			<p>syntax</p>
			<pre>"try" {IC} EXPRESSION {IC} "catch" {IC} EXPRESSION {"catch" {IC} EXPRESSION} [{IC} "finally" {IC} EXPRESSION]</pre>
		</div>



		<?php require('../../footer.php') ?>
	</body>
</html>