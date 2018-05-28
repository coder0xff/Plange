<meta charset='utf-8'/>
<meta name="viewport" content="width=device-width, initial-scale=0.6">
<html>
	<head>
		<title>Syntax Listing - Plange</title>
		<link rel=StyleSheet href='../css/general.css' type='text/css' />
	</head>
	<body>
		<?php require('../header.php') ?>


		<?php
			ini_set('display_errors', 'On');
			ini_set('display_startup_errors', 1);
			error_reporting(E_ALL);

			if (array_key_exists("name", $_GET)) {
				?>
				<?php
				exec("PYTHONIOENCODING=UTF-8 ./syntax-cgi.py " . $_GET["name"] . " 2>&1", $output, $error);
			} else {
				?>
					<p>This page is generated from the <a href='/source/syntax.yml'>syntax specification</a>. Tags, identities, and all {IC} (optional whitespace and comment regions) are filtered from the syntax display to improve readability. See the specification for the full grammar specification. The root production of the grammar is "STATEMENT_SCOPE".</p>
					<h2>Subpage Listing</h2>
				<?php
				exec("PYTHONIOENCODING=UTF-8 ./syntax-cgi.py 2>&1", $output, $error);
			}
			print(implode("\n", $output));
		?>

		<?php require('../footer.php') ?>
	</body>
</html>