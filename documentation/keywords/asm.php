<meta charset='utf-8'/>
<meta name="viewport" content="width=device-width, initial-scale=0.6">
<html>
    <head>
        <title>abstract - Plange</title>
        <link rel=StyleSheet href='../../css/general.css' type='text/css' />
    </head>
    <body>
        <?php require('../../header.php') ?>
        

        <p>indicates that the following block of code enclosed in curly braces is assembler instructions, and creates a nullary void function object</p>
        <div class="code2">
            <p>Example</p>
            <pre>
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
            </pre>
        </div>
        <h2>Notes</h2>
        <p>Zero or more symbols may be listed after the asm keyword as options. The asm keyword creates an opaque function object that may be or'd together to make a single function object with different implementations for different target platforms. It may also be or'd with a conventional nullary void function so that an implementation is available for platforms that have not been explicitly targeted.</p>
        <p>Built in target symbols include:</p>
        <ul>
            <li>intel_syntax (default)</li>
            <li>att_syntax</li>
            <li>x86</li>
            <li>x86_64</li>
            <li>arm</li>
            <li>mips</li>
            <li><a href="https://en.wikipedia.org/wiki/ARM_architecture#Advanced_SIMD_.28NEON.29" rel="nofollow">neon</a></li>
            <li><a href="https://en.wikipedia.org/wiki/SSE4" rel="nofollow">sse4</a></li>
            <li>aes</li>
            <li>avx</li>
            <li>fma</li>
        </ul>
        <p>This list may be expanded.</p>


        <?php require('footer.php') ?>
    </body>
</html>
