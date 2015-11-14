<meta charset='utf-8'/>
<html>
	<head>
		<title>break - Plange</title>
		<link rel=StyleSheet href='../../css/general.css' type='text/css' />
	</head>
	<body>
		<?php require('../../header.php') ?>


 a
    <a href="do.php">
        do
    </a>
    ,
    <a href="../syntax/loop.php">
        while, until
    </a>
    ,
    <a href="for.php">
        for
    </a>
    or
    <a href="../syntax/for_collection.php">
        for_collection
    </a>
     loop
    <div>
        <br>
        </br>
    </div>
    <div>
        Example:
    </div>
    <div>
    </div>
    <div class="sites-codeblock sites-codesnippet-block">
        <div>
            <code>
                //echo the users input until they enter nothing
            </code>
        </div>
        <div>
            <code>
                do {
            </code>
        </div>
        <div>
            <span>
                <code>
                        &lt;String&gt; x := input();
                </code>
            </span>
            <br>
            </br>
        </div>
        <div>
            <span>
                <span>
                    <code>
                            if (x = "") {
                    </code>
                </span>
                <br>
                </br>
            </span>
        </div>
        <div>
            <span>
                <span>
                    <span>
                        <code>
                                
                        </code>
                        <span>
                            <code>
                                    break;
                            </code>
                        </span>
                    </span>
                    <br>
                    </br>
                </span>
            </span>
        </div>
        <div>
            <span>
                <span>
                    <span>
                        <span>
                            <span>
                                <code>
                                        }
                                </code>
                            </span>
                            <br>
                            </br>
                        </span>
                    </span>
                </span>
            </span>
        </div>
        <div>
            <span>
                <span>
                    <span>
                        <span>
                            <span>
                                <span>
                                    <code>
                                            print(x);
                                    </code>
                                </span>
                                <br>
                                </br>
                            </span>
                        </span>
                    </span>
                </span>
            </span>
        </div>
        <div>
            <code>
                }
            </code>
        </div>
    </div>



		<?php require('../../footer.php') ?>
	</body>
</html>