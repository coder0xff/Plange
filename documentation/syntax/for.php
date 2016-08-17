<meta charset='utf-8'/>
<meta name="viewport" content="width=device-width, initial-scale=0.6">
<html>
	<head>
		<title>for - Plange</title>
		<link rel=StyleSheet href='../../css/general.css' type='text/css' />
	</head>
	<body>
		<?php require('../../header.php') ?>


		<div class="syntax">
			<p>syntax</p>
			<div>"for" "(" [ <a href="/documentation/syntax/statement_scope.php">statement_scope</a> ] <a href="/documentation/syntax/expression.php">expression</a> ";" [ <a href="/documentation/syntax/assignment.php">assignment</a> | <a href="/documentation/syntax/expression.php">expression</a> ] ")" <a href="/documentation/syntax/expression.php">expression</a></div>
 		</div>

 		<div class="code">
 			<p>Example</p>
 			<pre>for (x ← 0; x < 100; x++) {
	print_line(x);
};</pre>
		</div>

 		<p>This next example demonstrates the optional statement_scope.</p>
 		<div class="code">
 			<p>Example</p>
 			<pre>spammer := (&lt;UInt&gt; count) {
	for (count > 0; count--) {
		print("SPAM!!!\n");
	};
};</pre>
 		</div>

 		<p>Further, more than one statement may be used to initialize, and a blank may be used for the increment expression.</p>
 		<div class="code">
 			<p>Example</p>
			<pre>mergeSorted := (List&lt;Int&gt; a, List&lt;Int&gt; b) {
	List&lt;Int&gt; result;
	&lt;Int&gt;i;
	&lt;Int&gt;j;
 	for (i ← 0; j ← 0; i < a.count && j < b.count; ) { //blank increment expression
 		if (a[i] < b[j]) {
 			result.add(a[i]);
 			i++;
 		} else {
 			result.add(b[j]);
 			j++;
 		}
 	}
 	for (i < a.count; i++) {
 		result.add(a[i])
 	}
 	for (j < b.count; j++) {
 		result.add(b[j]);
 	}
 	return result;
 }</pre>

		<?php require('../../footer.php') ?>
	</body>
</html>