<?php
session_start();

// Connect to database
$conn = mysqli_connect("localhost", "root", "", "akshay");
if (!$conn) {
    die("Connection failed: " . mysqli_connect_error());
}

// Check if form is submitted
if (isset($_POST['submit'])) {
    $rollno = $_POST['rollno'];
    $password = $_POST['password'];

    $sql = "SELECT * FROM bio WHERE Rollno='$rollno' AND password='$password'";
    $result = mysqli_query($conn, $sql);

    if (mysqli_num_rows($result) == 1) {
        $_SESSION['rollno'] = $rollno;  // save username in session
        header("Location: Studenthome.php");  // go to home page
        exit();
    } else {
        echo "<center><h3 style='color:red;'>Invalid username or password!</h3></center>";
    }
}

mysqli_close($conn);
?>

<!DOCTYPE html>
<html>
<head>
    <title>Student Login</title>
</head>
<body>
<center>
    <h2>student Login</h2>
    <form method="POST">
        Rollno: <input type="number" name="rollno" required><br><br>
        Password: <input type="password" name="password" required><br><br>
        <input type="submit" name="submit" value="Login">
        <a class="link" href="123.php" target="self">back</a>
    </form>
</center>
</body>
</html>