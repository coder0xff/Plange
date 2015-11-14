<meta charset='utf-8'/>
<html>
	<head>
		<title>imperative - Plange</title>
		<link rel=StyleSheet href='../../css/general.css' type='text/css' />
	</head>
	<body>
		<?php require('../../header.php') ?>


used in the function syntax, indicates that a functions behavior (side effects) is not tractable
    <div>
        <br>
        </br>
    </div>
    <div>
        Notes:
    </div>
    <div>
        The imperative keyword indicates to the compiler that it should not attempt to model the behavior of the function for the purposes of optimization and introspection. Functions that cannot be statically analyzed in a predetermined time frame are assumed to be imperative. This hint avoids the computational cost involved, thereby improving performance.
    </div>



		<?php require('../../footer.php') ?>
	</body>
</html>