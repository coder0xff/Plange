<meta charset='utf-8'/>
<html>
	<head>
		<title>asm - Plange</title>
		<link rel=StyleSheet href='../../css/general.css' type='text/css' />
	</head>
	<body>
		<?php require('../../header.php') ?>



        indicates that the following block of code enclosed in curly braces is assembler instructions, and creates a nullary void function object.
        <br>
        </br>
        <div style="margin-top:12pt;margin-bottom:12pt;border-style:solid;border-width:1px">
            <p style="font-size:12pt;margin:0px;padding-left:6pt;background-color:#cda">
                Example
            </p>
            <pre style="margin:0px;padding:3px;width:715px;max-height:500px;overflow:auto">
                <font face="Courier New">
                    &lt;Float32x3 * Float32x3 -&gt; Float32x3&gt; crossMultiply := (lhs, rhs) =&gt; {
    &lt;Float32x4&gt; result;
    implementation := asm sse4 {
        //where (a, b, c) = lhs
        //where (d, e, f) = rhs

        //xmm0 = b * f, c * d, a * e, _ * _
        shufps xmm0, lhs, 0x06 // b c a _ -&gt; 01 10 00 00 -&gt; 00000110
        shufps xmm1, rhs, 0x12 // f d e _ -&gt; 10 00 01 00 -&gt; 00010010
        mulps xmm0, xmm1

        //xmm1 = c * e, a * f, b * d, _ * _
        shufps xmm1, lhs, 0x12 // c a b _ -&gt; 10 00 01 00 -&gt; 00010010
        shufps xmm2, rhs, 0x06 // e f d _ -&gt; 01 10 00 00 -&gt; 00000110
        mulps xmm1, xmm2

        //xmm0 = b*f - c*e, c*d - a*f, a*e - b*d
        subps xmm0, xmm1
        movps result, xmm0
    } | {
        result &lt;- (
            lhs(1)*rhs(2)-lhs(2)*rhs(1),
            lhs(2)*rhs(0)-lhs(0)*rhs(2),
            lhs(0)*rhs(1)-lhs(1)*rhs(0)
        );
    };
    implementation();
    return reinterpret_cast&lt;Float32x3&gt;(result);
}
                </font>
            </pre>
        </div>
    </div>
    <h4>
        <a name="TOC-Notes">
        </a>
        Notes
    </h4>
    <div>
        <span style="font-size:13.3333px;line-height:21.3333px;background-color:transparent">
            Zero or more symbols may be listed after the asm keyword as options. The asm keyword creates an opaque function object that may be or'd together to make a single function object with different implementations for different target platforms. It may also be or'd with a conventional nullary void function so that an implementation is available for platforms that have not been explicitly targeted.
        </span>
    </div>
    <div>
        <span style="font-size:13.3333px;line-height:21.3333px;background-color:transparent">
            <br>
            </br>
        </span>
    </div>
    Built in target symbols include:
    <ul>
        <li>
            intel_syntax (default)
        </li>
        <li>
            att_syntax
        </li>
        <li>
            x86
        </li>
        <li>
            x86_64
        </li>
        <li>
            arm
        </li>
        <li>
            mips
        </li>
        <li>
            <a href="../../../../../external.php?link=https://en.wikipedia.org/wiki/ARM_architecture#Advanced_SIMD_.28NEON.29" rel="nofollow">
                neon
            </a>
        </li>
        <li>
            <a href="../../../../../external.php?link=https://en.wikipedia.org/wiki/SSE4" rel="nofollow">
                sse4
            </a>
        </li>
        <li>
            aes
        </li>
        <li>
            avx
        </li>
        <li>
            fma
        </li>
    </ul>
    <p>
        This list may be expanded.
        <br>
        </br>
    </p>



		<?php require('../../footer.php') ?>
	</body>
</html>