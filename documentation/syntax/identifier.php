<meta charset='utf-8'/>
<html>
	<head>
		<title>identifier - Plange</title>
		<link rel=StyleSheet href='../../css/general.css' type='text/css' />
	</head>
	<body>
		<?php require('../../header.php') ?>


        <p>text that uniquely identifies a constant or variable</p>
		<div class="syntax">
			<p>syntax</p>
			<div>(letter | "_") ( letter | number | "_")*</div>
        </div>

		<p>The first character must be a letter character. Note that the character groups "letter" and "number" are inclusive of many unicode characters.</p>
		
		<h2>Notes</h2>
		<p>The 'letter' and 'number' terminals include more than the conventional a-z, A-Z and 0-9. Specifically, all unicode codepoints in a letter or number category may be used in an identifier.</p>
		<p>Examples of valid identifiers:</p>
		<code>
			<ul>
				<li>x</li>
				<li>myVariable</li>
				<li>q4</li>
				<li>Employee</li>
				<li>print_line</li>
				<li>символ</li>
				<li>θ</li>
			</ul>
		</code>

		<p>Non examples:</p>
		<code>
			<ul>
				<li>1stValue</li>
			</ul>
		</code>
		<?php require('../../footer.php') ?>
	</body>
</html>