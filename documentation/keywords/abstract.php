<meta charset='utf-8'/>
<html>
	<head>
		<title>abstract - Plange</title>
		<link rel=StyleSheet href='..//css/general.css' type='text/css' />
	</head>
	<body>
		<?php require('..//header.php') ?>



        a function object that can be cast to any function type, and throws when invoked
    </div>
    <div>
        <br>
        </br>
    </div>
    <div>
        Notes: The abstract keyword is used to declare interfaces that will be implemented by derived types
    </div>
    <div>
        <div style="font-size:13.3333330154419px;line-height:21.3333320617676px;margin-top:12pt;margin-bottom:12pt;border-style:solid;border-width:1px">
            <p style="font-size:12pt;margin:0px;padding-left:6pt;background-color:rgb(204,221,170)">
                Example
            </p>
            <pre style="margin-top:0px;margin-bottom:0px;padding:3px;font-family:Courier New;width:715px;max-height:500px;overflow:auto">
                //Base type
Animal := type {
    &lt;Void -&gt; Void&gt; speak &lt;- abstract; //there is no default implementation
};

//Derived type
Cat := type inheriting Animal {
    speak &lt;- { Meow(); }; //override the inherited speak method
};

&lt;List&lt;Animal&gt; -&gt; Void&gt; choir := (animals) {    
    for (animal in animals) {
        animal.speak();
    }
};

&lt;Cat&gt; bernard;
&lt;Cat&gt; russel;
List&lt;Cat&gt; kittehs := [ bernard, russel ];
choir(kittehs); //covariant argument
            </pre>
        </div>
    </div>
    <div>
        <br>
        </br>
    </div>
    <div>
        <br>
        </br>
    </div>



		<?php require('..//footer.php') ?>
	</body>
</html>