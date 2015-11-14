<meta charset='utf-8'/>
<html>
	<head>
		<title>relational_op - Plange</title>
		<link rel=StyleSheet href='..//css/general.css' type='text/css' />
	</head>
	<body>
		<?php require('..//header.php') ?>



        <a href="equality.php">
            equality
        </a>
        |
        <a href="inequality.php">
            inequality
        </a>
        |
        <a href="lesser_than.php">
            lesser_than
        </a>
        |
        <a href="greater_than.php">
            greater_than
        </a>
        |
        <a href="not_greater_than.php">
            not_greater_than
        </a>
        |
        <a href="not_lesser_than.php">
            not_lesser_than
        </a>
        |
        <a href="relational_collection_op.php">
            relational_collection_op
        </a>
    </div>
    <div>
        <br>
        </br>
    </div>
    <div>
        Notice: This document represents a cross section of the
        <a href="../operators.php">
            complete operator specification
        </a>
        . Reference the specification for definitive information.
    </div>
    <div>
        <br>
        </br>
    </div>
    <div>
        Relational operators are used to establish or test relationships between two values. In an expression, they take a left hand side operand and right hand side operand and return a value of type relation. When a relation is coerced to bool, the relation is tested. 
        <span style="line-height:1.6;font-size:10pt;background-color:transparent">
            Some operators are not represented on keyboards. The "pseudonym" column contains sequences of keystrokes used to type their corresponding operators.
        </span>
    </div>
    <div>
        <br>
        </br>
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
    </div>
    <h2>
        <a name="TOC-Semantics">
        </a>
        Semantics
    </h2>
    <div>
        There is more than one way to use relational operators. The most familiar use is for the conditional execution of code:
    </div>
    <div>
        <div style="font-size:13.3333330154419px;line-height:21.3333320617676px;margin-top:12pt;margin-bottom:12pt;border-style:solid;border-width:1px">
            <p style="font-size:12pt;margin:0px;padding-left:6pt;background-color:rgb(204,221,170)">
                Example
            </p>
            <pre style="margin-top:0px;margin-bottom:0px;padding:3px;font-family:Courier New;width:715px;max-height:500px;overflow:auto">
                if (coerce(input("Enter a number: ")) &lt; 0) {
	print "You entered a negative number.";
}
            </pre>
        </div>
        <div style="font-size:13.3333330154419px;line-height:21.3333320617676px">
            In such cases, the result of the relational operator application is coerced to Bool and therefore tested. Another uses the result of the operator as a constraint or binary relation.
            <br>
            </br>
        </div>
    </div>
    <div>
        <div style="margin-top:12pt;margin-bottom:12pt;border-style:solid;border-width:1px">
            <p style="font-size:12pt;line-height:21.3333320617676px;margin:0px;padding-left:6pt;background-color:rgb(204,221,170)">
                Example
            </p>
            <pre style="margin-top:0px;margin-bottom:0px;padding:3px;width:715px;max-height:500px;overflow:auto">
                <font face="Courier New">
                    0 &lt;= x &lt; 1; //constrain x to be a non-negative Real less than 1.
                </font>
            </pre>
        </div>
        <div style="font-size:13.3333330154419px;line-height:21.3333320617676px">
            <br>
            </br>
        </div>
    </div>



		<?php require('..//footer.php') ?>
	</body>
</html>