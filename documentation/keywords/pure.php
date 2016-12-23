<meta charset='utf-8'/>
<meta name="viewport" content="width=device-width, initial-scale=0.6">
<html>
	<head>
		<title>pure - Plange</title>
		<link rel=StyleSheet href='../../css/general.css' type='text/css' />
	</head>
	<body>
		<?php require('../../header.php') ?>


		<p>when used in the <a href="../syntax/FUNCTION.php">function</a> syntax, indicates that the implementation's behavior meets the requirements of a pure function</p>
		<div class="code2">
			<p>Example</p>
			<pre>
pow2 := (x) pure { return x * x; };
			</pre>
		</div>
		<p>Notes: The pure keyword asserts to the toolchain that the behavior of the function is tractable and supports all properties and operations offered by function objects. An error occurs if the toolchain determines that any of the requirements of pure functions are not met by the implementation. Pure functions may only use data-pull semantics, and only on constants, which includes values (not by reference) passed as formal parameters. See <a href="../syntax/FUNCTION.php">function</a></p>


		<?php require('../../footer.php') ?>
	</body>
</html>