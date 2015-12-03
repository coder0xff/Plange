<meta charset='utf-8'/>
<html>
	<head>
		<title>embedded_string - Plange</title>
		<link rel=StyleSheet href='../../css/general.css' type='text/css' />
	</head>
	<body>
		<?php require('../../header.php') ?>


		<p>an unbounded delimiter for embedding arbitrary data as a string</p>
		<div class="code">
			<p>syntax</p>
			<pre>("\"\"\"" any_character* "\"\"\"") | ("\"\"\"\n" any_character* "\n\"\"\"") | ("\"" embedded_string "\"")</pre>
		</div>
		<h2>Notes</h2>
		<p>An embedded_string is similar to a regular string literal of the form:</p>
		<div class="code">
			<p>Typical string literal</p>
			<pre>"hello world"</pre>
		</div>
		<p>except that it permits the text to contain any finite number of double quotes. An embedded_string begins with three or more double quotes, and ends with the same number of double quotes. All white spaces, characters, and other bytes between the opening and closing delimiter becomes a string value when accessed in Plange.</p>
		<div class="code">
			<p>Example</p>
			<pre>stringWithDoubleQuotes := """""
The remainder of this is a string literal, excluding the five quotes at the very end.
We can use four double quotes, like """", but not 5 which is the number of quotes that
start this string literal. If a string literal with 100 consecutive double quotes in it
were desired, we would then use 101 double quotes to start and end the string literal.
"""""</pre>
		</div>
		<p>Note that the syntax indicates that two newline characters may optionally be consumed as part of the delimiters, as in the example above (there's no text after the openning line's quotes, and no text before the closing line's quotes). If embedding some unknown data (which may or may not contain leading and/or trailing new line characters) then the newline characters are non-optional as to avoid ambiguity. That is, only use the version lacking the new line characters if it's manually entered text:</p>

		<div class="code">
			<p>Example</p>
			<pre>myString := """My favorite Poe is "The Fall of the House of Usher."""";
		</div>

		<p>This syntactic element requires context sensitive processing, in a similar fashion to how operator fixity and precedence works. The example above may appear ambiguous at first glance (due to the 4 quotes at the end) but only one interpretation leads to a valid top-level statement. Situations where ambiguity might arise rely on the newline characters within the delimiter to clarify the meaning. This is why newline characters should always be used when the contents of the embedded string is not know ahead of time.
		See:
		<p><a href="../quote-comment-embedding.php">Quote Embedding, Comment Embedding</a></p>


		<?php require('../../footer.php') ?>
	</body>
</html>