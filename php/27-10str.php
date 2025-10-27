<?php
$a="hellO wOrld";
echo "string=".$a."<br>";
echo "length of string:".strlen($a)."<br>";
echo "upprcase=".strtoupper($a)."<br>";
echo "lowercase=".strtolower($a)."<br>";
echo "reversed string=".strrev($a)."<br>";
echo "replaced string=".str_replace("wOrld","earth",$a)."<br>";
echo "wOrld's position=".strpos($a,"wOrld")."<br>";
echo "substring=".substr($a,0,5)."<br>";

?>