<meta charset='utf-8'/><html><head><title>
    <span style="font-size:1.6em;line-height:1.6;background-color:transparent">
        Plange (plaːnd͡ʒ) is a project to create a revolutionary
      development environment, including a programming language,
      standard library, and runtime.
        <br>
        </br>
        <br>
        </br>
    </span>
    <font color="#2a2a2a" style="font-size:1.6em;line-height:1.6;background-color:transparent" face="Benton Sans, Helvetica, sans-serif">
        <span style="font-size:16px;line-height:26px">
        </span>
    </font>
    This site
    is far from complete, but the
    <a href="goals/">
        Goals
    </a>
    page has
    a good amount of information that you may find interesting. Use the
    navigation bar to the left to browse the site. The&nbsp;
    <a href="documentation">
        Documentation
    </a>
    pages are the technical
    specifications and reference materials.
    <font color="#2a2a2a" style="font-size:1.6em;line-height:1.6;background-color:transparent" face="Benton Sans, Helvetica, sans-serif">
        <span style="font-size:16px;line-height:26px">
        </span>
    </font>
    <div>
        <div>
            <h2>
                Introduction
                <br>
                </br>
            </h2>
            <span style="font-size:13.3333330154419px;line-height:21.3333320617676px">
                Plange began as a list of features and ideas. Existing
          languages were used as inspiration for this list - their
          successes and also their failings.&nbsp;
            </span>
            <span style="background-color:transparent">
                Creating a language that
          picks and chooses the best features of many successful
          languages, integrates them, and has an expansive and robust
          runtime and standard library is an ambitious undertaking.
          Nonetheless, this is the goal for Plange.
            </span>
        </div>
        <div>
            <br>
            </br>
            <br>
            </br>
        </div>
        <div>
            A recurring trend in programming language development has
        been to focus on a small set of problems that other languages
        don’t currently address well, and design the language, its
        runtime, and its standard library with those few goals in mind.
        This drives not only the noticeable differences in syntax, but
        often different features in the standard library of the
        language, and in features of the language itself. Some examples:
            <br>
            </br>
            <br>
            </br>
            <ul>
                <li>
                    C# makes object lifetime management a non issue, but
            precludes any possibility of cooperative multithreading.
                </li>
                <li>
                    Perl is a scripting language that’s great at string
            manipulation, but isn’t suitable for low level systems
            programming.
                </li>
                <li>
                    Cuda is a powerful parallel processing tool, but isn’t
            practical for database access.
                </li>
            </ul>
            C++ and Java are excellent general purpose languages, but have
        begun to show their age. Features are added, but they will
        forever remain in the same generation of languages to which they
        were born.
            <br>
            </br>
            <br>
            </br>
            <br>
            </br>
            <br>
            </br>
            Most languages’ capabilities can be expanded through creating
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
        powerful package, while anticipating its own incompleteness.
            <br>
            </br>
            <br>
            </br>
            <h3>
                <a name="TOC-Hello-World">
                </a>
                Hello World
            </h3>
            <div>
                It is traditional to start with the "Hello world" program:
            </div>
            <div>
                <span style="color:rgb(0,96,0);font-family:monospace;font-size:13.3333330154419px;line-height:13.3333320617676px;background-color:rgb(239,239,239)">
                </span>
            </div>
            <div style="margin-top:12pt;margin-bottom:12pt;border-style:solid;border-width:1px">
                <pre style="margin:0px;padding:3px;font-family:Courier New;width:715px;max-height:500px;overflow-x:auto;overflow-y:auto">
                    print("Hello, world!");
                </pre>
            </div>
            <div>
                <span style="line-height:1.6;font-size:10pt;background-color:transparent">
                    Statements are terminated by a semicolon. Comments are
            created using two syntactic variations:
                </span>
            </div>
        </div>
        <div style="margin-top:12pt;margin-bottom:12pt;border-style:solid;border-width:1px">
            <p style="font-size:12pt;margin:0px;padding-left:6pt;background-color:#cda">
                End of line comment (red is comment text)
            </p>
            <pre style="margin:0px;padding:3px;font-family:Courier New;width:715px;max-height:500px;overflow-x:auto;overflow-y:auto">
                print("My name is HAL 9000.");
                <font color="#ff0000">
                    //only kidding!
                </font>
            </pre>
        </div>
        <div style="margin-top:12pt;margin-bottom:12pt;border-style:solid;border-width:1px">
            <p style="font-size:12pt;margin:0px;padding-left:6pt;background-color:#cda">
                Inline comments (red is comment text)
            </p>
            <pre style="margin:0px;padding:3px;font-family:Courier New;width:715px;max-height:500px;overflow-x:auto;overflow-y:auto">
                <font color="#ff0000">
                    /* This function returns the time */
                </font>
                &lt;Void -&gt; Int
                <font color="#ff0000">
                    /*unix time*/
                </font>
                &gt; now;
            </pre>
        </div>
        <h3>
            <a name="TOC-Constants-and-Variables">
            </a>
            Constants and
        Variables
        </h3>
        <div>
            When a value is given a symbol to identify it, that symbol
        is a constant. For example:
        </div>
        <div style="margin-top:12pt;margin-bottom:12pt;border-style:solid;border-width:1px">
            <p style="font-size:12pt;margin:0px;padding-left:6pt;background-color:#cda">
                Example
            </p>
            <pre style="margin:0px;padding:3px;font-family:Courier New;width:715px;max-height:500px;overflow-x:auto;overflow-y:auto">
                print(π); //print pi
            </pre>
        </div>
        The symbol
        <code>
            π
        </code>
        is an identifier for the pi
      constant. It can be substituted in places where pi is needed, and
      provides arbitrarily high precision.&nbsp;
        <span style="line-height:1.6;font-size:10pt;background-color:transparent">
            Constants are created using the definition operator
        </span>
        <code style="line-height:1.6;font-size:10pt;background-color:transparent">
            :=
        </code>
        <div>
            <div style="font-size:13.3333330154419px;line-height:21.3333320617676px;margin-top:12pt;margin-bottom:12pt;border-style:solid;border-width:1px">
                <p style="font-size:12pt;margin:0px;padding-left:6pt;background-color:rgb(204,221,170)">
                    Example
                </p>
                <pre style="margin-top:0px;margin-bottom:0px;padding:3px;font-family:Courier New;width:715px;max-height:500px;overflow:auto">
                    daysInAWeek := 7;
                </pre>
            </div>
            <div style="font-size:13.3333330154419px;line-height:21.3333320617676px">
                <span style="line-height:1.6;font-size:10pt;background-color:transparent">
                    Variables are symbols which hold a value that can change.
                </span>
            </div>
        </div>
        <div style="margin-top:12pt;margin-bottom:12pt;border-style:solid;border-width:1px">
            <p style="font-size:12pt;margin:0px;padding-left:6pt;background-color:#cda">
                Example
            </p>
            <pre style="margin:0px;padding:3px;font-family:Courier New;width:715px;max-height:500px;overflow-x:auto;overflow-y:auto">
                color &lt;- "Blue";
print(color);
color &lt;- "Red";
print(color);
            </pre>
        </div>
        <div>
            The above program outputs the following text:
        </div>
        <div style="margin-top:12pt;margin-bottom:12pt;border-style:solid;border-width:1px">
            <p style="font-size:12pt;margin:0px;padding-left:6pt;background-color:#cda">
                Output
            </p>
            <pre style="margin:0px;padding:3px;font-family:Courier New;width:715px;max-height:500px;overflow-x:auto;overflow-y:auto">
                Blue
Red
            </pre>
        </div>
        <h3>
            <a name="TOC-Types">
            </a>
            Types
        </h3>
        <div>
            Constants and variables can be constrained to a specific
        type.
        </div>
        <div style="margin-top:12pt;margin-bottom:12pt;border-style:solid;border-width:1px">
            <p style="font-size:12pt;margin:0px;padding-left:6pt;background-color:#cda">
                Example
            </p>
            <pre style="margin:0px;padding:3px;font-family:Courier New;width:715px;max-height:500px;overflow-x:auto;overflow-y:auto">
                &lt;Int&gt; x &lt;- 10;
x &lt;- 1.5; // error - can't assign a fractional Number to an integer
            </pre>
        </div>
        <div>
            See
            <a href="documentation/using-types.php">
                Type System
            </a>
            .
        </div>
        <h3>
            <a name="TOC-Functions">
            </a>
            Functions
        </h3>
        <div>
            Create function types using the
            <code>
                -&gt;
            </code>
            operator. Create function implementations using parenthesis
            <code>
                ( )
            </code>
            containing the parameter list, followed by curly
        braces
            <code>
                { }
            </code>
            containing the implementation.
        </div>
        <div style="margin-top:12pt;margin-bottom:12pt;border-style:solid;border-width:1px">
            <p style="font-size:12pt;margin:0px;padding-left:6pt;background-color:#cda">
                Example
            </p>
            <pre style="margin:0px;padding:3px;font-family:Courier New;width:715px;max-height:500px;overflow-x:auto;overflow-y:auto">
                &lt;Int -&gt; Int&gt; doubler := (&lt;Int&gt; x) { return x * 2; };
print(doubler(5));
            </pre>
        </div>
        <div>
            <div style="font-size:13.3333330154419px;line-height:21.3333320617676px;margin-top:12pt;margin-bottom:12pt;border-style:solid;border-width:1px">
                <p style="font-size:12pt;margin:0px;padding-left:6pt;background-color:rgb(204,221,170)">
                    Output
                </p>
                <pre style="margin-top:0px;margin-bottom:0px;padding:3px;font-family:Courier New;width:715px;max-height:500px;overflow:auto">
                    10
                </pre>
            </div>
        </div>
        <h3>
            <a name="TOC-Functions-can-have-more-than-one-parameter.">
            </a>
            <span style="font-size:13.3333330154419px;line-height:21.3333320617676px">
                Functions can have more than one parameter.
            </span>
        </h3>
        <div>
            <div style="font-size:13.3333330154419px;line-height:21.3333320617676px;margin-top:12pt;margin-bottom:12pt;border-style:solid;border-width:1px">
                <p style="font-size:12pt;margin:0px;padding-left:6pt;background-color:rgb(204,221,170)">
                    Example
                </p>
                <pre style="margin-top:0px;margin-bottom:0px;padding:3px;font-family:Courier New;width:715px;max-height:500px;overflow:auto">
                    &lt;Real * Real -&gt; Real&gt; geometric_mean := (&lt;Real&gt; x, &lt;Real&gt; y) { return (x * y)^(0.5); };
                </pre>
            </div>
        </div>
        <h3>
            <a name="TOC-Pattern-Matching">
            </a>
            Pattern Matching
        </h3>
        <div>
            From functional programming, a recursive function to print
        the last element of a list:
        </div>
        <div>
            <div style="margin-top:12pt;margin-bottom:12pt;border-style:solid;border-width:1px">
                <p style="font-size:12pt;line-height:21.3333320617676px;margin:0px;padding-left:6pt;background-color:rgb(204,221,170)">
                    Example
                </p>
                <pre style="margin-top:0px;margin-bottom:0px;padding:3px;width:715px;max-height:500px;overflow:auto">
                    <font face="Courier New">
                        &lt;List&lt;_&gt; -&gt; Void&gt; printLast := 
    (_:tail) { printLast(tail); } |
    (x) { print(x); };

myList := [ 5, 12, 8, 9 ];
printLast(myList);
                    </font>
                </pre>
            </div>
        </div>
        <div style="font-size:13.3333330154419px;line-height:21.3333320617676px">
            <div style="font-size:13.3333330154419px;line-height:21.3333320617676px;margin-top:12pt;margin-bottom:12pt;border-style:solid;border-width:1px">
                <p style="font-size:12pt;margin:0px;padding-left:6pt;background-color:rgb(204,221,170)">
                    Output
                </p>
                <pre style="margin-top:0px;margin-bottom:0px;padding:3px;font-family:Courier New;width:715px;max-height:500px;overflow:auto">
                    9
                </pre>
            </div>
        </div>
        Note the use of the underscore
        <code>
            _
        </code>
        character. It is
      substituted for a symbol (a named constant) when the code does not
      care about its value. In the first line of the example above, we
      are unconcerned with the type of the elements the input list
      contains, and only need to ensure that the input is a list of
      something. In the second line, we don't need to know the value of
      the head element. The underscore keyword is called
        <a href="documentation/keywords/dontcare.php">
            dont_care
        </a>
        .
        <div>
            <h3>
                <a name="TOC-Type-Deduction">
                </a>
                Type Deduction
            </h3>
            <div style="font-size:13.3333330154419px;line-height:21.3333320617676px">
                <div style="font-size:13.3333330154419px;line-height:21.3333320617676px">
                    When the type of a constant or variable can be deduced, it
            is often possible to omit it.
                </div>
                <div style="font-size:13.3333330154419px;line-height:21.3333320617676px;margin-top:12pt;margin-bottom:12pt;border-style:solid;border-width:1px">
                    <p style="font-size:12pt;margin:0px;padding-left:6pt;background-color:rgb(204,221,170)">
                        Example
                    </p>
                    <pre style="margin-top:0px;margin-bottom:0px;padding:3px;font-family:Courier New;width:715px;max-height:500px;overflow:auto">
                        &lt;&gt; name := "Snippet"; // name is deduced to be a String
                    </pre>
                </div>
                <div style="font-size:13.3333330154419px;line-height:21.3333320617676px">
                    Modifying a previous example:
                </div>
                <div style="font-size:13.3333330154419px;line-height:21.3333320617676px">
                    <div style="font-size:13.3333330154419px;line-height:21.3333320617676px">
                        <div>
                            <div style="font-size:13.3333330154419px;line-height:21.3333320617676px;margin-top:12pt;margin-bottom:12pt;border-style:solid;border-width:1px">
                                <p style="font-size:12pt;margin:0px;padding-left:6pt;background-color:rgb(204,221,170)">
                                    Example
                                </p>
                                <pre style="margin-top:0px;margin-bottom:0px;padding:3px;font-family:Courier New;width:715px;max-height:500px;overflow:auto">
                                    &lt;&gt; doubler := (x) { return x * 2; };
print(doubler(5));
                                </pre>
                            </div>
                        </div>
                    </div>
                </div>
            </div>
            <div>
                In definitions of constants, and declarations and
          assignments of variables, the angle brackets &lt; &gt; may be
          omitted entirely.
            </div>
            <div>
                <div style="font-size:13.3333330154419px;line-height:21.3333320617676px">
                    <div style="font-size:13.3333330154419px;line-height:21.3333320617676px">
                        <div style="font-size:13.3333330154419px;line-height:21.3333320617676px">
                            <div style="font-size:13.3333330154419px;line-height:21.3333320617676px;margin-top:12pt;margin-bottom:12pt;border-style:solid;border-width:1px">
                                <p style="font-size:12pt;margin:0px;padding-left:6pt;background-color:rgb(204,221,170)">
                                    Example
                                </p>
                                <pre style="margin-top:0px;margin-bottom:0px;padding:3px;font-family:Courier New;width:715px;max-height:500px;overflow:auto">
                                    doubler := (x) { return x * 2; };
print(doubler(5));
                                </pre>
                            </div>
                        </div>
                    </div>
                </div>
            </div>
            <h3>
                <a name="TOC-Type-deduction-is-not-limited-to-only-simple-cases.">
                </a>
                <span style="font-size:13.3333330154419px;line-height:21.3333320617676px">
                    Type deduction is not limited to only simple cases.
                </span>
            </h3>
            <div>
                <div style="font-size:13.3333330154419px;line-height:21.3333320617676px;margin-top:12pt;margin-bottom:12pt;border-style:solid;border-width:1px">
                    <p style="font-size:12pt;margin:0px;padding-left:6pt;background-color:rgb(204,221,170)">
                        Demonstration of more complex type deduction via pattern
              matching
                    </p>
                    <pre style="margin-top:0px;margin-bottom:0px;padding:3px;font-family:Courier New;width:715px;max-height:500px;overflow:auto">
                        return_type_getter := ( &lt;_ -&gt; x&gt; func ) { return x; };

addFive := (&lt;Int&gt; x) { return x + 5; };
print(return_type_getter(addFive));  // output: Int
                    </pre>
                </div>
                <div style="font-size:13.3333330154419px;line-height:21.3333320617676px">
                    <span style="font-size:1.4em;line-height:1.6;background-color:transparent">
                        Types
                    </span>
                </div>
            </div>
            <div>
                The
                <a href="documentation/keywords/type.php">
                    <code>
                        type
                    </code>
                </a>
                &nbsp;(not capitalized) keyword is
          used to make a new
                <a href="documentation/standard-library/type.php">
                    <code>
                        Type
                    </code>
                </a>
                &nbsp;(capitalized) object.
            </div>
        </div>
        <div>
            <div style="margin-top:12pt;margin-bottom:12pt;border-style:solid;border-width:1px">
                <p style="font-size:12pt;line-height:21.3333320617676px;margin:0px;padding-left:6pt;background-color:rgb(204,221,170)">
                    Example
                </p>
                <pre style="margin-top:0px;margin-bottom:0px;padding:3px;width:715px;max-height:500px;overflow:auto">
                    <font face="Courier New">
                        Color := type {
    &lt;Double&gt; r;
    &lt;Double&gt; g;
    &lt;Double&gt; b;
};

&lt;Color&gt; red &lt;- (1, 0, 0);

print(type_of( (1, 0, 0) ));  // output: Tuple&lt;Number, Number, Number&gt;
print(type_of(red));          // output: Color
print(type_of(Color));        // output: Type
                    </font>
                </pre>
            </div>
            <div style="font-size:13.3333330154419px;line-height:21.3333320617676px">
            </div>
        </div>
        <h4>
            <a name="TOC-Type-Functions">
            </a>
            Type Functions
        </h4>
        <h4>
            <a name="TOC-Type-functions-or-parametric-types-are-functions-that-return-Type-objects.">
            </a>
            <span style="line-height:1.6;font-size:10pt;background-color:transparent">
                Type functions, or parametric types are functions that return
          Type objects.
            </span>
        </h4>
        <div>
            <div style="font-size:13.3333330154419px;line-height:21.3333320617676px;margin-top:12pt;margin-bottom:12pt;border-style:solid;border-width:1px">
                <p style="font-size:12pt;margin:0px;padding-left:6pt;background-color:rgb(204,221,170)">
                    Example
                </p>
                <pre style="margin-top:0px;margin-bottom:0px;padding:3px;font-family:Courier New;width:715px;max-height:500px;overflow:auto">
                    Node := (&lt;Type&gt; valueType) { 
	&lt;valueType&gt; v;
	Pointer&lt;Node&gt; next;
}
                </pre>
            </div>
        </div>
        <h4>
            <a name="TOC-Functions-that-return-Type-objects-can-be-called-with-the-angle-bracket-syntax:">
            </a>
            <span style="line-height:1.6;font-size:10pt;background-color:transparent">
                Functions that return Type objects can be called with the
          angle bracket syntax:
            </span>
        </h4>
        <div>
            <div style="font-size:13.3333330154419px;line-height:21.3333320617676px;margin-top:12pt;margin-bottom:12pt;border-style:solid;border-width:1px">
                <p style="font-size:12pt;margin:0px;padding-left:6pt;background-color:rgb(204,221,170)">
                    Example
                </p>
                <pre style="margin-top:0px;margin-bottom:0px;padding:3px;font-family:Courier New;width:715px;max-height:500px;overflow:auto">
                    &lt;Node&lt;Int&gt;&gt; myNode;
                </pre>
            </div>
        </div>
        <h4>
            <a name="TOC-Polymorphism">
            </a>
            Polymorphism
        </h4>
        <div>
            <span style="line-height:1.6;font-size:10pt;background-color:transparent">
                The
                <a href="documentation/keywords/inheriting.php">
                    inheriting
                </a>
                keyword, used in conjunction with the type
          keyword, makes a new Type object that inherits the members of
          the specified base Types. See also:
            </span>
            <a style="line-height:1.6;font-size:10pt;background-color:transparent" href="documentation/keywords/implementing.php">
                implementing
            </a>
        </div>
        <div>
            <div style="font-size:13.3333330154419px;line-height:21.3333320617676px;margin-top:12pt;margin-bottom:12pt;border-style:solid;border-width:1px">
                <p style="font-size:12pt;margin:0px;padding-left:6pt;background-color:rgb(204,221,170)">
                    Example
                </p>
                <pre style="margin-top:0px;margin-bottom:0px;padding:3px;font-family:Courier New;width:715px;max-height:500px;overflow:auto">
                    // base Type
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
};
                </pre>
            </div>
            <h4>
                <a name="TOC-Algebraic-Types">
                </a>
                Algebraic Types
            </h4>
        </div>
        Types can be combined together to make algebraic Types using the |
      operator.
        <div>
            <div style="font-size:13.3333330154419px;line-height:21.3333320617676px;margin-top:12pt;margin-bottom:12pt;border-style:solid;border-width:1px">
                <p style="font-size:12pt;margin:0px;padding-left:6pt;background-color:rgb(204,221,170)">
                    Example
                </p>
                <pre style="margin-top:0px;margin-bottom:0px;padding:3px;font-family:Courier New;width:715px;max-height:500px;overflow:auto">
                    Some := (t) { return type { &lt;t&gt; value; } };
None := type {};
Maybe := (t) { return Some&lt;t&gt; | None; };

&lt;Void -&gt; Maybe&lt;Int&gt;&gt; get_age := {
    return coerce(input("What's your age? You don't have to tell me."));
}

print(get_age);
                </pre>
            </div>
        </div>
        <div>
            <br>
            </br>
            <br>
            </br>
            <div>
                <br>
                </br>
                <br>
                </br>
            </div>
        </div>
    </div>
css/general.css' type='text/css' /></head><body><?php require('header.php') ?>


index.html


<?php require('footer.php') ?></body></html>