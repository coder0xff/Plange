<meta charset='utf-8'/>
<meta name="viewport" content="width=device-width, initial-scale=0.6">
<html>
	<head>
		<title>Pointer - Plange</title>
		<link rel=StyleSheet href='../../css/general.css' type='text/css' />
	</head>
	<body>
		<?php require('../../header.php') ?>


		<div class="code2">
			<p>Example</p>
			<pre>
x ← 12;
printLine(x + "\n"); //prints 12
xPtr ← address_of(x);
dereference(xPtr) ← 5;
printLine(x + "\n"); //prints 5
			</pre>
		</div>


		<?php require('../../footer.php') ?>
	</body>
</html>