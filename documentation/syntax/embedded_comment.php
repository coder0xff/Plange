<meta charset='utf-8'/><html><head><title>
    style="margin-top:12pt;margin-bottom:12pt;border-style:solid;border-width:1px">
    <p style="font-size:12pt;margin:0px;padding-left:6pt;background-color:#cda">
        Wirth syntax notation
    </p>
    <pre style="margin:0px;padding:3px;font-family:Courier New;width:715px;max-height:500px;overflow-x:auto;overflow-y:auto">
        embedded_comment_interior:= newline payload newline | "*" embedded_comment_interior "*"
embedded_comment:= newline "/*" embedded_comment_interior "*/" newline
    </pre>
</title><link rel=StyleSheet href='../../css/general.css' type='text/css' /></head><body><?php require('../../header.php') ?>


embedded_comment.html


<?php require('../../footer.php') ?></body></html>