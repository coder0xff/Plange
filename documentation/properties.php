<meta charset='utf-8'/>
<html>
	<head>
		<title>Properties - Plange</title>
		<link rel=StyleSheet href='../css/general.css' type='text/css' />
	</head>
	<body>
		<?php require('../header.php') ?>


		<p>A property is used like a variable.</p>
		<div class="code">
			<p>Example</p>
			<pre>temp_f ← 70;</pre>
		</div>
		<p>The meaning of this single statement changes when some additional code is prepended.</p>
		<div class="code">
			<p>Example</p>
			<pre>&lt;Real&gt; temp_celsius;
temp_fahrenheit = temp_celsius * 9/5 + 32; //make an equality constraint

temp_fahrenheit ← 70; //assigns 190/9 to temp_celsius;</pre>
		</div>
		<div class="code">
			<p>Example</p>
			<pre>Angle := type {
	&lt;Double&gt; radians;
	&lt;Double&gt; degrees = radians / Math.pi * 180;
};

Angle right;
right.degrees ← 90;
print(right.radians); //prints 1.5707963268</pre>
		</div>
		<p>Each time a value is read from or written to a property additional processing occurs. This example above is the first of the two varities of property: 1) A constraint that can be modeled as an invertible function, 2) Functions called accessors are used for each read and write; the get accessor and set accessor respectively, such as the following:</p>
		<div class="code">
			<p>Example</p>
			<pre>Property&lt;&lt;String&gt;&gt; saved_username := {| get := { return File.read_text("username.txt"); }
	set := { File.write_text("username.txt", value); }
};</pre>
		</div>
		<p>This is transparent to the program reading or writing the property.<sup>†</sup> Get and set accessors execute within their defining execution context. The space within the outermost curly braces { } also permits the definition of additional symbols, such as hidden value storage or helper functions.</p>
		<div class="code">
			<p>Example</p>
			<pre>&lt;Double&gt; clamped := {
	&lt;Double&gt; v;
	get { return v; }
	set { v ← value &lt; 0 ? 0 : value &gt; 1 ? 1 : value; }
};</pre>
		</div>

		<p style="border-style:solid;border-width:1px;padding:6pt">† dependency injection (and other late binding) is limited when the target binary is stripped. This may be considered a security feature and/or a design flaw.</p>


		<?php require('../footer.php') ?>
	</body>
</html>