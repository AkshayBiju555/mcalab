<!DOCTYPE html>
<html>
<head>
    <title>Update Student Marks</title>
</head>
<body bgcolor="beige">
<center>
    <h2>Update Student Marks</h2>

    <?php
    $conn = mysqli_connect("localhost", "root", "", "student");
    if (!$conn) {
        die("Connection failed: " . mysqli_connect_error());
    }

    if (isset($_POST['delete'])) 
    {
        $rollno=$_POST['rollno'];
        $sql="Delete from bio where Rollno='$rollno'";
        $result1=mysqli_query($conn,$sql);
        if($result1)
        {
            echo "deleted successfully";
        }
        
    }
    if(isset($_POST['update']))
    {
        $rollno=$_POST['rollno'];
        $name=$_POST['name'];
        $gender=$_POST['gender'];
        $mark1=$_POST['mark1'];
        $mark2=$_POST['mark2'];
        $total=$mark1+$mark2;
        $sql="update bio set name='$name',Gender='$gender',mark1='$mark1',mark2='$mark2',Total='$total' where Rollno='$rollno'";
        $result=mysqli_query($conn,$sql);
        if($result)
        {
            echo "updated succesfully";
        }
    }
    ?>

    <form method="POST">

    <br><br>
    <h3>All Students</h3>
    <table border="1" cellpadding="5">
<tr><th>Name</th><th>Rollno</th><th>Gender</th><th>Mark1</th><th>Mark2</th><th>Total</th><th>Action</th></tr>
<?php
$result = mysqli_query($conn, "SELECT * FROM bio");
while ($row = mysqli_fetch_assoc($result)) {
    echo "<tr>
        <form method='post' action=''>
            <td><input type='text' name='name' value='{$row['name']}'></td>
            <td><input type='text' name='rollno' value='{$row['Rollno']}' readonly></td>
            <td><input type='text' name='gender' value='{$row['Gender']}'></td>
            <td><input type='number' name='mark1' value='{$row['mark1']}'></td>
            <td><input type='number' name='mark2' value='{$row['mark2']}'></td>
            <td><input type='number' name='total' value='{$row['Total']}' readonly></td>
            <td>
                <input type='submit' name='update' value='Update'>
                <input type='submit' name='delete' value='Delete'
                       onclick=\"return confirm('Are you sure you want to delete this student?');\">
            </td>
        </form>
    </tr>";
}
?>
</table>

</center>
</body>
</html>