<meta charset='utf-8'/>
<html>
	<head>
		<title>embedded_string - Plange</title>
		<link rel=StyleSheet href='../../css/general.css' type='text/css' />
	</head>
	<body>
		<?php require('../../header.php') ?>


style="margin-top:12pt;margin-bottom:12pt;border-style:solid;border-width:1px">
        <p style="font-size:12pt;margin:0px;padding-left:6pt;background-color:#cda">
            syntax
        </p>
        <pre style="margin:0px;padding:3px;font-family:Courier New;width:715px;max-height:500px;overflow-x:auto;overflow-y:auto">
            "\"\"\"" non_double_quote "\"\"\"" | "\"" stacked_string "\""
        </pre>
    </div>
    <div>
        <h4>
            <a name="TOC-Notes">
            </a>
            Notes
        </h4>
        <div>
            <span style="line-height:1.6;font-size:10pt;background-color:transparent">
                An embedded_string is similar to a regular string literal of the form:
            </span>
        </div>
        <div>
            <br>
            </br>
            <div class="sites-codeblock sites-codesnippet-block">
                <code>
                    "hello world"
                </code>
            </div>
        </div>
        <div>
            <br>
            </br>
        </div>
        except that it permits the text to contain any finite number of double quotes. An embedded_string begins with three or more double quotes, and ends with the same number of double quotes. All white spaces, characters, and other bytes between the opening and closing delimiter becomes a string value when accessed in Plange.
    </div>
    <div>
        <div style="font-size:13.3333330154419px;line-height:21.3333320617676px;margin-top:12pt;margin-bottom:12pt;border-style:solid;border-width:1px">
            <p style="font-size:12pt;margin:0px;padding-left:6pt;background-color:rgb(204,221,170)">
                Example
            </p>
            <pre style="margin-top:0px;margin-bottom:0px;padding:3px;font-family:Courier New;width:715px;max-height:500px;overflow:auto">
                stringWithDoubleQuotes := """""
The remainder of this is a string literal, excluding the five quotes at the very end.
We can use four double quotes, like """", but not 5 which is the number of quotes that
start this string literal. If a string literal with 100 consecutive double quotes in it
were desired, we would then use 101 double quotes to start and end the string literal.
            </pre>
            <pre style="margin-top:0px;margin-bottom:0px;padding:3px;font-family:Courier New;width:715px;max-height:500px;overflow:auto">
                """""
            </pre>
        </div>
    </div>
    <div>
        <br>
        </br>
    </div>
    See:
    <a href="../quote-comment-embedding.php">
        Quote Stacking, Comment Stacking
    </a>
    <br>
    </br>



		<?php require('../../footer.php') ?>
	</body>
</html>