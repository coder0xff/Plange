<meta charset='utf-8'/>
<html>
	<head>
		<title>break - Plange</title>
		<link rel=StyleSheet href='../../css/general.css' type='text/css' />
	</head>
	<body>
		<?php require('../../header.php') ?>


		<p>exit a <a href="do.php">do</a>, <a href="../syntax/loop.php">while, until</a>, <a href="for.php">for</a> or <a href="../syntax/for_collection.php">for_collection</a> loop</p>
		<div class="code">
			<p>Example</p>
			<pre>//echo the users input until they enter nothing
do {
	&lt;String&gt; x := input();
	if (x = "") {
		break;
	}
	print(x);
}</pre>
		</div>


		<?php require('../../footer.php') ?>
	</body>
</html>