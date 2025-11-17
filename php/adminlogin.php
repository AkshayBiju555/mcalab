<?php
session_start();

// Connect to database
$conn = mysqli_connect("localhost", "root", "", "student");
if (!$conn) {
    die("Connection failed: " . mysqli_connect_error());
}

// Check if form is submitted
if (isset($_POST['submit'])) {
    $username = $_POST['username'];
    $password = $_POST['password'];

    $sql = "SELECT * FROM login WHERE username='$username' AND password='$password'";
    $result = mysqli_query($conn, $sql);

    if (mysqli_num_rows($result) == 1) {
        $_SESSION['username'] = $username;  // save username in session
        header("Location: adminhome.php");  // go to home page
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
    <title>Admin Login</title>
</head>
<body>
<center>
    <h2>Admin Login</h2>
    <form method="POST">
        Username: <input type="text" name="username" required><br><br>
        Password: <input type="password" name="password" required><br><br>
        <input type="submit" name="submit" value="Login">
    </form>
</center>
</body>
</html>