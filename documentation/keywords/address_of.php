<meta charset='utf-8'/>
<html>
	<head>
		<title>address_of - Plange</title>
		<link rel=StyleSheet href='..//css/general.css' type='text/css' />
	</head>
	<body>
		<?php require('..//header.php') ?>


ns a value of type Pointer&lt;T&gt;
    <div>
        <br>
        </br>
    </div>
    <div>
        Example:
    </div>
    <div class="sites-codeblock sites-codesnippet-block">
        <div>
            <font color="#006000" face="monospace">
                <code>
                    &lt;Int&gt; x = 0xABC123;
                </code>
            </font>
        </div>
        <div>
            <code>
                &lt;Pointer&lt;Int&gt;&gt; ptr = address_of(x);
            </code>
        </div>
        <div>
            <code>
                print "Address of x: " + ptr;
            </code>
        </div>
        <div>
            <code>
                print "Value of x: " +
                <a href="dereference.php">
                    dereference
                </a>
                (ptr)
            </code>
        </div>
    </div>
    <p>
        Notes: address_of is similar in function to C's address-of operator, '&amp;'. 
        <span style="font-size:13.3333px;line-height:21.3333px;background-color:transparent">
            See the 
        </span>
        <a style="font-size:13.3333px;line-height:21.3333px;background-color:transparent" href="dereference.php">
            dereference
        </a>
        <span style="font-size:13.3333px;line-height:21.3333px;background-color:transparent">
             keyword.
        </span>
    </p>



		<?php require('..//footer.php') ?>
	</body>
</html>