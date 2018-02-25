<meta charset='utf-8'/>
<meta name="viewport" content="width=device-width, initial-scale=0.6">
<html>
	<head>
		<meta name="google-site-verification" content="OKvej4xSIY4zxFPd7v6mor2L0hzDXUJaV2gzl5rKYJY" />
		<title>Plange</title>
		<link rel=StyleSheet href='css/general.css' type='text/css' />
		<link rel="icon" type="image/png" href="/plange_favicon.png" />
	</head>
	<body>
		<?php require('header.php') ?>


		<div style="padding:1em;font-size:1.6em">
			Plange is an open-source project to create a development environment including a programming language, standard library, and runtime.
		</div>
		<ul>
			<li>license: <a href="https://tldrlegal.com/license/bsd-3-clause-license-(revised)#fulltext">New BSD</a></li>
			<li>source code: <a href="https://github.com/coder0xff/Plange">git repository</a></li>
			<li>status: pre-alpha</li>
			<li>monetization: compute resources and pro support</li>
			<li>pronunciation:
				plænd͡ʒ
				[<a href="http://www.internationalphoneticalphabet.org/ipa-sounds/ipa-chart-with-sounds/">ipa</a>]
			</li>
		</ul>
		<hr>
		
		
		
		<h1>Introduction</h1>
		<p>Plange is an algebra of constraints on data, functions, variables, types, and other objects. It is traditional to start with the <u>Hello World</u> program.</p>
		
		<div class="code2">
			<pre>
print("Hello, world!");
			</pre>
		</div>

		<p>Comments are created using two syntactic variations.</p>
		
		<div class="code2">
			<p>End of line comment (red is comment text)</p>
			<pre>
print("My name is HAL 9000."); <span style="color: red">//only kidding!</span>
			</pre>
		</div>
		
		<div class="code2">
			<p>Inline comment (red is comment text) <small><small><small><a href="https://www.xkcd.com/221/">source</a></small></small></small></p>
			<pre>
getRandomNumber := { return 4; <span style="color: red">/*choosen by fair dice roll*/</span> }; <span style="color: red">//guaranteed to be random</span>
			</pre>
		</div>
		
		
		
		<h2>Special Characters</h2>
		<p>Several Unicode characters are included for completeness, but cannot be typed using a keyboard. These characters have typable equivalents for convenience. For example <code>⇒</code> may be typed <code>=></code>. Unicode characters will be used in documentation. A partial list can be find on the <a href="/documentation/operators.php">Operators</a> page.</p>
		
		
		<h2>Variables</h2>
		<p>A variable is a symbol that may take place in a constraint system, be free or bound, and may have memory allocated to it. Constraints on variables define a problem space for which solutions are desired. A variable can also contain data and be changed at will by the programmer.</p>
		<div class="code2">
			<p>Assign a value to a variable</p>
			<pre>
x ← 1337;
			</pre>
		</div>

		<p>Variables can be reassigned.</p>
		<div class="code2">
			<p>Reassign a variable</p>
			<pre>
color ← "Blue";
color ← "Red";
			</pre>
		</div>

		<p>A variable may be constrained to a type.</p>

		<div class="code2">
			<p>Type constrain a variable</p>
			<pre>
&lt;Number&gt; x ← 1337;
			</pre>
		</div>

		<p>Unbound variables can be targets for symbolic or numerical solutions.</p>

		<div class="code2">
			<p>Symbolic manipulation</p>
			<pre>
x = 1337;
tan(y*2) = x;
print y; // arctan(1337) / 2 = { 1.570048, -1.571544 };
			</pre>
		</div>
		


		<h2>Constants</h2>
		<p>A symbol with a value that is immutable is a constant.</p>

		<div class="code2">
			<p>Example</p>
			<pre>
print(π); //print pi
			</pre>
		</div>

		<p>The symbol <code>π</code> is an identifier for the pi constant. It can be substituted in places where pi is needed, and provides arbitrarily high precision. It may be typed <code>pi</code>.</p>
		
		<p>Constants are created using the definition operator <code>:=</code></p>
		<div class="code2">
			<p>Example</p>
			<pre>
daysInAWeek := 7;
			</pre>
		</div>



		<h2>Functions</h2>
				<p>Create function implementations using parenthesis <code>( )</code> containing the parameter list, followed by curly braces <code>{ }</code> containing the implementation.</p>

		<div class="code2">
			<p>Example</p>
			<pre>
doubler := (x) { return x * 2; };
			</pre>
		</div>

		<p>The parameters consist of the single constant <code>x</code>, and the implementation multiplies it by two and returns the value. Functions can have more than one parameter.</p>
		<div class="code2">
			<p>Example</p>
			<pre>
geometric_mean := (x, y) { return √(x * y); };
			</pre>
		</div>



		<h2>Types</h2>
		<p>Constants and variables can be constrained to a specific type.</p>

		
		<div class="code2">
			<p>Example</p>
			<pre>
&lt;Int&gt; x ← 10;
x ← 1.5; // error - can't assign a fractional Number to an integer
			</pre>
		</div>

		<p>"Int" is shorthand for <a href="https://en.wikipedia.org/wiki/Integer">integer</a>. The first line constrains x to be an <code>Int</code>, which means it cannot be assigned a number with a decimal point. The second line demonstrates this restriction. See <a href="documentation/type-system.php">Type System</a>.</p>

		<h3>Functions Types</h3>
		<p>Create function types using the <code>→</code> operator, or <code>-&gt;</code>.</p>

		<div class="code2">
			<p>Example</p>
			<pre>
&lt;Int → Int&gt; doubler = (x) { return x * 2; };
			</pre>
		</div>

		<p>The above code constraints <code>doubler</code> to the function type <code>Int → Int</code>. Simply, doubler is a function takes an Int as an input, and returns an Int as a result. Function arguments can also be type constrained.</p>

		<div class="code2">
			<p>Example (continued)</p>
			<pre>
&lt;Int → Int&gt; doubler := (&lt;Int&gt; x) { return x * 2; };
			</pre>
		</div>


 		<p>Variables that have no specified type constraint are dynamically typed.</p>
 		
		<div class="code2">
			<p>Assigning objects of varied type to a variable</p>
			<pre>
x ← 10;
x ← "Alice";
x ← { print("fubar"); };
			</pre>
		</div>

		<h3>Making Types</h3>
		<p>The <a href="/documentation/keywords/type.php"><code>type</code></a> (not capitalized) keyword is used to make a new <a href="/documentation/standard-library/Type.php"><code>Type</code></a> (capitalized) object. </p>
		<div class="code2">
			<p>Example</p>
			<pre>
Color := type {
	&lt;Double&gt; r;
	&lt;Double&gt; g;
	&lt;Double&gt; b;
};

&lt;Color&gt; red ← (| 1, 0, 0 |);

print(type_of( (| 1, 0, 0 |) ));  // output: Tuple&lt;Number, Number, Number&gt;
print(type_of(red));          // output: Color
print(type_of(Color));        // output: Type
print(type_of(Type));         // output: Type
			</pre>
		</div>




		<h2>Parametric Types</h2>
		<p>Parametric types are functions that return Type objects.</p>
		<div class="code2">
			<p>Example</p>
			<pre>
Node := (&lt;Type&gt; valueType) {
	return type {
		&lt;valueType&gt; v;
		Maybe&lt;Node&lt;valueType&gt;&gt; next;
	};
};
			</pre>
		</div>

		<p>Constant folding evaluates most invocations of type functions at compile time. Functions that return Type objects (<a href="/documentation/syntax/INVOCATION.php">or another type function</a>) can be called with the angle bracket syntax:</p>
		<div class="code2">
			<p>Example</p>
			<pre>
&lt;List&lt;Int&gt;&gt; myList;
			</pre>
		</div>
		



		<h2>Pattern Matching</h2>
		<p>A recursive function to print the last element of a list:</p>

		<div class="code2">
			<p>Example</p>
			<pre>
&lt;List&lt;_&gt; → Void&gt; printLast := 
	(_ &amp; tail) { printLast(tail); } |
	(x) { print(x); };

myList := [ 5, 12, 8, 9 ];
printLast(myList);
			</pre>
		</div>

		<div class="code2">
			<p>Output</p>
			<pre>
9
			</pre>
		</div>

		<p>The prepend operator <code>&</code> takes a value on the left, a list on the right, and produces a new list with the left prepended to the right. In the example above, the first parameter to the function is being broken apart into two pieces.</p>

		<p>Note the use of the underscore <code>_</code> character. It's substituted for a variable when the code doesn't care about the value. In the first line of the example above, we are unconcerned with the type of the elements the input list contains, and only need to ensure that the input is a list of something. In the second line, we don't need to know the value of the head element. The underscore keyword is called <a href="documentation/keywords/dont_care.php">dont_care</a>.</p>


	
	
		<h2>Polymorphism</h2>
		<p>The <a href="documentation/keywords/inheriting.php">inheriting</a> keyword, used in conjunction with the type keyword, makes a new Type object inheriting the members of the specified base Types. See also: <a href="documentation/keywords/implementing.php">implementing</a></p>
		<div class="code2">
			<p>Example</p>
			<pre>
// base Type
Widget := type {
	&lt;Void → Image&gt; Paint;
};

// derived Type
TextBox := type inheriting Widget {
	&lt;String&gt; text ← "Hello, world!";

	// override the inherited Paint method
	Paint ← {
		return Drawing.Render(text);
	};
};
			</pre>
		</div>
		
		
		
		
		<h2>Algebraic Types</h2>
		<p>Types can be combined together to make algebraic Types using the compound operator <code>|</code>.</p>
		<div class="code2">
			<p>Example</p>
			<pre>
Some := (t) { return type { &lt;t&gt; value; }; };
None := type {};
Maybe := (t) { return Some&lt;t&gt; | None };

&lt;Void → Maybe&lt;Int&gt;&gt; get_age := {
	return coerce(input("What's your age? You don't have to tell me."));
};

print(get_age());
			</pre>
		</div>

		
		
		
		<h2>Constraint solving</h2>
		<p>Many interesting problems may be constructed as one or more constraints, using operators (arithmetic, set theoric, quantifiers, etc), and invocations such as calling the sin() function. Constant folding and satisfiability solving yield equality constraints upon termination. Symbolic manipulation is very limited, unfortunately. Even attempts at numeric methods are intractible in general. Instead, an algebra is a component that operates given an expression in the canonical form, which is again in general left to the programmer. A computer algebra system such as Risch integration is a pass on the source code, which has a bounded running time. Generally, there's no guaranteed completion.</p>

		<div class="code2">
			<p>Example</p>
			<pre>
children := {| abe, dan, mary, sue |};
ages := {| 3, 5, 6, 9 |};
children ↔ ages; // One child per one age (bijection operator)

abe > dan; //abe is older than dan
sue < mary; //sue is younger than mary
sue = dan + 3; //sue's age is dan's age plus 3 years
mary > abe; //mary is older than abe
			</pre>
		</div>

		<p>This code is semantically equivalent to the following:</p>

		<div class="code2">
			<p>Example (continued)</p>
			<pre>
abe = 5;
dan = 3;
mary = 9;
sue = 6;
			</pre>
		</div>

		<p>One well studied domain is <a href="https://en.wikipedia.org/wiki/Initial_value_problem">initial value problems</a>. An ordinary differential equation is given with boundary conditions on free variables:</p>

		<div class="code2">
			<p>Example: Aerodynamic Drag On A Projectile</p>
			<pre>
projectilePosition := (
		&lt;Vector3D&gt; initialPos,
		&lt;Vector3D&gt; initialVel,
		&lt;Real&gt; mass,
		&lt;Real&gt; drag,
		&lt;Vector3D&gt; gravity,
		&lt;Real&gt; t
) {
	// declare the position function, x
	&lt;Real → Vector3&gt; x;
	
	// model x as a differential equation
	mass * Δ^2x(t)/Δt^2 = -drag * Δx(t)/Δt + mass * gravity;
	
	// with boundary conditions
	x(0) = initialPos;
	Δx(0)/Δt = initialVel;
	
	// solve, substitute, evaluate
	return x(delta_t);
};
			</pre>
		</div>

		<p>ODE solving gives a symbolic solution for x such that the following program is functionally equivalent. This constant folding is performed and cached at compile time. This result was computed manually for demonstrative purposes.</p>
		<div class="code2">
			<p>Example (continued)</p>
			<pre>
projectilePosition := (
		&lt;Vector3D&gt; initialPos,
		&lt;Vector3D&gt; initialVel,
		&lt;Real&gt; mass,
		&lt;Real&gt; drag,
		&lt;Vector3D&gt; gravity,
		&lt;Real&gt; t
) {
	a := 𝑒^(drag*t/mass);
	return (
			gravity * (mass-(mass*a + drag*t)) + 
			initialPos*a*drag^2 + 
			drag*mass*initialVel*(a-1)
		) / (a*drag^2);
};
			</pre>
		</div>

		<a name="property_based_testing" />
		<div class="code2">
			<p>Example</p>
			<pre>
&lt;Number * Number * Number → Number&gt; linear_interpolation :=
	(min, max, x) { min * (1 - x) + max * x }
;
			
inverted_linear_interpolation := (min, max, interpolated) { 
	interpolated = linear_interpolation(min, max, x); //x is a free variable
	return x;
}

assert(x = inverted_linear_interpolation(y, z, linear_interpolation(y, z, x));
			</pre>
		</div>

		<h3>Limitations</h3>
		<p>Constraint solving is intractible in the general case. Users must familiarize themselves with the capabilities of the language, which are expected to expand. A demonstration of a semantically correct but nonfunctional program is in order.</p>

		<div class="code2">
			<p>Counter Example</p>
			<pre>
&lt;Collection * BinaryRelation → Collection&gt; sort := (items, ordering) {
	result ↔ items; // result and items make a bijection
	∀ { ordering(result[i - 1], result[i]) | i ∈ (0...|result|) }; //the result has to be sorted
	return result; // solve, substitute, and return
};
			</pre>
		</div>
		<p>The above function, sort, is functionaly equivalent to the sorting functions. However, this constraint based problem is not yet solvable using available techniques.</p>

		<h2>Type Constraints</h2><a name="Type_Constraints" />
		<p>Since types are values, and values can be constrained, type constraints are realised.</p>

		<div class="code2">
			<p>Example</p>
			<pre>
all := (Collection&lt;X&gt; items) {
	Bool casts typeof(X); //values of type X must be castable to type Bool
	
	for (item ∈ items) {
		if (¬(Bool)item) {
			return false;
		};
	};
	return true;
};
			</pre>
		</div>

		</div>
		<h2>Further reading</h2>
		<ul>
			<li><a href="/documentation/syntax/IF.php">if (syntax)</a></li>
			<li><a href="/documentation/syntax/FOR.php">for (syntax)</a></li>
			<li><a href="/documentation/syntax/STATEMENT_SCOPE.php">statement_scope (syntax)</a></li>
			<li><a href="/documentation/operators.php">operators</a></li>
		</ul>

		<?php require('footer.php') ?>
	</body>
</html>