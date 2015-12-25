<meta charset='utf-8'/>
<html>
	<head>
		<title>embedded_string - Plange</title>
		<link rel=StyleSheet href='../../css/general.css' type='text/css' />
	</head>
	<body>
		<?php require('../../header.php') ?>


		<p>uses unbounded delimiters for embedding arbitrary data as a string</p>
		<div class="code">
			<p>syntax</p>
			<pre>("\"\"\"\n" any_character* "\n\"\"\"") | ("\"" embedded_string "\"")</pre>
		</div>
		<h2>Notes</h2>
		<p>An embedded_string is similar to a regular string literal of the form:</p>
		<div class="code">
			<p>Typical string literal</p>
			<pre>"hello world"</pre>
		</div>
		<p>except that it permits the text to contain any finite number of double quotes. An embedded_string begins with three or more double quotes followed by a new line character, and ends with a new line character followed by the same number of double quotes. All white spaces, characters, and other bytes between the opening and closing delimiter becomes a string literal.</p>
		<div class="code">
			<p>Example</p>
			<pre>stringWithDoubleQuotes := """""
The remainder of this is a string literal, excluding the five quotes at the very end.
We can use four double quotes, like """", but not 5 which is the number of quotes that
start this string literal. If a string literal with 100 consecutive double quotes in it
were desired, we would then use 101 double quotes to start and end the string literal.
"""""</pre>
		</div>

		<p>This syntactic element requires context sensitive processing, in a similar fashion to how operator fixity and precedence works.</p>
		<p>See: <a href="/documentation/quote-comment-embedding.php">Quote Embedding, Comment Embedding</a></p>


		<?php require('../../footer.php') ?>
	</body>
</html>