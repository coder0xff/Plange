<meta charset='utf-8'/>
<html>
	<head>
		<title>function - Plange</title>
		<link rel=StyleSheet href='../../css/general.css' type='text/css' />
	</head>
	<body>
		<?php require('../../header.php') ?>


		<p>creates a function</p>
		<div class="syntax">
			<p>syntax</p>
			<div>[ "(" [ <a href="/documentation/syntax/parameter.php">parameter</a> ("," <a href="/documentation/syntax/parameter.php">parameter</a> )* ] ")" ] ["stable"|"unstable"] ["no_throw"] ["atomic"] ["pure"|"imperative"|"opaque"] "{" <a href="/documentation/syntax/statement_scope.php">statement_scope</a> "}"</div>
		</div>
		<div class="code">
			<p>Example</p>
			<pre>(a, b) pure { return a * b; }</pre>
		</div>
		<div class="code">
			<p>Example</p>
			<pre>&lt;int → int&gt; factorial := (x) { return x == 0 ? 1 : x * factorial(x - 1); };</pre>
		</div>
		<div class="code">
			<p>Example</p>
			<pre>&lt;Collection&lt;T&gt; → T&gt; head := (a:b) { return a; }</pre>
		</div>
		<h2>Notes</h2>
		<p>Function objects are invoked using the <a href="/documentation/syntax/invocation.php">invocation</a> syntax.</p>
		<p>The <a href="/documentation/keywords/atomic.php">atomic</a>, <a href="/documentation/keywords/pure.php">pure</a>, <a href="/documentation/keywords/imperative.php">imperative</a> , and <a href="/documentation/keywords/opaque.php">opaque</a>
		keywords influence assumptions that the compiler may make regarding a functions implementation. The pure keyword indicates that the implementation uses only pull semantics, is idempotent, and has no side effects. Additionally, only constants can be read, which includes value (not by reference/pointer values) passed as formal parameters. Any violation of these constraints causes an error to occur. The imperative keyword indicates that the implementation is likely not tractable, and it may interact with memory or hardware in unknown ways. Without either pure or imperative, the implementation is assumed to be push-pull and tractable. If the tool chain determines that this is not the case, it will fall back to imperative behavior. Pure functions are implicitly atomic.</p>


		<?php require('../../footer.php') ?>
	</body>
</html>