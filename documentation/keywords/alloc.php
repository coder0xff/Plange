<meta charset='utf-8'/>
<html>
	<head>
		<title>alloc - Plange</title>
		<link rel=StyleSheet href='..//css/general.css' type='text/css' />
	</head>
	<body>
		<?php require('..//header.php') ?>


e a new value on the heap
    <div>
        <br>
        </br>
    </div>
    <div>
        Example:
    </div>
    <div>
        <font color="#006000" face="monospace">
            <div class="sites-codeblock sites-codesnippet-block">
                Complex := class {
                <br>
                </br>
                <span>
                        Double real;
                    <br>
                    </br>
                    <span>
                            Double imaginary;
                        <br>
                        </br>
                    </span>
                    };
                    <br>
                    </br>
                    <br>
                    </br>
                    &lt;Pointer&lt;Complex&gt;&gt; ptr := alloc(Complex);
                </span>
            </div>
        </font>
    </div>
    Create a new value on the heap
    <br>
    </br>
    <br>
    </br>



		<?php require('..//footer.php') ?>
	</body>
</html>