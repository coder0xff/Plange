<meta charset='utf-8'/>
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
	Double real;
	Double imaginary;
};

&lt;Pointer&lt;Complex&gt;&gt; ptr := <b>alloc(Complex)</b>; // create a new value on the heap</pre>
		</div>


		<?php require('../../footer.php') ?>
	</body>
</html>