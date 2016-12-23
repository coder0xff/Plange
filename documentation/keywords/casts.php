<meta charset='utf-8'/>
<meta name="viewport" content="width=device-width, initial-scale=0.6">
<html>
	<head>
		<title>casts - Plange</title>
		<link rel=StyleSheet href='../../css/general.css' type='text/css' />
	</head>
	<body>
		<?php require('../../header.php') ?>


        <p>binary infix operator creates a relation object representing the constraint that the left hand side:
            <ul>
                <li>is the Type, or a super class of the Type, of the right hand side</li>
                <li>has an implicit constructor using the right hand side as the sole parameter, or</li>
                <li>has an explicit or implicit cast operator, or</li>
                <li>can promote the right hand side value</li>
            </ul>
        </p>

        <div class="code2">
            <p>Example</p>
            <pre>
print(Real casts Int32); //prints "true"
            </pre>
        </div>


		<?php require('../../footer.php') ?>
	</body>
</html>