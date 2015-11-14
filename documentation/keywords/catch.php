<meta charset='utf-8'/>
<html>
	<head>
		<title>catch - Plange</title>
		<link rel=StyleSheet href='../../css/general.css' type='text/css' />
	</head>
	<body>
		<?php require('../../header.php') ?>


 any exceptions thrown within the preceding try block
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
                try {
            </code>
        </div>
        <div>
            <span>
                <code>
                        open("test.txt");
                </code>
            </span>
            <br>
            </br>
        </div>
        <div>
            <span>
                <code>
                    } catch (File.NotFoundException) {
                </code>
            </span>
        </div>
        <div>
            <span>
                <span>
                    <code>
                        <span>
                                print
                        </span>
                        ("test.txt was not found in the working directory);
                    </code>
                </span>
                <br>
                </br>
            </span>
        </div>
        <div>
            <span>
                <code>
                    } finally {
                    <br>
                    </br>
                </code>
            </span>
        </div>
        <div>
            <span>
                <code>
                    <span>
                           
                    </span>
                    <span>
                        // todo: cleanup    
                    </span>
                    <span>
                           
                    </span>
                    <br>
                    </br>
                </code>
            </span>
        </div>
        <div>
            <span>
                <code>
                    }
                    <br>
                    </br>
                </code>
            </span>
        </div>
    </div>
    <div>
        <br>
        </br>
    </div>
    <div>
        See: 
        <a href="try.php">
            try
        </a>
         
        <a href="finally.php">
            finally
        </a>
         See also:
        <a href="../syntax/try.php">
            try (syntax)
        </a>
    </div>



		<?php require('../../footer.php') ?>
	</body>
</html>