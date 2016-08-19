<meta charset='utf-8'/>
<meta name="viewport" content="width=device-width, initial-scale=0.6">
<html>
	<head>
		<title>EMBEDDED_COMMENT - Syntax Pages - Plange</title>
		<link rel=StyleSheet href='../../css/general.css' type='text/css' />
	</head>
	<body>
		<?php require('../../header.php') ?>


		<p>a comment bounded by arbirtrarily-sized delimiters</p>

		<div class="syntax">
			<p>syntax</p>
			<div>"/***" <a href="/documentation/syntax/EMBEDDED_COMMENT_INTERIOR.php">EMBEDDED_COMMENT_INTERIOR</a> "***/"</div>
		</div>
		<div class="code">
			<p>Example</p>
			<pre>/**** this is an embedded_comment
***/ the characters at the start of this line have no affect on this ongoing comment
Embed blocks of code that themselves contain block comments:
    /* Do the thing */
    thing();
No problem. Now, lets end this comment. ****/</pre>
		</div>		<h2>Notes</h2>
				<p>This allows for commented code to be safely commented out completely by including a sufficient number of asterisks to serve as an opening and closing delimiter.
		</p>



		<?php require('../../footer.php') ?>
	</body>
</html>