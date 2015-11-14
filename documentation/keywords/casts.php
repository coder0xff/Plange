<meta charset='utf-8'/>
<html>
	<head>
		<title>casts - Plange</title>
		<link rel=StyleSheet href='../../css/general.css' type='text/css' />
	</head>
	<body>
		<?php require('../../header.php') ?>


binary infix operator creates a relation object representing the constraint that the left hand side:
    <br>
    </br>
    <ul>
        <li>
            is the Type, or a super class of the Type, of the right hand side
        </li>
        <li>
            has an implicit constructor using the right hand side as the sole parameter, or
        </li>
        <li>
            has an explicit or implicit cast operator, or
            <br>
            </br>
        </li>
        <li>
            can promote the right hand side value
        </li>
    </ul>
    <p>
        In other words,
        <code>
            T casts a
        </code>
        is true when the C style cast
        <code>
            (T)a
        </code>
        is valid.
        <br>
        </br>
    </p>



		<?php require('../../footer.php') ?>
	</body>
</html>