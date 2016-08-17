<meta charset='utf-8'/>
<meta name="viewport" content="width=device-width, initial-scale=0.6">
<html>
	<head>
		<title>map - Plange</title>
		<link rel=StyleSheet href='../../css/general.css' type='text/css' />
	</head>
	<body>
		<?php require('../../header.php') ?>


		<p>construct an object that implements <code>Map&lt;a → b&gt;</code></p>

		<div class="syntax">
			<p>syntax</p>
			<div>"{" expression ":" expression ("," expression ":" expression)* "}"</div>
		</div>

		<div class="code">
			<p>Example</p>
			<pre>{ "first": "john", "last": "doe" }</pre>
		</div>

		<h2>Notes</h2>

		<p>The element type is constrained to some type that <a href="../keywords/casts.php">casts</a> all the given elements.</p>


		<?php require('../../footer.php') ?>
	</body>
</html>