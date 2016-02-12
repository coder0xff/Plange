<meta charset='utf-8'/>
<html>
	<head>
		<title>dot_product - Plange</title>
		<link rel=StyleSheet href='../../css/general.css' type='text/css' />
	</head>
	<body>
		<?php require('../../header.php') ?>


		<div class="syntax">
			<p>syntax</p>
			<div><a href="expression.php">expression</a> ("⋅"|"_dot_") <a href="expression.php">expression</a></div>
		</div>
		<ul>
			<li>Int * Int → Int</li>

			<li>Int8 * Int8 → Int16</li>
			<li>Int16 * Int16 → Int32</li>
			<li>Int32 * Int32 → Int64</li>
			<li>Int64 * Int64 → Int128</li>
			<li>Int128 * Int128 → Int</li>

			<li>UInt8 * UInt8 → UInt16</li>
			<li>UInt16 * UInt16 → UInt32</li>
			<li>UInt32 * UInt32 → UInt64</li>
			<li>UInt64 * UInt64 → UInt128</li>
			<li>UInt128 * UInt128 → Int</li>

			<li>Int8 * UInt8 → Int16</li>
			<li>Int16 * UInt16 → Int32</li>
			<li>Int32 * UInt32 → Int64</li>
			<li>Int64 * UInt64 → Int128</li>
			<li>Int128 * UInt128 → Int</li>

			<li>UInt8 * Int8 → Int16</li>
			<li>UInt16 * Int16 → Int32</li>
			<li>UInt32 * Int32 → Int64</li>
			<li>UInt64 * Int64 → Int128</li>
			<li>UInt128 * Int128 → Int</li>

			<li>Real * Real → Real</li>
			<li>Complex * Complex → Complex</li>
			<li>Complex * Real → Complex</li>
			<li>Geometry.Vector3 * Geometry.Vector3 → Real</li>
		</ul>


		<?php require('../../footer.php') ?>
	</body>
</html>