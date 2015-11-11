<meta charset='utf-8'/><html><head><title>
    ns an object of type Value that models the specified expression
    <h4>
        <a name="TOC-Notes">
        </a>
        Notes
    </h4>
    <div>
        The box keyword should not be confused with the keyword of the same name in other languages, though some use cases may appear similar. In this case, the box keyword returns an object with properties and methods for interacting with a values representation rather than its interpretation. More specifically, the representation is either concrete or algebraic. 
    </div>
    <div>
        <div style="font-size:13.3333px;line-height:21.3333px;margin-top:12pt;margin-bottom:12pt;border-style:solid;border-width:1px">
            <p style="font-size:12pt;margin:0px;padding-left:6pt;background-color:rgb(204,221,170)">
                Example
            </p>
            <pre style="margin-top:0px;margin-bottom:0px;padding:3px;font-family:Courier New;width:715px;max-height:500px;overflow:auto">
                x &lt;- 5 + 2; //x is 7
x &lt;- box(7); //x is a concrete Value with a binary representation
                <span style="font-size:13.3333px;line-height:21.3333px;background-color:transparent">
                    x &lt;- box(5 + 2); //x is an algebraic Value
                </span>
            </pre>
        </div>
        <div style="font-size:13.3333px;line-height:21.3333px">
            Concrete values have a single binary representation
        </div>
        <br>
        </br>
    </div>
    <br>
    </br>
</title><link rel=StyleSheet href='../../css/general.css' type='text/css' /></head><body><?php require('../../header.php') ?>


box.html


<?php require('../../footer.php') ?></body></html>