<?php

$con = mysqli_connect('localhost', 'root', '', 'student');
if (!$con) {
    die("Connection failed: " . mysqli_connect_error());
}

// Fetch all roll numbers for dropdown
$rollQuery = "SELECT rollno FROM stud ORDER BY rollno";
$rollResult = mysqli_query($con, $rollQuery);

// If a roll number is selected, fetch and display its details
if (isset($_POST['rollno1']) && $_POST['rollno1'] != "") {
    $rollno = $_POST['rollno1'];
    $sql = "SELECT rollno, Name, Mark FROM stud WHERE rollno = $rollno";
    $result = mysqli_query($con, $sql);

    if (mysqli_num_rows($result) > 0) {
        while ($row = mysqli_fetch_assoc($result)) {
            // Use exact column names from the table
            echo "Rollno: " . $row['rollno'] . ", Name: " . $row['Name'] . ", Mark: " . $row['Mark'] . "<br>";
        }
    } else {
        echo "Roll number $rollno does not exist in the table.";
    }
}
?>

<!DOCTYPE html>
<html>
<head>
    <title>Student Lookup</title>
</head>
<body bgcolor="beige">
<center>
    <h1>Student Details Lookup</h1>
    <form method="post" action="">
        Select Roll Number: 
        <select name="rollno1" required>
            <!--<option value="">--Select--</option>-->
            <?php
            while ($row = mysqli_fetch_assoc($rollResult)) {
                echo "<option value='".$row['rollno']."'>".$row['rollno']."</option>";
            }
            ?>
        </select>
        <input type="submit" value="Show Details">
    </form>
</center>
</body>
</html>

<?php
mysqli_close($con);
?>
