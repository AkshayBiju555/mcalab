<!DOCTYPE html>
<html>
<head>
    <title>Update Student Marks</title>
</head>
<body bgcolor="lightcyan">
<center>
    <h2>Update Student Marks</h2>

    <?php
    $conn = mysqli_connect("localhost", "root", "", "akshay");
    if (!$conn) {
        die("Connection failed: " . mysqli_connect_error());
    }

    // When the update form is submitted
    if (isset($_POST['update'])) {
        $rollno = $_POST['rollno'];
        $mark1 = $_POST['mark1'];
        $mark2 = $_POST['mark2'];
        $total = $mark1 + $mark2;

        $sql = "UPDATE bio SET mark1='$mark1', mark2='$mark2', Total='$total' WHERE Rollno='$rollno'";
        if (mysqli_query($conn, $sql)) {
            echo "<h3 style='color:green;'>Marks updated successfully!</h3>";
        } else {
            echo "<h3 style='color:red;'>Error: " . mysqli_error($conn) . "</h3>";
        }
    }
    ?>

    <form method="POST">
        <table border="0" cellpadding="5">
            <tr><td>Enter Roll No:</td><td><input type="text" name="rollno" required></td></tr>
            <tr><td>Mark 1:</td><td><input type="number" name="mark1" required></td></tr>
            <tr><td>Mark 2:</td><td><input type="number" name="mark2" required></td></tr>
            <tr><td colspan="2" align="center"><input type="submit" name="update" value="Update Marks"></td></tr>
        </table>
    </form>

    <br><br>
    <h3>All Students</h3>
    <table border="1" cellpadding="5">
        <tr><th>Name</th><th>Rollno</th><th>Gender</th><th>Mark1</th><th>Mark2</th><th>Total</th></tr>
        <?php
        $result = mysqli_query($conn, "SELECT * FROM bio");
        while ($row = mysqli_fetch_assoc($result)) {
            echo "<tr>
                    <td>{$row['name']}</td>
                    <td>{$row['Rollno']}</td>
                    <td>{$row['Gender']}</td>
                    <td>{$row['mark1']}</td>
                    <td>{$row['mark2']}</td>
                    <td>{$row['Total']}</td>
                  </tr>";
        }
        mysqli_close($conn);
        ?>
    </table>
</center>
</body>
</html>