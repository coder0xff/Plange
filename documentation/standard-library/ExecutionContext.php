<meta charset='utf-8'/>
<html>
	<head>
		<title>ExecutionContext - Plange</title>
		<link rel=StyleSheet href='../../css/general.css' type='text/css' />
	</head>
	<body>
		<?php require('../../header.php') ?>


        <div class="code">
            <p>Outline</p>
            <pre>ExecutionContext := type {
    &lt;Scope&gt; scope;
    &lt;Threading.Thread&gt; creatingThread;
    &lt;Runtime.StackTrace&gt; stack;
    &lt;Runtime.FunctionModel&gt; model;
    &lt;Void → Void&gt; continue; //cooperative multithreading entrypoint
    &lt;Bool&gt; isReentrant; //this execution context may be the target of a long jump
    &lt;List&lt;Constant&gt;&gt; constants;
    &lt;List&lt;Statements&gt;&gt; statements;
};</pre>
        </div>
    

		<?php require('../../footer.php') ?>
	</body>
</html>