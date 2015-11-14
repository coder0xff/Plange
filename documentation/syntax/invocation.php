<meta charset='utf-8'/>
<html>
	<head>
		<title>invocation - Plange</title>
		<link rel=StyleSheet href='../../css/general.css' type='text/css' />
	</head>
	<body>
		<?php require('../../header.php') ?>


es the specified function, passing in the parameters specified between the parenthesis, or between angle brackets for parametric types and parametric functions, or between square brackets when all parameters belong to sets that are ordered and denumerable
    <div>
        <div style="font-size:13.3333330154419px;line-height:21.3333320617676px;margin-top:12pt;margin-bottom:12pt;border-style:solid;border-width:1px">
            <p style="font-size:12pt;margin:0px;padding-left:6pt;background-color:rgb(204,221,170)">
                Syntax
            </p>
            <pre style="margin-top:0px;margin-bottom:0px;padding:3px;font-family:Courier New;width:715px;max-height:500px;overflow:auto">
                <a href="expression.php">
                    expression
                </a>
                (
    ( "(" [
                <a style="font-size:13.3333330154419px;line-height:21.3333320617676px;background-color:transparent" href="expression.php">
                    expression
                </a>
                <span style="font-size:13.3333330154419px;line-height:21.3333320617676px;background-color:transparent">
                    [","
                </span>
                <a style="font-size:13.3333330154419px;line-height:21.3333320617676px;background-color:transparent" href="expression.php">
                    expression
                </a>
                <span style="font-size:13.3333330154419px;line-height:21.3333320617676px;background-color:transparent">
                    ]* ] ")" ) |
                </span>
                <span style="font-size:13.3333330154419px;line-height:21.3333320617676px;background-color:transparent">
                     
                </span>
                <span style="font-size:13.3333330154419px;line-height:21.3333320617676px;background-color:transparent">
                    ( "&lt;" [
                </span>
                <a style="font-size:13.3333330154419px;line-height:21.3333320617676px;background-color:transparent" href="expression.php">
                    expression
                </a>
                <span style="font-size:13.3333330154419px;line-height:21.3333320617676px;background-color:transparent">
                    [","
                </span>
                <a style="font-size:13.3333330154419px;line-height:21.3333320617676px;background-color:transparent" href="expression.php">
                    expression
                </a>
                <span style="font-size:13.3333330154419px;line-height:21.3333320617676px;background-color:transparent">
                    ]* ] "&gt;" )
                </span>
                <span style="font-size:13.3333330154419px;line-height:21.3333320617676px;background-color:transparent">
                    |
    ( "["
                </span>
                <span style="font-size:13.3333px;line-height:21.3333px;background-color:transparent">
                    [
                </span>
                <a style="font-size:13.3333px;line-height:21.3333px;background-color:transparent" href="expression.php">
                    expression
                </a>
                <span style="font-size:13.3333px;line-height:21.3333px;background-color:transparent">
                    [","
                </span>
                <a style="font-size:13.3333px;line-height:21.3333px;background-color:transparent" href="expression.php">
                    expression
                </a>
                <span style="font-size:13.3333px;line-height:21.3333px;background-color:transparent">
                    ]* ] "]" )
                </span>
                <span style="font-size:13.3333px;line-height:21.3333px;background-color:transparent">
                    )
                </span>
            </pre>
        </div>
        <div>
            <span style="font-size:13.3333px;line-height:21.3333px">
                <br>
                </br>
            </span>
        </div>
    </div>
    <div>
        <div style="font-size:13.3333330154419px;line-height:21.3333320617676px;margin-top:12pt;margin-bottom:12pt;border-style:solid;border-width:1px">
            <p style="font-size:12pt;margin:0px;padding-left:6pt;background-color:rgb(204,221,170)">
                Example
            </p>
            <pre style="margin-top:0px;margin-bottom:0px;padding:3px;font-family:Courier New;width:715px;max-height:500px;overflow:auto">
                myMethod(1, x^2, "hello\n", someThing)
            </pre>
        </div>
    </div>
    <div style="font-size:13.3333330154419px;line-height:21.3333320617676px">
        <div style="font-size:13.3333330154419px;line-height:21.3333320617676px;margin-top:12pt;margin-bottom:12pt;border-style:solid;border-width:1px">
            <p style="font-size:12pt;margin:0px;padding-left:6pt;background-color:rgb(204,221,170)">
                Example
            </p>
            <pre style="margin-top:0px;margin-bottom:0px;padding:3px;font-family:Courier New;width:715px;max-height:500px;overflow:auto">
                IntList := List&lt;int&gt;; //List is a type function, IntList is a Type
            </pre>
        </div>
    </div>
    <h4>
        <a name="TOC-Exampleprint-myArray-4-4-is-ordered-and-denumerable-myArray-implements-RandomlyAccessible">
        </a>
        <div style="font-size:13.3333px;line-height:21.3333px;margin-top:12pt;margin-bottom:12pt;border-style:solid;border-width:1px">
            <p style="font-size:12pt;margin:0px;padding-left:6pt;background-color:rgb(204,221,170)">
                Example
            </p>
            <pre style="margin-top:0px;margin-bottom:0px;padding:3px;font-family:Courier New;width:715px;max-height:500px;overflow:auto">
                print myArray[4]; //4 is ordered and denumerable, myArray implements RandomlyAccessible
            </pre>
        </div>
    </h4>
    <h4>
        <a name="TOC-Notes">
        </a>
        Notes
    </h4>
    <div>
        <span style="font-size:13.3333px;line-height:21.3333px">
            The &lt; &gt; syntactic variety requires the returned value to be a type (it must implement Type), or a function (it must implement Function) that when invoked results in such a type or function. Note that this definition is deliberately recursive. The [ ] syntactic variety requires that each given "indexer" is some element of an ordered and denumerable set, such as the natural numbers or enum values, and that the invokee is randomly accessible (implements RandomlyAccessible). Lastly, the angle bracket and square bracket syntax are optional; the behavior is identical to being invoked using parentheses. However, alternate syntax is encouraged whenever such requirements are met and helps to both document and enforce the invariants assumed by the author.
        </span>
    </div>



		<?php require('../../footer.php') ?>
	</body>
</html>