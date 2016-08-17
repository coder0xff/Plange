<meta charset='utf-8'/>
<meta name="viewport" content="width=device-width, initial-scale=0.6">
<html>
	<head>
		<title>Shunting-yard algorithm - Plange</title>
		<link rel=StyleSheet href='../css/general.css' type='text/css' />
	</head>
	<body>
		<?php require('../header.php') ?>

        <div class="code">
            <p>shuntingYard.pge</p>
            <pre>&lt;String&gt; ops = &quot;-+/*^&quot;;
&lt;Stack&lt;Int&gt;&gt; s;
String result = &quot;&quot;;

for (token &isin; input(&quot;Enter expression&quot;).split(&quot; &quot;)) {
    c := token[0];
    idx := ops.indexOf(c);
    
    //check for operator
    if (idx &ne; -1) {
        if (s.empty) {
            s.push(idx);
        } else {
            while (&not;s.empty) {
                prec2 := s.peek() / 2;
                prec1 := idx / 2;
                if (prec2 &gt; prec1 &or; (prec2 = prec1 &and; c &ne; '^')) {
                    result = result + ops[s.pop()] + ' ';
                } else {
                    break;
                }
                s.push(idx);
            }
        }
    } elif (c = '(') {
        s.push(-2);
    } elif (c == ')') {
        while (s.peek() &ne; -2) {
            result = result + ops[s.pop()] + ' ';
        }
        s.pop();
    } else {
        result = result + token + ' ';
    }
}
while (&not;s.empty) {
    result = result + ops[s.pop()] + ' ';
}

print(result);</pre>
        </div>
            

		<?php require('../footer.php') ?>
	</body>
</html>