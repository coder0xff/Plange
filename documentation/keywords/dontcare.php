<meta charset='utf-8'/>
<html>
	<head>
		<title>_ (dont_care) - Plange</title>
		<link rel=StyleSheet href='../../css/general.css' type='text/css' />
	</head>
	<body>
		<?php require('../../header.php') ?>


nderscore character '_', or "don't care" keyword is a place holder for an identifier, when the name of that identifier is irrelevant.
    <br>
    </br>
    <div style="margin-top:12pt;margin-bottom:12pt;border-style:solid;border-width:1px">
        <p style="font-size:12pt;margin:0px;padding-left:6pt;background-color:rgb(204,221,170)">
            Example
        </p>
        <pre style="margin:0px;padding:3px;font-family:Courier New;width:715px;max-height:500px;overflow:auto">
            (_, y) := myVector; //extract the y coordinate of a vector, ignoring the x coordinate
            <br>
            </br>
        </pre>
    </div>
    <h4>
        <a name="TOC-Notes">
        </a>
        Notes
    </h4>
    This keyword has important properties that separates it from
    <a href="../../system/errors/NodeNotFound2e12.php?suri=wuid:gx:72ab6458122efce1" class="disabled">
        identifiers
    </a>
    .
    <div>
        <ul>
            <li>
                <span style="line-height:1.6;font-size:10pt;background-color:transparent">
                    <span style="font-size:13.3333330154419px;line-height:21.3333320617676px">
                        It is not possible to retrieve a value from _.
                    </span>
                </span>
            </li>
            <li>
                <span style="line-height:1.6;font-size:10pt;background-color:transparent">
                    Any constraints placed on _ are discarded.
                </span>
            </li>
        </ul>
        <div>
            <br>
            </br>
        </div>
    </div>



		<?php require('../../footer.php') ?>
	</body>
</html>