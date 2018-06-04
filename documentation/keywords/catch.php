<meta charset='utf-8'/>
<meta name="viewport" content="width=device-width, initial-scale=0.6">
<html>
	<head>
		<title>catch - Plange</title>
		<link rel=StyleSheet href='../../css/general.css' type='text/css' />
	</head>
	<body>
		<?php require('../../header.php') ?>


		<p>handle any exceptions thrown within the preceding try block</p>
		<div class="code2">
			<p>Example</p>
			<pre>
try {
	open("test.txt");
} catch (File.NotFoundException) {
	print("test.txt was not found in the working directory);
} finally {
	print("done");
}
			</pre>
		</div>

		<p>See: <a href="try.php">try</a>, <a href="finally.php">finally</a></p>
		<p>See also: <a href="../syntax.php?name=TRY">try (syntax)</a></p>


		<?php require('../../footer.php') ?>
	</body>
</html>