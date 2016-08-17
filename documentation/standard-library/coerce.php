<meta charset='utf-8'/>
<meta name="viewport" content="width=device-width, initial-scale=0.6">
<html>
	<head>
		<title>coerce - Plange</title>
		<link rel=StyleSheet href='../../css/general.css' type='text/css' />
	</head>
	<body>
		<?php require('../../header.php') ?>


        <p>converts the specified value to another type</p>
        <div class="code">
            <p>Example</p>
            <pre>&lt;Int&gt; x := coerce("0xff");</pre>
        </div>
        <p>
            The target type is determined through type deduction where possible. Alternatively, the explicit form:
        </p>
        <div class="code">
            <p>Example</p>
            <pre>print("\nYou entered: " + (Number)coerce(input("Enter a number: ")));</pre>
        </div>
        <p>Notably, coerce is useful for dynamic type behavior when a value respects an external interface that it did not explicitly implement.</p>
        <div class="code">
            <p>Example</p>
            <pre>Human := type {
	&lt;void -&gt; void&gt; speak &lt;- () { print("Hello, world!\n"); };
};

TalkingActionFigure := type {
	&lt;void -&gt; void&gt; speak := () { print("Stay in school.\n"); };
};

&lt;TalkingActionFigure&gt; amazotron;
&lt;Human&gt; canSpeak &lt;- coerce(amazotron);
canSpeak.speak();</pre>
        </div>


		<?php require('../../footer.php') ?>
	</body>
</html>