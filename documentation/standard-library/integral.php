<meta charset='utf-8'/>
<meta name="viewport" content="width=device-width, initial-scale=0.6">
<html>
	<head>
		<title>integral - Plange</title>
		<link rel=StyleSheet href='../../css/general.css' type='text/css' />
	</head>
	<body>
		<?php require('../../header.php') ?>

		<div class="syntax">
			<p>Usage</p>
			<div>"∫(" expression, identifier ("(-"|"∈") expression ")"</div>
		</div>
		<div class="code2">
			<p>Example</p>
			<pre>
1 = ∫(dirac_delta(x), x ∈ [-infinity to infinity]);
			</pre>
		</div>
		<div class="code2">
			<p>Example</p>
			<pre>
pi := ∫(√(1 - i(0)^2 - i(1)^2), i ∈ [-1.0 to 1.0]^2) / (4/3);
			</pre>
		</div>


		<?php require('../../footer.php') ?>
	</body>
</html>