<meta charset='utf-8'/>
<meta name="viewport" content="width=device-width, initial-scale=0.6">
<html>
	<head>
		<title>Value - Plange</title>
		<link rel=StyleSheet href='../../css/general.css' type='text/css' />
	</head>
	<body>
		<?php require('../../header.php') ?>



        <p>a non-polymorphic abstraction for manipulating values as first class object</p>
    
        <div class="code2">
            <p>Outline</p>
            <pre>
Value := type {
    &lt;List&lt;Relation&gt;&gt; typeConstraints;
    &lt;Maybe&lt;Type*&gt;&gt; T;
    &lt;List&lt;Relation&gt;&gt; constraints;
    &lt;Maybe&lt;Pointer&lt;Any&gt;&gt;&gt; value;
}
            </pre>
        </div>
    
        <p>See: <a href="../keywords/box.php">box (keyword)</a></p>


		<?php require('../../footer.php') ?>
	</body>
</html>