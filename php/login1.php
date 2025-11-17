<?php
$con = mysqli_connect('localhost', 'root', '', 'akshay');
if (!$con) 
{
    die("Connection failed: " . mysqli_connect_error());
}
if (isset($_POST['login'])) 
{

    
    $user = $_POST['username'];
    $pass = $_POST['password'];

    
    $sql = "SELECT * FROM login WHERE username='$user' AND password='$pass'";
    $result = mysqli_query($con, $sql);

    
    if (mysqli_num_rows($result) > 0) 
        {
        echo "<center><h2>Login Successful! Welcome, $user.</h2></center>";
    } else {
        echo "<center><h2>Invalid Username or Password.</h2></center>";
    }

}
else 
{
    
    echo "<center><h3>Please submit the login form.</h3></center>";
}