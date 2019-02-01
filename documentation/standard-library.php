<meta charset='utf-8'/>
<meta name="viewport" content="width=device-width, initial-scale=0.6">
<html>
	<head>
		<title>Standard Library - Plange</title>
		<link rel=StyleSheet href='../css/general.css' type='text/css' />
	</head>
	<body>
		<?php require('../header.php') ?>


		<p>The plange standard library is in the <code>Plange</code> namespace, which is the top-level (global) namespace. The top-level <a href="syntax.php?name=STATEMENT_SCOPE">statement_scope</a> of each source unit is within the Plange namespace. As such, the following symbols are accessible immediately in a source unit.
		<h2>Functions</h2>
		<code>
			<table style="width:2000px;">
				<tr><th>Signature</th><th>Comments</th></tr>
				<tr><td>&lt;Number → Number&gt; abs</td><td>absolute value</td></tr>
				<tr><td>&lt;UInt8 → Char&gt; ansi_chr</td></tr>
				<tr><td>&lt;Char → Maybe&lt;UInt8&gt;&gt; ansi_ord</td></tr>
				<tr><td>&lt;Bool * String → Void&gt; assert</td></tr>
				<tr><td>&lt;Int32 → Char&gt; chr</td></tr>
				<tr><td>&lt;File → Void&gt; close</td></tr>
				<tr><td>&lt;T → U&gt; <a href="/documentation/standard-library/coerce.php">coerce</a></td><td>convert a value to a different representation, possibly using lexographic algorithms</td></tr>
				<tr><td>&lt;Void → Void&gt; collect</td><td>trigger garbage collection if the runtime deems it sensible</td></tr>
				<tr><td>&lt;Function&lt;T, T, Pointer, argTypes...&gt;&gt; construct</td></tr>
				<tr><td>&lt;Function&lt;T, U, ^argTypes&gt; * U → Function&gt;T, argTypes...&gt; curry</td></tr>
				<tr><td>&lt;_ → Void&gt; debug</td></tr>
				<tr><td>&lt;_ → String&gt; dump</td></tr>
				<tr><td>&lt;_ → Void&gt; error</td></tr>
				<tr><td>&lt;String → Value&gt; eval</td></tr>
				<tr><td>&lt;File → Void&gt; flush</td></tr>
				<tr><td>&lt;&lt;T → Maybe&lt;U&gt; * Collection&lt;T&gt; → Collection&lt;U&gt; filter</td></tr>
				<tr><td>&lt;&lt;T * U → U&gt; * Collection&lt;T&gt; * U → U&gt; fold</td></tr>
				<tr><td>&lt;&lt;T * U → U&gt; * Collection&lt;T&gt; * U → U&gt; fold_r</td></tr>
				<tr><td>&lt;_ → Int32&gt; hash</td></tr>
				<tr><td>&lt;Void → Void&gt; help</td><td>print help information for the given object or string</td></tr>
				<tr><td>&lt;_ → String&gt; input</td></tr>
				<tr><td>&lt;Void → Void&gt; interrupt</td><td>programmatically trigger a breakpoint</td></td></tr>
				<tr><td>&lt;&lt;T → U&gt; * Collection&lt;T&gt; → Collection&lt;U&gt;&gt; map</td></tr>
				<tr><td>&lt;(Collection&lt;T&gt; | T^_) → T&gt; max</td></tr>
				<tr><td>&lt;(Collection&lt;T&gt; | T^_) → T&gt; min</td></tr>
				<tr><td>&lt;Void → DateTime&gt; now</td></tr>
				<tr><td>&lt;String * FileMode → File&gt; open</td></tr>
				<tr><td>&lt;Char → Int32&gt; ord</td></tr>
				<tr><td>&lt;_ → Void&gt; print</td></tr>
				<tr><td>&lt;_ → Void&gt; print_line</td></tr>
				<tr><td>&lt;File * Int → Array&lt;Byte&gt;&gt; read</td></tr>
				<tr><td>&lt;&lt;T * T → T&gt; * Collection&lt;T&gt; → T&gt; reduce</td></tr>
				<tr><td>&lt;&lt;T * T → T&gt; * Collection&lt;T&gt; → T&gt; reduce_r</td></tr>
				<tr><td>&lt;File * Int * SeekOrigin → Void&gt; seek</td></tr>
				<tr><td>&lt;String → Int32&gt; | &lt;String * File * File * File → Int32&gt; shell</td><td>execute a command in the system shell</td></tr>
				<tr><td>&lt;Collection&lt;T&gt; → Tuple&lt;T&gt;&gt; to_tuple</td><td>convert an ordered collection or object to tuple</td></tr>
				<tr><td>&lt;Void → Date&gt; today</td></tr>
				<tr><td>&lt;File * Array&lt;Byte&gt; → Void&gt; write</td></tr>
			</table>
		</code>
		<h2>Types</h4>
		<code>
			<table style="width:2000px;">
				<tr><th>Name</th><th>Comments</th></tr>
				<tr><td>BitArray</td></tr>
				<tr><td>Bool</td></tr>
				<tr><td><a href="/documentation/standard-library/Complex.php">Complex</a></td><td>An element of ℂ (<a href="http://www.fileformat.info/info/unicode/char/2102/index.htm">DOUBLE-STRUCK CAPITAL C U+2102</a>), the complex numbers { &lt;Real&gt; r; &lt;Real&gt; i; }</td></tr>
				<tr><td>Date, DateTime</td></tr>
				<tr><td><a href="/documentation/standard-library/ExecutionContext.php">ExecutionContext</a></td></tr>
				<tr><td>Expression</td></tr>
				<tr><td>Float</td><td>An element of ℚ (<a href="http://www.fileformat.info/info/unicode/char/211a/index.htm">DOUBLE-STRUCK CAPITAL Q U+211A</a>), the rational numbers</td></tr>
				<tr><td>Float16, Float32, Float64, Float128</td></tr>
				<tr><td>Imaginary</td><td>An element of 𝕀 (<a href="http://www.fileformat.info/info/unicode/char/1d540/index.htm">MATHEMATICAL DOUBLE-STRUCK CAPITAL I U+1D540</a>)</td></tr>
				<tr><td><a href="/documentation/standard-library/Int.php">Int</a></td><td>An element of ℤ (<a href="http://www.fileformat.info/info/unicode/char/2124/index.htm">DOUBLE-STRUCK CAPITAL Z U+2124</a>) , the integers (<a href="https://en.wikipedia.org/wiki/Arbitrary-precision_arithmetic">big integer</a>)</td></tr>
				<tr><td>Int8, Int16, Int32, Int64, Int128, UInt8, UInt16, UInt32, UInt64, UInt128</td></tr>
				<tr><td>Int16Set</td><td>a 65536-bit array for fast set operations</td></tr>
				<tr><td>Int24Set</td><td>a 16777216-bit (2M) array for fast set operations</td></tr>
				<tr><td>Int8Set</td><td>a 256-bit array for fast set operations</td></tr>
				<tr><td>Octonion</td><td>An element of 𝕆 (<a href="http://www.fileformat.info/info/unicode/char/1d546/index.htm">MATHEMATICAL DOUBLE-STRUCK CAPITAL O U+1D546</a>)</td></tr>
				<tr><td>Parameter</td></tr>
				<tr><td>Quaternion</td><td>An element of ℍ (<a href="http://www.fileformat.info/info/unicode/char/210d/index.htm">DOUBLE-STRUCK CAPITAL H U+210D</a>)</td></tr>
				<tr><td><a href="/documentation/standard-library/Real.php">Real</a></td><td>An element of ℝ (<a href="http://www.fileformat.info/info/unicode/char/211d/index.htm">DOUBLE-STRUCK CAPITAL R U+211D</a>), the real numbers (either BigFloat or an algebraic value)</td></tr>
				<tr><td><a href="/documentation/standard-library/Relation.php">Relation</a></td></tr>
				<tr><td><a href="/documentation/standard-library/Scope.php">Scope</a></td></tr>
				<tr><td>String</td></tr>
				<tr><td><a href="/documentation/standard-library/Type.php">Type</a></td></tr>
				<tr><td><a href="/documentation/standard-library/Unit.php">Unit</a></td></tr>
				<tr><td><a href="/documentation/standard-library/UnitOfMeasure.php">UnitOfMeasure</a></td></tr>
				<tr><td><a href="/documentation/standard-library/Value.php">Value</a></td></tr>
				<tr><td><a href="/documentation/standard-library/Void.php">Void</a></td></tr>
			</table>
		</code>
		<h2>Constants</h2>
		<code>
			<table style="width:2000px;">
				<tr><td>args</td><td></td><td></td><td>the command line arguments</td></tr>
				<tr><td>env</td><td></td><td></td><td>the environment variables</td></tr>
				<tr><td>false</td><td></td><td></td><td>one of two values that a Bool may take, the other being true</td></tr>
				<tr><td>endline</td><td>the platform-specific endline string</td></tr>
				<tr><td>null</td><td></td><td></td><td>the null pointer</td></tr>
				<tr><td>true</td><td></td><td></td><td>one of two values that a Bool may take, the other being false</td></tr>
				<tr><td>π</td><td>pi</td><td>(<a href="http://www.fileformat.info/info/unicode/char/03c0/index.htm">GREEK SMALL LETTER PI U+03CO</a>)</td><td>pi mathematical constant</td></tr>
				<tr><td>ℂ</td><td>CC</td><td>(<a href="http://www.fileformat.info/info/unicode/char/2102/index.htm">DOUBLE-STRUCK CAPITAL C U+2102</a>)</td><td>complex numbers</td></tr>
				<tr><td>ℍ</td><td>HH</td><td>(<a href="http://www.fileformat.info/info/unicode/char/210d/index.htm">DOUBLE-STRUCK CAPITAL H U+210D</a>)</td><td>quaternions</td></tr>
				<tr><td>ℕ</td><td>NN</td><td>(<a href="http://www.fileformat.info/info/unicode/char/2115/index.htm">DOUBLE-STRUCK CAPITAL N U+2115</a>)</td><td>natural numbers (positive integers)</td></tr>
				<tr><td>ℚ</td><td>QQ</td><td>(<a href="http://www.fileformat.info/info/unicode/char/211a/index.htm">DOUBLE-STRUCK CAPITAL Q U+211A</a>)</td><td>rational numbers</td></tr>
				<tr><td>ℝ</td><td>RR</td><td>(<a href="http://www.fileformat.info/info/unicode/char/211d/index.htm">DOUBLE-STRUCK CAPITAL R U+211D</a>)</td><td>real numbers</td></tr>
				<tr><td>ℤ</td><td>ZZ</td><td>(<a href="http://www.fileformat.info/info/unicode/char/2124/index.htm">DOUBLE-STRUCK CAPITAL Z U+2124</a>)</td><td>integers</td></tr>
				<tr><td>ℵ(n)</td><td></td><td>(<a href="http://www.fileformat.info/info/unicode/char/2135/index.htm">ALEF SYMBOL U+2135</a>)</td><td>When n = 0, the cardinality of ℕ, |ℕ|</td></tr>
				<tr><td>𝑖</td><td>ii</td><td>(<a href="http://www.fileformat.info/info/unicode/char/1d456/index.htm">MATHEMATICAL ITALIC SMALL I U+1D456</a>)</td><td>imaginary unit</td></tr>
				<tr><td>∅</td><td>{||}</td><td>(<a href="http://www.fileformat.info/info/unicode/char/2205/index.htm">EMPTY SET U+2205</a>)</td><td>the empty set</td></tr>
				<tr><td>𝑒</td><td>e</td><td>(<a href="http://www.fileformat.info/info/unicode/char/1d452/index.htm">MATHEMATICAL ITALIC SMALL E U+1D452</a>)</td><td>e mathematical constant</td></tr>
				<tr><td>𝔹</td><td>BB</td><td>(<a href="http://www.fileformat.info/info/unicode/char/1d539/index.htm">MATHEMATICA DOUBLE-STRUCK CAPITAL B U+1D539</a>)</td><td>booleans</td></tr>
				<tr><td>𝕀</td><td>II</td><td>(<a href="http://www.fileformat.info/info/unicode/char/1d540/index.htm">MATHEMATICAL DOUBLE-STRUCK CAPITAL I U+1D540</a>)</td><td>imaginary numbers</td></tr>
				<tr><td>𝕄(m, n)</td><td>MM(m, n)</td><td>(<a href="http://www.fileformat.info/info/unicode/char/1d544/index.htm">MATHEMATICAL DOUBLE-STRUCK CAPITAL M U+1D544</a>)</td><td>m x n matrices of reals</td></tr>
				<tr><td>𝕆</td><td>OO</td><td>(<a href="http://www.fileformat.info/info/unicode/char/1d546/index.htm">MATHEMATICAL DOUBLE-STRUCK CAPITAL O U+1D546</a>)</td><td>octonions</td></tr>
				<tr><td>𝕎</td><td>WW</td><td>(<a href="http://www.fileformat.info/info/unicode/char/1d54e/index.htm">MATHEMATICAL DOUBLE-STRUCK CAPITAL W U+1D54E</a>)</td><td>whole numbers (non-negative integers)</td></tr>
			</table>
		</code>
		<h2>Type Functions</h2>
		<p>Notes: For parallel processing, "Ts" collections are thread safe, and "C" collections are concurrent. Concurrent collections provide an interface that differs from their non-concurrent counterparts - primarily using read-modify-write idioms. These interface variants facilitate provable correctness for some concurrent algorithms and should be preferred over other collections for such applications. Thread safe and concurrent collections are implemented with lock free algorithms whenever possible. Thread safe collections do not provide interfaces that encourage logical correctness, but they do guarantee that each operation executed by a thread appears atomic to all other threads.</p>
		<code>
			<table style="width:2000px;">
				<tr><td><a href="/documentation/standard-library/Accessor.php">Accessor</a></td></tr>
				<tr><td>Array, TsArray</td></tr>
				<tr><td>Bag, CBag</td></tr>
				<tr><td>BidirectionalIterator</td></tr>
				<tr><td>BinaryRelation</td><td>(&lt;Type&gt; Left, &lt;Type&gt; Right) { return Left * Right → Bool; };</td></tr>
				<tr><td>Bimap, HashBimap TsBimap, TsHashBimap</td></tr>
				<tr><td>BinNode, TsBinNode</td></tr>
				<tr><td>Cache, TsCache</td></tr>
				<tr><td>Collection, ReadOnlyCollection</td></tr>
				<tr><td>Complex</td></tr>
				<tr><td><a href="/documentation/standard-library/Const.php">Const</a></td></tr>
				<tr><td>Consumer</td></tr>
				<tr><td>Deque, TsDeque</td></tr>
				<tr><td>Denumerable</td></tr>
				<tr><td><a href="/documentation/standard-library/Function.php">Function</a></td></tr>
				<tr><td>FiniteDenumerable</td></tr>
				<tr><td>ForwardIterator</td></tr>
				<tr><td>InfiniteDenumerable</td></tr>
				<tr><td>Iterator</td></tr>
				<tr><td>List, TsList</td></tr>
				<tr><td>Map, HashMap, TsMap, TsHashMap, CMap, CHashMap</td><td>Non "hash" variations are ordered</td></tr>
				<tr><td>Matrix</td></tr>
				<tr><td>MaxHeap, MinHeap, TsMaxHeap, TsMinHeap, TsCoalescingMaxHeap</td></tr>
				<tr><td>MultiMap, TsMultiMap</span></td></tr>
				<tr><td>NonDenumerable</td></tr>
				<tr><td>Octonion</td></tr>
				<tr><td><a href="/documentation/standard-library/Pointer.php">Pointer</a></td></tr>
				<tr><td>Predicate</td><td>(&lt;Type&gt; Operand) { return Operand → Bool; };</td></tr>
				<tr><td>PriorityQueue, TsPriorityQueue</td></tr>
				<tr><td>Producer</td></tr>
				<tr><td>Quaternion</td></tr>
				<tr><td>Queue, TsQueue</td></tr>
				<tr><td>RandomAccessIterator</td></tr>
				<tr><td>Set, HashSet, TsSet, TsHashSet, CSet, CHashSet</td><td>Non "hash" variations are ordered</td></tr>
				<tr><td>Singleton</td></tr>
				<tr><td>Stack, CStack</td></tr>
				<tr><td>ThreadLocal</td></tr>
				<tr><td>Vector, TsVector</td><td>Fixed size; see DynamicArray for an array of variable size</td></tr>
			</table>
		</code>
		<h2>Namespaces</h2>
		<code>
			<table style="width:2000px;">
				<tr><td>Allocators</td></tr>
				<tr><td>Cas</td></tr>
				<tr><td>Compiler</td></tr>
				<tr><td>Containers</td></tr>
				<tr><td>Graphics</td></tr>
				<tr><td>Gtk</td></tr>
				<tr><td>IDE</td></tr>
				<tr><td>IDE.Debugger</td></tr>
				<tr><td>IO</td></tr>
				<tr><td><a href="/documentation/standard-library/LinearMath.php">LinearMath</a></td></tr>
				<tr><td>OpenGLv45</td></tr>
				<tr><td>OpenGLESv101</td></tr>
				<tr><td>OpenSLESv11</td></tr>
				<tr><td>Parser</td></tr>
				<tr><td><a href="/documentation/standard-library/Runtime.php">Runtime</a></td></tr>
				<tr><td>Structures</td></tr>
				<tr><td>Sychronization</td></tr>
				<tr><td>Task</td></tr>
				<tr><td>UnitsOfMeasure</td><td>(dimensional analysis)</td></tr>
				<tr><td>Virtualizations</td><td>instantiate and manage virtual execution environments</td>
				<tr><td>Virtualizations.Remote</td></tr>
				<tr><td>Vulkan10</td><td</tr>
			</table>
		</code>


		<?php require('../footer.php') ?>
	</body>
</html>
