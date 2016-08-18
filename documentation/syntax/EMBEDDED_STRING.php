<meta charset='utf-8'/>
<meta name="viewport" content="width=device-width, initial-scale=0.6">
<html>
	<head>
		<title>EMBEDDED_STRING - Syntax Pages - Plange</title>
		<link rel=StyleSheet href='../../css/general.css' type='text/css' />
	</head>
	<body>
		<?php require('../../header.php') ?>


		<p>a string bounded by arbirtrarily-sized delimiters</p>

		<div class="syntax">
			<p>syntax</p>
			<div>("\"\"\"\n" {all} "\n\"\"\"") | ("\"\"\"" not_double_quote {all} "\"\"\"") | ("\"" <a href="/documentation/syntax/EMBEDDED_STRING.php">EMBEDDED_STRING</a> "\"")</div>
		</div>
		<div class="code">
			<p>Example</p>
			<pre>stringWithDoubleQuotes := """""
The remainder of this is a string literal, excluding the five quotes at the very end.
We can use four double quotes, like """", but not 5 which is the number of quotes that
start this string literal. If a string literal with 100 consecutive double quotes in it
were desired, we would then use 101 double quotes to start and end the string literal.
"""""</pre>
		</div>		<h2>Notes</h2>
		<p>An embedded_string is similar to a regular string literal of the form:</p>
<div class="code">
    <p>Typical string literal</p>
    <pre>"hello world"</pre>
</div>
<p>except that it permits the text to contain any finite number of double quotes. An embedded_string begins with three or more double quotes followed by a new line character, and ends with a new line character followed by the same number of double quotes. All white spaces, characters, and other bytes between the opening and closing delimiter becomes a string literal.</p>



		<?php require('../../footer.php') ?>
	</body>
</html>