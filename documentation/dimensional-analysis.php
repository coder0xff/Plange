<meta charset='utf-8'/>
<html>
	<head>
		<title>Dimensional Analysis - Plange</title>
		<link rel=StyleSheet href='../css/general.css' type='text/css' />
	</head>
	<body>
		<?php require('../header.php') ?>
		

		<p>Dimensional analysis aids in the modeling of physical systems by providing type safety and unit conversion.</p>

		<div class="code">
			<p>Example</p>
			<pre>position <- (0m, 0m, 0m);
velocity := (1.3 km/s, 0 km/s, 1 km/s);
elapsed := 5s;
position += velocity * elapsed;</pre>
		</div>


		<p>The syntax for this feature can be found in <a href="/documentation/syntax/dimensional_number.php">dimensional_number</a> and is referenced by the <a href="/documentation/syntax/expression.php">expression</a> syntax.</p>


		<?php require('../footer.php') ?>
	</body>
</html>