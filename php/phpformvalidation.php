<!DOCTYPE html>
<html>
<head>
    <title>Add New Student</title>
</head>
<body bgcolor="lightyellow">
<center>
    <h2>Add New Student</h2>

<?php

$conn = mysqli_connect("localhost", "root", "", "akshay");
if (!$conn) {
    die("Connection failed: " . mysqli_connect_error());
}

// Variables
$name = $rollno = $gender = $mark1 = $mark2 = $password = "";
$nameErr = $rollErr = $genErr = $mark1Err = $mark2Err = $pwdErr = "";

// When submit button is clicked
if (isset($_POST['submit'])) {

    // -------------------------
    // VALIDATION
    // -------------------------

    // Name validation
    if (empty($_POST['name'])) {
        $nameErr = "Name is required";
    } elseif (!preg_match("/^[A-Za-z ]+$/", $_POST['name'])) {
        $nameErr = "Only letters allowed";
    } else {
        $name = $_POST['name'];
    }

    // Roll number validation
    if (empty($_POST['rollno'])) {
        $rollErr = "Roll number is required";
    } else {
        $rollno = $_POST['rollno'];
    }

    // Gender validation
    if (empty($_POST['gender'])) {
        $genErr = "Gender is required";
    } else {
        $gender = $_POST['gender'];
    }

    // Mark1 validation
    if (empty($_POST['mark1'])) {
        $mark1Err = "Mark 1 is required";
    } elseif (!is_numeric($_POST['mark1'])) {
        $mark1Err = "Mark must be a number";
    } else {
        $mark1 = $_POST['mark1'];
    }

    // Mark2 validation
    if (empty($_POST['mark2'])) {
        $mark2Err = "Mark 2 is required";
    } elseif (!is_numeric($_POST['mark2'])) {
        $mark2Err = "Mark must be a number";
    } else {
        $mark2 = $_POST['mark2'];
    }

    // Password validation
    if (empty($_POST['pwd'])) {
        $pwdErr = "Password is required";
    } elseif (strlen($_POST['pwd']) < 4) {
        $pwdErr = "Password must be at least 4 characters";
    } else {
        $password = $_POST['pwd'];
    }

    // If no errors → Insert into database
    if ($nameErr == "" && $rollErr == "" && $genErr == "" && $mark1Err == "" && $mark2Err == "" && $pwdErr == "") {

        $total = $mark1 + $mark2;

        $sql = "INSERT INTO bio (name, Rollno, Gender, mark1, mark2, Total, password)
                VALUES ('$name', '$rollno', '$gender', '$mark1', '$mark2', '$total', '$password')";

        if (mysqli_query($conn, $sql)) {
            echo "<h3 style='color:green;'>Student added successfully!</h3>";

            // Clear form after successful insertion
            $name = $rollno = $gender = $mark1 = $mark2 = $password = "";
        } else {
            echo "<h3 style='color:red;'>Error: " . mysqli_error($conn) . "</h3>";
        }
    }
}

mysqli_close($conn);
?>

<!-- -------------------------- -->
<!--     STUDENT FORM           -->
<!-- -------------------------- -->

<form method="POST">
    <table border="0" cellpadding="5">

        <tr>
            <td>Name:</td>
            <td><input type="text" name="name" value="<?php echo $name; ?>"></td>
            <td><span style="color:red;"><?php echo $nameErr; ?></span></td>
        </tr>

        <tr>
            <td>Roll No:</td>
            <td><input type="text" name="rollno" value="<?php echo $rollno; ?>"></td>
            <td><span style="color:red;"><?php echo $rollErr; ?></span></td>
        </tr>

        <tr>
            <td>Gender:</td>
            <td>
                <select name="gender">
                    <option value="">Select</option>
                    <option value="Male"   <?php if ($gender == "Male") echo "selected"; ?>>Male</option>
                    <option value="Female" <?php if ($gender == "Female") echo "selected"; ?>>Female</option>
                </select>
            </td>
            <td><span style="color:red;"><?php echo $genErr; ?></span></td>
        </tr>

        <tr>
            <td>Mark 1:</td>
            <td><input type="number" name="mark1" value="<?php echo $mark1; ?>"></td>
            <td><span style="color:red;"><?php echo $mark1Err; ?></span></td>
        </tr>

        <tr>
            <td>Mark 2:</td>
            <td><input type="number" name="mark2" value="<?php echo $mark2; ?>"></td>
            <td><span style="color:red;"><?php echo $mark2Err; ?></span></td>
        </tr>

        <tr>
            <td>Password:</td>
            <td><input type="password" name="pwd" value="<?php echo $password; ?>"></td>
            <td><span style="color:red;"><?php echo $pwdErr; ?></span></td>
        </tr>

        <tr>
            <td colspan="2" align="center">
                <input type="submit" name="submit" value="Add Student">
            </td>
        </tr>

    </table>
</form>

</center>
</body>
</html>
