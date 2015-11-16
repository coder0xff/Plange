<meta charset='utf-8'/>
<html>
	<head>
		<title>assignment - Plange</title>
		<link rel=StyleSheet href='../../css/general.css' type='text/css' />
	</head>
	<body>
		<?php require('../../header.php') ?>


		<div class="code">
			<p>Syntax</p>
			<pre><a href="expression.php">expression</a> ("←"|"&lt;-") <a href="expression.php">expression</a></pre>
		</div>
		<div class="code">
			<p>Example</p>
			<pre>iPow2 &lt;- -1;</pre>
		</div>
		<h2>Notes</h2>
		<p>Note that the left hand side of assignments need not be trivial expressions mapping to a single memory structure - a so called lvalue in other circles. Rather, arbitrary expressions can be solved when a single free variable is present. Revisiting the above example:</p>
		<div class="code">
			<p>Example</p>
			<pre>   iPow2 &lt;- -1;
	// *****         - a single variable
	//       **      - is assigned
	//          **   - a single value</pre>
		</div>
		<p>It is straightforward in that a single value is being put in a single variable, and both of them are clearly defined. However:</p>
		<div class="code">
			<p>Example</p>
			<pre>x + 1 &lt;- 0;</pre>
		</div>
		<p>The above example is contrived, but provides a simple segue to constraint based programming. When this statement is executed the value -1 is stored in <code>x</code>. Substituting -1 for x yields <code>(-1) + 1 = 0</code>.</p>


		<?php require('../../footer.php') ?>
	</body>
</html>