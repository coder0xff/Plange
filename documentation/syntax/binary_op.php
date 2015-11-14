<meta charset='utf-8'/>
<html>
	<head>
		<title>binary_op - Plange</title>
		<link rel=StyleSheet href='..//css/general.css' type='text/css' />
	</head>
	<body>
		<?php require('..//header.php') ?>



        <span style="line-height:1.6;font-size:10pt;background-color:transparent">
            a sequence of one or more punctuation characters representing an infix operator
        </span>
    </div>
    <div>
        <div>
            <div style="font-size:13.3333330154419px;line-height:21.3333320617676px;margin-top:12pt;margin-bottom:12pt;border-style:solid;border-width:1px">
                <p style="font-size:12pt;margin:0px;padding-left:6pt;background-color:rgb(204,221,170)">
                    Syntax
                </p>
                <pre style="margin-top:0px;margin-bottom:0px;padding:3px;font-family:Courier New;width:715px;max-height:500px;overflow:auto">
                    <a href="binary_arithmetic_op.php">
                        binary_arithmetic_op
                    </a>
                    <span style="font-size:13.3333330154419px;line-height:21.3333320617676px;background-color:transparent">
                        |
                        <a href="bitwise_op.php">
                            bitwise_op
                        </a>
                        |
                        <a href="collection_op.php">
                            collection_op
                        </a>
                        |
                        <a href="constructive_op.php">
                            constructive_op
                        </a>
                        |
                        <a href="binary_logical_op.php">
                            binary_logical_op
                        </a>
                        |
                        <a href="multiplicative_op.php">
                            multiplicative_op
                        </a>
                        |
                    </span>
                    <a href="relational_op.php">
                        relational_op
                    </a>
                </pre>
            </div>
            <h2>
                <a name="TOC-Notes">
                </a>
                Notes
            </h2>
            <div>
                Some operators are not represented on keyboards. Such operators have pseudonyms. Take for example, the maps_to relational operator. It can be typed as "-&gt;" or pasted as "→". Alternatively, you can use your operating system's or text editor's capabilities to type the unicode character U+2192. In editors that are syntax aware, typing "-&gt;" may be automatically converted to →.
            </div>
            <h4>
                <a name="TOC---asterisk">
                </a>
                * - asterisk
            </h4>
        </div>
        <div>
            The asterisk character may be typed SHIFT+8.
        </div>
        <div>
            <ul>
                <li>
                    as the arithmetic operator 
                    <a href="multiplication.php">
                        multiplication
                    </a>
                    <br>
                    </br>
                    Function signature: Number 
                    <span style="font-family:Courier New;font-size:13.3333330154419px;line-height:21.3333320617676px">
                        *
                    </span>
                     Number 
                    <span style="font-size:13.3333330154419px;line-height:21.3333320617676px;background-color:transparent">
                        →
                    </span>
                    <span style="line-height:1.6;font-size:10pt;background-color:transparent">
                         Number
                    </span>
                </li>
                <li>
                    as the product of sets or types, making a tuple Type, 
                    <a href="../../system/errors/NodeNotFound0bf4.php?suri=wuid:gx:50b55d46dad496f3" class="disabled">
                        cartesian_product
                    </a>
                    <br>
                    </br>
                    Function signature: Type 
                    <span style="font-family:Courier New;font-size:13.3333330154419px;line-height:21.3333320617676px;background-color:transparent">
                        *
                    </span>
                    <span style="line-height:1.6;font-size:10pt;background-color:transparent">
                         Type 
                        <span style="font-size:13.3333330154419px;line-height:21.3333320617676px;background-color:transparent">
                            →
                        </span>
                        <span style="font-size:10pt;line-height:1.6;background-color:transparent">
                             Type
                            <br>
                            </br>
                            Function signature: Set * Set
                        </span>
                    </span>
                    →
                    <span style="font-size:13.3333330154419px;line-height:21.3333320617676px">
                        Set
                    </span>
                </li>
                <li>
                    as the the inner product of two vectors
                    <a href="dot_product.php">
                        dot_product
                    </a>
                    <br>
                    </br>
                    Function signature: Vector&lt;_&gt; 
                    <span style="font-family:Courier New;font-size:13.3333330154419px;line-height:21.3333320617676px">
                        *
                    </span>
                     Vector&lt;_&gt; 
                    <span style="font-size:13.3333330154419px;line-height:21.3333320617676px;background-color:transparent">
                        →
                    </span>
                    <span style="line-height:1.6;font-size:10pt;background-color:transparent">
                         Number
                    </span>
                </li>
                <li>
                    as the free monad in regular expressions or grammars, 
                    <span style="font-size:13.3333330154419px;line-height:21.3333320617676px">
                        an unary operator,
                        <a href="kleene_star.php">
                            kleene_star
                        </a>
                    </span>
                    <br>
                    </br>
                    Function signature: Production 
                    <span style="font-size:13.3333330154419px;line-height:21.3333320617676px;background-color:transparent">
                        →
                    </span>
                    <span style="line-height:1.6;font-size:10pt;background-color:transparent">
                         Production
                    </span>
                </li>
            </ul>
            <h4>
                <a name="TOC---cross">
                </a>
                × - cross
            </h4>
            <span style="font-size:13.3333330154419px;line-height:21.3333320617676px;background-color:transparent">
                The unicode character 
            </span>
            <span style="line-height:1.6;font-size:10pt;background-color:transparent">
                MULTIPLICATION SIGN (U+00D7) (not to be confused with x, the unicode character LATIN SMALL LETTER X (U+0078)) 
            </span>
            <span style="line-height:1.6;font-size:10pt;background-color:transparent">
                may be typed as
                <code>
                    _x_
                </code>
                .
            </span>
        </div>
        <div>
            <div>
                <ul>
                    <li>
                        as the arithmetic_operator 
                        <a href="multiplication.php">
                            multiplication
                        </a>
                        <br>
                        </br>
                        Function signature: Number 
                        <span style="font-family:Courier New;font-size:13.3333330154419px;line-height:21.3333320617676px">
                            *
                        </span>
                         Number 
                        <span style="font-size:13.3333330154419px;line-height:21.3333320617676px;background-color:transparent">
                            →
                        </span>
                        <span style="line-height:1.6;font-size:10pt;background-color:transparent">
                             Number
                        </span>
                    </li>
                    <li>
                        as the cross product of two three component vectors 
                        <a href="cross_product.php">
                            cross_product
                        </a>
                        <br>
                        </br>
                        Function signature: Vector&lt;3&gt; * Vector&lt;3&gt; 
                        <span style="font-size:13.3333330154419px;line-height:21.3333320617676px">
                            → 
                        </span>
                        Vector&lt;3&gt;
                    </li>
                </ul>
            </div>
            <h4>
                <a name="TOC-arrow-">
                </a>
                → (arrow)
            </h4>
            The unicode character RIGHTWARD ARROW (U+2192) may be typed as
            <code>
                -&gt;
            </code>
            . The arrow operator creates an object which is simultaneously a
            <b>
                function type
            </b>
            and a
            <a href="maps_to.php">
                maps_to
            </a>
             relation. A
            <b>
                function type
            </b>
            is an object that implements
            <a href="../standard-library/type.php">
                Type
            </a>
            (it is a
            <a href="../using-types.php">
                type
            </a>
            ), and instances of this
            <a href="../standard-library/type.php">
                Type
            </a>
            are invokable with the specified signature (they're functions). The signature of a function is composed with the left hand side defining the function's domain (the input parameter types) and the right hand defining the codomain (the return type).
            <div>
                <ul>
                    <li>
                        as a factory of a function type
                        <br>
                        </br>
                        Function signature: Type * Type→Type
                    </li>
                    <li>
                        as a relation indicating a
                        <a href="maps_to.php">
                            maps_to
                        </a>
                        constraint
                        <br>
                        </br>
                        Function signature: Set * Set→Relation
                    </li>
                </ul>
            </div>
            <h4>
                <a name="TOC-ring-">
                </a>
                ∘ (ring)
            </h4>
            <div>
                <span style="font-size:13.3333330154419px;line-height:21.3333320617676px;background-color:transparent">
                    <code>
                        ∘
                    </code>
                    is the unicode character 
                </span>
                <span style="line-height:1.6;font-size:10pt;background-color:transparent">
                    RING OPERATOR (U+2218). It may be typed as
                    <code>
                        _o_
                    </code>
                    . 
                </span>
                <span style="line-height:1.6;font-size:10pt;background-color:transparent">
                    The ring operator composes functions such that
                </span>
                <code style="line-height:1.6;font-size:10pt;background-color:transparent">
                    (f ○ g)(x)
                </code>
                <span style="line-height:1.6;font-size:10pt;background-color:transparent">
                    is equivalent to
                </span>
                <code style="line-height:1.6;font-size:10pt;background-color:transparent">
                    f(g(x))
                </code>
                <span style="line-height:1.6;font-size:10pt;background-color:transparent">
                    .
                </span>
            </div>
        </div>
        <div>
            <ul>
                <li>
                    as function composition
                    <br>
                    </br>
                    <span style="line-height:1.6;font-size:10pt;background-color:transparent">
                        Function signature: (X 
                        <span style="font-size:13.3333330154419px;line-height:21.3333320617676px">
                            →
                        </span>
                         Y) 
                        <span style="font-size:13.3333330154419px;line-height:21.3333320617676px">
                            *
                        </span>
                         (Y 
                        <span style="font-size:13.3333330154419px;line-height:21.3333320617676px">
                            →
                        </span>
                         Z)
                        <span style="font-size:13.3333330154419px;line-height:21.3333320617676px">
                            →
                        </span>
                         (X 
                        <span style="font-size:13.3333330154419px;line-height:21.3333320617676px">
                            →
                        </span>
                         Z)
                    </span>
                </li>
            </ul>
        </div>
        <div>
            <div>
                <h4>
                    <a name="TOC-:-prepend-">
                    </a>
                    : (prepend)
                </h4>
                <div>
                    <code>
                        :
                    </code>
                    is the colon character (SHIFT + ;). Named the "prepend operator", it makes a new collection by putting the left hand operand at the beginning of the collection in the right hand operand.
                </div>
                <div>
                    <ul>
                        <li>
                            as the denumerable constructor
                            <a href="prepend.php">
                                prepend
                            </a>
                            <br>
                            </br>
                            <span style="line-height:1.6;font-size:10pt;background-color:transparent">
                                Function signature: T * Denumerable&lt;T&gt; -&gt; Denumerable&lt;T&gt;
                                <br>
                                </br>
                            </span>
                        </li>
                    </ul>
                </div>
            </div>
            <div>
                <h4>
                    <a name="TOC-Set-union">
                    </a>
                    <span style="color:rgb(0,96,0);font-family:monospace;font-size:13.3333330154419px;line-height:13.3333320617676px;background-color:rgb(239,239,239)">
                        ∪ 
                    </span>
                    <span style="font-size:1.2em;line-height:1.6;background-color:transparent">
                        Set union
                    </span>
                </h4>
            </div>
            <div>
                <p>
                    Note that set union is not the 'U' character (0x55) but the UNION character (0x222A)
                </p>
                <div class="sites-codeblock sites-codesnippet-block">
                    <code>
                        expression
                    </code>
                    <code>
                        "∪"
                    </code>
                    <code>
                        expression
                    </code>
                </div>
                <div>
                    <br>
                    </br>
                </div>
                Set × Set 
                <span style="font-size:13.3333330154419px;line-height:21.3333320617676px;background-color:transparent">
                    →
                </span>
                <span style="line-height:1.6;font-size:10pt;background-color:transparent">
                     Set
                </span>
            </div>
            <div>
                <h4>
                    <a name="TOC-Set-intersection">
                    </a>
                    Set intersection
                </h4>
                <div class="sites-codeblock sites-codesnippet-block">
                    <code>
                        expression "∩" expression
                    </code>
                </div>
                <h4>
                    <a name="TOC-Set-Set-Set">
                    </a>
                    <span style="background-color:transparent">
                        <span style="font-size:13.3333330154419px;line-height:21.3333320617676px">
                            Set × Set 
                        </span>
                    </span>
                    <span style="line-height:21.3333320617676px;font-size:13.3333330154419px;background-color:transparent">
                        →
                    </span>
                    <span style="line-height:1.6;font-size:10pt;background-color:transparent">
                         Set
                    </span>
                </h4>
                <h4>
                    <a name="TOC-Set-difference-also-divide-">
                    </a>
                    Set difference (also divide)
                    <br>
                    </br>
                </h4>
                <div class="sites-codeblock sites-codesnippet-block">
                    <code>
                        expression "/" expression
                    </code>
                </div>
                <h4>
                    <a name="TOC-Set-Set-Set1">
                    </a>
                    <span style="background-color:transparent">
                        <span style="font-size:13.3333330154419px;line-height:21.3333320617676px">
                            Set × Set 
                        </span>
                    </span>
                    <span style="line-height:21.3333320617676px;font-size:13.3333330154419px;background-color:transparent">
                        →
                    </span>
                    <span style="line-height:1.6;font-size:10pt;background-color:transparent">
                         Set
                    </span>
                </h4>
                <h4>
                    <a name="TOC-Set-symmetric-difference-also-bitwise-xor-">
                    </a>
                    Set symmetric difference (also bitwise xor)
                    <br>
                    </br>
                </h4>
                <div class="sites-codeblock sites-codesnippet-block">
                    <code>
                        expression ("
                    </code>
                    <code>
                        ⊕"|"xor") expression
                    </code>
                </div>
                <h4>
                    <a name="TOC-Set-Set-Set2">
                    </a>
                    <span style="background-color:transparent">
                        <span style="font-size:13.3333330154419px;line-height:21.3333320617676px">
                            Set × Set 
                        </span>
                    </span>
                    <span style="line-height:21.3333320617676px;font-size:13.3333330154419px;background-color:transparent">
                        →
                    </span>
                    <span style="line-height:1.6;font-size:10pt;background-color:transparent">
                         Set
                    </span>
                </h4>
            </div>
        </div>
    </div>
    <div>
        <span style="font-size:13.3333px;line-height:21.3333px">
            See: 
        </span>
        <a style="font-size:13.3333px;line-height:21.3333px" href="../operators.php">
            Operators
        </a>
    </div>



		<?php require('..//footer.php') ?>
	</body>
</html>