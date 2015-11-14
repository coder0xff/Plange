<meta charset='utf-8'/>
<html>
	<head>
		<title>type_scope - Plange</title>
		<link rel=StyleSheet href='../../css/general.css' type='text/css' />
	</head>
	<body>
		<?php require('../../header.php') ?>


style="margin-top:0px;margin-bottom:0px;padding:3px;width:715px;max-height:500px;overflow:auto">
        <div style="font-family:Arial,Verdana,sans-serif;font-size:13.3333px;line-height:21.3333px;white-space:normal">
            when used in the
            <a href="type.php">
                type
            </a>
            syntax, the instance member declarations, static member definitions, constraint expressions, and static construction statements, between curly brackets, that define the resulting type
        </div>
        <div style="font-family:Arial,Verdana,sans-serif;font-size:13.3333px;line-height:21.3333px;white-space:normal;margin-top:12pt;margin-bottom:12pt;border-style:solid;border-width:1px">
            <p style="font-size:12pt;margin:0px;padding-left:6pt;background-color:rgb(204,221,170)">
                Syntax
            </p>
            <pre style="margin-top:0px;margin-bottom:0px;padding:3px;font-family:Courier New;width:715px;max-height:500px;overflow:auto">
                ((
                <a href="expression.php">
                    expression
                </a>
                |(
                <a href="declaration_assignment.php">
                    declaration_assignment
                </a>
                |
                <a href="declaration.php">
                    declaration
                </a>
                ) ["
                <a href="../keywords/at.php">
                    at
                </a>
                "
                <a href="whole_number.php">
                    whole_number
                </a>
                ]) |
                <a href="assignment.php">
                    assignment
                </a>
                |
                <a href="definition.php">
                    definition
                </a>
                ) ";")*
            </pre>
        </div>
        <h4>
            <a name="TOC-Notes">
            </a>
            Notes
        </h4>
        <div>
            Any use of the assignment operator indicates an instance member declaration. Any use of the definition operator indicates a static member of the class, since it is immutable it will not vary between instances. Like statement_scope, an execution context is available and will execute any top-level statements inside the type.
        </div>
    </pre>
    <pre style="font-size:13.3333px;line-height:21.3333px;margin-top:0px;margin-bottom:0px;padding:3px;font-family:Courier New;width:715px;max-height:500px;overflow:auto">
        <br>
        </br>
    </pre>
    <pre style="font-size:13.3333px;line-height:21.3333px;margin-top:0px;margin-bottom:0px;padding:3px;font-family:Courier New;width:715px;max-height:500px;overflow:auto">
        <br>
        </br>
    </pre>



		<?php require('../../footer.php') ?>
	</body>
</html>