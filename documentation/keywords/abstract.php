<meta charset='utf-8'/>
<html>
	<head>
		<title>abstract - Plange</title>
		<link rel=StyleSheet href='../../css/general.css' type='text/css' />
	</head>
	<body>
		<?php require('../../header.php') ?>


		<p>a function object that can be cast to any function type, and throws when invoked</p>
		<h2>Notes</h2>
		<p>The abstract keyword is used to declare interfaces that will be implemented by derived types. This information is also used by the compiler to detect attempts to instantiate types with abstract members.</p>
		<div class="code">
			<p>Example</p>
			<pre>//Base type
Animal := type {
	&lt;Void → Void&gt; speak ← abstract; //there is no default implementation
};

//Derived type
Cat := type inheriting Animal {
	speak ← { Meow(); }; //override the inherited speak method
};

&lt;List&lt;Animal&gt; → Void&gt; choir := (animals) {    
	for (animal in animals) {
		animal.speak();
	}
};

&lt;Cat&gt; bernard;
&lt;Cat&gt; russel;
List&lt;Cat&gt; kittehs := [ bernard, russel ];
choir(kittehs); //covariant argument</pre>
		</div>


		<?php require('../../footer.php') ?>
	</body>
</html>