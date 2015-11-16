<meta charset='utf-8'/>
<html>
	<head>
		<title>dereference - Plange</title>
		<link rel=StyleSheet href='../../css/general.css' type='text/css' />
	</head>
	<body>
		<?php require('../../header.php') ?>


		<p>returns the value at a memory address specified by a <a href="documentation/standard-library/pointer.php">Pointer</a></p>
		<h2>Notes</h2>
		<p>Use of the dereference keyword will often cause the containing code block to be implicitly <a href="imperative.php">imperative</a>. That is, static analysis may not be able to model the behavior of random memory access.
		<p>See also: <a href="address_of.php">address_of</a></p>


		<?php require('../../footer.php') ?>
	</body>
</html>