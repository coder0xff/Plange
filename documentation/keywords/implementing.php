<meta charset='utf-8'/><html><head><title>implementing.html</title><link rel=StyleSheet href='../../css/general.css' type='text/css' /></head><body><?php require('../../header.php') ?>



    with the type keyword to inherit the interface of the specified Type
    <div style="margin-top:12pt;margin-bottom:12pt;border-style:solid;border-width:1px">
        <p style="font-size:12pt;margin:0px;padding-left:6pt;background-color:#cda">
            Example
        </p>
        <pre style="margin:0px;padding:3px;font-family:Courier New;width:715px;max-height:500px;overflow-x:auto;overflow-y:auto">
            TextBox = type implementing Widget {
     &lt;Image&gt; draw;
}
        </pre>
    </div>
    The implementing keyword is similar to inheriting, but only the external interface is inherited. 
    <span style="font-size:13.3333330154419px;line-height:21.3333320617676px">
        The external interface is all of the publicly accessible members of the base type and all the base types ancestors. 
    </span>
    The derived type must implement this interface. 
    <span style="font-size:13.3333330154419px;line-height:21.3333320617676px">
        This feature removes the need for explicit interfaces. All types have an interface. Like the inheriting keyword, implementing permits covariant return types, contravariant argument types, and covariant argument types (pattern matching).
    </span>
    <div>
        <br>
        </br>
    </div>



<?php require('../../footer.php') ?></body></html>