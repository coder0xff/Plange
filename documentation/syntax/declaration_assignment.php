<meta charset='utf-8'/>
<meta name="viewport" content="width=device-width, initial-scale=0.6">
<html>
	<head>
		<title>declaration_assignment - Plange</title>
		<link rel=StyleSheet href='../../css/general.css' type='text/css' />
	</head>
	<body>
		<?php require('../../header.php') ?>


		<p>a statement combining a variable declaration and an assignment</p>
		<div class="syntax">
			<p>syntax</p>
			<div>[ <a href="/documentation/syntax/type_dereference.php">type_dereference</a> | <a href="/documentation/syntax/implicit_type_dereference.php">implicit_type_dereference</a> ] <a href="/documentation/syntax/identifier.php">identifier</a> "&lt;-" <a href="/documentation/syntax/expression.php">expression</a></div>
		</div>
		<div class="code">
			<p>Example</p>
			<pre>&lt;Number&gt; x &lt;- 100;</pre>
		</div>
		<div class="code">
			<p>Example</p>
			<pre>&lt;&gt; name &lt;- "Alice"; //implicitly type String</pre>
		</div>
		<div class="code">
			<p>Example</p>
			<pre>object &lt;- { "employees":[
	("John", "Doe"),
	("Anna", "Smith"),
	("Peter", Jones")
]}; //type Any (duck typed)

object &lt;- (x) { return x*2; }; //type Any</pre>
		</div>


		<?php require('../../footer.php') ?>
	</body>
</html>