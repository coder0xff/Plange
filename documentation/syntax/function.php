<meta charset='utf-8'/>
<html>
	<head>
		<title>function - Plange</title>
		<link rel=StyleSheet href='../../css/general.css' type='text/css' />
	</head>
	<body>
		<?php require('../../header.php') ?>



        creates a function value
    </div>
    <div style="margin-top:12pt;margin-bottom:12pt;border-style:solid;border-width:1px">
        <p style="font-size:12pt;margin:0px;padding-left:6pt;background-color:#cda">
            Syntax
        </p>
        <pre style="margin:0px;padding:3px;font-family:Courier New;width:715px;max-height:500px;overflow-x:auto;overflow-y:auto">
            [ "(" [
            <a href="formal_parameter.php">
                parameter
            </a>
            ("," 
            <a style="font-size:13.3333px;line-height:21.3333px;background-color:transparent" href="formal_parameter.php">
                parameter
            </a>
            <span style="line-height:1.6;font-size:10pt;background-color:transparent">
                )* ] ")" ] ["no_throw"] ["atomic"] ["pure"|"imperative"|"opaque"] "{"
                <a href="statement_scope.php">
                    statement_scope
                </a>
                "}"
            </span>
        </pre>
    </div>
    <div>
        <br>
        </br>
        <div style="margin-top:12pt;margin-bottom:12pt;border-style:solid;border-width:1px">
            <p style="font-size:12pt;margin:0px;padding-left:6pt;background-color:#cda">
                Example
            </p>
            <pre style="margin:0px;padding:3px;font-family:Courier New;width:715px;max-height:500px;overflow-x:auto;overflow-y:auto">
                (a, b) pure { return a * b; }
            </pre>
        </div>
    </div>
    <div style="margin-top:12pt;margin-bottom:12pt;border-style:solid;border-width:1px">
        <p style="font-size:12pt;margin:0px;padding-left:6pt;background-color:#cda">
            Example
        </p>
        <pre style="margin:0px;padding:3px;font-family:Courier New;width:715px;max-height:500px;overflow-x:auto;overflow-y:auto">
            &lt;int -&gt; int&gt; factorial := (x) { return x == 0 ? 1 : x * factorial(x - 1); };
        </pre>
    </div>
    <h4>
        <a name="TOC-Example-Collection-T---T-head-:-a:b-return-a-">
        </a>
        <div style="font-size:13.3333px;line-height:21.3333px;margin-top:12pt;margin-bottom:12pt;border-style:solid;border-width:1px">
            <p style="font-size:12pt;margin:0px;padding-left:6pt;background-color:rgb(204,221,170)">
                Example
            </p>
            <pre style="margin-top:0px;margin-bottom:0px;padding:3px;font-family:Courier New;width:715px;max-height:500px;overflow:auto">
                &lt;Collection&lt;T&gt; -&gt; T&gt; head := (a:b) { return a; }
            </pre>
        </div>
    </h4>
    <h4>
        <a name="TOC-Notes">
        </a>
        Notes
    </h4>
    <div>
        Function objects are invoked using the
        <a href="invocation.php">
            invocation
        </a>
        operator.
    </div>
    <div>
        <br>
        </br>
    </div>
    <div>
        The
        <a href="../keywords/atomic.php">
            atomic
        </a>
        , 
        <a href="../keywords/pure.php">
            pure
        </a>
        , 
        <a href="../keywords/imperative.php">
            imperative
        </a>
        , and 
        <a href="../keywords/opaque.php">
            opaque
        </a>
         keywords influence assumptions that the compiler may make regarding a functions implementation. The pure keyword indicates that the implementation uses only pull semantics, is idempotent, and has no side effects. Additionally, only constants can be read, which includes value (not by reference/pointer values) passed as formal parameters. Any violation of these constraints causes an error to occur. The imperative keyword indicates that the implementation is likely not tractable, and it may interact with memory or hardware in unknown ways. Without either pure or imperative, the implementation is assumed to be push-pull and tractable. If the tool chain determines that this is not the case, it will fall back to imperative behavior. Pure functions are implicitly atomic.
        <br>
        </br>
    </div>
    <div>
        <br>
        </br>
    </div>
    <div>
        <br>
        </br>
    </div>
    <div>
        <br>
        </br>
    </div>



		<?php require('../../footer.php') ?>
	</body>
</html>