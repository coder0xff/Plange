<meta charset='utf-8'/>
<meta name="viewport" content="width=device-width, initial-scale=0.6">
<html>
	<head>
		<title>FOR - Syntax Pages - Plange</title>
		<link rel=StyleSheet href='../../css/general.css' type='text/css' />
	</head>
	<body>
		<?php require('../../header.php') ?>


		<p>creates a nullary void function that evaluate the second expression repeatedly while the second expression is true, all after evaluating the optional STATEMENT_SCOPE</p>

		<div class="syntax">
			<p>syntax</p>
			<div>"for" {<a href="/documentation/syntax/IC.php">IC</a>} "(" {<a href="/documentation/syntax/IC.php">IC</a>} [ <a href="/documentation/syntax/STATEMENT_SCOPE.php">STATEMENT_SCOPE</a> {<a href="/documentation/syntax/IC.php">IC</a>} ] <a href="/documentation/syntax/EXPRESSION.php">EXPRESSION</a> {<a href="/documentation/syntax/IC.php">IC</a>} ";" {<a href="/documentation/syntax/IC.php">IC</a>} [ (<a href="/documentation/syntax/ASSIGNMENT.php">ASSIGNMENT</a> | <a href="/documentation/syntax/EXPRESSION.php">EXPRESSION</a>) {<a href="/documentation/syntax/IC.php">IC</a>} ] ")" {<a href="/documentation/syntax/IC.php">IC</a>} <a href="/documentation/syntax/EXPRESSION.php">EXPRESSION</a></div>
		</div>
		<div class="code">
			<p>Example</p>
			<pre>for (x ← 0; x &lt; 100; x++) {
    print_line(x);
};</pre>
		</div>		<p>demonstrates the optional statement_scope
		</p>
		<div class="code">
			<p>Example</p>
			<pre>spammer := (&lt;UInt&gt; count) {
    for (count &gt; 0; count--; ) {
        print("SPAM!!!\n");
    };
};</pre>
		</div>		<p>more than one statement may be used to initialize, and a blank may be used for the increment expression
		</p>
		<div class="code">
			<p>Example</p>
			<pre>mergeSorted := (List&lt;Int&gt; a, List&lt;Int&gt; b) {
    List&lt;Int&gt; result;
    &lt;Int&gt;i;
    &lt;Int&gt;j;
    for (i ← 0; j ← 0; i &lt; a.count &amp;&amp; j &lt; b.count; ) { //blank increment expression
        if (a[i] &lt; b[j]) {
            result.add(a[i]);
            i++;
        } else {
            result.add(b[j]);
            j++;
        }
    }
    for (i &lt; a.count; i++) {
        result.add(a[i])
    }
    for (j &lt; b.count; j++) {
        result.add(b[j]);
    }
    return result;
}</pre>
		</div>


		<?php require('../../footer.php') ?>
	</body>
</html>