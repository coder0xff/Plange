<meta charset='utf-8'/>
<html>
	<head>
		<title>relational_op - Plange</title>
		<link rel=StyleSheet href='../../css/general.css' type='text/css' />
	</head>
	<body>
		<?php require('../../header.php') ?>


        <div class="code">
            <p>Syntax</p>
            <pre><a href="equality.php">equality</a> | <a href="inequality.php">inequality</a> | <a href="lesser_than.php">lesser_than</a> | <a href="greater_than.php">greater_than</a> | <a href="not_greater_than.php">not_greater_than</a> | <a href="not_lesser_than.php">not_lesser_than</a> | <a href="relational_collection_op.php">relational_collection_op</a></pre>
        </div>
        <h2>Notice</h2>
        <p>This document represents a cross section of the
            <a href="../operators.php">complete operator specification</a>.
            Reference the specification for definitive information.
        </p>
        <p>
            Relational operators are used to establish or test relationships between two values. In an expression, they take left and right hand operands and return a value of type <a href="/documentation/standard-library/relation.php">Relation</a>. When a relation is coerced to bool, the relation is tested.
        </p>
        <p>
            Some operators are not represented on keyboards. The "pseudonym" column contains sequences of keystrokes used to type their corresponding operators.
        </p>
        <table bordercolor="#888" border="1" style="border-collapse:collapse;border-color:rgb(136,136,136);border-width:1px" cellspacing="0">
            <tbody>
                <tr>
                    <td>
                        <b>
                             operator
                        </b>
                        <br>
                        </br>
                    </td>
                    <td style="width:60px">
                         
                        <b>
                            unicode
                        </b>
                    </td>
                    <td>
                         
                        <b>
                            pseudonym
                        </b>
                        <br>
                        </br>
                    </td>
                    <td style="width:60px">
                         
                        <b>
                            name
                        </b>
                    </td>
                    <td>
                        <b>
                            read as
                            <br>
                            </br>
                        </b>
                    </td>
                </tr>
                <tr>
                    <td style="width:60px">
                         =
                    </td>
                    <td style="width:60px">
                         
                    </td>
                    <td style="width:60px">
                         
                    </td>
                    <td style="width:150px">
                         equality
                    </td>
                    <td style="width:300px">
                         is equal to
                        <br>
                        </br>
                    </td>
                </tr>
                <tr>
                    <td style="width:60px">
                         
                        <span style="background-color:transparent;line-height:1.6;font-size:10pt">
                            ≠
                        </span>
                    </td>
                    <td style="width:60px">
                         
                    </td>
                    <td style="width:60px">
                         
                    </td>
                    <td style="width:60px">
                         not_equal_to
                    </td>
                    <td style="width:60px">
                         is not equal to
                        <br>
                        </br>
                    </td>
                </tr>
                <tr>
                    <td style="width:60px">
                         &lt;
                    </td>
                    <td style="width:60px">
                         
                    </td>
                    <td style="width:60px">
                         
                    </td>
                    <td style="width:60px">
                         lesser_than
                        <br>
                        </br>
                    </td>
                    <td style="width:60px">
                         is lesser than
                        <br>
                        </br>
                    </td>
                </tr>
                <tr>
                    <td style="width:60px">
                         &gt;
                    </td>
                    <td style="width:60px">
                         
                    </td>
                    <td style="width:60px">
                         
                    </td>
                    <td style="width:60px">
                         greater_than
                        <br>
                        </br>
                    </td>
                    <td style="width:60px">
                         is greater than
                        <br>
                        </br>
                    </td>
                </tr>
                <tr>
                    <td style="width:60px">
                         ≤
                    </td>
                    <td style="width:60px">
                         
                    </td>
                    <td style="width:60px">
                         &lt;=
                    </td>
                    <td style="width:60px">
                         not_greater_than
                    </td>
                    <td style="width:60px">
                         is not greater than, is less than or equal to
                        <br>
                        </br>
                    </td>
                </tr>
                <tr>
                    <td style="width:60px">
                         ≥
                    </td>
                    <td style="width:60px">
                         
                    </td>
                    <td style="width:60px">
                         &gt;=
                    </td>
                    <td style="width:60px">
                         not_lesser_than
                        <br>
                        </br>
                    </td>
                    <td style="width:60px">
                         is not less than, is greater than or equal to
                        <br>
                        </br>
                    </td>
                </tr>
                <tr>
                    <td style="width:60px">
                         ∈
                    </td>
                    <td style="width:60px">
                         
                    </td>
                    <td style="width:60px">
                         in
                    </td>
                    <td style="width:60px">
                         in
                    </td>
                    <td style="width:60px">
                         is in (is an element of)
                        <br>
                        </br>
                    </td>
                </tr>
                <tr>
                    <td style="width:60px">
                         
                        <span style="background-color:transparent;line-height:1.6;font-size:10pt">
                            ∉
                        </span>
                    </td>
                    <td style="width:60px">
                         
                    </td>
                    <td style="width:60px">
                         !in
                    </td>
                    <td style="width:60px">
                         not_in
                        <br>
                        </br>
                    </td>
                    <td style="width:60px">
                         is not in (is not an element of)
                    </td>
                </tr>
                <tr>
                    <td style="width:60px">
                         
                        <span style="background-color:transparent;line-height:1.6;font-size:10pt">
                            ∋
                        </span>
                    </td>
                    <td style="width:60px">
                         
                    </td>
                    <td style="width:60px">
                         has
                    </td>
                    <td style="width:60px">
                         has
                    </td>
                    <td style="width:60px">
                         has (contains)
                        <br>
                        </br>
                    </td>
                </tr>
                <tr>
                    <td style="width:60px">
                         
                        <span style="background-color:transparent;line-height:1.6;font-size:10pt">
                            ∌
                        </span>
                    </td>
                    <td style="width:60px">
                         
                    </td>
                    <td style="width:60px">
                         !has
                    </td>
                    <td style="width:60px">
                         not_has
                    </td>
                    <td style="width:60px">
                         hasn't (does not contain)
                        <br>
                        </br>
                    </td>
                </tr>
                <tr>
                    <td>
                         ⊆
                    </td>
                    <td style="width:60px">
                         
                    </td>
                    <td>
                         subs
                    </td>
                    <td>
                         subset
                    </td>
                    <td>
                         is a subset of
                    </td>
                </tr>
                <tr>
                    <td>
                         ⊂
                    </td>
                    <td style="width:60px">
                         
                    </td>
                    <td>
                         psubs
                    </td>
                    <td>
                         proper_subset
                    </td>
                    <td>
                         is a proper subset of
                    </td>
                </tr>
                <tr>
                    <td>
                         ⊇
                    </td>
                    <td style="width:60px">
                         
                    </td>
                    <td>
                         sups
                    </td>
                    <td>
                         superset
                    </td>
                    <td>
                         is a superset of
                    </td>
                </tr>
                <tr>
                    <td>
                         ⊃
                    </td>
                    <td style="width:60px">
                         
                    </td>
                    <td>
                         psups
                    </td>
                    <td>
                         proper_superset
                    </td>
                    <td>
                         is a proper superset of
                    </td>
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