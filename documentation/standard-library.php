<meta charset='utf-8'/><html><head><title>standard-library.html</title><link rel=StyleSheet href='../css/general.css' type='text/css' /></head><body><?php require('../header.php') ?>



    lange standard library is in the
    <code>
        Plange
    </code>
    namespace, which is the top-level (global) scope. The top-level
    <a href="syntax/statement_scope.php">
        statement_scope
    </a>
     of each source unit is within the Plange scope. As such, the following symbols are accessible immediately in a source unit.
    <h4>
        <a name="TOC-Functions">
        </a>
        Functions
    </h4>
    <div>
        <ul>
            <li>
                &lt;(Void | String) -&gt; Void&gt; print
            </li>
            <li>
                &lt;(Void | String) -&gt; Void&gt; error
            </li>
            <li>
                &lt;(Void | String) -&gt; String&gt; input
            </li>
            <li>
                &lt;String * FileMode -&gt; File&gt; open
            </li>
            <li>
                &lt;File * Int -&gt; Array&lt;Byte&gt;&gt; read
            </li>
            <li>
                &lt;File * Array&lt;Byte&gt; -&gt; Void&gt; write
            </li>
            <li>
                &lt;File * Int * SeekOrigin -&gt; Void&gt; seek
            </li>
            <li>
                &lt;File -&gt; Void&gt; flush
            </li>
            <li>
                &lt;File -&gt; Void&gt; close
            </li>
            <li>
                &lt;UInt8 -&gt; Char&gt; ansi_chr
            </li>
            <li>
                &lt;Char -&gt; Maybe&lt;UInt8&gt;&gt; ansi_ord
            </li>
            <li>
                &lt;Int32 -&gt; Char&gt; chr
            </li>
            <li>
                &lt;Char -&gt; Int32&gt; ord
            </li>
            <li>
                &lt;Any -&gt; String&gt; dump
            </li>
            <li>
                &lt;(Void | String) -&gt; Void&gt; debug
            </li>
            <li>
                &lt;Void -&gt; Void&gt; interrupt
            </li>
            <li>
                &lt;String -&gt; Value&gt; eval
            </li>
            <li>
                &lt;Any -&gt; Int32&gt; hash
            </li>
            <li>
                &lt;Collection&lt;T&gt; -&gt; T&gt; | &lt;T^_ -&gt; T&gt; min
            </li>
            <li>
                <span style="font-size:13.3333px;line-height:21.3333px">
                    &lt;Collection&lt;T&gt; -&gt; T&gt; | &lt;T^_ -&gt; T&gt; 
                </span>
                max
            </li>
            <li>
                &lt;&lt;T * T -&gt; T&gt; * Collection&lt;T&gt; -&gt; T&gt; reduce
            </li>
            <li>
                <span style="font-size:13.3333px;line-height:21.3333px">
                    &lt;&lt;T * T -&gt; T&gt; * Collection&lt;T&gt; -&gt; T&gt; 
                </span>
                reduce_r
            </li>
            <li>
                &lt;&lt;T * U -&gt; U&gt; * Collection&lt;T&gt; * U -&gt; U&gt; fold
            </li>
            <li>
                <span style="font-size:13.3333px;line-height:21.3333px">
                    &lt;&lt;T * U -&gt; U&gt; * Collection&lt;T&gt; * U -&gt; U&gt; 
                </span>
                fold_r
            </li>
            <li>
                <span style="font-size:13.3333px;line-height:21.3333px">
                    &lt;&lt;T -&gt; U&gt; * Collection&lt;T&gt; -&gt; Collection&lt;U&gt;&gt; 
                </span>
                map
            </li>
            <li>
                <span style="font-size:13.3333px;line-height:21.3333px">
                    &lt;&lt;T -&gt; Bool U -&gt; U&gt; * Collection&lt;T&gt; * U -&gt; U&gt; 
                </span>
                filter
            </li>
            <li>
                &lt;Collection&lt;T&gt; -&gt; Tuple&lt;T&gt;&gt; to_tuple - convert ordered collection or object to tuple
            </li>
            <li>
                <span style="line-height:1.6;font-size:10pt;background-color:transparent">
                    &lt;String -&gt; void&gt; | &lt;String * File * File * File -&gt; void&gt; shell - execute a command in the system shell
                </span>
            </li>
            <li>
                &lt;T -&gt; U&gt; 
                <a href="standard-library/coerce.php">
                    coerce
                </a>
                - convert a value to a different representation, possibly using lexographic algorithms
            </li>
            <li>
                help - print help information for the given object or string
            </li>
            <li>
                <br>
                </br>
            </li>
        </ul>
    </div>
    <h4>
        <a name="TOC-Types">
        </a>
        Types
    </h4>
    <div>
        <ul>
            <li>
                <span style="font-size:10pt;line-height:1.6;background-color:transparent">
                    BitArray
                </span>
            </li>
            <li>
                <span style="font-size:10pt;line-height:1.6;background-color:transparent">
                    Bool
                </span>
            </li>
            <li>
                <span style="font-size:13.3333px;line-height:21.3333px">
                    <a href="standard-library/complex.php">
                        Complex
                    </a>
                     - An element of 
                </span>
                <span style="font-size:13.3333px;line-height:21.3333px">
                    ℂ, the complex numbers { &lt;Real&gt; r; &lt;Real&gt; i; }
                </span>
            </li>
            <li>
                <a href="standard-library/executioncontext.php">
                    ExecutionContext
                </a>
                <br>
                </br>
            </li>
        </ul>
        <li>
            Float - An element of 
            <span style="font-size:13.3333px;line-height:21.3333px">
                ℚ, the rational numbers
            </span>
        </li>
        <li>
            <span style="line-height:1.6;font-size:10pt;background-color:transparent">
                Float16, Float32, Float64, Float128
            </span>
        </li>
        <li>
            <span style="line-height:21.3333px;font-size:13.3333px;background-color:transparent">
                Imaginary - An element of 
            </span>
            <span style="line-height:21.3333px;font-size:13.3333px;background-color:transparent">
                &#x1d540;
            </span>
        </li>
        <li>
            <a style="line-height:1.6;font-size:10pt;background-color:transparent" href="standard-library/int.php">
                Int
            </a>
            <span style="line-height:1.6;font-size:10pt;background-color:transparent">
                - 
            </span>
            <span style="line-height:21.3333px;font-size:13.3333px;background-color:transparent">
                An element of 
            </span>
            <span style="line-height:21.3333px;font-size:13.3333px;background-color:transparent">
                ℤ, the integers (big integer)
            </span>
        </li>
        <li>
            <span style="font-size:13.3333330154419px;line-height:21.3333320617676px">
                Int8, Int16, Int32, Int64, Int128, UInt8, UInt16, UInt32, UInt64, UInt128
            </span>
        </li>
        <li>
            Int16Set - a 65536-bit array for fast set operations
        </li>
        <li>
            <span style="line-height:1.6;font-size:10pt;background-color:transparent">
                Int8Set - a 256-bit array for fast set operations
            </span>
        </li>
        <li>
            <span style="line-height:1.6;font-size:10pt;background-color:transparent">
                Matrix&lt;r, c&gt; - An element of 
            </span>
            <span style="line-height:21.3333px;font-size:13.3333px;background-color:transparent">
                &#x1d544;(r, c)
            </span>
        </li>
        <li>
            <span style="line-height:1.6;font-size:10pt;background-color:transparent">
                Octonion - An element of 
            </span>
            <span style="line-height:21.3333px;font-size:13.3333px;background-color:transparent">
                &#x1d546;
            </span>
        </li>
        <li>
            <span style="font-size:10pt;line-height:1.6;background-color:transparent">
                Parameter
            </span>
        </li>
        <li>
            <span style="line-height:1.6;font-size:10pt;background-color:transparent">
                Quaternion - An element of ℍ
            </span>
        </li>
        <li>
            <a style="line-height:1.6;font-size:10pt;background-color:transparent" href="standard-library/real.php">
                Real
            </a>
            <span style="line-height:1.6;font-size:10pt;background-color:transparent">
                - An element of 
            </span>
            <span style="line-height:21.3333px;font-size:13.3333px;background-color:transparent">
                ℝ, the real numbers (can be coerced to BigFloat, storage is TBD and may be a relation)
            </span>
        </li>
        <li>
            <a style="font-size:13.3333px;line-height:21.3333px;background-color:transparent" href="standard-library/scope.php">
                Scope
            </a>
        </li>
        <li>
            <span style="font-size:10pt;line-height:1.6;background-color:transparent">
                String
            </span>
        </li>
        <li>
            <a href="standard-library/type.php">
                Type
            </a>
        </li>
        <li>
            <a style="line-height:1.6;font-size:10pt;background-color:transparent" href="standard-library/unit.php">
                Unit
            </a>
        </li>
        <li>
            <a style="line-height:1.6;font-size:10pt;background-color:transparent" href="standard-library/Value.php">
                Value
            </a>
        </li>
        <li>
            <a href="standard-library/void.php">
                Void
            </a>
        </li>
    </div>
    <h4>
        <a name="TOC-Constants">
        </a>
        Constants
    </h4>



<?php require('../footer.php') ?></body></html>