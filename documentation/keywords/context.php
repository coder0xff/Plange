<meta charset='utf-8'/>
<meta name="viewport" content="width=device-width, initial-scale=0.6">
<html>
	<head>
		<title>context - Plange</title>
		<link rel=StyleSheet href='../../css/general.css' type='text/css' />
	</head>
	<body>
		<?php require('../../header.php') ?>


		<p>an alias for the current ExecutionContext</p>

		<div class="code">
			<p>Example</p>
			<pre>MergeSortedLists := (List&lt;Int&gt; a, List&lt;Int&gt; b) {
	&lt;List&lt;Int&gt; result;
	&lt;Int&gt; q;
	&lt;ExecutionContext&gt; mainRoutine;

	// construct the first coroutine
	a ← ExecutionContext({
		for (i ∈ a) {
			if (i &gt; q) {
				q ← i;
				fiberB.switch(); //symmetric context switch
			}
			result.append(i);
		}
	});

	// second coroutine
	b ← ExecutionContext({
		for (i ∈ b) {
			if (i &gt; q) {
				q ← i;
				fiberA.switch();
			}
			result.append(i);
		}
	});

	if (a.count &gt; 0) {
		//seed the algorithm
		q ← a[0];
		b.switch(context); //asymmetric context switch returns here when done
	};
}</pre>
		</div>

	<h2>Notes</h2>
	<p>The value of 'context' contains members for inspecting the current scope and its parents. It can be thought of as localized reflection. It can also be used as a re-entry point for cooperative multi-threading. In this capacity, it also increments a call counter, and stores a user object for passing in data during re-entry. See <a href="/documentation/standard-library/ExecutionContext.php">ExecutionContext</a></p>



		<?php require('../../footer.php') ?>
	</body>
</html>