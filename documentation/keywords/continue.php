<meta charset='utf-8'/>
<html>
	<head>
		<title>continue - Plange</title>
		<link rel=StyleSheet href='../../css/general.css' type='text/css' />
	</head>
	<body>
		<?php require('../../header.php') ?>


		<p>return to the start of the innermost do, while, until, for, or for_collection loop</p>
		<div class="code">
			<p>Example</p>
			<pre>for (employee in Employees) {
	if (employee.hoursWorked == 0) {
		continue;
	}
	
	wages = employee.hoursWorked * employee.hourlyWage;
	employee.yearToDate += wages;
	payroll.deposit(employee, wages * (1 - incomeTax));
}</pre>
		</div>
		<h2>Notes</h2>
		<p>Since if, for_collection, and others take nullary void functions as their conditional code, continue is not sensible because continue is not used in nullary void functions in general. Further (though not a reason to exclude it), the context required to correctly interpret a continue statement is easily confused. For these reasons, use of continue and break are discouraged. They are, however, supported, and will be subjected to rewrite rules and and/or other transformations.</p>


		<?php require('../../footer.php') ?>
	</body>
</html>