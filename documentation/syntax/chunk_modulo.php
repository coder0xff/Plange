<meta charset='utf-8'/>
<html>
	<head>
		<title>chunk_modulo - Plange</title>
		<link rel=StyleSheet href='../../css/general.css' type='text/css' />
	</head>
	<body>
		<?php require('../../header.php') ?>


		<p>returns a collection containing the elements that would not be consumed from the end of the left hand side by taking the chunk of the right hand side</p>
		<div class="syntax">
			<p>syntax</p>
			<div><a href="expression.php">expression</a> "%" <a href="expression.php">expression</a></div>
		</div>
		<h2>Notes</h2>
		<p>The returned collection always contains zero to N-1 elements, where N is the integer specified on the right hand side</p>
		<p>See: <a href="chunk.php">chunk</a></p>


		<?php require('../../footer.php') ?>
	</body>
</html>