<meta charset='utf-8'/>
<meta name="viewport" content="width=device-width, initial-scale=0.6">
<html>
	<head>
		<title>Dimensional Analysis - Plange</title>
		<link rel=StyleSheet href='../css/general.css' type='text/css' />
	</head>
	<body>
		<?php require('../header.php') ?>
		

		<p>Dimensional analysis aids in the modeling of physical systems by providing type safety and unit conversion.</p>

		<div class="code2">
			<p>Example</p>
			<pre>
position ← (0m, 0m, 0m);
velocity := (1.3 cm/s, 0 cm/s, 1 cm/s);
elapsed := 5s;
position ← position + velocity * elapsed;
			</pre>
		</div>

		<p>The syntax for this feature can be found in <a href="/documentation/syntax.php?name=DIMENSIONAL_NUMBER">dimensional_number</a> and is referenced by the <a href="/documentation/syntax.php?name=EXPRESSION">expression</a> syntax.</p>


		<?php require('../footer.php') ?>
	</body>
</html>