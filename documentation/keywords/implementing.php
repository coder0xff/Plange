<meta charset='utf-8'/>
<html>
	<head>
		<title>implementing - Plange</title>
		<link rel=StyleSheet href='..//css/general.css' type='text/css' />
	</head>
	<body>
		<?php require('..//header.php') ?>


with the type keyword to inherit the interface of the specified Type
    <div style="margin-top:12pt;margin-bottom:12pt;border-style:solid;border-width:1px">
        <p style="font-size:12pt;margin:0px;padding-left:6pt;background-color:#cda">
            Example
        </p>
        <pre style="margin:0px;padding:3px;font-family:Courier New;width:715px;max-height:500px;overflow-x:auto;overflow-y:auto">
            TextBox = type implementing Widget {
     &lt;Image&gt; draw;
}
        </pre>
    </div>
    The implementing keyword is similar to inheriting, but only the external interface is inherited. 
    <span style="font-size:13.3333330154419px;line-height:21.3333320617676px">
        The external interface is all of the publicly accessible members of the base type and all the base types ancestors. 
    </span>
    The derived type must implement this interface. 
    <span style="font-size:13.3333330154419px;line-height:21.3333320617676px">
        This feature removes the need for explicit interfaces. All types have an interface. Like the inheriting keyword, implementing permits covariant return types, contravariant argument types, and covariant argument types (pattern matching).
    </span>
    <div>
        <br>
        </br>
    </div>
    <div>
        Implementers can be used for code injection. Altering an Scope to override an existing base type, using a derived implementing type, ensures that the external interface is preserved. This does not, however, guarantee that either 1) the same pre/postconditions exist on each method, or 2) that fields will remain as native scalars or non-volatile. Due to the second, there may be cases where a field becomes a
        <a href="../properties.php">
            property
        </a>
        . If the affected code is being interpreted, no additional modifications are needed. Otherwise, if it is possible to recompile or switch to interpreting (the source code is available), then do either. If the source code is not available (it was stripped), then an exception is thrown.
    </div>
    <div>
        <br>
        </br>
    </div>



		<?php require('..//footer.php') ?>
	</body>
</html>