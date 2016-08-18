<meta charset='utf-8'/>
<meta name="viewport" content="width=device-width, initial-scale=0.6">
<html>
	<head>
		<title>IF - Syntax Pages - Plange</title>
		<link rel=StyleSheet href='../../css/general.css' type='text/css' />
	</head>
	<body>
		<?php require('../../header.php') ?>


		<p>returns the expression corresponding to the first parenthetical that evaluates to true when coerced to a boolean, or the else case if none of them evaluate to true, assuming that the else case is present, otherwise returning void</p>

		<div class="syntax">
			<p>syntax</p>
			<div>"if" {IC} PARENTHETICAL {IC} EXPRESSION {{IC} "elif" {IC} PARENTHETICAL {IC} EXPRESSION} [ {IC} "else" {IC} EXPRESSION ]</div>
		</div>
		<div class="code">
			<p>Example</p>
			<pre>if (input("What is 1 + 1 ? ") = "2") {
    print("You are correct!");
} else {
    print("Sorry, you are incorrect.");
}</pre>
		</div>


		<?php require('../../footer.php') ?>
	</body>
</html>