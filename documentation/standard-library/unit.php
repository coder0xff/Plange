<meta charset='utf-8'/>
<html>
	<head>
		<title>Unit - Plange</title>
		<link rel=StyleSheet href='..//css/general.css' type='text/css' />
	</head>
	<body>
		<?php require('..//header.php') ?>



        Unit := type implementing Const&lt;Map&lt;Units.FundamentalUnit, Int&gt;&gt;, Type {
    </div>
    <div>
        <span style="white-space:pre">
        </span>
        ctor := (Map&lt;FundamentalUnit, Int&gt; dimensions) {
    </div>
    <div>
        <span style="white-space:pre">
        </span>
        this.dimensions := dimensions;
    </div>
    <div>
        <span style="white-space:pre">
        </span>
        }
    </div>
    <div>
        <br>
        </br>
    </div>
    <div>
        <span style="white-space:pre">
        </span>
        indexer := (FundamentalUnit u) { return this.dimensions.get_or_default(u, 0); }
    </div>
    <div>
        }
    </div>
    <div>
        <br>
        </br>
    </div>
    <div>
        Unit implements Const&lt;Map&lt;Unit, Int&gt;&gt;;
    </div>



		<?php require('..//footer.php') ?>
	</body>
</html>