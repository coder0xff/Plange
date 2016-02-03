<meta charset='utf-8'/>
<html>
	<head>
		<title>type - Plange</title>
		<link rel=StyleSheet href='../../css/general.css' type='text/css' />
	</head>
	<body>
		<?php require('../../header.php') ?>


        <p>create a new <a href="../standard-library/Type.php">Type</a></p>
        <div class="code">
            <p>Syntax</p>
            <pre>"type" "{" <a href="type_scope.php">type_scope</a> "}"</pre>
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