<meta charset='utf-8'/>
<html>
	<head>
		<title>coerce - Plange</title>
		<link rel=StyleSheet href='../../css/general.css' type='text/css' />
	</head>
	<body>
		<?php require('../../header.php') ?>


        <p>convert the specified value to another type</p>
        <div class="code">
            <p>Example</p>
            <pre>&lt;Int&gt; x := coerce("0xff");</pre>
        </div>
        <p>
            The target type is determined through type deduction where possible. Alternatively, the parametric form:
        </p>
        <div class="code">
            <p>Example</p>
            <pre>print("\nYou entered: " + coerce&lt;Number&gt;(input("Enter a number: ")));</pre>
        </div>
        <p>Notably, coerce is useful for dynamic type behavior when a value respects an external interface that is did not explicitly implement.</p>
        <div>
            <p style="font-size:12pt;line-height:21.3333px;margin:0px;padding-left:6pt;background-color:rgb(204,221,170)">
                Example
            </p>
            <pre>Human := type {
	&lt;void -&gt; void&gt; speak &lt;- () { print("Hello, world!\n"); };
};

TalkingActionFigure := type {
	&lt;void -&gt; void&gt; speak := () { print("Stay in school.\n")}
};

&lt;TalkingActionFigure&gt; amazotron;
&lt;Human&gt; canSpeak &lt;- coerce(amazotron);
canSpeak.speak();</pre>
        </div>


		<?php require('../../footer.php') ?>
	</body>
</html>