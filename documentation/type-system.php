<meta charset='utf-8'/>
<meta name="viewport" content="width=device-width, initial-scale=0.6">
<html>
	<head>
		<title>Type System - Plange</title>
		<link rel=StyleSheet href='../css/general.css' type='text/css' />
	</head>
	<body>
		<?php require('../header.php') ?>
		
		
		<p>Types are used to constrain the structure and behavior (class invariant) of the values that a variable can be assigned, or that a constant can be defined as. The type system, being based on the culmination of many feature sets, is necessarily complex. However, by simply working in a familiar paradigm - among imperative, functional, or constraint based and among static typing, late binding, or duck typing - the type system applies the appropriate constraints and compile-time analyses.</p>
		
		<p>Here, we declare x as a variable that can store an integer, and assign the value 10.</p>

		<div class="code">
			<p>declare and assign a variable</p>
			<pre>&lt;Int&gt; x ← 10;</pre>
		</div>

		<div class="code">
			<p>error caused by contradicting the invariant</p>
			<pre>&lt;Int&gt; x ← 10;
<b>x ← 1.5; //error - can't assign a fractional number to an integer</b></pre>
		</div>

		<p>To use a type in the declaration of a variable or in the definition of a constant, the type must be enclosed by angle brackets <code>&lt; &gt;</code> (see <a href="/documentation/syntax/TYPE_DEREFERENCE.php">TYPE_DEREFERENCE</a>).</p>

		<div class="code">
			<p>Example</p>
			<pre>&lt;Int&gt; x;
print(type_of(x).name);         //prints "Int"
print(type_of(Int).name);       //prints "Type"
print(type_of(Type).name);      //prints "Type"</pre>
		</div>

		<p>Types can be elided in many cases, and can be used to create unquantified generic functions.</p>
		
		<div class="code">
			<p>Example</p>
			<pre>identity := (value) { return value; };</pre>
		</div>

		<h2>Type Constructors</h2>
		<p>Functions may construct and return Type objects. These functions may be <a href="/documentation/syntax/TYPE_INVOCATION.php">invoked using the angle-bracket syntax</a>. Further, any function that returns an angle-bracket invokable function may also be angle-bracket invoked.</p>
		
		<div class="code">
			<p>Example</p>
			<pre>&lt;Type * Int → Type&gt; Vector := (T, s) { return T^s; };  // Vector is a function that return a Type.
Float32x3 := Vector&lt;Float32, 3&gt;;                       // type def and a function call

&lt;Float32x3&gt; aVectorVariable;                           // make a variable
&lt;Vector&lt;Float32, 3&gt;&gt; anotherVectorVariable;            // same type as previous line
&lt;type_of(aVectorVariable)&gt; yetAnotherVectorVariable;   // contrived but doable</pre>
		</div>

		<p>Despite the function-like definition, simple constructs (e.g. Vector from above) are recognized as parametric types and benefit from the generic features involving variance and deduction.</p>

		<h3>Notes</h3>
		<p>The angle-bracket syntax is not required, since parenthesis can be used also. The convention is to use the angle-bracket syntax when the intent is use as a parametric type (see <a href="/documentation/syntax/INVOCATION.php">INVOCATION</a>).</p>

		<h2>Type inference</h2>
		<p>Type inference, a feature of static typing, extends beyond inference of elided types in "obvious" scenarios, instead using all logical tools available (specifically constraint propogation and constant folding) for deduction. Type checking benefits from the same sophistication. Consider the following:</p>

		<div class="code">
			<p>Example</p>
			<pre>getParamCount := (&lt;Function&lt;types, retType&gt;&gt; f) {
	&lt;List&lt;Type&gt;&gt; types;
	return types.length;
};</pre>
		</div>

		<p><code>types</code> is never defined or assigned to, and is therefore unbound, but must be a List of Types. Upon attempting to evaluate <code>types.length</code>, a value for <code>types</code> is computed. An example of implicitly quantified generic programming:</p>
		
		<div class="code">
			<p>Example</p>
			<pre>&lt;(X * X → X) → Type&gt; binary_op_type := (&lt;X * X → X&gt; f) { return X; } </pre>
		</div>

		<p><code>X</code> is unbound, so may take on any type.</p>
		
		<h2>Covariance and Contravariance</h2>
		<p>The inheritance graph and variance properties are modeled and can be tested programmatically.</p>

		<h3>Covariance</h3>
		
		<div class="code">
			<p>Example</p>
			<pre>Animal := type {
	&lt;Void → Void&gt; speak &lt;- abstract;
};

Cat := type implementing Animal {
	&lt;Void → Void&gt; speak &lt;- { Meow(); };
};

&lt;List&lt;Animal&gt; → Void&gt; choir := (animals) {
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
                       .,,uod8B8bou,,.
              ..,uod8BBBBBBBBBBBBBBBBRPFT?l!i:.
         ,=m8BBBBBBBBBBBBBBBRPFT?!||||||||||||||
         !...:!TVBBBRPFT||||||||||!!^^""'   ||||
         !.......:!?|||||!!^^""'            ||||
         !.........||||                     ||||
         !.........||||  #                  ||||
         !.........||||                     ||||
         !.........||||                     ||||
         !.........||||                     ||||
         !.........||||                     ||||
         `.........||||                    ,||||
          .;.......||||               _.-!!|||||
   .,uodWBBBBb.....||||       _.-!!|||||||||!:'
!YBBBBBBBBBBBBBBb..!|||:..-!!|||||||!iof68BBBBBb....
!..YBBBBBBBBBBBBBBb!!||||||||!iof68BBBBBBRPFT?!::   `.
!....YBBBBBBBBBBBBBBbaaitf68BBBBBBRPFT?!:::::::::     `.
!......YBBBBBBBBBBBBBBBBBBBRPFT?!::::::;:!^"`;:::       `.
!........YBBBBBBBBBBRPFT?!::::::::::^''...::::::;         iBBbo.
`..........YBRPFT?!::::::::::::::::::::::::;iof68bo.      WBBBBbo.
  `..........:::::::::::::::::::::::;iof688888888888b.     `YBBBP^'
    `........::::::::::::::::;iof688888888888888888888b.     `
      `......:::::::::;iof688888888888888888888888888888b.
        `....:::;iof688888888888888888888888888888888899fT!
          `..::!8888888888888888888888888888888899fT|!^"'
            `' !!988888888888888888888888899fT|!^"'
                `!!8888888888888888899fT|!^"'
                  `!988888888899fT|!^"'
                    `!9899fT|!^"'
                      `!^"'
""";
};</pre>
		</div>

		<h2>Algebraic Types</h2>

		<p>Types may be combined with the or | operator to create a new type thats instances must be any one of those types. This operator is associative.<p>

		<div class="code">
			<p>Example</p>
			<pre>InteriorNode := type { &lt;Int&gt; value; <LinkedListNode> next; };
TerminalNode := type { &lt;Int&gt; value; };
LinkedListNode := InteriorNode | TerminalNode</pre>
		</div>

		<p>Further, algebraic types are not limited to simple switching. Like all algebraic values, they may be defined through a system of constraints.</p>

		<?php require('../footer.php') ?>
	</body>
</html>