<meta charset='utf-8'/>
<meta name="viewport" content="width=device-width, initial-scale=0.6">
<html>
	<head>
		<title>DO - Syntax Pages - Plange</title>
		<link rel=StyleSheet href='../../css/general.css' type='text/css' />
	</head>
	<body>
		<?php require('../../header.php') ?>


		<p>creates a nullary void function that invokes a specified nullary void function (expression) once and then repeatedly while or until the parenthetical evaluates to true (when coerced to bool), unless the optional portion is omitted, in which case the function is invoked indefinitely</p>

		<div class="syntax">
			<p>syntax</p>
			<div>"do" {IC} EXPRESSION [ {IC} ("while"|"until") {IC} PARENTHETICAL ]</div>
		</div>
		<p>See:<a href="LOOP.php">LOOP</a>
		</p>



		<?php require('../../footer.php') ?>
	</body>
</html>