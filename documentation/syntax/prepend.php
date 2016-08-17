<meta charset='utf-8'/>
<meta name="viewport" content="width=device-width, initial-scale=0.6">
<html>
	<head>
		<title>prepend - Plange</title>
		<link rel=StyleSheet href='../../css/general.css' type='text/css' />
	</head>
	<body>
		<?php require('../../header.php') ?>


		<div class="syntax">
			<p>syntax</p>
			<div><a href="expression.php">expression</a> "&" <a href="expression.php">expression</a></div>
		</div>

		<div class="code">
			<p>Example</p>
			<pre>x := 1 &amp; [2, 3, 4, 5];
y := [1, 2, 3, 4, 5];
x = y;</pre>
		</div>
		
		<?php require('../../footer.php') ?>
	</body>
</html>