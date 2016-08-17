<meta charset='utf-8'/>
<meta name="viewport" content="width=device-width, initial-scale=0.6">
<html>
	<head>
		<title>Greatest Common Divisor - Plange</title>
		<link rel=StyleSheet href='../css/general.css' type='text/css' />
	</head>
	<body>
		<?php require('../header.php') ?>

        <div class="code">
            <p>greatestCommonDivisor.pge</p>
            <pre>&lt;Int * Int &rarr; Int&gt; gcd :=
    (a, 0) { return a; } |
    (a, b) {
        a &ge; 0; //preconditions - only positive
        b &ge; 0;
        return gcd(b, a % b);
    } |
    (a, b) {
        a &ne; 0;
        return gcd(abs(a), abs(b));
    } |
    (_, _) {
        throw &quot;gcd undefined for given values&quot;;
    };</pre></div>

		<?php require('../footer.php') ?>
	</body>
</html>