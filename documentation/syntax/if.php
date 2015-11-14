<meta charset='utf-8'/>
<html>
	<head>
		<title>if - Plange</title>
		<link rel=StyleSheet href='../../css/general.css' type='text/css' />
	</head>
	<body>
		<?php require('../../header.php') ?>



        <span style="font-size:10pt;line-height:1.6;background-color:transparent">
            returns the 
        </span>
        <a style="font-size:13.3333px;line-height:21.3333px;background-color:transparent" href="expression.php">
            expression
        </a>
         
        <span style="line-height:1.6;font-size:10pt;background-color:transparent">
            corresponding to the first
            <a href="parenthetical.php">
                parenthetical
            </a>
            that evaluates to true when coerced to a boolean, or the else case if none of them evaluate to true, assuming that the else case is present, otherwise returning void
        </span>
    </div>
    <div>
        <div style="font-size:13.3333px;line-height:21.3333px;margin-top:12pt;margin-bottom:12pt;border-style:solid;border-width:1px">
            <p style="font-size:12pt;margin:0px;padding-left:6pt;background-color:rgb(204,221,170)">
                Syntax
            </p>
            <pre style="margin-top:0px;margin-bottom:0px;padding:3px;font-family:Courier New;width:715px;max-height:500px;overflow:auto">
                "
                <a href="../keywords/if.php">
                    if
                </a>
                "
                <a href="parenthetical.php">
                    parenthetical
                </a>
                <a href="expression.php">
                    expression
                </a>
                ( "
                <a style="font-size:13.3333px;line-height:21.3333px;background-color:transparent" href="../keywords/if.php">
                    <font>
                        elif
                    </font>
                </a>
                <span style="font-size:13.3333px;line-height:21.3333px;background-color:transparent">
                    "
                </span>
                <a style="font-size:13.3333px;line-height:21.3333px;background-color:transparent" href="parenthetical.php">
                    parenthetical
                </a>
                <span style="font-size:13.3333px;line-height:21.3333px;background-color:transparent">
                </span>
                <a style="font-size:13.3333px;line-height:21.3333px;background-color:transparent" href="expression.php">
                    expression
                </a>
                <span style="font-size:13.3333px;line-height:21.3333px;background-color:transparent">
                    )* [ "
                </span>
                <a style="font-size:13.3333px;line-height:21.3333px;background-color:transparent" href="../keywords/if.php">
                    else
                </a>
                <span style="font-size:13.3333px;line-height:21.3333px;background-color:transparent">
                    "
                </span>
                <a style="font-size:13.3333px;line-height:21.3333px;background-color:transparent" href="expression.php">
                    expression
                </a>
                <span style="font-size:13.3333px;line-height:21.3333px;background-color:transparent">
                    ]
                </span>
            </pre>
        </div>
    </div>



		<?php require('../../footer.php') ?>
	</body>
</html>