<meta charset='utf-8'/>
<html>
	<head>
		<title>static - Plange</title>
		<link rel=StyleSheet href='../../css/general.css' type='text/css' />
	</head>
	<body>
		<?php require('../../header.php') ?>


		<p>in type_scope, indicates that a member function, field, or property is not an instance member, but one that becomes part of the type object itself</p>
		<div class="code">
			<p>Example</p>
			<pre>&lt;Type&gt; Dog := type {
	&lt;String&gt; name;
	&lt;Date&gt; birth_date;
	static &lt;String&gt; binomial_nomenclature := "Canis Familiaris";
};</pre>
		</div>


		<?php require('../../footer.php') ?>
	</body>
</html>