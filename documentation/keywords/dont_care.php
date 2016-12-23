<meta charset='utf-8'/>
<meta name="viewport" content="width=device-width, initial-scale=0.6">
<html>
	<head>
		<title>_ (dont_care) - Plange</title>
		<link rel=StyleSheet href='../../css/general.css' type='text/css' />
	</head>
	<body>
		<?php require('../../header.php') ?>


		<p>a place holder for an identifier, when the name of that identifier is irrelevant</p>
		<div class="code">
			<p>Example</p>
			<pre>(_, y) := myVector; //extract the y coordinate of a vector, ignoring the x coordinate</pre>
		</div>
		<h2>Notes</h2>
		<p>This keyword has important properties that separates it from <a href="/documentation/syntax/IDENTIFIER.php">identifiers</a>.</p>
		<ul>
			<li>It is not possible to retrieve a value from <code>_</code>.</li>
			<li>Any constraints placed on <code>_</code> are discarded.</li>
		</ul>


		<?php require('../../footer.php') ?>
	</body>
</html>