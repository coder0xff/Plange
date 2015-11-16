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
    &lt;Runtime.StackDump&gt; stack;
    &lt;Void -&gt; Void&gt; continue;
    &lt;Bool&gt; isReentrant;
};</pre>
        </div>
    

		<?php require('../../footer.php') ?>
	</body>
</html>