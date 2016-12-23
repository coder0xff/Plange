<meta charset='utf-8'/>
<meta name="viewport" content="width=device-width, initial-scale=0.6">
<html>
	<head>
		<title>Quote & Comment Embedding - Plange</title>
		<link rel=StyleSheet href='../css/general.css' type='text/css' />
	</head>
	<body>
		<?php require('../header.php') ?>


		<p>String embedding and comment embedding leverage recursive and context sensitive grammar features to make the embedding of raw data into code more convenient.</p>
		
		<h2>String Embedding</h2>
		<p>To address the problem of embedding unformatted and unescaped strings into code, string embedding defines 2 delimiter classes. A string literal is placed between matching delimiters:</p>

		<div class="code2">
  			<p>Example/p>
			<pre>
text := """
This is a string literal.
We can use any characters in this literal aside from a sequence of three quotes.
One or two quotes (like "") is fine though.
""";
			</pre>
		</div>

		<p>Embedding is used to lexographically isolate any string literal, regardless of how many double quote characters it has, while avoiding escape sequences.</p>

		<div class="code2">
			<p>Example</p>
			<pre>
stringWithDoubleQuotes := """""
The remainder of this is a string literal, excluding the 5 double quotes at the very end.
We can use four double quotes, like """", but not 5 which is the number of quotes that
start this string literal. If a string literal with 100 consecutive double quotes in it
were desired, we would then use 101 double quotes to start and end the string literal.
""""";
			</pre>
		</div>

		<p>The opening delimiter must end with a single newline character, and the closing delimiter must start with one. However, any additional new lines (or any byte for that matter) will be part of the string literal.</p>

		<h2>Comment Embedding</h2>
		<p>A very similar feature exists for comments.</p>

		<div class="code2">  
			<p>Example</p>
			<pre>
/**** this is an embedded_comment
***/ the characters at the start of this line have no affect on this ongoing comment
Embed blocks of code that themselves contain block comments:
void main() { /* Do the thing */ thing(); }
No problem. Now, lets end this comment. ****/
			</pre>
		</div>



		<?php require('../footer.php') ?>
	</body>
</html>