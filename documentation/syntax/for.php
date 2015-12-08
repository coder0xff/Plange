<meta charset='utf-8'/>
<html>
	<head>
		<title>for - Plange</title>
		<link rel=StyleSheet href='../../css/general.css' type='text/css' />
	</head>
	<body>
		<?php require('../../header.php') ?>


		<div class="code">
			<p>Syntax</p>
 			<pre>"for" "(" [ <a href="/documentation/syntax/statement_scope.php">statement_scope</a> ] expression ";" expression ")" expresssion</pre>
 		</div>

 		<div class="code">
 			<p>Example</p>
 			<pre>for (x ← 0; x < 100; x++) {
	print(x);
};</pre>
		</div>

 		<p>This next example demonstrates the optional statement_scope.</p>
 		<div class="code">
 			<p>Example</p>
 			<pre>spammer := (<UInt> count) {
	for (count > 0; count--) {
		print("SPAM!!!\n");
	};
};</pre>
 		</div>

 		<p>Further, more than one statement may be used to initialize, and blanks may be used.</p>
 		<div class="code">
 			<p>Example</p>
			<pre>f := (a, b) {
 	for (x ← 0; y ← 0; x < a.count && y < b.count; ) {
 		if (a[x] < b[y]) {
 			x++;
 		} else {
 			y++;
 		}
 	}
 }</pre>

		<?php require('../../footer.php') ?>
	</body>
</html>