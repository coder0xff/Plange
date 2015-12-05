<meta charset='utf-8'/>
<html>
	<head>
		<title>Plange</title>
		<link rel=StyleSheet href='css/general.css' type='text/css' />
	</head>
	<body>
		<?php require('header.php') ?>


		<div style="padding:1em;font-size:1.6em">
			Plange (plaːnd͡ʒ) is a project to create a revolutionary
			development environment, including a programming language,
			standard library, and runtime.
		</div>
		<p>See the <a href="goals/">Goals</a> page for a high-level overview.</p>

		<h1>Introduction & Tutorial</h1>
		<p>Plange began as a list of features and ideas. Existing languages were used as inspiration for this list - their successes and also their failings. Creating a language that picks and chooses the best features of many successful languages, integrates them, and has an expansive and robust runtime and standard library is an ambitious undertaking. Nonetheless, this is the goal for Plange.</p>

		<p>A recurring trend in programming language development has been to focus on a small set of problems that other languages don’t currently address well, and design the language, its runtime, and its standard library with those few goals in mind. This drives not only the noticeable differences in syntax, but often different features in the standard library of the language, and in features of the language itself. Some examples:</p>
		<ul>
			<li>C# makes object lifetime management a non issue, but precludes any possibility of cooperative multithreading.</li>
			<li>Perl is a scripting language that’s great at string manipulation, but isn’t suitable for low level systems programming.</li>
			<li>Cuda is a powerful parallel processing tool, but isn’t practical for database access.</li>
		</ul>

		<p>C++ and Java are excellent general purpose languages, but have begun to show their age. Features are added, but they will forever remain in the same generation of languages to which they were born. Most languages’ capabilities can be expanded through creating new libraries, or even inter-operating with libraries written in other languages. For many common cases, however, this approach lacks the straight forward integration that one might find by working in another language. As a result, fragmentation of the global software ecosystem runs deep. From a practical standpoint, developers eventually discover the limits of their chosen development language, and find themselves locked in, or forced to use an additional language. They may migrate entirely (or in rare cases fix it themselves). Plange represents an effort to aggregate current technologies into an accessible yet powerful package, while anticipating its own incompleteness.</p>

		<h2>Hello World</h2>
		<p>It is traditional to start with the "Hello world" program.</p>
		<div class="code">
			<pre>print("Hello, world!");</pre>
		</div>

		<p>Statements are terminated by a semicolon. Comments are created using two syntactic variations:</p>
		<div class="code">
			<p>End of line comment (red is comment text)</p>
			<pre>print("My name is HAL 9000."); <span style="color: red">//only kidding!</span></pre>
		</div>
		<div class="code">
			<p>Inline comment (red is comment text) <small><small><small><a href="https://www.xkcd.com/221/">source</a></small></small></small></p>
			<pre>getRandomNumber := { return 4; <span style="color: red">/*choosen by fair dice roll*/</span> }; <span style="color: red">//guaranteed to be random</span></pre>
		</div>

		<h2>Constants and Variables</h2>
		<p>When a value is given a symbol to identify it, that symbol is a constant.</p>

		<div class="code">
				<p>Example</p>
				<pre>print(π); //print pi</pre>
		</div>

		<p>The symbol <code>π</code> is an identifier for the pi constant. It can be substituted in places where pi is needed, and provides arbitrarily high precision.</p>
		
		<p><span style="color: red">IMPORTANT!</span> As you've probably noticed, there's no π key on your keyboard. The plange editor will change "<code> pi </code>" (must have the spaces, but not the quotes) into π. It's just a <a href="http://www.fileformat.info/info/unicode/char/03c0/index.htm">UTF character</a>. If your editor of choice doesn't auto-replace "<code> pi </code>", that's ok too. The interpreter will know what you mean if you just write "<code>pi</code>".</p>

		<p>Constants are created using the definition operator <code>:=</code></p>
		<div class="code">
			<p>Example</p>
			<pre>daysInAWeek := 7;</pre>
		</div>
		<p>Variables are symbols which hold a value that can change.</p>
		<div class="code">
			<p>Example</p>
			<pre>color ← "Blue";
print(color);
color ← "Red";
print(color);</pre>
		</div>

		<p>The <code>←</code> character is typed <code>" <- "</code>. The above program outputs the following text:</p>

		<div class="code">
			<p>Output</p>
			<pre>Blue
Red</pre>
		</div>

		<h2>Types</h2>
		<p>Constants and variables can be constrained to a specific type.</p>

		<div class="code">
			<p>Example</p>
			<pre>&lt;Int&gt; x ← 10;
x ← 1.5; // error - can't assign a fractional Number to an integer</pre>
		</div>

		<p>"Int" is shorthand for <a href="https://en.wikipedia.org/wiki/Integer">integer</a>. The first line constrains x to be an <code>Int</code>, which means it cannot be assigned a number with a decimal point. The second line demonstrates this restriction. See <a href="documentation/type-system.php">Type System</a>.</p>

		<h2>Functions</h2>
		<p>Create function types using the <code>→</code> operator, or <code>-&gt;</code>.</p>

		<div class="code">
			<p>Example</p>
			<pre>&lt;Int → Int&gt; doubler;</pre>
		</div>

		<p>The above code defines a new symbol <code>doubler</code>, which has a type of <code>Int → Int</code>. Simply, doubler is a function that takes an Int as an input, and returns an Int as a result.</p>

		<p>Create function implementations using parenthesis <code>( )</code> containing the parameter list, followed by curly braces <code>{ }</code> containing the implementation.</p>

		<div class="code">
			<p>Example (continued)</p>
			<pre>&lt;Int → Int&gt; doubler := (&lt;Int&gt; x) { return x * 2; };</pre>
		</div>

		<p>The parameters consist of the single constant <code>x</code>, and the implementation multiplies it by two and returns the value.</p>

		<div class="code">
			<p>Example (continued)</p>
			<pre>&lt;Int → Int&gt; doubler := (&lt;Int&gt; x) { return x * 2; };
print(doubler(5)); //test it out</pre>
		</div>

		<div class="code">
			<p>Output</p>
			<pre>10</pre>
		</div>

		<p>Functions can have more than one parameter.</p>
		<div class="code">
			<p>Example</p>
			<pre>&lt;Real * Real → Real&gt; geometric_mean := (&lt;Real&gt; x, &lt;Real&gt; y) { return (x * y)^(0.5); };</pre>
		</div>

		<p>See also:<a href="/documentation/standard-library/Function.php">Plange.Function</a>

		<h2>Pattern Matching</h2>
		<p>From functional programming, a recursive function to print the last element of a list:</p>

		<div class="code">
			<p>Example</p>
			<pre>&lt;List&lt;_&gt; → Void&gt; printLast := 
	(_ &amp; tail) { printLast(tail); } |
	(x) { print(x); };

myList := [ 5, 12, 8, 9 ];
printLast(myList);</pre>
		</div>

		<div class="code">
			<p>Output</p>
			<pre>9</pre>
		</div>

		<p>Note the use of the underscore <code>_</code> character. It is substituted for a symbol (a named constant) when the code does not care about its value. In the first line of the example above, we are unconcerned with the type of the elements the input list contains, and only need to ensure that the input is a list of something. In the second line, we don't need to know the value of the head element. The underscore keyword is called <a href="documentation/keywords/dont_care.php">dont_care</a>.</p>

		<p>This example also uses the prepend operator <code>&</code> which is similar to Haskell's "cons operator," the colon :, but is the ampersand to avoid confusion with other syntax (See: <a href="/documentation/syntax/prepend.php">prepend</a>). In the example above, it's working in reverse as pattern matching. That is, the first parameter to the function is being broken apart into two pieces.</p>

		<h2>Type Deduction</h2>
		<p>When the type of a constant or variable can be deduced, it is often possible to omit it.</p>
		<div class="code">
			<p>Example</p>
			<pre>&lt;&gt; name ← "Snippet"; // name is deduced to be a String</pre>
		</div>

		<p>Modifying a previous example:</p>
		<div class="code">
			<p>Example</p>
			<pre>&lt;&gt; doubler ← (x) { return x * 2; };
print(doubler(5));</pre>
		</div>

		<p>In definitions of constants, and declarations and assignments of variables, the angle brackets &lt; &gt; may be omitted entirely.</p>
		<div class="code">
				<p>Example</p>
				<pre>doubler := (x) { return x * 2; };
print(doubler(5));</pre>
		</div>

 		<p>When defining a constant like above, no special meaning is implied. However, variables that have no specified type constraint are dynamically typed.</p>
		<div class="code">
			<p>Example</p>
			<pre>x ← 10;
x ← "Alice";
x ← { print("fubar"); };</pre>
		</div>

		<p>Type deduction is not limited to only simple cases. The following code defines a function <code>get_return_type</code> which takes another function <code>func</code> as its only parameter, and then returns the Type that func returns!</p>
		<div class="code">
			<p>Demonstration of more complex type deduction via pattern matching</p>
			<pre>get_return_type := ( &lt;_ → x&gt; func ) { return x; };
addFive := (&lt;Int&gt; x) { return x + 5; };
print(get_return_type(addFive));  // output: Int</pre>
		</div>

		<a href="#Type_Constraints">More on this later</a>. 

		<h2>Types</h2>
		<p>The <a href="/documentation/keywords/type.php"><code>type</code></a> (not capitalized) keyword is used to make a new <a href="/documentation/standard-library/type.php"><code>Type</code></a> (capitalized) object. </p>
		<div class="code">
			<p>Example</p>
			<pre>Color := type {
	&lt;Double&gt; r;
	&lt;Double&gt; g;
	&lt;Double&gt; b;
};

&lt;Color&gt; red ← (1, 0, 0);

print(type_of( (1, 0, 0) ));  // output: Tuple&lt;Number, Number, Number&gt;
print(type_of(red));          // output: Color
print(type_of(Color));        // output: Type</pre>
		</div>

		<h2>Type Functions</h2>
		<p>Type functions, or parametric types are functions that return Type objects.</p>
		<div class="code">
			<p>Example</p>
			<pre>Node := (&lt;Type&gt; valueType) {
	return type {
		&lt;valueType&gt; v;
		Pointer&lt;Node&gt; next;
	};
};</pre>
		</div>

		<p>Functions that return Type objects (<a href="/documentation/syntax/invocation.php">or another type function</a>) can be called with the angle bracket syntax:</p>
		<div class="code">
			<p>Example</p>
			<pre>&lt;Node&lt;Int&gt;&gt; myNode;</pre>
		</div>

		<h2>Polymorphism</h2>
		<p>The <a href="documentation/keywords/inheriting.php">inheriting</a> keyword, used in conjunction with the type keyword, makes a new Type object that inherits the members of the specified base Types. See also: <a href="documentation/keywords/implementing.php">implementing</a></p>
		<div class="code">
			<p>Example</p>
			<pre>// base Type
Widget := type {
	&lt;Void → Image&gt; Paint;
};

// derived Type
TextBox := type inheriting Widget {
	&lt;String&gt; text ← "Hello, world!";

	// override the inherited Paint method
	Paint ← {
		return Drawing.Render(text)
	};
};</pre>
		</div>
		<h2>Algebraic Types</h2>
		<p>Types can be combined together to make algebraic Types using the | operator.</p>
		<div class="code">
			<p>Example</p>
			<pre>Some := (t) { return type { &lt;t&gt; value; } };
None := type {};
Maybe := (t) { return Some&lt;t&gt; | None; };

&lt;Void → Maybe&lt;Int&gt;&gt; get_age := {
	return coerce(input("What's your age? You don't have to tell me."));
};

print(get_age);</pre>
		</div>

		<h2>Constraint solving</h2>
		<p>Many interesting problems may be constructed as one or more assertions regarding the relationships of values, using operators (arithmetic, set theoric, quantifiers, etc), and invocations such as calling the sin() function.</p>

		<div class="code">
			<p>Example</p>
<pre>children := {| abe, dan, mary, sue |};
ages := {| 3, 5, 6, 9 |};
children ↔ ages; // One child per one age (bijection operator)

abe > dan; //abe is older than dan
sue < mary; //sue is younger than mary
sue = dan + 3; //sue's age is dan's age plus 3 years
mary > abe; //mary is older than abe</pre>
		</div>

		<p>This code is semantically equivalent to the following:</p>

		<div class="code">
			<p>Example (continued)</p>
			<pre>abe = 5;
dan = 3;
mary = 9;
sue = 6;</pre>
		</div>

		<p>One well studied domain is <a href="https://en.wikipedia.org/wiki/Initial_value_problem">initial value problems</a>. If partial differential equations aren't your cup of tea, just read the comments.</p>

		<div class="code">
			<p>Example</p>
			<pre>advanceProjectilePosition :=
	(Vector3D initialPos, Vector3D initialVel, mass, drag, Vector3D gravity, delta_t)
{
	&lt;Real → Vector3&gt; p;                              // declare the position function, p
	mass * p''(t) = -drag * p'(t) + mass * gravity;  // model p as a differential equation
	p(0) = initialPos;                               // with boundary conditions
	p'(0) = initialVel;
	return p(delta_t);                               // solve, substitute, evaluate
};</pre>
		</div>

		<p>A closed form solution for p is determined symbollically, such that the following program is functionally equivalent.</p>
		<div class="code">
			<p>Example (continued)</p>
			<pre>advanceProjectilePosition := 
	(Vector3D initialPos, Vector3D initialVel, mass, drag, Vector3D gravity, delta_t)
{
	//closed form solution determined automatically
	a := 𝑒^(drag*t/mass);
	return (
		gravity * (mass-(mass*a + drag*delta_t)) + 
		initialPos*a*drag^2 + 
		drag*mass*initialVel*(a-1)
	) / (a*drag^2);
};</pre>
		</div>

		<h2>Type Constraints</h2><a name="Type_Constraints" />
		<p>Since types are values, and values can be constrained, type constraints are realised.</p>

		<div class="code">
			<p>Example</p>
			<pre>all := (Collection&lt;X&gt; items) {
	Bool casts X; //values of type X must be castable to type Bool
	result ← true;
	for (item ∈ items) {
		if (¬(Bool)item) {
			result ← false;
			break;
		}
	}
	return result;
};</pre>
		</div>


		<?php require('footer.php') ?>
	</body>
</html>