<meta charset='utf-8'/>
<html>
	<head>
		<title>assignment - Plange</title>
		<link rel=StyleSheet href='../../css/general.css' type='text/css' />
	</head>
	<body>
		<?php require('../../header.php') ?>


style="margin-top:12pt;margin-bottom:12pt;border-style:solid;border-width:1px">
        <p style="font-size:12pt;margin:0px;padding-left:6pt;background-color:#cda">
            Syntax
        </p>
        <pre style="margin:0px;padding:3px;font-family:Courier New;width:715px;max-height:500px;overflow-x:auto;overflow-y:auto">
            <a href="expression.php">
                expression
            </a>
            ("←"|"&lt;-")
            <a href="expression.php">
                expression
            </a>
        </pre>
    </div>
    <div style="margin-top:12pt;margin-bottom:12pt;border-style:solid;border-width:1px">
        <p style="font-size:12pt;margin:0px;padding-left:6pt;background-color:#cda">
            Example
        </p>
        <pre style="margin:0px;padding:3px;width:715px;max-height:500px;overflow:auto">
            <span style="font-family:Courier New">
                iPow2 &lt;- -1;
            </span>
        </pre>
    </div>
    <h4>
        <a name="TOC-special-characters:-U-2190">
        </a>
        <span style="font-size:13.3333px;line-height:21.3333px">
            special characters: U+2190
        </span>
    </h4>
    <h4>
        <a name="TOC-Notes">
        </a>
         Notes
    </h4>
    <div>
        Note that the left hand side of assignments need not be trivial expressions mapping to a single memory structure - a so called lvalue in other circles. Rather, arbitrary expressions can be solved when a single free variable is present. Revisiting the above example:
    </div>
    <div>
        <div style="font-size:13.3333330154419px;line-height:21.3333320617676px;margin-top:12pt;margin-bottom:12pt;border-style:solid;border-width:1px">
            <p style="font-size:12pt;margin:0px;padding-left:6pt;background-color:rgb(204,221,170)">
                Example
            </p>
            <pre style="margin-top:0px;margin-bottom:0px;padding:3px;font-family:Courier New;width:715px;max-height:500px;overflow:auto">
                iPow2 &lt;- -1;
                <span style="font-size:13.3333330154419px;line-height:21.3333320617676px;background-color:transparent">
                    // *****         - a single variable
                </span>
                <span style="font-size:13.3333330154419px;line-height:21.3333320617676px;background-color:transparent">
                    //       **      - is assigned
                </span>
                <span style="font-size:13.3333330154419px;line-height:21.3333320617676px;background-color:transparent">
                    //          **   - a single value
                </span>
            </pre>
        </div>
    </div>
    <div>
        It is straightforward in that a single value is being put in a single variable, and both of them are clearly defined. However:
    </div>
    <div>
        <div style="font-size:13.3333330154419px;line-height:21.3333320617676px;margin-top:12pt;margin-bottom:12pt;border-style:solid;border-width:1px">
            <p style="font-size:12pt;margin:0px;padding-left:6pt;background-color:rgb(204,221,170)">
                Example
            </p>
            <pre style="margin-top:0px;margin-bottom:0px;padding:3px;font-family:Courier New;width:715px;max-height:500px;overflow:auto">
                x + 1 &lt;- 0;
            </pre>
        </div>
        <div style="font-size:13.3333330154419px;line-height:21.3333320617676px">
            The above example is contrived, but provides a simple segue to constraint based programming. When this statement is executed the value -1 is stored in 
            <code>
                x
            </code>
            . Substituting -1 for x yields
            <code>
                (-1) + 1 = 0
            </code>
            .
        </div>
    </div>
    <div style="font-size:13.3333330154419px;line-height:21.3333320617676px">
        <br>
        </br>
    </div>
    <div style="font-size:13.3333330154419px;line-height:21.3333320617676px">
        <span style="font-size:13.3333px;line-height:21.3333px">
            See: 
        </span>
        <a style="font-size:13.3333px;line-height:21.3333px" href="../operators.php">
            Operators
        </a>
    </div>



		<?php require('../../footer.php') ?>
	</body>
</html>