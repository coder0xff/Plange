<meta charset='utf-8'/>
<html>
	<head>
		<title>context - Plange</title>
		<link rel=StyleSheet href='..//css/general.css' type='text/css' />
	</head>
	<body>
		<?php require('..//header.php') ?>



        an alias for the current execution context
        <br>
        </br>
    </div>
    <h4>
        <a name="TOC-Notes">
        </a>
        Notes
        <br>
        </br>
    </h4>
    The value of 'context' contains members for inspecting the current scope and its parents. It can be thought of as localized reflection. It can also be used as a re-entry point for cooperative multi-threading. In this capacity, it also increments a call counter, and stores a user object for passing in data during re-entry.
    <br>
    </br>



		<?php require('..//footer.php') ?>
	</body>
</html>