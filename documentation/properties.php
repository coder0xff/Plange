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
			<pre>temp_fahrenheit ← 70;</pre>
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
	degrees = radians / Math.pi * 180;
};

Angle right;
right.degrees ← 90;
print(right.radians); //prints 1.5707963268</pre>
		</div>
		
		<p>Each time a value is read from or written to a property additional processing occurs. Under-constrained properties are read only:</p>
		
		<div class="code">
			<p>Example</p>
			<pre>Rectangle := type {
	&lt;Real&gt; left;
	&lt;Real&gt; top;
	&lt;Real&gt; width;
	&lt;Real&gt; height;
	right = left + width; //read only property
	bottom = top + height; //read only property
};</pre>
		</div>
		
		
		<p>The examples above represent the first class of properties, pure properties, which are modeled as relations. The second class, imperative properties, are built from get and set accessors, which resemble functions:</p>
		<div class="code">
			<p>Example</p>
			<pre>&lt;String&gt; saved_username := { 
	get := { return File.read_text("username.txt"); }, 
	set := { File.write_text("username.txt", value); }
};</pre>
		</div>
		<p>Each time an imperative property is accessed (read from or written to) control passes to the get or set accessor functions (respectively) rather than accessing a memory location. Access is transparent to the calling program.<sup>†</sup> Get and set accessors execute within their defining execution context. The space within the outermost curly braces { } also permits the definition of additional symbols, such as hidden value storage or helper functions which are not accessible from outside the property's scope. The presence of the get or set keywords in a statement scope causes that scope to be interpreted as a property.</p>
		<div class="code">
			<p>Example</p>
			<pre>&lt;Double&gt; clamped := {
	&lt;Double&gt; v;
	get := { return v; }
	set := { v ← value &lt; 0 ? 0 : value &gt; 1 ? 1 : value; }
};</pre>
		</div>

		<p>† dependency injection (and other late binding) is limited when the target binary is stripped. This may be considered a security feature and/or a design flaw.</p>

		<?php require('../footer.php') ?>
	</body>
</html>