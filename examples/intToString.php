<meta charset='utf-8'/>
<meta name="viewport" content="width=device-width, initial-scale=0.6">
<html>
	<head>
		<title>Int to String - Plange</title>
		<link rel=StyleSheet href='../css/general.css' type='text/css' />
	</head>
	<body>
		<?php require('../header.php') ?>



        <div class="code">
            <p>intToString.pge</p>
            <pre>&lt;Int &rarr; String&gt; intToString := (i) {
    &lt;Int&gt; register &larr; i;
    if (i &lt; 0) {
        register &larr; -i;
    };
    &lt;String&gt; result &larr; &quot;&quot;;
    while (register &gt; 0) {
        digit := register  % 10;
        result &larr; chr(digit + 48) + result;
        register &larr; register / 10;
    };
    if (i &lt; 0) {
        result &larr; &quot;-&quot; + result;
    };
    return result;
};


&lt;Int * Int &rarr; String&gt; coordsToString := (x, y) {
    return &quot;(&quot; + intToString(x) + &quot;, &quot; + intToString(y) + &quot;)&quot;;
};

&lt;a * (a &rarr; String) &rarr; String&gt; meta := (&lt;a&gt; i, func) {
    return func(i);
};
</pre>
        </div>



		<?php require('../footer.php') ?>
	</body>
</html>