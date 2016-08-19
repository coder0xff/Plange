<meta charset='utf-8'/>
<meta name="viewport" content="width=device-width, initial-scale=0.6">
<html>
	<head>
		<title>TYPE - Syntax Pages - Plange</title>
		<link rel=StyleSheet href='../../css/general.css' type='text/css' />
	</head>
	<body>
		<?php require('../../header.php') ?>


		<p>create a type</p>

		<div class="syntax">
			<p>syntax</p>
			<div>"type" {<a href="/documentation/syntax/IC.php">IC</a>} ["inheriting" {<a href="/documentation/syntax/IC.php">IC</a>} <a href="/documentation/syntax/INHERITANCE_LIST.php">INHERITANCE_LIST</a> {<a href="/documentation/syntax/IC.php">IC</a>}] ["implementing" {<a href="/documentation/syntax/IC.php">IC</a>} <a href="/documentation/syntax/INHERITANCE_LIST.php">INHERITANCE_LIST</a> {<a href="/documentation/syntax/IC.php">IC</a>}] "{" <a href="/documentation/syntax/TYPE_SCOPE.php">TYPE_SCOPE</a> "}"</div>
		</div>
		<div class="code">
			<p>Example</p>
			<pre>bank_account := type inheriting account {
    &lt;float&gt; balance @ 0;
};</pre>
		</div>


		<?php require('../../footer.php') ?>
	</body>
</html>