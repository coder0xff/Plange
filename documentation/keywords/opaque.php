<meta charset='utf-8'/>
<meta name="viewport" content="width=device-width, initial-scale=0.6">
<html>
	<head>
		<title>opaque - Plange</title>
		<link rel=StyleSheet href='../../css/general.css' type='text/css' />
	</head>
	<body>
		<?php require('../../header.php') ?>


used in
    <a href="../syntax.php?name=function">
        function
    </a>
     syntax, causes the resulting function object to be stripped of introspection information
    <br>
    </br>
    <br>
    </br>
    Notes:
    <div>
        Function properties can be accessed programmatically. For example, the implementation and side effects are both modeled as objects. This permits safe assumptions about the behavior a function, or groups of functions, to be determined and applied for the purposes of static analysis and optimization, such as inlining and closed form solutions. The opaque keyword removes all information pertaining to the implementation and side effects of the function so that introspection is limited to analyses of native binaries and memory.
    </div>



		<?php require('../../footer.php') ?>
	</body>
</html>