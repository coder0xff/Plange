<meta charset='utf-8'/>
<html>
	<head>
		<title>declaration_assignment - Plange</title>
		<link rel=StyleSheet href='..//css/general.css' type='text/css' />
	</head>
	<body>
		<?php require('..//header.php') ?>


tement combining a variable declaration and an assignment
    <div style="margin-top:12pt;margin-bottom:12pt;border-style:solid;border-width:1px">
        <p style="font-size:12pt;margin:0px;padding-left:6pt;background-color:#cda">
            Syntax
        </p>
        <pre style="margin:0px;padding:3px;font-family:Courier New;width:715px;max-height:500px;overflow-x:auto;overflow-y:auto">
            [
            <a href="type_dereference.php">
                type_dereference
            </a>
            |
            <a href="implicit_type_dereference.php">
                implicit_type_dereference
            </a>
            ]
            <a href="symbol.php">
                identifier
            </a>
            "&lt;-"
            <a href="expression.php">
                expression
            </a>
        </pre>
    </div>
    <div style="margin-top:12pt;margin-bottom:12pt;border-style:solid;border-width:1px">
        <p style="font-size:12pt;margin:0px;padding-left:6pt;background-color:#cda">
            Example
        </p>
        <pre style="margin:0px;padding:3px;font-family:Courier New;width:715px;max-height:500px;overflow-x:auto;overflow-y:auto">
            &lt;Number&gt; x &lt;- 100;
        </pre>
    </div>
    <div style="margin-top:12pt;margin-bottom:12pt;border-style:solid;border-width:1px">
        <p style="font-size:12pt;margin:0px;padding-left:6pt;background-color:#cda">
            Example
        </p>
        <pre style="margin:0px;padding:3px;font-family:Courier New;width:715px;max-height:500px;overflow-x:auto;overflow-y:auto">
            &lt;&gt; name &lt;- "Alice"; //implicitly type String
        </pre>
    </div>
    <div>
        <br>
        </br>
    </div>
    <div>
        <div style="font-size:13.3333px;line-height:21.3333px;margin-top:12pt;margin-bottom:12pt;border-style:solid;border-width:1px">
            <p style="font-size:12pt;margin:0px;padding-left:6pt;background-color:rgb(204,221,170)">
                Example
            </p>
            <pre style="margin-top:0px;margin-bottom:0px;padding:3px;font-family:Courier New;width:715px;max-height:500px;overflow:auto">
                object &lt;- { "employees":[
    ("John", "Doe"),
    ("Anna", "Smith"),
    ("Peter", Jones")
]}; //type Any (duck typed)

object &lt;- (x) { return x*2; }; //type Any
            </pre>
        </div>
    </div>
    <div>
        <br>
        </br>
    </div>
    <div>
        <br>
        </br>
    </div>



		<?php require('..//footer.php') ?>
	</body>
</html>