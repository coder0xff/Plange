<meta charset='utf-8'/>
<meta name="viewport" content="width=device-width, initial-scale=0.6">
<html>
	<head>
		<title>DEFINITION - Syntax Pages - Plange</title>
		<link rel=StyleSheet href='../../css/general.css' type='text/css' />
	</head>
	<body>
		<?php require('../../header.php') ?>


		<p>define a constant, an alias for the valuation of a specified expression</p>

		<div class="syntax">
			<p>syntax</p>
			<div>[<a href="/documentation/syntax/XML_DOC_STRING.php">XML_DOC_STRING</a> {<a href="/documentation/syntax/IC.php">IC</a>}] [ (<a href="/documentation/syntax/TYPE_DEREFERENCE.php">TYPE_DEREFERENCE</a> | <a href="/documentation/syntax/IMPLICIT_TYPE_DEREFERENCE.php">IMPLICIT_TYPE_DEREFERENCE</a>) {<a href="/documentation/syntax/IC.php">IC</a>} ] <a href="/documentation/syntax/DEFINITION_PART.php">DEFINITION_PART</a> {{<a href="/documentation/syntax/IC.php">IC</a>} "," {<a href="/documentation/syntax/IC.php">IC</a>} <a href="/documentation/syntax/DEFINITION_PART.php">DEFINITION_PART</a>}</div>
		</div>
		<div class="code">
			<p>Example</p>
			<pre>&lt;Double&gt; almostPi := 355/113;</pre>
		</div>


		<?php require('../../footer.php') ?>
	</body>
</html>