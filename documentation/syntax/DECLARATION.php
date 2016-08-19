<meta charset='utf-8'/>
<meta name="viewport" content="width=device-width, initial-scale=0.6">
<html>
	<head>
		<title>DECLARATION - Syntax Pages - Plange</title>
		<link rel=StyleSheet href='../../css/general.css' type='text/css' />
	</head>
	<body>
		<?php require('../../header.php') ?>


		<p>declare a variable and optionally assign a value to it</p>

		<div class="syntax">
			<p>syntax</p>
			<div>[<a href="/documentation/syntax/XML_DOC_STRING.php">XML_DOC_STRING</a> {<a href="/documentation/syntax/IC.php">IC</a>}] ["extern" {<a href="/documentation/syntax/IC.php">IC</a>}] [(<a href="/documentation/syntax/TYPE_DEREFERENCE.php">TYPE_DEREFERENCE</a> | <a href="/documentation/syntax/IMPLICIT_TYPE_DEREFERENCE.php">IMPLICIT_TYPE_DEREFERENCE</a> | <a href="/documentation/syntax/VOLATILE_IMPLICIT_TYPE_DEREFERENCE.php">VOLATILE_IMPLICIT_TYPE_DEREFERENCE</a> | <a href="/documentation/syntax/VOLATILE_TYPE_DEREFERENCE.php">VOLATILE_TYPE_DEREFERENCE</a>) {<a href="/documentation/syntax/IC.php">IC</a>}] <a href="/documentation/syntax/DECLARATION_PART.php">DECLARATION_PART</a> {{<a href="/documentation/syntax/IC.php">IC</a>} "," [{<a href="/documentation/syntax/IC.php">IC</a>} <a href="/documentation/syntax/XML_DOC_STRING.php">XML_DOC_STRING</a>] {<a href="/documentation/syntax/IC.php">IC</a>} <a href="/documentation/syntax/DECLARATION_PART.php">DECLARATION_PART</a>}</div>
		</div>
		<div class="code">
			<p>Example</p>
			<pre>&lt;Number&gt; x &lt;- 100;</pre>
		</div>		<div class="code">
			<p>Example</p>
			<pre>&lt;&gt; name &lt;- "Alice"; //implicitly type String</pre>
		</div>		<div class="code">
			<p>Example</p>
			<pre>object &lt;- {
    "employees":[
        ("John", "Doe"),
        ("Anna", "Smith"),
        ("Peter", Jones")],
    "contractors":[
        ("Matt", "Williams")]
};

object &lt;- (x) { return x*2; }; //no type constraint</pre>
		</div>		<p>See: <a href="STATEMENT.php">STATEMENT</a>
		</p>



		<?php require('../../footer.php') ?>
	</body>
</html>