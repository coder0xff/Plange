<meta charset='utf-8'/>
<html>
	<head>
		<title>relational_op - Plange</title>
		<link rel=StyleSheet href='../../css/general.css' type='text/css' />
	</head>
	<body>
		<?php require('../../header.php') ?>


		<div class="syntax">
			<p>syntax</p>
			<div><a href="/documentation/syntax/equality.php">equality</a> | <a href="/documentation/syntax/inequality.php">inequality</a> | <a href="/documentation/syntax/lesser_than.php">lesser_than</a> | <a href="/documentation/syntax/greater_than.php">greater_than</a> | <a href="/documentation/syntax/not_greater_than.php">not_greater_than</a> | <a href="/documentation/syntax/not_lesser_than.php">not_lesser_than</a> | <a href="/documentation/syntax/relational_collection_op.php">relational_collection_op</a></div>
        </div>
        <h2>Notice</h2>
        <p>This document represents a cross section of the
            <a href="/documentation/operators.php">complete operator specification</a>.
            Reference the specification for definitive information.
        </p>
        <p>
            Relational operators are used to establish or test relationships between two values. In an expression, they take left and right hand operands and return a value of type <a href="/documentation/standard-library/Relation.php">Relation</a>. When a relation is coerced to bool, the relation is tested.
        </p>
        <p>
            Some operators are not represented on keyboards. The "pseudonym" column contains sequences of keystrokes used to type their corresponding operators.
        </p>
        <table bordercolor="#888" border="1" style="border-collapse:collapse;border-color:rgb(136,136,136);border-width:1px" cellspacing="0">
            <tbody>
                <tr>
                    <td>operator</td>
                    <td>unicode</td>
                    <td>pseudonym</td>
                    <td>name</td>
                    <td>read as</td>
                </tr>
                <tr>
                    <td>=</td>
                    <td></td>
                    <td></td>
                    <td>equality</td>
                    <td>is equal to</td>
                </tr>
                <tr>
                    <td>≠</td>
                    <td></td>
                    <td></td>
                    <td>not_equal_to</td>
                    <td>is not equal to</td>
                </tr>
                <tr>
                    <td>&lt;</td>
                    <td></td>
                    <td></td>
                    <td>lesser_than</td>
                    <td>is lesser than</td>
                </tr>
                <tr>
                    <td>&gt;</td>
                    <td></td>
                    <td></td>
                    <td>greater_than</td>
                    <td>is greater than</td>
                </tr>
                <tr>
                    <td>≤</td>
                    <td></td>
                    <td>&lt;=</td>
                    <td>not_greater_than</td>
                    <td>is not greater than, is less than or equal to</td>
                </tr>
                <tr>
                    <td>≥</td>
                    <td></td>
                    <td>&gt;=</td>
                    <td>not_lesser_than</td>
                    <td>is not less than, is greater than or equal to</td>
                </tr>
                <tr>
                    <td>∈</td>
                    <td></td>
                    <td>in</td>
                    <td>in</td>
                    <td>is in (is an element of)</td>
                </tr>
                <tr>
                    <td>∉</td>
                    <td></td>
                    <td>/in</td>
                    <td>not_in</td>
                    <td>is not in (is not an element of)</td>
                </tr>
                <tr>
                    <td>∋</td>
                    <td></td>
                    <td>has</td>
                    <td>has</td>
                    <td>has (contains)</td>
                </tr>
                <tr>
                    <td>∌</td>
                    <td></td>
                    <td>/has</td>
                    <td>not_has</td>
                    <td>hasn't (does not contain)</td>
                </tr>
                <tr>
                    <td>⊆</td>
                    <td></td>
                    <td>subs</td>
                    <td>subset</td>
                    <td>is a subset of</td>
                </tr>
                <tr>
                    <td>⊂</td>
                    <td></td>
                    <td>psubs</td>
                    <td>proper_subset</td>
                    <td>is a proper subset of</td>
                </tr>
                <tr>
                    <td>⊇</td>
                    <td></td>
                    <td>sups</td>
                    <td>superset</td>
                    <td>is a superset of</td>
                </tr>
                <tr>
                    <td>⊃</td>
                    <td></td>
                    <td></td>
                    <td>proper_superset</td>
                    <td>is a proper superset of</td>
                </tr>
            </tbody>
        </table>
        <h2>
            Semantics
        </h2>
        <p>
            There is more than one way to use relational operators. The most familiar use is for the conditional execution of code:
        </p>
        <div class="code">
            <p>Example</p>
            <pre>if (coerce(input("Enter a number: ")) &lt; 0) { print "You entered a negative number."; }</pre>
        </div>
        <p>
            In such cases, the result of the relational operator application is coerced to Bool and therefore tested. Other cases use the result of the operator as a constraint or binary relation.
        </p>
        <div class="code">
            <p>Example</p>
            <pre>0 &lt;= x &lt; 1; //constrain x to be a non-negative Real less than 1.</pre>
        </div>


		<?php require('../../footer.php') ?>
	</body>
</html>