<meta charset='utf-8'/>
<html>
	<head>
		<title>map - Plange</title>
		<link rel=StyleSheet href='../../css/general.css' type='text/css' />
	</head>
	<body>
		<?php require('../../header.php') ?>


		<p>construct an object that implements <code>Map&lt;a → b&gt;</code></p>

		<div class="code">
			<p>Syntax</p>
			<pre>"{" expression ":" expression ("," expression ":" expression)* "}"</pre>
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