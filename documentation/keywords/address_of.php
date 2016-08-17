<meta charset='utf-8'/>
<meta name="viewport" content="width=device-width, initial-scale=0.6">
<html>
	<head>
		<title>address_of - Plange</title>
		<link rel=StyleSheet href='../../css/general.css' type='text/css' />
	</head>
	<body>
		<?php require('../../header.php') ?>


		<p>returns a value of type <a href="/documentation/standard-library/Pointer.php">Pointer</a>&lt;T&gt;</p>
		<div class="code">
			<p>Example</p>
			<pre>&lt;Int&gt; x = 0xABC123;
&lt;Pointer&lt;Int&gt;&gt; ptr = address_of(x);
print("Address of x: " + ptr);
print("Value of x: " + <a href="dereference.php">dereference</a>(ptr));</pre>
		</div>
		<h2>Notes</h2>
		<p>address_of is similar in function to C's address-of operator, '&amp;'. See the <a href="dereference.php">dereference</a> keyword.</p>


		<?php require('../../footer.php') ?>
	</body>
</html>