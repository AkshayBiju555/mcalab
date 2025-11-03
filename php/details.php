<?php
$rollno=$_POST['rollno'];
$name=$_POST['name'];
$gender=$_POST['m'];
$grade=$_POST['class1'];
$m1=$_POST['m1'];
$m2=$_POST['m2'];
$m3=$_POST['m3'];
$total=$m1+$m2+$m3;
$con=mysqli_connect('localhost','root','','student');
if($con)
    echo "connected";
else
    echo "not connected";
$sq="insert into schooldb values($rollno,'$name','$gender',$grade,$m1,$m2,$m3,$total)";
$insert=mysqli_query($con,$sq);
if($insert)
    echo "<script>alert('Insertion successful');document.location='stdet311.php';</script>";
