<meta charset='utf-8'/>
<meta name="viewport" content="width=device-width, initial-scale=0.6">
<html>
	<head>
		<title>Syntax Listing - Plange</title>
		<link rel=StyleSheet href='../css/general.css' type='text/css' />
	</head>
	<body>
		<?php require('../header.php') ?>


		<p>The root production of the grammar is "STATEMENT_SCOPE".</p>
		<h2>Subpage Listing</h2>
		<ul>

            <?php
                $files = array_diff(scandir("./syntax"), array('.', '..'));
                
                foreach ($files as $index => $file) {
                    if (substr($file, -4) === ".php") {
                        echo "<li><a href='/documentation/syntax/" . $file . "'>" . substr($file, 0, -4) . "</a></li>";
                    }
                }
            ?>

        </ul>
		<?php require('../footer.php') ?>
	</body>
</html>