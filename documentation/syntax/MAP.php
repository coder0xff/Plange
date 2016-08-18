<meta charset='utf-8'/>
<meta name="viewport" content="width=device-width, initial-scale=0.6">
<html>
	<head>
		<title>MAP - Syntax Pages - Plange</title>
		<link rel=StyleSheet href='../../css/general.css' type='text/css' />
	</head>
	<body>
		<?php require('../../header.php') ?>


		<p>create an associative Collection implementing Map<a → b></p>

		<div class="syntax">
			<p>syntax</p>
			<div>"{" [{IC} EXPRESSION {IC} ":" {IC} EXPRESSION {{IC} "," {IC} EXPRESSION {IC} ":" {IC} EXPRESSION}] {IC} "}"</div>
		</div>
		<div class="code">
			<p>Example</p>
			<pre>{ "first": "john", "last": "doe" }</pre>
		</div>		<p>The element type is constrained to some type that CASTS all the given elements.
		</p>
		<p>See:<a href="CASTS.php">CASTS</a>
		</p>



		<?php require('../../footer.php') ?>
	</body>
</html>