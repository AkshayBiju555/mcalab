<?php
$rollno = $_POST['rollno'];
$name= $_POST['name'];
$mark=$_POST['mark'];
$con=mysqli_connect('localhost','root','','student');
if($con)
    echo "success";
else
    echo "unable to connect";

$check = "SELECT rollno FROM stud WHERE rollno = $rollno";
$result = mysqli_query($con, $check);
if(mysqli_num_rows($result) > 0){

    echo "<script>alert('Roll number already exists in the table');document.location='3-11.php';</script>";
    /*while($row=mysqli_fetch_assoc($result))
    {
        echo "rollno".$row["rollno"].",name".$row["name"];
    }*/
} else {
    
    $insertsq = "INSERT INTO stud (name, rollno, mark) VALUES ('$name', $rollno, $mark)";
    $sq=mysqli_query($con, $insertsq);
    if($sq){
        echo "<script>alert('Insertion successful'); document.location='3-11.php;</script>";
    } else {
        echo "<script>alert('Error: " . mysqli_error($con) . "');</script>";
    }
}
?>
