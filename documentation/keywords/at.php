<meta charset='utf-8'/>
<html>
	<head>
		<title>at - Plange</title>
		<link rel=StyleSheet href='../../css/general.css' type='text/css' />
	</head>
	<body>
		<?php require('../../header.php') ?>


		<p>when used in <a href="../syntax/type_scope.php">type_scope</a>
		syntax, specifies the offset of a field</p>
		<div class="code">
			<p>Example</p>
			<pre>FloatOrInt := type {
	&lt;Float32&gt; single at 0; //a union of Float32 and Int32
	&lt;Int32&gt; int32 at 0;
}</pre>
		</div>


		<?php require('../../footer.php') ?>
	</body>
</html>