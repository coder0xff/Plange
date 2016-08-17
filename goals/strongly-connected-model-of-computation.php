<meta charset='utf-8'/>
<meta name="viewport" content="width=device-width, initial-scale=0.6">
<html>
	<head>
		<title></title>
		<link rel=StyleSheet href='../css/general.css' type='text/css' />
	</head>
	<body>
		<?php require('../header.php') ?>


		<p>A developer makes programs using a computer. The development process requires the computer to convert source code into other representations, perform validation and optimization, and complete any additional compile time processing required by the developer. When the finished software is used, a new set of computations is performed, completely different from, but nonetheless dependent upon, the computations performed by the compiler previously. Notably, the reverse is not true. Compile time computations do not depend on runtime computations. This relationship can be modeled as a directed graph called the "dependency digraph."</p>

		<p>Bootstrapping a compiler is a monumental achievement. Like all programs, compilers start as source code. Source code is compiled, by a compiler, into a computer program. In the case of bootstrapping, the developer compiles the compiler — using itself. This creates a cycle in the computational dependency digraph described above. More importantly, it makes the digraph <a href="http://mathworld.wolfram.com/StronglyConnectedDigraph.html">strongly connected.</a> While difficult to achieve, it demonstrates that the differences between runtime computations and compile time computations can be reduced to zero.</p>
		<p>Following this, the distinctions between compile time and runtime become less relevant. The only distinction to be made from here is that some computations can be performed now (which may mean statically, at “compile time”), and some cannot. If the runtime environment maintains the strong digraph, then programs can perform any task that the original toolchain could, including self-modification. This is why it is desirable to bootstrap the entire toolchain. At the very least, the toolchain must be capable of taking the source code of the entire toolchain and building itself.</p>
		<p>As you move down the abstraction layers, the components of the bootstrapped compiler are revealed, but the graph remains strongly connected. Several features arise from this concept, such as continuous profile guided optimization, dependency injection, and much more.
		<h2>Advantages</h2>
		<ul>
			<li>Improves upon Eval using homoiconicity and first-class concepts (code is data)</li>
			<li>Mutable introspection </li>
			<li>Profile-guided optimization occurs at runtime. </li>
			<li>The number of nodes in a programs dependency graph is unbounded, and can become as interconnected or modular, as complex or as simple as desired, but is always strong because all nodes can use the toplevel.</li>
			<li>Moving up and down levels up abstraction does not break the strong property.</li>
		</ul>
		<h2>Disadvantages</h2>
		<ul>
			<li>The requirement for the digraph to be strong makes it more difficult to design, build and maintain.</li>
			<li>Complicated security requirements</li>
		</ul>
		<p>Note that if the runtime is internally transparent and mutable, meaning that all code and data for the runtime can be read and written by the runtime, then it can build copies of itself from its own introspection.</p>
		<h2>Optimization Time</h2>
		<p>Optimization is usually done during compile time. In plange, optimization is done whenever possible. A program can be executed by the plange interpreter, or it can be compiled. This decision can be made at runtime. To permit the highest level of flexibility, distributables may include an interpretable representation of the program. This enables the runtime to maintain the strongly connected digraph in deployment environments. A side affect of this arrangement is that dynamic recompilation can be performed (permitting full dependency injection support) and enhanced profile guided optimizations are enabled. Notably, since the optimizations may be performed at run time, there may be a "warm up" period before sustained performance is achieved. The runtime may be permitted to cache optimized binary portions to alleviate warm up.</p>
		<p>See also: <a href="/goals/first-classing.php">First Classing</a>
		</p>


		<?php require('../footer.php') ?>
	</body>
</html>