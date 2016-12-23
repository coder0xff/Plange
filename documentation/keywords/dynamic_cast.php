<meta charset='utf-8'/>
<meta name="viewport" content="width=device-width, initial-scale=0.6">
<html>
	<head>
		<title>dynamic_cast - Plange</title>
		<link rel=StyleSheet href='../../css/general.css' type='text/css' />
	</head>
	<body>
		<?php require('../../header.php') ?>


		<p>convert the specified pointer from a type A, to a type B, if B inherits A. Otherwise, the result is a null pointer.</p>
		<div class="code2">
			<pre>
&lt;Type&gt; Mammal = class { };

&lt;Type&gt; Dog = type inheriting Mammal {
	&lt;Void → Void&gt; bark;
};

&lt;Type&gt; Cat = type inheriting Mammal {
	&lt;Void → Void&gt; meow;
};

&lt;Mammal → Void&gt; speak := (x) {
	Dog dog := dynamic_cast&lt;Dog&gt;(x);
	if (dog != null) {
		dog.bark();
	}
	Cat cat := dynamic_cast&lt;Cat&gt;(x);
	if (cat != null) {
		cat.meow();
	}
};
			</pre>
		</div>


		<?php require('../../footer.php') ?>
	</body>
</html>