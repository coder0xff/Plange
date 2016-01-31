<script>
  (function(i,s,o,g,r,a,m){i['GoogleAnalyticsObject']=r;i[r]=i[r]||function(){
  (i[r].q=i[r].q||[]).push(arguments)},i[r].l=1*new Date();a=s.createElement(o),
  m=s.getElementsByTagName(o)[0];a.async=1;a.src=g;m.parentNode.insertBefore(a,m)
  })(window,document,'script','//www.google-analytics.com/analytics.js','ga');

  ga('create', 'UA-65060700-3', 'auto');
  ga('send', 'pageview');
</script>

<script>
  (function() {
    var cx = '010799772172995832082:w37iigi4wva';
    var gcse = document.createElement('script');
    gcse.type = 'text/javascript';
    gcse.async = true;
    gcse.src = (document.location.protocol == 'https:' ? 'https:' : 'http:') +
        '//cse.google.com/cse.js?cx=' + cx;
    var s = document.getElementsByTagName('script')[0];
    s.parentNode.insertBefore(gcse, s);
  })();
</script>

<div id="search">
	<gcse:search></gcse:search>
</div>

<h1><big>Plange</big></h1>
<hr>
<div id="navigation">
<h2>Navigation</h2>
<ul>
<li><a href="/index.php">Home</a></li>
<li><a href="/goals/index.php">Goals</a></li>	
<li><a href="/examples/">Examples</a></li>
<li><a href="/documentation/">Documentation</a>
	<ul>
		<li><a href="/documentation/keywords.php">Keywords</a></li>
		<li><a href="/documentation/standard-library.php">Standard Library</a></li>
		<li><a href="/documentation/syntax.php">Syntax</a></li>
		<li><a href="/documentation/glossary.php">Glossary</a></li>
		<li><a href="/documentation/operators.php">Operators</a></li>
	</ul>
</li>
<li><a href="/contribute.php">Contribute</a></li>
<li><a href="/about.php">About</a></li>
</ul>
</div>
<div id="left-margin">
	<div id="contents">
<?php
    function TableOfContents($depth)
    /*AutoTOC function written by Alex Freeman
    * Released under CC-by-sa 3.0 license
    * http://www.10stripe.com/  */
    {
    $filename = debug_backtrace()[0]["file"];
    //read in the file
    $file = fopen($filename,"r");
    $html_string = fread($file, filesize($filename));
    fclose($file);
 
    //get the headings down to the specified depth
    $pattern = '/<h[2-'.$depth.']*[^>]*>.*?<\/h[2-'.$depth.']>/';
    $whocares = preg_match_all($pattern,$html_string,$winners);
 
    //reformat the results to be more usable
    $heads = implode("\n",$winners[0]);
    $heads = str_replace('<a name="','<a href="#',$heads);
    $heads = str_replace('</a>','',$heads);
    $heads = preg_replace('/<h([1-'.$depth.'])>/','<li class="toc$1">',$heads);
    $heads = preg_replace('/<\/h[1-'.$depth.']>/','</a></li>',$heads);
 
    //plug the results into appropriate HTML tags
    $contents = '<div id="toc"> 
    <p>Contents</p>
    <ul>
    '.$heads.'
    </ul>
    </div>';
    echo $contents;
    }
 ?>