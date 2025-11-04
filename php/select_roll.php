<?php
$con = mysqli_connect('localhost', 'root', '', 'student');
if (!$con) {
    die("Connection failed: " . mysqli_connect_error());
}

// Fetch all roll numbers
$rollQuery = "SELECT Rollno FROM schooldb ORDER BY Rollno";
$rollResult = mysqli_query($con, $rollQuery);
?>

<!DOCTYPE html>
<html>
<head>
    <title>Select Roll Number</title>
</head>
<body bgcolor="beige">
<center>
    <h1>Select Student Roll Number</h1>
    <form method="post" action="update_marks.php">
        <label>Select Roll Number: </label>
        <select name="rollno" required>
            <option value="">--Select--</option>
            <?php
            
              while ($row = mysqli_fetch_assoc($rollResult)) 
                {
              $roll = $row['Rollno'];
              echo "<option value='$roll'>$roll</option>";
               }
            ?>
        </select>
        <br><br>
        <input type="submit" name="show" value="Show Details">
    </form>
</center>
</body>
</html>

<?php
mysqli_close($con);
?>
