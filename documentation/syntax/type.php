<meta charset='utf-8'/>
<meta name="viewport" content="width=device-width, initial-scale=0.6">
<html>
	<head>
		<title>type - Plange</title>
		<link rel=StyleSheet href='../../css/general.css' type='text/css' />
	</head>
	<body>
		<?php require('../../header.php') ?>


        <p>create a new <a href="../standard-library/Type.php">Type</a></p>
		<div class="syntax">
			<p>syntax</p>
			<div>"type" "{" <a href="type_scope.php">type_scope</a> "}"</div>
        </div>
        <div class="code">
            <p>Example</p>
            <pre>bank_account := type inheriting account {
    &lt;float&gt; balance at 0;
};</pre>
        </div>


		<?php require('../../footer.php') ?>
	</body>
</html>