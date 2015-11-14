<meta charset='utf-8'/>
<html>
	<head>
		<title>range - Plange</title>
		<link rel=StyleSheet href='..//css/general.css' type='text/css' />
	</head>
	<body>
		<?php require('..//header.php') ?>



        <div>
            Create an open, closed, or half open Set containing a range. It may be either discreet or continuous.
            <br>
            </br>
        </div>
        <div>
            <br>
            </br>
            <div class="sites-codeblock sites-codesnippet-block">
                <code>
                    "(" "..."
                </code>
                <a href="expression.php">
                    <code>
                        expression
                    </code>
                </a>
                <code>
                    ("]"|")") |
                    <br>
                    </br>
                </code>
                <br>
                </br>
                <code>
                    ("["|"(")
                </code>
                <a href="expression.php">
                    <code>
                        expression
                    </code>
                </a>
                <code>
                    "..." ")" |
                    <br>
                    </br>
                </code>
                <br>
                </br>
                <code>
                    ("("|"[")
                </code>
                <a href="expression.php">
                    <code>
                        expression
                    </code>
                </a>
                <code>
                    "..."
                </code>
                <a href="expression.php">
                    <code>
                        expression
                    </code>
                </a>
                <code>
                    ("]"|")")
                </code>
            </div>
            <br>
            </br>
        </div>
    </div>
    <div>
        examples:
    </div>
    <div>
    </div>
    <div class="sites-codeblock sites-codesnippet-block">
        <div>
            <code>
                [ 0 ... ) // the non negative integers - the set is infinite and denumerable
            </code>
        </div>
        <div>
            <code>
                [ 1 ... n ] // the integers 1 to n inclusive - the set is finite and denumerable
            </code>
        </div>
        <div>
            <code>
                ( ... 0.0 ) // the negative real numbers - the set is infinite and nondenumerable
            </code>
        </div>
    </div>
    <div>
        <br>
        </br>
    </div>



		<?php require('..//footer.php') ?>
	</body>
</html>