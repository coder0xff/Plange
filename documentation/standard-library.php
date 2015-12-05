<meta charset='utf-8'/>
<html>
	<head>
		<title>Standard Library - Plange</title>
		<link rel=StyleSheet href='../css/general.css' type='text/css' />
	</head>
	<body>
		<?php require('../header.php') ?>


		<p>The plange standard library is in the <code>Plange</code> namespace, which is the top-level (global)scope. The top-level <a href="syntax/statement_scope.php">statement_scope</a> of each source unit is within the Plange scope. As such, the following symbols are accessible immediately in a source unit.
		<h2>Functions</h2>
		<ul>
			<li>&lt;_ → Void&gt; print</li>
			<li>&lt;_ → Void&gt; error</li>
			<li>&lt;_ → String&gt; input</li>
			<li>&lt;String → Value&gt; eval</li>
			<li>&lt;_ → Void&gt; debug</li>
			<li>&lt;_ → String&gt; dump</li>
			<li>&lt;Void → Void&gt; interrupt</li>
			<li>&lt;String * FileMode → File&gt; open</li>
			<li>&lt;File * Int → Array&lt;Byte&gt;&gt; read</li>
			<li>&lt;File * Array&lt;Byte&gt; → Void&gt; write</li>
			<li>&lt;File * Int * SeekOrigin → Void&gt; seek</li>
			<li>&lt;File → Void&gt; flush</li>
			<li>&lt;File → Void&gt; close</li>
			<li>&lt;UInt8 → Char&gt; ansi_chr</li>
			<li>&lt;Char → Maybe&lt;UInt8&gt;&gt; ansi_ord</li>
			<li>&lt;Int32 → Char&gt; chr</li>
			<li>&lt;Char → Int32&gt; ord</li>
			<li>&lt;_ → Int32&gt; hash</li>
			<li>&lt;(Collection&lt;T&gt; | T^_) → T&gt; min</li>
			<li>&lt;(Collection&lt;T&gt; | T^_) → T&gt; max</li>
			<li>&lt;&lt;T * T → T&gt; * Collection&lt;T&gt; → T&gt; reduce</li>
			<li>&lt;&lt;T * T → T&gt; * Collection&lt;T&gt; → T&gt; reduce_r</li>
			<li>&lt;&lt;T * U → U&gt; * Collection&lt;T&gt; * U → U&gt; fold</li>
			<li>&lt;&lt;T * U → U&gt; * Collection&lt;T&gt; * U → U&gt; fold_r</li>
			<li>&lt;&lt;T → U&gt; * Collection&lt;T&gt; → Collection&lt;U&gt;&gt; map</li>
			<li>&lt;&lt;T → Bool U → U&gt; * Collection&lt;T&gt; * U → U&gt; filter</li>
			<li>&lt;Collection&lt;T&gt; → Tuple&lt;T&gt;&gt; to_tuple - convert ordered collection or object to tuple</li>
			<li>&lt;String → Int32&gt; | &lt;String * File * File * File → Int32&gt; shell - execute a command in the system shell</li>
			<li>&lt;T → U&gt; <a href="standard-library/coerce.php">coerce</a> - convert a value to a different representation, possibly using lexographic algorithms</li>
			<li>help - print help information for the given object or string</li>
		</ul>
		<h2>Types</h4>
		<ul>
			<li>BitArray</li>
			<li>Bool</li>
			<li><a href="standard-library/Complex.php">Complex</a> - An element of ℂ (<a href="http://www.fileformat.info/info/unicode/char/2102/index.htm">DOUBLE-STRUCK CAPITAL C U+2102</a>), the complex numbers { &lt;Real&gt; r; &lt;Real&gt; i; }</li>
			<li>Date, DateTime</li>
			<li><a href="standard-library/ExecutionContext.php">ExecutionContext</a></li>
			<li>Float - An element of ℚ (<a href="http://www.fileformat.info/info/unicode/char/211a/index.htm">DOUBLE-STRUCK CAPITAL Q U+211A</a>), the rational numbers</li>
			<li>Float16, Float32, Float64, Float128</li>
			<li>Imaginary - An element of 𝕀 (<a href="http://www.fileformat.info/info/unicode/char/1d540/index.htm">MATHEMATICAL DOUBLE-STRUCK CAPITAL I U+1D540</a>)</li>
			<li><a href="standard-library/Int.php">Int</a> - An element of ℤ (<a href="http://www.fileformat.info/info/unicode/char/2124/index.htm">DOUBLE-STRUCK CAPITAL Z U+2124</a>) , the integers (<a href="https://en.wikipedia.org/wiki/Arbitrary-precision_arithmetic">big integer</a>)</li>
			<li>Int8, Int16, Int32, Int64, Int128, UInt8, UInt16, UInt32, UInt64, UInt128</li>
			<li>Int16Set - a 65536-bit array for fast set operations</li>
			<li>Int8Set - a 256-bit array for fast set operations</li>
			<li>Matrix&lt;r, c&gt; - An element of 𝕄(r, c) (<a href="http://www.fileformat.info/info/unicode/char/1d544/index.htm">MATHEMATICAL DOUBLE-STRUCK CAPITAL M U+1D544</a>)</li>
			<li>Octonion - An element of 𝕆 (<a href="http://www.fileformat.info/info/unicode/char/1d546/index.htm">MATHEMATICAL DOUBLE-STRUCK CAPITAL O U+1D546</a>)</li>
			<li>Parameter</li>
			<li>Quaternion - An element of ℍ (<a href="http://www.fileformat.info/info/unicode/char/210d/index.htm">DOUBLE-STRUCK CAPITAL H U+210D</a>)</li>
			<li><a href="standard-library/Real.php">Real</a> - An element of ℝ (<a href="http://www.fileformat.info/info/unicode/char/211d/index.htm">DOUBLE-STRUCK CAPITAL R U+211D</a>), the real numbers (can be coerced to BigFloat, storage is TBD and may be a relation)</li>
			<li><a href="standard-library/Scope.php">Scope</a></li>
			<li>String</li>
			<li><a href="standard-library/Type.php">Type</a></li>
			<li><a href="standard-library/Unit.php">Unit</a></li>
			<li><a href="standard-library/Value.php">Value</a></li>
			<li><a href="standard-library/Void.php">Void</a></li>
		</ul>
		<h2>Constants</h2>
		<ul>
			<li>𝑒 or e (<a href="http://www.fileformat.info/info/unicode/char/1d452/fontsupport.htm">MATHEMATICAL ITALIC SMALL E U+1D452</a>) - e mathematical constant</li>
			<li>π or pi (<a href="http://www.fileformat.info/info/unicode/char/03c0/index.htm">GREEK SMALL LETTER PI U+03CO</a>) - pi mathematical constant</li>
			<li>ℕ or NN (<a href="http://www.fileformat.info/info/unicode/char/2115/index.htm">DOUBLE-STRUCK CAPITAL N U+2115</a>) - natural numbers (non-negative integers)</li>
			<li>ℂ or CC(<a href="http://www.fileformat.info/info/unicode/char/2102/index.htm">DOUBLE-STRUCK CAPITAL C U+2102</a>) - complex numbers</li>
			<li>ℚ or QQ (<a href="http://www.fileformat.info/info/unicode/char/211a/index.htm">DOUBLE-STRUCK CAPITAL Q U+211A</a>) - rational numbers</li>
			<li>ℝ or RR (<a href="http://www.fileformat.info/info/unicode/char/211d/index.htm">DOUBLE-STRUCK CAPITAL&nbsp;R U+211D</a>) - real numbers</li>
			<li>ℤ or ZZ (<a href="http://www.fileformat.info/info/unicode/char/2124/index.htm">DOUBLE-STRUCK CAPITAL&nbsp;Z U+2124</a>) - integers</li>
			<li>𝔹 or BB (<a href="http://www.fileformat.info/info/unicode/char/1d539/index.htm">MATHEMATICAL&nbsp;DOUBLE-STRUCK CAPITAL&nbsp;B U+1D539</a>) - booleans</li>
			<li>𝕎 or WW (<a href="http://www.fileformat.info/info/unicode/char/1d54e/index.htm">MATHEMATICAL&nbsp;DOUBLE-STRUCK CAPITAL&nbsp;W U+1D54E</a>) - whole numbers (positive integers)</li>
			<li>ℍ or HH (<a href="http://www.fileformat.info/info/unicode/char/210d/index.htm">DOUBLE-STRUCK CAPITAL&nbsp;H U+210D</a>) - quaternions</li>
			<li>𝕆 or OO (<a href="http://www.fileformat.info/info/unicode/char/1d546/index.htm">MATHEMATICAL&nbsp;DOUBLE-STRUCK CAPITAL&nbsp;O U+1D456</a>) - octonions</li>
			<li>𝕄(m, n) or MM(m, n) (<a href="http://www.fileformat.info/info/unicode/char/1d544/index.htm">MATHEMATICAL&nbsp;DOUBLE-STRUCK CAPITAL&nbsp;M U+1D544</a>) - m x n matrices of reals</li>
			<li>ⅈ or ii (<a href="http://www.fileformat.info/info/unicode/char/2148/index.htm">DOUBLE-STRUCK ITALIC SMALL I U+2148</a>) - imaginary unit</li>
			<li>𝕀 or II(<a href="http://www.fileformat.info/info/unicode/char/1d540/index.htm">MATHEMATICAL&nbsp;DOUBLE-STRUCK CAPITAL&nbsp;I U+1D540</a>) - imaginary numbers</li>
			<li>∅ or {} (<a href="http://www.fileformat.info/info/unicode/char/2205/index.htm">EMPTY SET U+2205</a>) - the empty set</li>
			<li>ℵ(n) (<a href="http://www.fileformat.info/info/unicode/char/2135/index.htm">ALEF SYMBOL U+2135</a>) - When n = 0, the cardinality of ℕ, |ℕ|&nbsp;</li>
			<li>env - the environment variables</li>
			<li>args - the command line arguments</li>
			<li>i - the primary axis' unit 2-vector or 3-vector</li>
			<li>j - the secondary axis' unit 2-vector or 3-vector</li>
			<li>k - the tertiary axis' unit 3-vector</li>
		</ul>
		<h2>Type Functions</h2>
		<p>Notes: For parallel processing, "Ts" collections are thread safe, and "C" collections are concurrent. Concurrent collections provide an interface that differs from their non-concurrent counterparts. These interface variants facilitate provable correctness for some concurrent algorithms and should be preferred over other collections for such applications. Thread safe and concurrent collections are implemented with lock free algorithms whenever possible. Thread safe collections do not provide interfaces that encourage logical correctness, but they do guarantee that each operation executed by a thread appears atomic to all other threads.</p>
		<ul>
			<li><a href="/documentation/standard-library/Const.php">Const</a></li>
			<li><a href="/documentation/standard-library/Function.php">Function</a></li>
			<li>Enumerable</li>
			<li><a href="/documentation/standard-library/Accessor.php">Accessor</a></li>
			<li>Complex</li>
			<li>Quaternion</li>
			<li>Octonion</li>
			<li>Matrix</li>
			<li>Pointer</li>
			<li>Array, TsArray</li>
			<li>List, TsList</li>
			<li>Vector, TsVector</li>
			<li>Stack, CStack</li>
			<li>Queue, CQueue</li>
			<li>Deque, TsDeque</li>
			<li>Set, HashSet, TsSet, TsHashSet, CSet</li>
			<li>Map, HashMap, TsMap, TsHashMap, CMap</li>
			<li>Bimap, HashBimap TsBimap, TsHashBimap</li>
			<li>Bag, CBag</li>
			<li>BinNode, TsBinNode</li>
			<li>KNode, TsKNode (a node of a K-ary tree)</li>
			<li>MultiMap, TsMultiMap</span></li>
			<li>MaxHeap, MinHeap, TsMaxHeap, TsMinHeap, CoalescingTsMaxHeap</li>
			<li>Producer</li>
			<li>Consumer</li>
			<li>Collection,&nbsp;ReadOnlyCollection</li>
			<li>Iterator</li>
			<li>Enumerable</li>
			<li>ThreadLocal</li>
			<li>Predicate := (&lt;Type&gt; Operand) { return Operand → Bool; };</li>
			<li>BinaryRelation := (&lt;Type&gt; Left, &lt;Type&gt; Right) { return Left * Right → Bool; };</li>
		</ul>
		<h2>Namespaces</h2>
		<ul>
			<li>Gtk</li>
			<li>OpenGL</li>
			<li>OpenSL</li>
			<li>Cas</li>
			<li>Compiler</li>
			<li>Parser</li>
			<li>IO</li>
			<li>Task</li>
			<li>Units (dimensional analysis)</li>
			<li>Runtime</li>
		</ul>


		<?php require('../footer.php') ?>
	</body>
</html>