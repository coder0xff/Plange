<meta charset='utf-8'/>
<meta name="viewport" content="width=device-width, initial-scale=0.6">
<html>
	<head>
		<title>FOR_COLLECTION - Syntax Pages - Plange</title>
		<link rel=StyleSheet href='../../css/general.css' type='text/css' />
	</head>
	<body>
		<?php require('../../header.php') ?>


		<p>evaluate the last expression repeatedly while iterating over the elements of the specified Collection</p>

		<div class="syntax">
			<p>syntax</p>
			<div>"for" {<a href="/documentation/syntax/IC.php">IC</a>} "(" {<a href="/documentation/syntax/IC.php">IC</a>} (%declaration([ (<a href="/documentation/syntax/TYPE_DEREFERENCE.php">TYPE_DEREFERENCE</a> | <a href="/documentation/syntax/IMPLICIT_TYPE_DEREFERENCE.php">IMPLICIT_TYPE_DEREFERENCE</a>) {<a href="/documentation/syntax/IC.php">IC</a>} ] <a href="/documentation/syntax/IDENTIFIER.php">IDENTIFIER</a> ) | $<a href="/documentation/syntax/EXPRESSION.php">EXPRESSION</a> ) {<a href="/documentation/syntax/IC.php">IC</a>} ("in"|"∈") {<a href="/documentation/syntax/IC.php">IC</a>} %collection(<a href="/documentation/syntax/EXPRESSION.php">EXPRESSION</a>) {<a href="/documentation/syntax/IC.php">IC</a>} ")" {<a href="/documentation/syntax/IC.php">IC</a>} %invoke(<a href="/documentation/syntax/EXPRESSION.php">EXPRESSION</a>)</div>
		</div>
		<div class="code2">
			<p>Example</p>
			<pre>
&lt;&gt; fibArray = [ 0, 1, 1, 2, 3, 5, 8, 13 ];
for (element ∈ fibArray) {
    print(element);
}
</pre>
		</div>		<div class="code2">
			<p>Example</p>
			<pre>
for ((key, value) ∈ myMap) {
    //do something
}
</pre>
		</div>


		<?php require('../../footer.php') ?>
	</body>
</html>