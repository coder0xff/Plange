<meta charset='utf-8'/>
<html>
	<head>
		<title>atomic - Plange</title>
		<link rel=StyleSheet href='../../css/general.css' type='text/css' />
	</head>
	<body>
		<?php require('../../header.php') ?>


        <p>indicates that the code in the following block should be performed either atomically or using transactions.</p>

        <p>For an example <a href="/source/Plange/stdlib/TsList.pge">TsList.pge</a></p>

        <h2>Notes</h2>
        <p>The actual machinery may not be a single operation and is indeed platform dependent. Here, atomicity is a property of the code block indicating that it is synchronized such that intermediate states are not visible from external processes. Hardware implemented atomic operations are used if they are suitable and available. An atomic block has, at minimum, acquire/release memory semantics on all accessed memory locations if pure or DAG. Imperative atomic blocks have sequentially consistent memory semantics. If atomic operations are not available or suitable, transactions and/or mutual exclusion are leveraged. Atomic blocks are explicitly thread safe.</p>

        <h2>Atomic imperative, atomic opaque</h2>
        <p>Atomic blocks are typically DAG functions or pure functions. When combined with the imperative or opaque keyword, however, the runtime does not perform any synchronization. Instead, the implementer is responsible for ensuring/proving the atomicity of the code. In this case, atomic is simply an indicator to the runtime that the function is thread safe. All pure functions are implicitly atomic.</p>


		<?php require('../../footer.php') ?>
	</body>
</html>