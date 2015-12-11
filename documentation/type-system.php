<meta charset='utf-8'/>
<html>
	<head>
		<title>Type System - Plange</title>
		<link rel=StyleSheet href='../css/general.css' type='text/css' />
	</head>
	<body>
		<?php require('../header.php') ?>


		<p>Types are used to define or constrain the structure and behavior (class invariant) of the values that a variable can be assigned, or that a constant can be defined as. Here, we declare x as a variable that can store an integer, and assign the value 10.</p>

		<div class="code">
			<p>declare and assign a variable</p>
			<pre>&lt;Int&gt; x ← 10;</pre>
		</div>

		<div class="code">
			<p>error caused by contradicting the type invariant</p>
			<pre>&lt;Int&gt; x ← 10;
<b>x ← 1.5; //error! can't assign a fractional number to an integer</b></pre>
		</div>

		<p>To use a type in the declaration of a variable or in the definition of a constant, the type must be enclosed by angle brackets < > (see <a href="/documentation/syntax/type_dereference.php">type_dereference</a>).</p>

		<div class="code">
			<p></p>
			<pre>print(type_of(x).name);         //prints "Int"
print(type_of(Int).name);       //prints "Type"
print(type_of(MyTypeDef).name); //prints "Type"
print(type_of(Type).name);      //prints "Type"</pre>
		</div>

		<h2>Parametric types</h2>
		<p>Functions may construct and return Type objects. Called <b>type functions</b>&nbsp;(also&nbsp;parametric type or generic type), they may be called using the angle-bracket invocation syntax:</p>
		
		<div class="code">
			<p>Example</p>
			<pre>&lt;Type * Int → Type&gt; Vector := (T, s) { return T^s; };  // Vector is a function
Foat32x3 := Vector&lt;Float32, 3&gt;;                        // type def and a function call

&lt;Float32x3&gt; aVectorVariable;                           // make a variable
&lt;Vector&lt;Float32, 3&gt;&gt; anotherVectorVariable;            // same type as previous line
&lt;type_of(aVectorVariable)&gt; yetAnotherVectorVariable;   // contrived but doable</pre>
		</div>

		<p>In the next example X is an unbound variable. The identity function returns any value it is passed while preserving type information.</p>
		<div class="code">
			<p>Example</p>
			<pre>&lt;X → X&gt; identity := (&ltX&gt value) { return value; }; //A constraint is built upon X and identity</pre>		
		</div>

		<p>Or with less verbosity, simply:</p>
		<div class="code">
			<p>Example</p>
			<pre>identity := (value) { return value; };</pre>
		</div>

		<h2>Notes</h2>
		<p>The angle-bracket syntax is not required, since parenthesis can be used also. The convention is to use the angle-bracket syntax when the intent is use as a generic type. See <a href="/documentation/syntax/invocation">invocation</a></p>

		<h2>Covariance and Contravariance</h2>
		<p>The inheritance graph is modeled and can be tested programmatically.</p>

		<h3>Covariance</h3>
		
		<div class="code">
			<p>Example</p>
			<pre>Animal := type {
	&lt;Void → Void&gt; speak &lt;- abstract;
};

Cat := type implementing Animal {
	&lt;Void → Void&gt; speak &lt;- { Meow(); };
};

&lt;List&lt;T&gt; → Void&gt; choir := (animals) {
	for (animal in animals) {
		animal.speak();
	}
};

&lt;Cat&gt; bernard;
&lt;Cat&gt; russel;
List&lt;Cat&gt; kittehs := [ bernard, russel ];
choir(kittehs);</pre>
		</div>

		<h3>Contravariance</h3>
		
		<div class="code">
			<p>Example</p>
			<pre>&lt;Animal → Void&gt; solo := (animal) { animal.speak(); } 
&lt;Cat → Void&gt; cat_solo = solo;</pre>
		</div>

		<h3>Covariant method arguments</h3>
		<p>Function overloads are ordered. The | operator, which is used to create function overloads, preserves the order of the elements (functions) and dispatches to the first overload that can accept the parameters.</p>

		<div class="code">
			<p>Example</p>
			<pre>&lt;Animal → Void&gt; solo :=
	(&lt;Cat&gt; _ ) { /* cats never do what you want */ } | // overload
	(animal) { animal.speak(); };</pre>
		</div>

		<p>Note that the semantics resemble pattern matching.</p>

		<h2>Partial Types</h2>

		<p>Types may be combined with the plus + operator to create a new type containing the elements from each. This operation is not associative, as the right hand side operator will override any elements from the left hand side.</p>

		<div class="code">
			<p>Example (part 1 of 2)</p>
			<pre>SomeThing := type {
	&lt;String&gt; data;
	print_data := { print(data); };
} + DataProvider;</pre>
			<p>(part 2 of 2)</p>
			<pre>DataProvider := type {
	&lt;String&gt; data := """
___.___    ~            _____________
\  \\  \   ,, ???      |        '\\\\\\
 \  \\  \ /&lt;   ?       |        ' ____|_
  --\//,- \_.  /_____  |        '||::::::
      o- /   \_/    '\ |        '||_____|
      | \ '   o       '________|_____|
      |  )-   #     &lt;  ___/____|___\___
      `_/'------------|    _    '  &lt;&lt;&lt;:|
          /________\| |_________'___o_o|
""";
};</pre>
		</div>

		<div class="code">
			<p>Pseudocode</p>
			<pre>List := type {Dynarray

			} + (<Type> T) { return type { }};
		</div>

		<h2>Algebraic Types</h2>

		<p>Types may be combined with the or | operator to create a new type thats instances must be any one of those types. This operator is associative.<p>

		<div class="code">
			<p>Example</p>
			<pre>LinkedListNode := type { <Int> value; <LinkedListNode> next; } | type { <Int> value; };</pre>
		</div>

		<p>Further, algebraic types are not limited to simple switching. Like all algebraic values, they may be defined through a system of constraints.</p>

		<div class="code">
			<p>Example</p>
			<pre>List<T>  
myVar <- "Hello!";
		</div>

		<?php require('../footer.php') ?>
	</body>
</html>