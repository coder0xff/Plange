<meta charset='utf-8'/>
<meta name="viewport" content="width=device-width, initial-scale=0.6">
<html>
	<head>
		<title>ASSIGNMENT - Syntax Pages - Plange</title>
		<link rel=StyleSheet href='../../css/general.css' type='text/css' />
	</head>
	<body>
		<?php require('../../header.php') ?>


		<p>place the given value into the given variable</p>

		<div class="syntax">
			<p>syntax (associativity: right)</p>
			<div><a href="/documentation/syntax/EXPRESSION.php">EXPRESSION</a> {<a href="/documentation/syntax/IC.php">IC</a>} ("←"|"&lt;-") {<a href="/documentation/syntax/IC.php">IC</a>} {<a href="/documentation/syntax/EXPRESSION.php">EXPRESSION</a> {<a href="/documentation/syntax/IC.php">IC</a>} ("←"|"&lt;-") {<a href="/documentation/syntax/IC.php">IC</a>}} <a href="/documentation/syntax/EXPRESSION.php">EXPRESSION</a></div>
		</div>
		<div class="code">
			<p>Example</p>
			<pre>iPow2 ← -1;</pre>
		</div>		<h2>Notes</h2>
		<p>Note that the left hand side of assignments need not be trivial expressions mapping to a single memory structure - a so called lvalue in some other languages. Rather, arbitrary expressions can be solved when a single free variable is present. Revisiting the above example:</p>
<div class="code">
    <p>A variable</p>
    <pre><span style="color:red">iPow2</span> ← -1;</pre>
    <p>is assigned</p>
    <pre>iPow2 <span style="color:red">←</span> -1;</pre>
    <p>a value</p>
    <pre>iPow2 ← <span style="color:red">-1</span>;</pre>
</div>
<p>It is straightforward in that a single value is being put in a single variable, and both of them are clearly defined. However:</p>
<div class="code">
    <p>Example</p>
    <pre>x + 1 ← 0;</pre>
</div>
<p>The above example is contrived, but provides a simple segue to constraint based programming. When this statement is executed the value -1 is stored in <code>x</code>. Substituting -1 for x yields <code>(-1) + 1 = 0</code>.</p>

<p>Assignment operations can be chained together</p>
<div class="code">
    <p>Example</p>
    <pre>a ← b ← c;</pre>
</div>        



		<?php require('../../footer.php') ?>
	</body>
</html>