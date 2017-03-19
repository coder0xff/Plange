	</div>
</div>
<hr>
<center>
	copyright © Brent Lewis 2017 &nbsp;&nbsp;&nbsp;&nbsp; hits: 
<?php
//Easy Counter code begins

$ec_username = 'coder0xff'; // <--- your username

if (!$ec_fsock = fsockopen('www.easycounter.com', 80, $errno, $errstr, 2)) {
  echo '<img src="http://www.easycounter.com/images/error.png">';
} else {
  fputs($ec_fsock, "GET /php.counter.php?username=".urlencode($ec_username)." HTTP/1.0\r\n".
  "Host:www.easycounter.com\r\n\r\n");
  $ec_buffer = '';
  while (!feof($ec_fsock)) $ec_buffer .= fgets($ec_fsock, 1024);
  echo substr($ec_buffer, strpos($ec_buffer, "\n\r\n")+3);
  fclose($ec_fsock);
}

//Easy Counter code ends
?>
</center>