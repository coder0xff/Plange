<meta charset='utf-8'/>
<meta name="viewport" content="width=device-width, initial-scale=0.6">
<html>
	<head>
		<title>alloc - Plange</title>
		<link rel=StyleSheet href='../../css/general.css' type='text/css' />
	</head>
	<body>
		<?php require('../../header.php') ?>


		<p>create a new value on the heap</p>

		<div class="code">
			<p>Example</p>
			<pre>Complex := class {
	&lt;Double&gt; real;
	&lt;Double&gt; imaginary;
};

&lt;Pointer&lt;Complex&gt;&gt; ptr := alloc(Complex); // create a new value on the heap</pre>
		</div>


		<?php require('../../footer.php') ?>
	</body>
</html>