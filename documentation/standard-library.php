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
		<code>
			<table style="width:2000px;">
				<tr><th>Signature</th><th>Comments</th></tr>
				<tr><td>&lt;UInt8 → Char&gt; ansi_chr</td></tr>
				<tr><td>&lt;Char → Maybe&lt;UInt8&gt;&gt; ansi_ord</td></tr>
				<tr><td>&lt;Int32 → Char&gt; chr</td></tr>
				<tr><td>&lt;File → Void&gt; close</td></tr>
				<tr><td>&lt;T → U&gt; <a href="standard-library/coerce.php">coerce</a></td><td>convert a value to a different representation, possibly using lexographic algorithms</td></tr>
				<tr><td>&lt;_ → Void&gt; debug</td></tr>
				<tr><td>&lt;_ → String&gt; dump</td></tr>
				<tr><td>&lt;_ → Void&gt; error</td></tr>
				<tr><td>&lt;String → Value&gt; eval</td></tr>
				<tr><td>&lt;File → Void&gt; flush</td></tr>
				<tr><td>&lt;&lt;T → Maybe&lt;U&gt; * Collection&lt;T&gt; → Collection&lt;U&gt; filter</td></tr>
				<tr><td>&lt;&lt;T * U → U&gt; * Collection&lt;T&gt; * U → U&gt; fold</td></tr>
				<tr><td>&lt;&lt;T * U → U&gt; * Collection&lt;T&gt; * U → U&gt; fold_r</td></tr>
				<tr><td>&lt;_ → Int32&gt; hash</td></tr>
				<tr><td>&lt;Void → Void&gt; help</td><td>print help information for the given object or string</td></tr>
				<tr><td>&lt;_ → String&gt; input</td></tr>
				<tr><td>&lt;Void → Void&gt; interrupt</td></tr>
				<tr><td>&lt;&lt;T → U&gt; * Collection&lt;T&gt; → Collection&lt;U&gt;&gt; map</td></tr>
				<tr><td>&lt;(Collection&lt;T&gt; | T^_) → T&gt; max</td></tr>
				<tr><td>&lt;(Collection&lt;T&gt; | T^_) → T&gt; min</td></tr>
				<tr><td>&lt;String * FileMode → File&gt; open</td></tr>
				<tr><td>&lt;Char → Int32&gt; ord</td></tr>
				<tr><td>&lt;_ → Void&gt; print</td></tr>
				<tr><td>&lt;File * Int → Array&lt;Byte&gt;&gt; read</td></tr>
				<tr><td>&lt;&lt;T * T → T&gt; * Collection&lt;T&gt; → T&gt; reduce</td></tr>
				<tr><td>&lt;&lt;T * T → T&gt; * Collection&lt;T&gt; → T&gt; reduce_r</td></tr>
				<tr><td>&lt;File * Int * SeekOrigin → Void&gt; seek</td></tr>
				<tr><td>&lt;String → Int32&gt; | &lt;String * File * File * File → Int32&gt; shell</td><td>execute a command in the system shell</td></tr>
				<tr><td>&lt;Collection&lt;T&gt; → Tuple&lt;T&gt;&gt; to_tuple</td><td>convert an ordered collection or object to tuple</td></tr>
				<tr><td>&lt;File * Array&lt;Byte&gt; → Void&gt; write</td></tr>
			</table>
		</code>
		<h2>Types</h4>
		<code>
			<table style="width:2000px;">
				<tr><th>Name</th><th>Comments</th></tr>
				<tr><td>BitArray</td></tr>
				<tr><td>Bool</td></tr>
				<tr><td><a href="standard-library/Complex.php">Complex</a></td><td>An element of ℂ (<a href="http://www.fileformat.info/info/unicode/char/2102/index.htm">DOUBLE-STRUCK CAPITAL C U+2102</a>), the complex numbers { &lt;Real&gt; r; &lt;Real&gt; i; }</td></tr>
				<tr><td>Date, DateTime</td></tr>
				<tr><td><a href="standard-library/ExecutionContext.php">ExecutionContext</a></td></tr>
				<tr><td>Expression</td></tr>
				<tr><td>Float</td><td>An element of ℚ (<a href="http://www.fileformat.info/info/unicode/char/211a/index.htm">DOUBLE-STRUCK CAPITAL Q U+211A</a>), the rational numbers</td></tr>
				<tr><td>Float16, Float32, Float64, Float128</td></tr>
				<tr><td>Imaginary</td><td>An element of 𝕀 (<a href="http://www.fileformat.info/info/unicode/char/1d540/index.htm">MATHEMATICAL DOUBLE-STRUCK CAPITAL I U+1D540</a>)</td></tr>
				<tr><td><a href="standard-library/Int.php">Int</a></td><td>An element of ℤ (<a href="http://www.fileformat.info/info/unicode/char/2124/index.htm">DOUBLE-STRUCK CAPITAL Z U+2124</a>) , the integers (<a href="https://en.wikipedia.org/wiki/Arbitrary-precision_arithmetic">big integer</a>)</td></tr>
				<tr><td>Int8, Int16, Int32, Int64, Int128, UInt8, UInt16, UInt32, UInt64, UInt128</td></tr>
				<tr><td>Int16Set</td><td>a 65536-bit array for fast set operations</td></tr>
				<tr><td>Int8Set</td><td>a 256-bit array for fast set operations</td></tr>
				<tr><td>Octonion</td><td>An element of 𝕆 (<a href="http://www.fileformat.info/info/unicode/char/1d546/index.htm">MATHEMATICAL DOUBLE-STRUCK CAPITAL O U+1D546</a>)</td></tr>
				<tr><td>Parameter</td></tr>
				<tr><td>Quaternion</td><td>An element of ℍ (<a href="http://www.fileformat.info/info/unicode/char/210d/index.htm">DOUBLE-STRUCK CAPITAL H U+210D</a>)</td></tr>
				<tr><td><a href="standard-library/Real.php">Real</a></td><td>An element of ℝ (<a href="http://www.fileformat.info/info/unicode/char/211d/index.htm">DOUBLE-STRUCK CAPITAL R U+211D</a>), the real numbers (either BigFloat or an algebraic value)</td></tr>
				<tr><td><a href="standard-library/Scope.php">Scope</a></td></tr>
				<tr><td>String</td></tr>
				<tr><td><a href="standard-library/Type.php">Type</a></td></tr>
				<tr><td><a href="standard-library/Unit.php">Unit</a></td></tr>
				<tr><td><a href="standard-library/Value.php">Value</a></td></tr>
				<tr><td><a href="standard-library/Void.php">Void</a></td></tr>
			</table>
		</code>
		<h2>Constants</h2>
		<code>
			<table style="width:2000px;">
				<tr><td>π</td><td>pi</td><td>(<a href="http://www.fileformat.info/info/unicode/char/03c0/index.htm">GREEK SMALL LETTER PI U+03CO</a>)</td><td>pi mathematical constant</td></tr>
				<tr><td>ℂ</td><td>CC</td><td>(<a href="http://www.fileformat.info/info/unicode/char/2102/index.htm">DOUBLE-STRUCK CAPITAL C U+2102</a>)</td><td>complex numbers</td></tr>
				<tr><td>ℍ</td><td>HH</td><td>(<a href="http://www.fileformat.info/info/unicode/char/210d/index.htm">DOUBLE-STRUCK CAPITAL&nbsp;H U+210D</a>)</td><td>quaternions</td></tr>
				<tr><td>ℕ</td><td>NN</td><td>(<a href="http://www.fileformat.info/info/unicode/char/2115/index.htm">DOUBLE-STRUCK CAPITAL N U+2115</a>)</td><td>natural numbers (non-negative integers)</td></tr>
				<tr><td>ℚ</td><td>QQ</td><td>(<a href="http://www.fileformat.info/info/unicode/char/211a/index.htm">DOUBLE-STRUCK CAPITAL Q U+211A</a>)</td><td>rational numbers</td></tr>
				<tr><td>ℝ</td><td>RR</td><td>(<a href="http://www.fileformat.info/info/unicode/char/211d/index.htm">DOUBLE-STRUCK CAPITAL&nbsp;R U+211D</a>)</td><td>real numbers</td></tr>
				<tr><td>ℤ</td><td>ZZ</td><td>(<a href="http://www.fileformat.info/info/unicode/char/2124/index.htm">DOUBLE-STRUCK CAPITAL&nbsp;Z U+2124</a>)</td><td>integers</td></tr>
				<tr><td>ℵ(n)</td><td></td><td>(<a href="http://www.fileformat.info/info/unicode/char/2135/index.htm">ALEF SYMBOL U+2135</a>)</td><td>When n = 0, the cardinality of ℕ, |ℕ|&nbsp;</td></tr>
				<tr><td>ⅈ</td><td>ii</td><td>(<a href="http://www.fileformat.info/info/unicode/char/2148/index.htm">DOUBLE-STRUCK ITALIC SMALL I U+2148</a>)</td><td>imaginary unit</td></tr>
				<tr><td>∅</td><td>{}</td><td>(<a href="http://www.fileformat.info/info/unicode/char/2205/index.htm">EMPTY SET U+2205</a>)</td><td>the empty set</td></tr>
				<tr><td>𝑒</td><td>e</td><td>(<a href="http://www.fileformat.info/info/unicode/char/1d452/index.htm">MATHEMATICAL ITALIC SMALL E U+1D452</a>)</td><td>e mathematical constant</td></tr>
				<tr><td>𝕄(m, n)</td><td>MM(m, n)</td><td>(<a href="http://www.fileformat.info/info/unicode/char/1d544/index.htm">MATHEMATICAL&nbsp;DOUBLE-STRUCK CAPITAL&nbsp;M U+1D544</a>)</td><td>m x n matrices of reals</td></tr>
				<tr><td>𝕆</td><td>OO</td><td>(<a href="http://www.fileformat.info/info/unicode/char/1d546/index.htm">MATHEMATICAL&nbsp;DOUBLE-STRUCK CAPITAL&nbsp;O U+1D456</a>)</td><td>octonions</td></tr>
				<tr><td>𝕎</td><td>WW</td><td>(<a href="http://www.fileformat.info/info/unicode/char/1d54e/index.htm">MATHEMATICAL&nbsp;DOUBLE-STRUCK CAPITAL&nbsp;W U+1D54E</a>)</td><td>whole numbers (positive integers)</td></tr>
				<tr><td>𝕀</td><td>II</td><td>(<a href="http://www.fileformat.info/info/unicode/char/1d540/index.htm">MATHEMATICAL&nbsp;DOUBLE-STRUCK CAPITAL&nbsp;I U+1D540</a>)</td><td>imaginary numbers</td></tr>
				<tr><td>𝔹</td><td>BB</td><td>(<a href="http://www.fileformat.info/info/unicode/char/1d539/index.htm">MATHEMATICAL&nbsp;DOUBLE-STRUCK CAPITAL&nbsp;B U+1D539</a>)</td><td>booleans</td></tr>
				<tr><td>env</td><td></td><td></td><td>the environment variables</td></tr>
				<tr><td>args</td><td></td><td></td><td>the command line arguments</td></tr>
				<tr><td>i</td><td></td><td></td><td>the primary axis' unit 2-vector or 3-vector</td></tr>
				<tr><td>j</td><td></td><td></td><td>the secondary axis' unit 2-vector or 3-vector</td></tr>
				<tr><td>k</td><td></td><td></td><td>the tertiary axis' unit 3-vector</td></tr>
			</table>
		</code>
		<h2>Type Functions</h2>
		<p>Notes: For parallel processing, "Ts" collections are thread safe, and "C" collections are concurrent. Concurrent collections provide an interface that differs from their non-concurrent counterparts. These interface variants facilitate provable correctness for some concurrent algorithms and should be preferred over other collections for such applications. Thread safe and concurrent collections are implemented with lock free algorithms whenever possible. Thread safe collections do not provide interfaces that encourage logical correctness, but they do guarantee that each operation executed by a thread appears atomic to all other threads.</p>
		<code>
			<table style="width:2000px;">
				<tr><td><a href="/documentation/standard-library/Accessor.php">Accessor</a></td></tr>
				<tr><td>Array, TsArray</td></tr>
				<tr><td>Bag, CBag</td></tr>
				<tr><td>BinaryRelation</td><td>(&lt;Type&gt; Left, &lt;Type&gt; Right) { return Left * Right → Bool; };</td></tr>
				<tr><td>Bimap, HashBimap TsBimap, TsHashBimap</td></tr>
				<tr><td>BinNode, TsBinNode</td></tr>
				<tr><td>Collection,&nbsp;ReadOnlyCollection</td></tr>
				<tr><td>Complex</td></tr>
				<tr><td><a href="/documentation/standard-library/Const.php">Const</a></td></tr>
				<tr><td>Consumer</td></tr>
				<tr><td>Deque, TsDeque</td></tr>
				<tr><td>Enumerable</td></tr>
				<tr><td><a href="/documentation/standard-library/Function.php">Function</a></td></tr>
				<tr><td>Iterator</td></tr>
				<tr><td>KAryNode, TsKAryNode (a node of a K-ary tree)</td></tr>
				<tr><td>List, TsList</td></tr>
				<tr><td>Map, HashMap, TsMap, TsHashMap, CMap</td></tr>
				<tr><td>Matrix</td></tr>
				<tr><td>MaxHeap, MinHeap, TsMaxHeap, TsMinHeap, CoalescingTsMaxHeap</td></tr>
				<tr><td>MultiMap, TsMultiMap</span></td></tr>
				<tr><td>Octonion</td></tr>
				<tr><td>Pointer</td></tr>
				<tr><td>Predicate</td><td>(&lt;Type&gt; Operand) { return Operand → Bool; };</td></tr>
				<tr><td>Producer</td></tr>
				<tr><td>Quaternion</td></tr>
				<tr><td>Queue, CQueue</td></tr>
				<tr><td>Set, HashSet, TsSet, TsHashSet, CSet</td></tr>
				<tr><td>Stack, CStack</td></tr>
				<tr><td>ThreadLocal</td></tr>
				<tr><td>Vector, TsVector</td></tr>
			</table>
		</code>
		<h2>Namespaces</h2>
		<code>
			<table style="width:2000px;">
				<tr><td>Cas</td></tr>
				<tr><td>Compiler</td></tr>
				<tr><td>Gtk</td></tr>
				<tr><td>IO</td></tr>
				<tr><td>OpenGL</td></tr>
				<tr><td>OpenSL</td></tr>
				<tr><td>Parser</td></tr>
				<tr><td>Runtime</td></tr>
				<tr><td>Task</td></tr>
				<tr><td>Units</td><td>(dimensional analysis)</td></tr>
			</table>
		</code>


		<?php require('../footer.php') ?>
	</body>
</html>