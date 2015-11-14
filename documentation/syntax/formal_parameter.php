<meta charset='utf-8'/>
<html>
	<head>
		<title>parameter - Plange</title>
		<link rel=StyleSheet href='..//css/general.css' type='text/css' />
	</head>
	<body>
		<?php require('..//header.php') ?>



        a formal parameter of a function
    </div>
    <div>
        <div style="font-size:13.3333px;line-height:21.3333px;margin-top:12pt;margin-bottom:12pt;border-style:solid;border-width:1px">
            <p style="font-size:12pt;margin:0px;padding-left:6pt;background-color:rgb(204,221,170)">
                Syntax
            </p>
            <pre style="margin-top:0px;margin-bottom:0px;padding:3px;font-family:Courier New;width:715px;max-height:500px;overflow:auto">
                [
                <a href="type_dereference.php">
                    type_dereference
                </a>
                ]
                <a href="symbol.php">
                    identifier
                </a>
                |
                <span style="font-size:13.3333px;line-height:21.3333px;background-color:transparent">
                    [
                </span>
                <a style="font-size:13.3333px;line-height:21.3333px;background-color:transparent" href="type_dereference.php">
                    type_dereference
                </a>
                |
                <a href="implicit_type_dereference.php">
                    implicit_type_dereference
                </a>
                <span style="font-size:13.3333px;line-height:21.3333px;background-color:transparent">
                    ]
                </span>
                <a style="font-size:13.3333px;line-height:21.3333px;background-color:transparent" href="symbol.php">
                    identifier
                </a>
                "="
                <a href="expression.php">
                    expression
                </a>
                |
                <a style="font-size:13.3333px;line-height:21.3333px;background-color:transparent" href="expression.php">
                    expression
                </a>
                ["="
                <a style="font-size:13.3333px;line-height:21.3333px;background-color:transparent" href="expression.php">
                    expression
                </a>
                ]
            </pre>
        </div>
        <div style="font-size:13.3333px;line-height:21.3333px">
            <span style="font-size:1.2em;line-height:1.6;background-color:transparent">
                Notes
            </span>
        </div>
    </div>
    <div>
        The last variation accepts an expression, which is then set to be equivalent to the passed in value. This enables pattern matching and solving on parameters.
    </div>
    <div>
        <br>
        </br>
    </div>
    <div>
        See also:
        <a href="function.php">
            function (syntax)
        </a>
    </div>
    <div>
        <br>
        </br>
    </div>



		<?php require('..//footer.php') ?>
	</body>
</html>