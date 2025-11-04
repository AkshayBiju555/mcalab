<?php
$con = mysqli_connect('localhost', 'root', '', 'student');
if (!$con) {
    die("Connection failed: " . mysqli_connect_error());
}

$student = null;

// When "Show Details" clicked from first page
if (isset($_POST['show'])) {
    $rollno = $_POST['rollno'];
    $sql = "SELECT Rollno, Name, Mark1, Mark2,Mark3,TotalMarks FROM schooldb WHERE Rollno = '$rollno'";
    $result = mysqli_query($con, $sql);

    if (mysqli_num_rows($result) > 0) {
        $student = mysqli_fetch_assoc($result);
    } else {
        echo "<center><p style='color:red;'>Roll number $rollno not found.</p></center>";
    }
}

// When "Update Marks" button clicked
if (isset($_POST['update'])) {
    $rollno = $_POST['rollno'];
    $mark1 = $_POST['mark1'];
    $mark2 = $_POST['mark2'];
    $mark3=$_POST['mark3'];
    $total=$mark1+$mark2+$mark3;

    $updateQuery = "UPDATE schooldb SET Mark1='$mark1', Mark2='$mark2',Mark3='$mark3',TotalMarks=$total WHERE Rollno='$rollno'";
    if (mysqli_query($con, $updateQuery)) {
        echo "<script>alert('Marks updated successfully!');</script>";
    } 
    // Reload updated student details
    $sql = "SELECT Rollno, Name, Mark1, Mark2,Mark3,TotalMarks FROM schooldb WHERE Rollno = '$rollno'";
    $result = mysqli_query($con, $sql);
    $student = mysqli_fetch_assoc($result);
}
?>

<!DOCTYPE html>
<html>
<head>
    <title>Update Student Marks</title>
</head>
<body bgcolor="beige">
<center>
    <h1>Update Student Marks</h1>

    <form method="post" action="select_roll.php">
        <input type="submit" value="← Back to Roll Number List">
    </form>

    <?php if ($student): ?>
        <hr>
        <form method="post" action="update_marks.php">
            <table border="1" cellpadding="8">
                <tr>
                    <th>Roll No</th>
                    <td><input type="text" name="rollno" value="<?php echo $student['Rollno']; ?>" readonly></td>
                </tr>
                <tr>
                    <th>Name</th>
                    <td><input type="text" name="name" value="<?php echo $student['Name']; ?>" readonly></td>
                </tr>
                <tr>
                    <th>Mark 1</th>
                    <td><input type="number" name="mark1" value="<?php echo $student['Mark1']; ?>" required></td>
                </tr>
                <tr>
                    <th>Mark 2</th>
                    <td><input type="number" name="mark2" value="<?php echo $student['Mark2']; ?>" required></td>
                </tr>
                <tr>
                    <th>Mark 3</th>
                    <td><input type="number" name="mark3" value="<?php echo $student['Mark3']; ?>" required></td>
                </tr>
                <tr>
                    <th>Total</th>
                    <td><input type="number" name="total" value="<?php echo $student['TotalMarks']; ?>" readonly></td>
                </tr>
                
            </table>
            <br>
            <input type="submit" name="update" value="Update Marks">
        </form>
    <?php endif; ?>
</center>
</body>
</html>

<?php
mysqli_close($con);
?>
