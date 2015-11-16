<meta charset='utf-8'/>
<html>
	<head>
		<title>box - Plange</title>
		<link rel=StyleSheet href='../../css/general.css' type='text/css' />
	</head>
	<body>
		<?php require('../../header.php') ?>


		<p>returns an object of type Value that models the specified expression</p>
		<h2>Notes</h2>
		<p>The box keyword should not be confused with the keyword of the same name in other languages, though some use cases may appear similar. In this case, the box keyword returns an object with properties and methods for interacting with a values representation rather than its interpretation. More specifically, the representation is either concrete or algebraic.</p>

		<div class="code">
			<p>Example</p>
			<pre>x &lt;- 5 + 2; //x is 7
x &lt;- box(7); //x is a concrete Value with a binary representation
x &lt;- box(5 + 2); //x is an algebraic Value</pre>
		</div>
		<p>Concrete values have a single binary representation</p>


		<?php require('../../footer.php') ?>
	</body>
</html>