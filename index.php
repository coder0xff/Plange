<meta charset='utf-8'/><html><head><title>Plange</title><link rel=StyleSheet href='css/general.css' type='text/css' /></head><body><?php require('header.php') ?>
    <div style="padding:1em;font-size:1.6em">
      Plange (plaːnd͡ʒ) is a project to create a revolutionary
      development environment, including a programming language,
      standard library, and runtime.
    </div>
    <p>
    This site is far from complete, but the <a href="goals/">Goals</a>
      page has a good amount of information that you may find interesting. Use the
      navigation bar to the left to browse the site. The <a href="documentation">Documentation</a>
      pages are the technical
      specifications and reference materials.</p>
    <h2>Introduction</h2>
    <p>Plange began as a list of features and ideas. Existing
      languages were used as inspiration for this list - their
      successes and also their failings.</p>
    <p>Creating a language that
      picks and chooses the best features of many successful
      languages, integrates them, and has an expansive and robust
      runtime and standard library is an ambitious undertaking.
      Nonetheless, this is the goal for Plange.</p>
    <p>A recurring trend in programming language development has
      been to focus on a small set of problems that other languages
      don’t currently address well, and design the language, its
      runtime, and its standard library with those few goals in mind.
      This drives not only the noticeable differences in syntax, but
      often different features in the standard library of the
      language, and in features of the language itself. Some examples:</p>
    <ul>
        <li>C# makes object lifetime management a non issue, but
          precludes any possibility of cooperative multithreading.</li>
        <li>Perl is a scripting language that’s great at string
          manipulation, but isn’t suitable for low level systems
          programming.</li>
        <li>Cuda is a powerful parallel processing tool, but isn’t
          practical for database access.</li>
    </ul>
    <p>C++ and Java are excellent general purpose languages, but have
      begun to show their age. Features are added, but they will
      forever remain in the same generation of languages to which they
      were born.</p>
    <p>Most languages’ capabilities can be expanded through creating
      new libraries, or even inter-operating with libraries written in
      other languages. For many common cases, however, this approach
      lacks the straight forward integration that one might find by
      working in another language. As a result, fragmentation of the
      global software ecosystem runs deep. From a practical
      standpoint, developers eventually discover the limits of their
      chosen development language, and find themselves locked in, or
      forced to use an additional language. They may migrate entirely
      (or in rare cases fix it themselves). Plange represents an
      effort to aggregate current technologies into an accessible yet
      powerful package, while anticipating its own incompleteness.</p>
    <h3>Hello World</h3>
    <p>It is traditional to start with the "Hello world" program:</p>
    <div class="code">
        <pre>print("Hello, world!");</pre>
    </div>
    <p>Statements are terminated by a semicolon. Comments are
        created using two syntactic variations:</p>
    <div class="code">
        <p>End of line comment (red is comment text)</p>
        <pre>print("My name is HAL 9000."); <font color="#ff0000">//only kidding!</font></pre>
    </div>
    <div class="code">
        <p>Inline comments (red is comment text) <small><small><small><a href="https://www.xkcd.com/221/">source</a></small></small></small></p>
        <pre>getRandomNumber := { return 4; <font color="#ff0000">/*choosen by fair dice roll*/</font> }; <font color="#ff0000">//guaranteed to be random</font></pre>
    </div>
    <h3>Constants and Variables</h3>
    <p>When a value is given a symbol to identify it, that symbol
      is a constant.
    </p>
    <div class="code">
        <p>Example</p>
        <pre>print(π); //print pi</pre>
    </div>
    <p>The symbol <code>π</code> is an identifier for the pi
      constant. It can be substituted in places where pi is needed, and
      provides arbitrarily high precision.</p>
    <p>Constants are created using the definition operator <code>:=</code></p>
    <div class="code">
        <p>Example</p>
        <pre>daysInAWeek := 7;</pre>
    </div>
    <p>Variables are symbols which hold a value that can change.</p>
    <div class="code">
        <p>Example</p>
        <pre>color &lt;- "Blue";
print(color);
color &lt;- "Red";
print(color);</pre>
    </div>
    <p>The above program outputs the following text:</p>
    <div class="code">
        <p>Output</p>
        <pre>Blue
Red</pre>
    </div>
    <h3>Types</h3>
    <p>Constants and variables can be constrained to a specific type.</p>
    <div class="code">
        <p>Example</p>
        <pre>&lt;Int&gt; x &lt;- 10;
x &lt;- 1.5; // error - can't assign a fractional Number to an integer</pre>
    </div>
    <p>
        See <a href="documentation/using-types.php">Type System</a>.</p>
    <h3>Functions</h3>
    <p>Create function types using the <code>-&gt;</code> operator.
      Create function implementations using parenthesis <code>( )</code>
      containing the parameter list, followed by curly braces <code>{ }</code>
      containing the implementation.</p>
    <div class="code">
        <p>Example</p>
        <pre>&lt;Int -&gt; Int&gt; doubler := (&lt;Int&gt; x) { return x * 2; };
print(doubler(5));</pre>
    </div>
    <div class="code">
        <p>Output</p>
        <pre>10</pre>
    </div>
    <p>Functions can have more than one parameter.</p>
    <div class="code">
        <p>Example</p>
        <pre>&lt;Real * Real -&gt; Real&gt; geometric_mean := (&lt;Real&gt; x, &lt;Real&gt; y) { return (x * y)^(0.5); };</pre>
    </div>
    <h3>Pattern Matching</h3>
    <p>From functional programming, a recursive function to print
    the last element of a list:</p>
    <div class="code">
        <p>Example</p>
        <pre>&lt;List&lt;_&gt; -&gt; Void&gt; printLast := 
    (_:tail) { printLast(tail); } |
    (x) { print(x); };

myList := [ 5, 12, 8, 9 ];
printLast(myList);</pre>
    </div>
    <div class="code">
        <p>Output</p>
        <pre>9</pre>
    </div>
    Note the use of the underscore <code>_</code> character. It is
      substituted for a symbol (a named constant) when the code does not
      care about its value. In the first line of the example above, we
      are unconcerned with the type of the elements the input list
      contains, and only need to ensure that the input is a list of
      something. In the second line, we don't need to know the value of
      the head element. The underscore keyword is called
        <a href="documentation/keywords/dontcare.php">dont_care</a>.
    <h3>Type Deduction</h3>
    <p>
        When the type of a constant or variable can be deduced, it
is often possible to omit it.
    </p>
    <div class="code">
        <p>Example</p>
        <pre>&lt;&gt; name := "Snippet"; // name is deduced to be a String</pre>
    </div>
    <p>
        Modifying a previous example:
    </p>
    <div class="code">
        <p>Example</p>
        <pre>&lt;&gt; doubler := (x) { return x * 2; };
print(doubler(5));</pre>
    </div>
    <p>In definitions of constants, and declarations and
      assignments of variables, the angle brackets &lt; &gt; may be
      omitted entirely.</p>
    <div class="code">
        <p>Example</p>
        <pre>doubler := (x) { return x * 2; };
print(doubler(5));</pre>
    </div>
    <p>Type deduction is not limited to only simple cases.</p>
    <div class="code">
        <p>Demonstration of more complex type deduction via pattern matching</p>
        <pre>return_type_getter := ( &lt;_ -&gt; x&gt; func ) { return x; };
addFive := (&lt;Int&gt; x) { return x + 5; };
print(return_type_getter(addFive));  // output: Int</pre>
    </div>
    <h3>Types</h3>
    <p>
        The <a href="documentation/keywords/type.php"><code>type</code></a>
        (not capitalized) keyword is used to make a new
        <a href="documentation/standard-library/type.php"><code>Type</code></a>
        (capitalized) object.
    </p>
    <div class="code">
        <p>Example</p>
        <pre>Color := type {
    &lt;Double&gt; r;
    &lt;Double&gt; g;
    &lt;Double&gt; b;
};

&lt;Color&gt; red &lt;- (1, 0, 0);

print(type_of( (1, 0, 0) ));  // output: Tuple&lt;Number, Number, Number&gt;
print(type_of(red));          // output: Color
print(type_of(Color));        // output: Type</pre>
    </div>
    <h3>Type Functions</h3>
    <p>Type functions, or parametric types are functions that return Type objects.</p>
    <div class="code">
        <p>Example</p>
        <pre>Node := (&lt;Type&gt; valueType) { 
    &lt;valueType&gt; v;
    Pointer&lt;Node&gt; next;
}</pre>
    </div>
    <p>Functions that return Type objects can be called with the
      angle bracket syntax:</p>
    <div class="code">
        <p>Example</p>
        <pre>&lt;Node&lt;Int&gt;&gt; myNode;</pre>
    </div>
    <h3>Polymorphism</h3>
    <p>The <a href="documentation/keywords/inheriting.php">inheriting</a>
      keyword, used in conjunction with the type
      keyword, makes a new Type object that inherits the members of
      the specified base Types. See also:
        <a href="documentation/keywords/implementing.php">implementing</a></p>
    <div class="code">
        <p>Example</p>
        <pre>// base Type
Widget := type {
    &lt;Void -&gt; Image&gt; Paint;
};

// derived Type
TextBox := type inheriting Widget {
    &lt;String&gt; text &lt;- "Hello, world!";

    // override the inherited Paint method
    Paint &lt;- {
        return Drawing.Render(text)
    };
};</pre>
    </div>
    <h3>Algebraic Types</h3>
    <p>Types can be combined together to make algebraic Types using the |
      operator.</p>
    <div class="code">
        <p>
            Example
        </p>
        <pre>Some := (t) { return type { &lt;t&gt; value; } };
None := type {};
Maybe := (t) { return Some&lt;t&gt; | None; };

&lt;Void -&gt; Maybe&lt;Int&gt;&gt; get_age := {
    return coerce(input("What's your age? You don't have to tell me."));
}

print(get_age);</pre>
    </div>

<?php require('footer.php') ?></body></html>