<?php
$con = mysqli_connect('localhost', 'root', '', 'akshay');
if (!$con) {
    die("Connection failed: " . mysqli_connect_error());
}


if (isset($_POST['login'])) {
    $user = $_POST['username'];
    $pass = $_POST['password'];

    $sql = "SELECT * FROM login WHERE username='$user' AND password='$pass'";
    $result = mysqli_query($con, $sql);

    if (mysqli_num_rows($result) == 1) {
        header("Location: admin.php");
        exit();
    } else {
        
        echo "<center><h3 style='color:red;'>Invalid Username or Password</h3></center>";
    }
}


mysqli_close($con);
?>


<html>
<head>
    <title>Admin Login</title>
</head>
<body bgcolor="beige">
    <center>
        <h1>Admin Login</h1>
        <form action="" method="POST">
            Username: <input type="text" name="username" required><br><br>
            Password: <input type="password" name="password" required><br><br>
            <input type="submit" name="login" value="Login">
        </form>
    </center>
</body>
</html>
