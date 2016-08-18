<meta charset='utf-8'/>
<meta name="viewport" content="width=device-width, initial-scale=0.6">
<html>
	<head>
		<title>FUNCTION_MODIFIER - Syntax Pages - Plange</title>
		<link rel=StyleSheet href='../../css/general.css' type='text/css' />
	</head>
	<body>
		<?php require('../../header.php') ?>


		<p>The FUNCTION_MODIFIER_* rules model: ["stable" | "unstable"] ["no_throw"] ["atomic"] {PLATFORM} ["pure"|"imperative"|"opaque"] with the caveat that there has to be an IC between any modifier and the next (if there is a next)</p>

		<div class="syntax">
			<p>syntax</p>
			<div>(<a href="/documentation/syntax/FUNCTION_MODIFIER_STABILITY.php">FUNCTION_MODIFIER_STABILITY</a>|<a href="/documentation/syntax/FUNCTION_MODIFIER_NO_THROW.php">FUNCTION_MODIFIER_NO_THROW</a>|<a href="/documentation/syntax/FUNCTION_MODIFIER_ATOMIC.php">FUNCTION_MODIFIER_ATOMIC</a>|<a href="/documentation/syntax/FUNCTION_MODIFIER_PLATFORM.php">FUNCTION_MODIFIER_PLATFORM</a>|<a href="/documentation/syntax/FUNCTION_MODIFIER_MODEL.php">FUNCTION_MODIFIER_MODEL</a>) {<a href="/documentation/syntax/IC.php">IC</a>}</div>
		</div>



		<?php require('../../footer.php') ?>
	</body>
</html>