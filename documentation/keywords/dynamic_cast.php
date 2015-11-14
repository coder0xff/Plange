<meta charset='utf-8'/>
<html>
	<head>
		<title>dynamic_cast - Plange</title>
		<link rel=StyleSheet href='../../css/general.css' type='text/css' />
	</head>
	<body>
		<?php require('../../header.php') ?>


rt the specified pointer from a type A, to a type B, if B inherits A. Otherwise, the result is a null pointer.
    <div>
        <br>
        </br>
    </div>
    <div>
        Example:
    </div>
    <div>
    </div>
    <div class="sites-codeblock sites-codesnippet-block">
        <div>
            <code>
                &lt;Type&gt; Mammal = class {
            </code>
            <span style="line-height:1.6;font-size:10pt;background-color:transparent">
                <code>
                        
                </code>
            </span>
        </div>
        <div>
            <code>
                };
                <br>
                </br>
            </code>
            <span style="color:rgb(0,96,0);font-size:10pt;line-height:1">
                <font face="monospace">
                    <br>
                    </br>
                </font>
                &lt;Type&gt; Dog = class inheriting Mammal {
            </span>
        </div>
        <div>
            <span>
                <code>
                        &lt;void 
                </code>
            </span>
            <code>
                → void&gt; bark;
            </code>
        </div>
        <div>
            <code>
                };
                <br>
                </br>
            </code>
            <span style="color:rgb(0,96,0);font-size:13.3333330154419px">
                <font face="monospace">
                    <br>
                    </br>
                </font>
                <span style="line-height:21.3333320617676px">
                    &lt;Type&gt; Cat = class inheriting Mammal {
                </span>
            </span>
        </div>
        <div>
            <div style="font-size:13.3333330154419px;line-height:21.3333320617676px">
                <code>
                        &lt;void → void&gt; meow;
                </code>
            </div>
            <div style="font-size:13.3333330154419px;line-height:21.3333320617676px">
                <code>
                    };
                    <br>
                    </br>
                    <code style="font-size:13.3333330154419px;line-height:21.3333320617676px">
                        <br>
                        </br>
                        &lt;Mammal 
                    </code>
                    <span style="font-size:13.3333330154419px;line-height:21.3333320617676px;color:rgb(68,68,68);font-family:Arial,Verdana,sans-serif;background-color:transparent">
                        <code>
                            → void&gt; speak := (x) {
                        </code>
                    </span>
                </code>
            </div>
        </div>
        <div style="font-size:13.3333330154419px;line-height:21.3333320617676px">
            <span style="font-size:13.3333330154419px;line-height:21.3333320617676px;background-color:transparent">
                <span>
                    <code>
                            Dog dog := dynamic_cast&lt;Dog&gt;(x);
                    </code>
                </span>
                <br>
                </br>
            </span>
        </div>
        <div style="font-size:13.3333330154419px;line-height:21.3333320617676px">
            <span style="font-size:13.3333330154419px;line-height:21.3333320617676px;background-color:transparent">
                <span>
                    <span>
                        <code>
                                if (dog != null) {
                        </code>
                    </span>
                    <br>
                    </br>
                </span>
            </span>
        </div>
        <div style="font-size:13.3333330154419px;line-height:21.3333320617676px">
            <span style="font-size:13.3333330154419px;line-height:21.3333320617676px;background-color:transparent">
                <span>
                    <span>
                        <span>
                            <code>
                                    
                            </code>
                            <span>
                                <code>
                                        dog.bark();
                                </code>
                            </span>
                        </span>
                        <br>
                        </br>
                    </span>
                </span>
            </span>
        </div>
        <div style="font-size:13.3333330154419px;line-height:21.3333320617676px">
            <span>
                <code>
                        }
                </code>
            </span>
            <br>
            </br>
        </div>
        <div style="font-size:13.3333330154419px;line-height:21.3333320617676px">
            <span style="font-size:13.3333330154419px;line-height:21.3333320617676px;background-color:transparent">
                <code>
                        Cat cat := dynamic_cast&lt;Cat&gt;(x);
                </code>
                <br>
                </br>
            </span>
        </div>
        <div style="font-size:13.3333330154419px;line-height:21.3333320617676px">
            <span style="font-size:13.3333330154419px;line-height:21.3333320617676px;background-color:transparent">
                <code>
                        if (cat != null) {
                </code>
                <br>
                </br>
            </span>
        </div>
        <div style="font-size:13.3333330154419px;line-height:21.3333320617676px">
            <span style="font-size:13.3333330154419px;line-height:21.3333320617676px;background-color:transparent">
                <code>
                        
                </code>
                <code>
                        cat.meow();
                </code>
                <br>
                </br>
            </span>
        </div>
        <div style="font-size:13.3333330154419px;line-height:21.3333320617676px">
            <code>
                    }
            </code>
            <br>
            </br>
        </div>
        <div style="font-size:13.3333330154419px;line-height:21.3333320617676px">
            <span style="font-size:13.3333330154419px;line-height:21.3333320617676px;background-color:transparent">
                <code>
                    };
                </code>
            </span>
        </div>
    </div>



		<?php require('../../footer.php') ?>
	</body>
</html>