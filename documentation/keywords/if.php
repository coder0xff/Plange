<meta charset='utf-8'/>
<meta name="viewport" content="width=device-width, initial-scale=0.6">
<html>
	<head>
		<title>if - Plange</title>
		<link rel=StyleSheet href='../../css/general.css' type='text/css' />
	</head>
	<body>
		<?php require('../../header.php') ?>


		<p>The if keyword is used create branches in the flow of the program.</p>

		<div class="code2">
			<p>Example</p>
			<pre>
if (input("What is 1 + 1 ? ") = "2") {
	print("You are correct!");
} else {
	print("Sorry, you are incorrect.");
}
			</pre>
		</div>

		<p>The user is prompted to enter a number. If they answer correctly, the code between the first set of braces { } is executed. Otherwise, the statements in the second set of braces is. Clauses can be chained together.</p>

		<div class="code2">
			<p>Example</p>
			<pre>
choice := | coerce(input("Chose a number: ")) |;
if (choice < 100) {
	print("That's a nice number.");
} elif (choice < 10000) {
	print("Great.");
} elif (choice < 1000000000) {
	print("Huge!");
} else {
	print("Let's not get carried away. o_O")
}
			</pre>
		</div>

		<p>The simplest if statement; one without any elif or else clause</p>

		<div class="code2">
			<p>Example</p>
			<pre>
buffer ← input();
if (buffer != "") {
	print(buffer); //echo the input back
}
			</pre>
		</div>

    	<p>Looking carefully at the <a href="/documentation/syntax.php?name=IF">syntax of if</a>, see that the use of expressions does not require that { } are used. Interestingly, things like this are possible:</p>

    	<div class="code2">
    		<p>Pseudocode</p>
    		<pre>
resultString := if (success) "All is well." else "Something went wrong.";
			</pre>
    	</div>

    	<p>Further, the void-function evaluation of the earlier examples is not implied by the if. It's only implied by being in a statement_scope. Another example is in order:</p>

    	<div class="code2">
    		<p>Pseudocode</p>
    		<pre>
myFunction := if (!override) { print(5 + 5); } else { print("ABC"); };
print(type_of(myFunction)); //prints "Void → Void"
			</pre>
		</div>

		<p>Note that the above program does <b>not</b> print "10" or "ABC", because evaluation of the statements inside curly braces does not occur until:</p>

		<div class="code2">
			<p>Pseudocode (continued)</p>
			<pre>
<span style="color: #CCC;">myFunction := if (!override) { print(5 + 5); } else { print("ABC"); };
print(type_of(myFunction)); //prints "Void → Void"</span>
myFunction;
			</pre>
		</div>

		<p>This provides a nice segue into a discussion on <a href="/documentation/syntax.php?name=STATEMENT_SCOPE">statement_scope (syntax)</a>, specifically that if a program statement is an expression that evaluates to a Void → Void function then that function is invoked as a step in evaluating the statement.</p>
		</div>


		<?php require('../../footer.php') ?>
	</body>
</html>