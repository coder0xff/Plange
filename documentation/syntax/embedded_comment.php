<meta charset='utf-8'/>
<html>
	<head>
		<title>embedded_comment - Plange</title>
		<link rel=StyleSheet href='../../css/general.css' type='text/css' />
	</head>
	<body>
		<?php require('../../header.php') ?>


		<div class="code">
			<p>Syntax (full Wirth Syntax Notation)</p>
			<pre>embedded_comment_interior:= newline payload newline | "*" embedded_comment_interior "*" embedded_comment:= newline "/*" embedded_comment_interior "*/" newline</pre>
		</div>
		<h2>Notes</h2>
		<p>This allows for commented code to be safely commented out completely by including a sufficient number of asterisks to serve as an opening and closing delimiter.</p>

		<div class="code">
			<p>Example</p>
			<pre>/**** this is an embedded_comment
***/ the characters at the start of this line have no affect on this ongoing comment
Embed blocks of code that themselves contain block comments:
	/* Do the thing */
	thing();
No problem. Now, lets end this comment. ****/</pre>
		</div>


		<?php require('../../footer.php') ?>
	</body>
</html>