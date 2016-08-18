<meta charset='utf-8'/>
<meta name="viewport" content="width=device-width, initial-scale=0.6">
<html>
	<head>
		<title>INVOCATION - Syntax Pages - Plange</title>
		<link rel=StyleSheet href='../../css/general.css' type='text/css' />
	</head>
	<body>
		<?php require('../../header.php') ?>


		<p>invoke a function, type-function or array-function</p>

		<div class="syntax">
			<p>syntax</p>
			<pre>PARENTHETICAL_INVOCATION | ARRAY_INVOCATION | TYPE_INVOCATION</pre>
		</div>
		<div class="code">
			<p>Example</p>
			<pre>myMethod(1, x^2, "hello\n", someThing)</pre>
		</div>		<div class="code">
			<p>Example</p>
			<pre>IntList := List&lt;int&gt;; //List is a type function, IntList is a Type</pre>
		</div>		<div class="code">
			<p>Example</p>
			<pre>print myArray[4]; //4 is ordered and denumerable, myArray implements RandomlyAccessible</pre>
		</div>		<p>The &lt; &gt; syntactic variety requires the returned value to be a type (it must implement Type), or a function (it must implement Function) that when invoked results in such a type or function. Note that this definition is deliberately recursive. The [ ] syntactic variety requires that each given "indexer" is some element of an ordered set, such as the natural numbers or enum values, and that the invokee is randomly accessible (implements RandomlyAccessible). Lastly, the angle bracket and square bracket syntax are optional; the behavior is identical to being invoked using parentheses. However, alternate syntax is encouraged whenever such requirements are met and helps to both document and enforce the invariants assumed by the author.
		</p>



		<?php require('../../footer.php') ?>
	</body>
</html>