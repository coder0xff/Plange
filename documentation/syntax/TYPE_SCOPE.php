<meta charset='utf-8'/>
<meta name="viewport" content="width=device-width, initial-scale=0.6">
<html>
	<head>
		<title>TYPE_SCOPE - Syntax Pages - Plange</title>
		<link rel=StyleSheet href='../../css/general.css' type='text/css' />
	</head>
	<body>
		<?php require('../../header.php') ?>


		<p>zero or more statements or member declarations/definitions, used strictly in the TYPE syntax only</p>

		<div class="syntax">
			<p>syntax</p>
			<div> {<a href="/documentation/syntax/TYPE_STATEMENT.php">TYPE_STATEMENT</a>}</div>
		</div>
		<h2>Notes</h2>
				<p>Any use of the assignment operator indicates an instance member declaration. Any use of the definition operator indicates a static member of the class, since it is immutable it will not vary between instances. Like in statement_scope, an execution context is available and will execute any top-level statements inside the type.
		</p>



		<?php require('../../footer.php') ?>
	</body>
</html>