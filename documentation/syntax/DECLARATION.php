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
			<pre>[XML_DOC_STRING {IC}] ["extern" {IC}] (TYPE_DEREFERENCE | IMPLICIT_TYPE_DEREFERENCE | VOLATILE_IMPLICIT_TYPE_DEREFERENCE | VOLATILE_TYPE_DEREFERENCE) {IC} DECLARATION_PART {{IC} "," {IC} DECLARATION_PART}</pre>
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
		</div>		<p>See:<a href="S.php">S</a><a href="T.php">T</a><a href="A.php">A</a><a href="T.php">T</a><a href="E.php">E</a><a href="M.php">M</a><a href="E.php">E</a><a href="N.php">N</a><a href="T.php">T</a>
		</p>



		<?php require('../../footer.php') ?>
	</body>
</html>