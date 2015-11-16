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
		<p>The abstract keyword is used to declare interfaces that will be implemented by derived types</p>
		<div class="code">
			<p>Example</p>
			<pre>//Base type
Animal := type {
	&lt;Void -&gt; Void&gt; speak &lt;- abstract; //there is no default implementation
};

//Derived type
Cat := type inheriting Animal {
	speak &lt;- { Meow(); }; //override the inherited speak method
};

&lt;List&lt;Animal&gt; -&gt; Void&gt; choir := (animals) {    
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