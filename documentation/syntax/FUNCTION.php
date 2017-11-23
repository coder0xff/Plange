<meta charset='utf-8'/>
<meta name="viewport" content="width=device-width, initial-scale=0.6">
<html>
	<head>
		<title>FUNCTION - Syntax Pages - Plange</title>
		<link rel=StyleSheet href='../../css/general.css' type='text/css' />
	</head>
	<body>
		<?php require('../../header.php') ?>


		<p>creates a function</p>

		<div class="syntax">
			<p>syntax</p>
			<div>[ "(" {<a href="/documentation/syntax/IC.php">IC</a>} [ $<a href="/documentation/syntax/PARAMETER.php">PARAMETER</a> {{<a href="/documentation/syntax/IC.php">IC</a>} "," {<a href="/documentation/syntax/IC.php">IC</a>} $<a href="/documentation/syntax/PARAMETER.php">PARAMETER</a>} {<a href="/documentation/syntax/IC.php">IC</a>} ] ")" {<a href="/documentation/syntax/IC.php">IC</a>} ] [<a href="/documentation/syntax/FUNCTION_MODIFIER_0.php">FUNCTION_MODIFIER_0</a> {<a href="/documentation/syntax/IC.php">IC</a>}] $<a href="/documentation/syntax/BLOCK.php">BLOCK</a></div>
		</div>
		<div class="code2">
			<p>Example</p>
			<pre>
(a, b) pure { return a * b; }
</pre>
		</div>		<div class="code2">
			<p>Example</p>
			<pre>
&lt;int → int&gt; factorial := (x) { return x == 0 ? 1 : x * factorial(x - 1); };
</pre>
		</div>		<div class="code2">
			<p>Example</p>
			<pre>
&lt;Collection&lt;T&gt; → T&gt; head := (a&amp;b) { return a; }
</pre>
		</div>		<div class="code2">
			<p>Example</p>
			<pre>

</pre>
		</div>		<h2>Notes</h2>
				<p>Function objects are invoked using the invocation syntax.

The FUNCTION_MODIFIER_* rules model: ["stable" | "unstable"] ["throwing" | "throwing []" | "throwing [type0, type1]"] ["atomic"] {PLATFORM} ["pure"|"imperative"|"opaque"] with the caveat that there has to be an IC between any modifier and the next (if there is a next)

The atomic, pure, imperative, and opaque keywords influence assumptions that the compiler may make regarding a functions implementation. The pure keyword indicates that the implementation uses only pull semantics, is idempotent, and has no side effects. Additionally, only constants can be read, which includes value (not by reference/pointer values) passed as formal parameters. Any violation of these constraints causes an error to occur. The imperative keyword indicates that the implementation is likely not tractable, and it may interact with memory or hardware in unknown ways. Without either pure or imperative, the implementation is assumed to be push-pull and tractable. If the tool chain determines that this is not the case, it will fall back to imperative behavior. Pure functions are implicitly atomic.
		</p>



		<?php require('../../footer.php') ?>
	</body>
</html>