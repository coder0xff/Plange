<meta charset='utf-8'/>
<html>
	<head>
		<title>Scope - Plange</title>
		<link rel=StyleSheet href='../../css/general.css' type='text/css' />
	</head>
	<body>
		<?php require('../../header.php') ?>


		<div class="code">
			<p>Outline</p>
			<pre>Scope := type {
	&lt;Array&lt;Relation&gt;&gt; relations;
	&lt;Array&lt;Variable&gt;&gt; variables;
	&lt;Array&lt;Statement&gt;&gt; statements;
	&lt;Array&lt;Parameter&gt;&gt; parameters;
	&lt;ExecutionContext&gt; instantiator;
	&lt;SideEffectCollection&gt; sideEffects;
	&lt;SourceCode&gt; sourceCode;
	&lt;Bool&gt; isPure;
	&lt;Bool&gt; isAtomic;
};</pre>
		</div>


		<?php require('../../footer.php') ?>
	</body>
</html>