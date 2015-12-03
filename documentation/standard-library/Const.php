<meta charset='utf-8'/>
<html>
	<head>
		<title>Const - Plange</title>
		<link rel=StyleSheet href='../../css/general.css' type='text/css' />
	</head>
	<body>
		<?php require('../../header.php') ?>


		<p>returns a new type wrapping the specified type so that no fields/properties may be written/set and only functions that do not alter state may be called, which includes all pure functions</p>

		<h2>Notes</h2>
		<p>The returned type also provides an implicit cast back to the non-wrapped (non const) type, iff the wrapped type can be value copied. Due to the limitations of static analysis, violations of Const correctness may not be detected until runtime. Warnings are generated during compile time if static analysis was inconclusive.</p>


		<?php require('../../footer.php') ?>
	</body>
</html>