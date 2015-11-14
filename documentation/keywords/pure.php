<meta charset='utf-8'/>
<html>
	<head>
		<title>pure - Plange</title>
		<link rel=StyleSheet href='..//css/general.css' type='text/css' />
	</head>
	<body>
		<?php require('..//header.php') ?>


used in the 
    <a href="../syntax/function.php">
        function
    </a>
    syntax, indicates that the implementation's behavior meets the requirements of a pure function
    <div style="margin-top:12pt;margin-bottom:12pt;border-style:solid;border-width:1px">
        <p style="font-size:12pt;margin:0px;padding-left:6pt;background-color:#cda">
            Example
        </p>
        <pre style="margin:0px;padding:3px;font-family:Courier New;width:715px;max-height:500px;overflow-x:auto;overflow-y:auto">
            pow2 := (x) pure { return x * x; };
        </pre>
    </div>
    Notes: The pure keyword asserts to the toolchain that the behavior of the function is tractable and supports all properties and operations offered by function objects. An error occurs if the toolchain determines that any of the requirements of pure functions are not met by the implementation. Pure functions may 
    <span style="line-height:1.6;font-size:10pt;background-color:transparent">
        only use data-pull semantics, and only on constants, which includes values (not by reference) passed as formal parameters. See
        <a href="../syntax/function.php">
            function
        </a>
    </span>



		<?php require('..//footer.php') ?>
	</body>
</html>