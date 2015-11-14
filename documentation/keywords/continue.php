<meta charset='utf-8'/>
<html>
	<head>
		<title>continue (removed) - Plange</title>
		<link rel=StyleSheet href='..//css/general.css' type='text/css' />
	</head>
	<body>
		<?php require('..//header.php') ?>


n to the start of a do, while, until, for, or for_collection loop
    <div>
        <br>
        </br>
    </div>
    <div>
        Example:
    </div>
    <div>
    </div>
    <div class="sites-codeblock sites-codesnippet-block">
        <div>
            <code>
                for (employee in Employees) {
            </code>
        </div>
        <div>
            <span>
                <code>
                        if (employee.hoursWorked == 0) {
                </code>
            </span>
            <br>
            </br>
        </div>
        <div>
            <span>
                <span>
                    <code>
                            
                    </code>
                    <span>
                        <code>
                                continue;
                        </code>
                    </span>
                </span>
                <br>
                </br>
            </span>
        </div>
        <div>
            <span>
                <span>
                    <span>
                        <span>
                            <code>
                                    }
                            </code>
                        </span>
                    </span>
                </span>
            </span>
        </div>
        <div>
            <span>
                <span>
                    <span>
                        <span>
                            <span>
                                <code>
                                        wages = employee.hoursWorked * employee.hourlyWage;
                                </code>
                            </span>
                            <br>
                            </br>
                        </span>
                    </span>
                </span>
            </span>
        </div>
        <div>
            <span>
                <span>
                    <span>
                        <span>
                            <span>
                                <span>
                                    <code>
                                            employee.yearToDate += wages;
                                    </code>
                                </span>
                            </span>
                        </span>
                    </span>
                </span>
            </span>
        </div>
        <div>
            <span>
                <span>
                    <span>
                        <span>
                            <span>
                                <span>
                                    <span>
                                        <code>
                                                payroll.deposit(employee, wages * (1 - incomeTax));
                                        </code>
                                    </span>
                                    <br>
                                    </br>
                                </span>
                            </span>
                        </span>
                    </span>
                </span>
            </span>
        </div>
        <div>
            <code>
                }
            </code>
        </div>
    </div>
    <div>
        <br>
        </br>
    </div>
    Notes: The continue keyword is removed because it breaks scope isolation. Since if, for_collection, and others take nullary void functions as their conditional code, continue is not sensible because continue is not used in nullary void functions in general. Further (though not a reason to exclude it), the context required to correctly interpret a continue statement is easily confused.



		<?php require('..//footer.php') ?>
	</body>
</html>