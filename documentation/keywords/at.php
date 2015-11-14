<meta charset='utf-8'/>
<html>
	<head>
		<title>at - Plange</title>
		<link rel=StyleSheet href='..//css/general.css' type='text/css' />
	</head>
	<body>
		<?php require('..//header.php') ?>


used in
    <a href="../syntax/type_scope.php">
        type_scope
    </a>
     syntax, specifies the offset of a field
    <div>
        <br>
        </br>
    </div>
    <div>
        Example:
    </div>
    <div>
        <div class="sites-codeblock sites-codesnippet-block">
            <font color="#006000" face="monospace">
                FloatOrInt := type {
                <br>
                </br>
                <span>
                        &lt;Float32&gt; single at 0; //a union of Float32 and Int32
                    <br>
                    </br>
                </span>
                <span>
                        &lt;Int32&gt; int32 at 0;
                </span>
                <br>
                </br>
            </font>
            <span style="color:rgb(0,96,0);font-family:monospace;line-height:1;font-size:10pt">
                }
            </span>
        </div>
    </div>



		<?php require('..//footer.php') ?>
	</body>
</html>