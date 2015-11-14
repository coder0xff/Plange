<meta charset='utf-8'/>
<html>
	<head>
		<title>volatile - Plange</title>
		<link rel=StyleSheet href='..//css/general.css' type='text/css' />
	</head>
	<body>
		<?php require('..//header.php') ?>


ates that a variable's value may change unpredictably
    <div>
        <br>
        </br>
    </div>
    <div>
        volatile &lt;Int&gt; var;
    </div>
    <div>
        <br>
        </br>
    </div>
    <h4>
        <a name="TOC-Notes">
        </a>
        Notes
    </h4>
    <div>
        The compiler nor CPU are allowed to make assumptions about value consistency or memory ordering semantics. As such, reordering optimizations and caching are disabled. All access to a volatile is surrounded by memory fences as available.
    </div>



		<?php require('..//footer.php') ?>
	</body>
</html>