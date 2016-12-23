<meta charset='utf-8'/>
<meta name="viewport" content="width=device-width, initial-scale=0.6">
<html>
	<head>
		<title>Function - Plange</title>
		<link rel=StyleSheet href='../../css/general.css' type='text/css' />
	</head>
	<body>
		<?php require('../../header.php') ?>


        <div class="code2">
            <p>Outline</p>
            <pre>
&lt;Type^n * ReturnType → Type&gt TypedFunction :=  {
    return type inheriting GenericFunction {
        &lt;Type&gt; returnType := params[params.length - 1];
        &lt;Array&lt;Parameter&gt;&gt; parameters := { Parameter&lt;T&gt; where (_, T) ∈ params };
    };
};

GenericFunction := type inheriting <a href="/documentation/standard-library/Scope.php">Scope</a> {
    &lt;Type&gt; returnType;
    &lt;Array&lt;Parameter&gt;&gt; parameters;
    &lt;String&gt; name;
}

Function := TypedFunction + GenericFunction;
            </pre>
        </div>


		<?php require('../../footer.php') ?>
	</body>
</html>