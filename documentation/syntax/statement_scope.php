<meta charset='utf-8'/>
<html>
	<head>
		<title>statement_scope - Plange</title>
		<link rel=StyleSheet href='../../css/general.css' type='text/css' />
	</head>
	<body>
		<?php require('../../header.php') ?>


        <p>the top level syntax rule for a source file, and the rule used in the code block of function literals, where expressions may be evaluated, variables may be declared and assigned, and constants may be defined</p>
        <div class="code">
            <p>Syntax</p>
            <pre>(( <a href="expression.php">expression</a> | <a href="declaration.php">declaration</a> | <a href="declaration_assignment.php">declaration_assignment</a> | <a href="assignment.php">assignment</a> | <a href="definition.php">definition</a> ) ";")*</pre>
        </div>
        <h2>Notes</h2>
        <p>
            This is the syntactic root of the Plange language. That is, code added to an empty Plange source file will be in statement_scope.
        </p>
        <h2>Truth statements</h2>
        <p>Statements are the buildings blocks of programs in Plange.
            Each statement is an assertion of truth, and is followed by a semicolon.
            An expression may be given as a statement in statement_scope:
        </p>
        <div class="code">
            <p>Example</p>
            <pre>A &lt; B;        // this statement is an assertion of truth that A is less than B
B &lt; C;        // now, because less_than is transitive
print(A &lt; C); // this will print "true"</pre>
        </div>
        <p>
            This example code causes a compile time error because it is contradictory:
        </p>
        <div class="code">
            <p>Example of invalid code</p>
            <pre>false; // cannot assert that false is true!</pre>
        </div>
        <div class="code">
            <p>Example</p>;
            <pre>a + 3 &lt;= b * 5; // assert a linear inequality</pre>
        </div>
        <p>
            An expression e, is in the set E (the valid truth statements in the current execution context) iff:
        </p>
        <ul>
            <li>
                <code>
                    coerce(Bool, e)
                </code>
                <span>
                     evaluates to true, or
                </span>
            </li>
            <li>
                <span>
                    <code>
                        coerce(Bool, e)
                    </code>
                     is unbound, creating a relation, or
                </span>
            </li>
            <li>
                e is an expression that cannot be coerced to Bool, and is not a function or
            </li>
            <li>
                e is a nullary function, and 
                <code>
                    e()
                </code>
                 is an element of E, or
            </li>
            <li>
                e is a non-nullary function, and all values of e over its domain are elements of E, creating a universal predicate
            </li>
        </ul>
        <div>
            It may be helpful to imagine all statement-scope expressions being passed to the following function. Note that this code does not fully represent the behavior of truth statements.:
        </div>
        <div class="code">
            <p>
                pseudo code
            </p>
            <pre>eval_expression(expression) {
        if (bool casts expression) {
            if (!expression) {
                throw "contradictory assertion";
            }
        }
        if ((Void -&gt; _) casts expression) { eval_expression(expression()); }
        if (Function casts expression) {
        	asFunction := (Function)expression;
        	x ∈ Tuple.apply&lt;asFunction.argument_types&gt;;
        	∀x eval_expression(asFunction.apply(x));
        }
    }</pre>
        </div>
    <p>
        Syntax to declare/define a variable:
    </p>
    <div>
        <div class="code">
            <code>
                <i>
                    &lt;
                </i>
            </code>
            <code>
                <i>
                    <a href="expression.php">
                        <code>
                            <i>
                                expression
                            </i>
                        </code>
                    </a>
                    &gt;
                </i>
            </code>
            <a href="symbol.php">
                <code>
                    identifier
                </code>
            </a>
            <code>
                 [&lt;-
            </code>
            <i>
                <a href="expression.php">
                    <code>
                        expression
                    </code>
                </a>
            </i>
            <code>
                ]
            </code>
            <code>
                ;
            </code>
        </div>
        <div>
            <code>
                <i>
                    <a style="font-family:Arial,Verdana,sans-serif" href="symbol.php">
                        <code>
                            identifier
                        </code>
                    </a>
                </i>
                <code>
                    &lt;-
                </code>
                <i>
                    <a style="font-family:Arial,Verdana,sans-serif" href="expression.php">
                        <code>
                            expression
                        </code>
                    </a>
                </i>
                <code>
                    ;
                </code>
            </code>
        </div>
    </div>
    <div>
        <br>
        </br>
    </div>
    <div>
        Examples:
        <div>
            <div>
                <code>
                    &lt;int&gt; x;
                </code>
            </div>
            <br>
            </br>
        </div>
        <div>
            Syntax to declare a constant:
        </div>
        <div>
            <div>
                <code>
                    [&lt;
                </code>
                <a href="../../system/errors/NodeNotFoundd3a2.php?suri=wuid:gx:69cc1cec114ce299" class="disabled">
                </a>
                <code>
                    <code>
                        <i>
                            <a href="expression.php">
                                <code>
                                    <i>
                                        expression
                                    </i>
                                </code>
                            </a>
                        </i>
                    </code>
                    &gt;]
                </code>
                <a href="symbol.php">
                    <code>
                        identifier
                    </code>
                </a>
                <code>
                    :=
                </code>
                <a href="expression.php">
                    <code>
                        expression
                    </code>
                </a>
                <code>
                    ;
                    <br>
                    </br>
                </code>
            </div>
        </div>
    </div>
    <br>
    </br>
    <div>
        Example:
    </div>
    <div>
        <div>
            <code>
                pi := 22/7;
            </code>
        </div>
        <div>
            <br>
            </br>
        </div>
        <div>
            When declaring or defining a variable or constant, a relation is also created. Specifically, a relation indicating that the variable or constant is an instance of the specified type.
            <br>
            </br>
            <br>
            </br>
            If a type is not specified:
            <br>
            </br>
            <div>
                <div>
                    <code>
                        y &lt;- 3.14;
                    </code>
                </div>
            </div>
            <br>
            </br>
            then the relation indicates that the variable or constant is an instance of some type that can be assigned the right hand side value. In the example: It is true that y is an instance of some type that can be assigned 3.14, and 3.14 is assigned to it.
            <br>
            </br>
        </div>
    </div>



		<?php require('../../footer.php') ?>
	</body>
</html>