<meta charset='utf-8'/><html><head><title>atomic.html</title><link rel=StyleSheet href='../../css/general.css' type='text/css' /></head><body><?php require('../../header.php') ?>



    Indicates that the code in the following block should be performed either atomically or using transactions. The actual machinery may not be a single operation and is indeed platform dependent. Here, atomicity is a property of the code block indicating that it is synchronized such that intermediate states are not visible from external processes. Hardware implemented atomic operations are used if they are suitable and available. An atomic block has, at minimum, acquire/release memory semantics on all accessed memory locations if pure or DAG. Imperative atomic blocks have sequentially consistent memory semantics. If atomic operations are not available or suitable, transactions and/or mutual exclusion are leveraged. Atomic blocks are explicitly thread safe.
    <br>
    </br>



<?php require('../../footer.php') ?></body></html>