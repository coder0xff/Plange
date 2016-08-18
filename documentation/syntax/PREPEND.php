<meta charset='utf-8'/>
<meta name="viewport" content="width=device-width, initial-scale=0.6">
<html>
	<head>
		<title>PREPEND - Syntax Pages - Plange</title>
		<link rel=StyleSheet href='../../css/general.css' type='text/css' />
	</head>
	<body>
		<?php require('../../header.php') ?>


		<p>create a new Collection starting with the left hand side followed by the elements of the right hand side Collection</p>

		<div class="syntax">
			<p>syntax</p>
			<div>EXPRESSION {IC} "&amp;" {IC} EXPRESSION</div>
		</div>
		<div class="code">
			<p>Example</p>
			<pre>x := 1 &amp; [2, 3, 4, 5]; y := [1, 2, 3, 4, 5]; x = y;</pre>
		</div>


		<?php require('../../footer.php') ?>
	</body>
</html>