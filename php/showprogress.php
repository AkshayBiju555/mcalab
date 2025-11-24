<?php
$conn = mysqli_connect("localhost", "root", "", "akshay");

if (!$conn) {
    die("Connection failed: " . mysqli_connect_error());
}

// Load all roll numbers for dropdown
$rollResult = mysqli_query($conn, "SELECT Rollno FROM bio");
?>

<!DOCTYPE html>
<html>
<head>
    <title>Student Progress Card</title>
</head>

<body>
    <h1>Student Progress Card</h1>

    <form method="post">
        Select Roll Number:

        <select name="rollno" required>
            <option value="">--Select--</option>

            <?php
            while ($row = mysqli_fetch_assoc($rollResult)) {
                $roll = $row['Rollno'];
                echo "<option value='$roll'>$roll</option>";
            }
            ?>
        </select>

        <br><br>
        <input type="submit" name="shoprogress" value="Show Progress">
    </form>

    <br><br>

    <?php
    // If user clicks Show Progress button
    if (isset($_POST['shoprogress'])) {
        $rollno = $_POST['rollno'];

        $result = mysqli_query($conn, "SELECT * FROM bio WHERE Rollno='$rollno'");
        $row = mysqli_fetch_assoc($result);

        if ($row) {
            echo "<h3>Student Details</h3>";
            echo "<table border='1' cellpadding='5'>
                    <tr><th>Name</th><td>{$row['name']}</td></tr>
                    <tr><th>Roll No</th><td>{$row['Rollno']}</td></tr>
                    <tr><th>Gender</th><td>{$row['Gender']}</td></tr>
                    <tr><th>Mark 1</th><td>{$row['mark1']}</td></tr>
                    <tr><th>Mark 2</th><td>{$row['mark2']}</td></tr>
                    <tr><th>Total</th><td>{$row['Total']}</td></tr>
                  </table>";
        } else {
            echo "<p>No record found for Roll No: $rollno</p>";
        }
    }

    mysqli_close($conn);
    ?>
</body>
</html>
