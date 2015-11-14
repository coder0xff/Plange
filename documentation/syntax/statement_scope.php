<meta charset='utf-8'/>
<html>
	<head>
		<title>statement_scope - Plange</title>
		<link rel=StyleSheet href='../../css/general.css' type='text/css' />
	</head>
	<body>
		<?php require('../../header.php') ?>



        the top level syntax rule for a source file, and the rule used in the code block of function literals
    </div>
    <div style="margin-top:12pt;margin-bottom:12pt;border-style:solid;border-width:1px">
        <p style="font-size:12pt;margin:0px;padding-left:6pt;background-color:#cda">
            Syntax
        </p>
        <pre style="margin:0px;padding:3px;font-family:Courier New;width:715px;max-height:500px;overflow-x:auto;overflow-y:auto">
            ((
            <a href="expression.php">
                expression
            </a>
            |
            <a href="declaration.php">
                declaration
            </a>
            |
            <a href="declaration_assignment.php">
                declaration_assignment
            </a>
            |
            <a href="assignment.php">
                assignment
            </a>
            |
            <a href="definition.php">
                definition
            </a>
            ) ";")*
        </pre>
    </div>
    I
    <span style="line-height:1.6;font-size:10pt;background-color:transparent">
        n statement_scope, expressions may be evaluated, variables may be declared and assigned, and constants may be defined. This is the syntactic root of the Plange language. That is, code added to an empty Plange source file will be in statement_scope.
    </span>
    <div>
        <h2>
            <a name="TOC-Truth-statements">
            </a>
            Truth statements
            <br>
            </br>
        </h2>
        <p>
            Statements are the buildings blocks of programs in Plange.
            <span style="font-size:13.3333330154419px;line-height:21.3333320617676px;background-color:transparent">
                Each statement is an assertion of truth, and is followed by a semicolon.
            </span>
            <span style="font-size:13.3333330154419px;line-height:21.3333320617676px;background-color:transparent">
                 
            </span>
            <span style="line-height:1.6;font-size:10pt;background-color:transparent">
                An expression may be given as a statement 
in statement_scope:
            </span>
        </p>
        <div class="sites-codeblock sites-codesnippet-block">
            <code>
                A &lt; B;        // this statement is an assertion of truth that A is less than B
            </code>
            <br>
            </br>
            <code>
                B &lt; C;        // now, because less_than is transitive
                <br>
                </br>
                print(A &lt; C); // this will print "true"
                <br>
                </br>
            </code>
        </div>
    </div>
    <div>
        <span style="font-size:10pt;line-height:1.6;background-color:transparent">
            <br>
            </br>
        </span>
    </div>
    <div>
        <span style="font-size:10pt;line-height:1.6;background-color:transparent">
            This example code causes a compile time error because it is contradictory:
        </span>
    </div>
    <div>
        <br>
        </br>
    </div>
    <div>
        <div class="sites-codeblock sites-codesnippet-block">
            <code>
                false; //cannot assert that false is true!
                <br>
                </br>
            </code>
        </div>
        <br>
        </br>
    </div>
    <div>
        Syntax:
        <br>
        </br>
    </div>
    <div>
        <i>
            <u>
                <a href="expression.php">
                </a>
            </u>
        </i>
        <div class="sites-codeblock sites-codesnippet-block">
            <i>
                <u>
                    <a href="expression.php">
                        <code>
                            expression
                        </code>
                    </a>
                </u>
            </i>
            <u>
                <a href="expression.php">
                </a>
            </u>
            <code>
                ;
            </code>
        </div>
    </div>
    <div>
        <br>
        </br>
    </div>
    <div>
        Example:
    </div>
    <div>
    </div>
    <div class="sites-codeblock sites-codesnippet-block">
        <div>
            <code>
                a + 3 &lt;= b * 5;
            </code>
        </div>
        <div>
        </div>
    </div>
    <div style="font-size:13.3333330154419px;line-height:21.3333320617676px">
        <br>
        </br>
    </div>
    <div style="font-size:13.3333330154419px;line-height:21.3333320617676px">
        An expression e, is in the set E (the valid truth statements in the current execution context) iff:
    </div>
    <div style="font-size:13.3333330154419px;line-height:21.3333320617676px">
        <ul>
            <li>
                <code style="font-size:10pt;line-height:1.6;background-color:transparent">
                    coerce(Bool, e)
                </code>
                <span style="font-size:10pt;line-height:1.6;background-color:transparent">
                     evaluates to true, or
                </span>
            </li>
            <li>
                <span style="line-height:1.6;font-size:10pt;background-color:transparent">
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
    </div>
    <div style="font-size:13.3333330154419px;line-height:21.3333320617676px">
        It may be helpful to imagine all statement-scope expressions being passed to the following function. Note that this code does not fully represent the behavior of truth statements.:
    </div>
    <div style="font-size:13.3333330154419px;line-height:21.3333320617676px;margin-top:12pt;margin-bottom:12pt;border-style:solid;border-width:1px">
        <p style="font-size:12pt;margin:0px;padding-left:6pt;background-color:rgb(204,221,170)">
            pseudo code
        </p>
        <pre style="margin-top:0px;margin-bottom:0px;padding:3px;font-family:Courier New;width:715px;max-height:500px;overflow:auto">
            eval_expression(expression) {
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
}
        </pre>
        <div>
            <br>
            </br>
        </div>
    </div>
    <div>
        Syntax to declare/define a variable:
    </div>
    <div>
        <a href="../../system/errors/NodeNotFoundd3a2.php?suri=wuid:gx:69cc1cec114ce299" class="disabled">
        </a>
        <a href="../../system/errors/NodeNotFoundd3a2.php?suri=wuid:gx:69cc1cec114ce299" class="disabled">
        </a>
        <div class="sites-codeblock sites-codesnippet-block">
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
        <div class="sites-codeblock sites-codesnippet-block">
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
            <div class="sites-codeblock sites-codesnippet-block">
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
            <div class="sites-codeblock sites-codesnippet-block">
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
        <div class="sites-codeblock sites-codesnippet-block">
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
            <div class="sites-codeblock sites-codesnippet-block">
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