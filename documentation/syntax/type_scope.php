<meta charset='utf-8'/>
<html>
	<head>
		<title>type_scope - Plange</title>
		<link rel=StyleSheet href='../../css/general.css' type='text/css' />
	</head>
	<body>
		<?php require('../../header.php') ?>
        

        <p>
            when used in the <a href="type.php">type</a> syntax, the instance member declarations, static member definitions, constraint expressions, and static construction statements, between curly brackets, that define the resulting type
        </p>
        <div class="syntax">
            <p>syntax</p>
            <div>((<a href="expression.php">expression</a> | (<a href="declaration_assignment.php">declaration_assignment</a> | <a href="declaration.php">declaration</a> ) ["<a href="../keywords/at.php">at</a>" <a href="whole_number.php">whole_number</a>]) | <a href="assignment.php">assignment</a> | <a href="definition.php">definition</a>) ";")*</div>
        </div>
        <h4>
            Notes
        </h4>
        <p>Any use of the assignment operator indicates an instance member declaration. Any use of the definition operator indicates a static member of the class, since it is immutable it will not vary between instances. Like in statement_scope, an execution context is available and will execute any top-level statements inside the type.</p>


		<?php require('../../footer.php') ?>
	</body>
</html>