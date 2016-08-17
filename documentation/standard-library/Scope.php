<meta charset='utf-8'/>
<meta name="viewport" content="width=device-width, initial-scale=0.6">
<html>
	<head>
		<title>Scope - Plange</title>
		<link rel=StyleSheet href='../../css/general.css' type='text/css' />
	</head>
	<body>
		<?php require('../../header.php') ?>


		<p>provides an abstraction for code scopes, which are delimited by curly braces { }</p>
		
		<div class="code">
			<p>Outline</p>
			<pre>Scope := type {
	&lt;Maybe&lt;Scope&gt;&gt; parent;
	&lt;Array&lt;Scope&gt;&gt; children;
	&lt;SourceCode&gt; sourceCode;
	&lt;Array&lt;Constant&gt;&gt; constants;
	&lt;Array&lt;Assertion&gt;&gt; assertions;
	&lt;Array&lt;Statement&gt;&gt; statements;
	&lt;Array&lt;Variable&gt;&gt; variables; //includes captures
	&lt;ExecutionContext&gt; instantiator;
	&lt;Bool&gt; isPure;
	&lt;Bool&gt; isAtomic;
	&lt;Bool&gt; isReentrant; //this scope may be the target of a long jump
	&lt;FunctionModel&gt; model;
	&lt;SideEffectSet&gt; sideEffects;
	&lt;Scope → Bool&gt; is_descendent_of;
	&lt;&lt;Void → Void&gt; → Bool&gt; can_execute; //based on symbol binding
};</pre>
		</div>


		<?php require('../../footer.php') ?>
	</body>
</html>