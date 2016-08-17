<meta charset='utf-8'/>
<meta name="viewport" content="width=device-width, initial-scale=0.6">
<html>
	<head>
		<title>statement_scope - Plange</title>
		<link rel=StyleSheet href='../../css/general.css' type='text/css' />
	</head>
	<body>
		<?php require('../../header.php') ?>


        <p>the top level syntax rule for a source file, and the rule used in the code block of function literals, where expressions may be evaluated, variables may be declared and assigned, constants may be defined, and relations asserted</p>
		<div class="syntax">
			<p>syntax</p>
			<div><a href="/documentation/syntax/statement.php">statement</a>*</div>
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
            <p>Example</p>
            <pre>a + 3 &lt;= b * 5; // assert a linear inequality</pre>
        </div>

        <p>An expression e, is in the set E (the valid truth statements in the current execution context) if and only if</p>
        <ul>
            <li><code>coerce(Bool, e)</code> evaluates to true, or</li>
            <li><code>coerce(Bool, e)</code> is unbound, creating a relation, or</li>
            <li>e is an expression that cannot be coerced to Bool, and is not a function or</li>
            <li>e is a nullary function, and <code>e()</code> is an element of E, or</li>
            <li>e is a non-nullary function, and all values of e over its domain are elements of E, creating a universal predicate</li>
        </ul>

        <p>The <a href="/documentation/syntax/definition.php">definition</a>, <a href="/documentation/syntax/declaration.php">declaration</a>, <a href="/documentation/syntax/declaration_assignment.php">declaration_assignment</a>, and <a href="/documentation/syntax/assignment.php">assignment</a> syntaxes are used for creating symbols and setting their values.</p>

        <div class="code">
            <p>Example - declaring a variable</p>
            <pre>&lt;Int&gt; x;</pre>
        </div>

        <div class="code">
            <p>Example - defining a constant</p>
            <pre>pi_approximation := 22/7;</pre>
        </div>

        <p>When declaring or defining a variable or constant, a relation is also created. Specifically, a relation indicating that the variable or constant is an instance of the specified type.<p>
        
        <p>If a type is not specified</p>
        <div class="code">
            <pre>y ← 3.14;</pre>
        </div>
        <p>then the relation indicates that the variable or constant is an instance of some type that can be assigned the right hand side value. In the example: It is true that y is an instance of some type that can be assigned 3.14, and 3.14 is assigned to it.</p>


		<?php require('../../footer.php') ?>
	</body>
</html>