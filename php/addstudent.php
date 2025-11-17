<!DOCTYPE html>
<html>
<head>
    <title>Add New Student</title>
</head>
<body bgcolor="lightyellow">
<center>
    <h2>Add New Student</h2>

    <?php
    $conn = mysqli_connect("localhost", "root", "", "student");
    if (!$conn) {
        die("Connection failed: " . mysqli_connect_error());
    }

    if (isset($_POST['submit'])) {
        $name = $_POST['name'];
        $rollno = $_POST['rollno'];
        $gender = $_POST['gender'];
        $mark1 = $_POST['mark1'];
        $mark2 = $_POST['mark2'];
        $total = $mark1 + $mark2;

        $sql = "INSERT INTO bio (name, Rollno, Gender, mark1, mark2, Total)
                VALUES ('$name', '$rollno', '$gender', '$mark1', '$mark2', '$total')";
        
        if (mysqli_query($conn, $sql)) {
            echo "<h3 style='color:green;'>Student added successfully!</h3>";
        } else {
            echo "<h3 style='color:red;'>Error: " . mysqli_error($conn) . "</h3>";
        }
    }

    mysqli_close($conn);
    ?>

    <form method="POST">
        <table border="0" cellpadding="5">
            <tr><td>Name:</td><td><input type="text" name="name" required></td></tr>
            <tr><td>Roll No:</td><td><input type="text" name="rollno" required></td></tr>
            <tr><td>Gender:</td>
                <td>
                    <select name="gender">
                        <option value="Male">Male</option>
                        <option value="Female">Female</option>
                    </select>
                </td>
            </tr>
            <tr><td>Mark 1:</td><td><input type="number" name="mark1" required></td></tr>
            <tr><td>Mark 2:</td><td><input type="number" name="mark2" required></td></tr>
            <tr><td colspan="2" align="center"><input type="submit" name="submit" value="Add Student"></td></tr>
        </table>
    </form>
</center>
</body>
</html>