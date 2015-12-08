<meta charset='utf-8'/>
<html>
	<head>
		<title>if - Plange</title>
		<link rel=StyleSheet href='../../css/general.css' type='text/css' />
	</head>
	<body>
		<?php require('../../header.php') ?>


		<p>The if keyword is used create branches in the flow of the program.</p>

		<div class="code">
			<p>Example</p>
			<pre>if (input("What is 1 + 1 ? ") = "2") {
	print("You are correct!");
} else {
	print("Sorry, you are incorrect.");
}</pre>
		</div>

		<p>The user is prompted to enter a number. If they answer, the first branch is executed printing "correct". Otherwise, "incorrect" is printed. If clauses can be chained together.</p>

		<div class="code">
			<p>Example</p>
			<pre>choice := |input("Chose a number: ")|;
if (choice < 100) {
	print("That's a nice number.");
} elif (choice < 10000) {
	print("Great.");
} elif (choice < 1000000000) {
	print("Huge!");
} else {
	print("Let's not get carried away. o_O")
}</pre>
		</div>

		<p>The simplest if statement; one without any elif or else clause</p>

		<div class="code">
			<p>Example</p>
			<pre>buffer ← input();
if (buffer != "") {
	print(buffer); //echo the input back
}</pre>
		</div>

    	<p>Looking carefully at the <a href="/documentation/syntax/if.php">syntax of if</a>, see that the use of expressions does not require that { } are used. Interestingly, things like this are possible:</p>

    	<div class="code">
    		<p>Pseudocode</p>
    		<pre>resultString := if (success) "All is well." else "Something went wrong.";</pre>
    	</div>

    	<p>Further, the void-function evaluation of the earlier examples is not implied by the if. It's only implied by being in a statement_scope. That may be a bit confusing, so here is an example.</p>

    	<div class="code">
    		<p>Pseudocode</p>
    		<pre>myFunction := if (!override) { print(5 + 5); } else { print("ABC"); };
print(type_of(myFunction)); //prints "Void → Void"</pre>
		</div>

		<p>Note that the above program does not print ten or "ABC", because evaluation of the statements inside curly braces does not execute until:</p>

		<div class="code">
			<p>Pseudocode (continued)</p>
			<pre><span style="color: #CCC;">myFunction := if (!override) { print(5 + 5); } else { print("ABC"); };
print(type_of(myFunction)); //prints "Void → Void"</span>
print(myFunction());</pre>
		</div>

		<p>For more details on these evaluation rules see <a href="/documentation/syntax/statement_scope.php">statement_scope (syntax)</a>.
		</div>


		<?php require('../../footer.php') ?>
	</body>
</html>