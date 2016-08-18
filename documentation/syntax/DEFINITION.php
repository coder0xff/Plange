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
			<div>[XML_DOC_STRING {IC}] [ (TYPE_DEREFERENCE | IMPLICIT_TYPE_DEREFERENCE) {IC} ] DEFINITION_PART {{IC} "," {IC} DEFINITION_PART}</div>
		</div>
		<div class="code">
			<p>Example</p>
			<pre>&lt;Double&gt; almostPi := 355/113;</pre>
		</div>


		<?php require('../../footer.php') ?>
	</body>
</html>