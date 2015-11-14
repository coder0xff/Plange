<meta charset='utf-8'/>
<html>
	<head>
		<title>embedded_comment - Plange</title>
		<link rel=StyleSheet href='../../css/general.css' type='text/css' />
	</head>
	<body>
		<?php require('../../header.php') ?>


style="margin-top:12pt;margin-bottom:12pt;border-style:solid;border-width:1px">
        <p style="font-size:12pt;margin:0px;padding-left:6pt;background-color:#cda">
            Wirth syntax notation
        </p>
        <pre style="margin:0px;padding:3px;font-family:Courier New;width:715px;max-height:500px;overflow-x:auto;overflow-y:auto">
            embedded_comment_interior:= newline payload newline | "*" embedded_comment_interior "*"
embedded_comment:= newline "/*" embedded_comment_interior "*/" newline
        </pre>
    </div>
    <h4>
        <a name="TOC-Notes">
        </a>
        Notes
    </h4>
    This allows for commented code to be safely commented out completely by including a sufficient number of asterisks to serve as an opening and closing delimiter.
    <div style="margin-top:12pt;margin-bottom:12pt;border-style:solid;border-width:1px">
        <p style="font-size:12pt;margin:0px;padding-left:6pt;background-color:rgb(204,221,170)">
            Example
        </p>
        <pre style="margin:0px;padding:3px;font-family:Courier New;width:715px;max-height:500px;overflow-x:auto;overflow-y:auto">
            /**** this is an embedded_comment
***/ the characters at the start of this line have no affect on this ongoing comment
Embed blocks of code that themselves contain block comments:
    /* Do the thing */
    thing();
No problem. Now, lets end this comment. ****/
        </pre>
    </div>



		<?php require('../../footer.php') ?>
	</body>
</html>