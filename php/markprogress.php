<html>
<head>
    <title>Student Progress Card</title>
</head>
<body bgcolor="beige">
<center>
<h1>Student Progress Card</h1>

<?php
if (isset($_POST['show'])){
    $name = $_POST['name'];
    $age = $_POST['age'];
    $m1 = $_POST['m1'];
    $m2 = $_POST['m2'];
    $m3 = $_POST['m3'];
    $total = $_POST['total'] ?? ($m1 + $m2 + $m3);
    
    echo "<table border='1' cellpadding='10' cellspacing='0' style='border-collapse: collapse; width: 300px; text-align: left;'>";
    echo "<tr><th colspan='2' style='text-align:center;'>Progress Card</th></tr>";
    echo "<tr><td><strong>Name</strong></td><td>$name</td></tr>";
    echo "<tr><td><strong>Age</strong></td><td>$age</td></tr>";
    echo "<tr><td><strong>Mark 1</strong></td><td>$m1</td></tr>";
    echo "<tr><td><strong>Mark 2</strong></td><td>$m2</td></tr>";
    echo "<tr><td><strong>Mark 3</strong></td><td>$m3</td></tr>";
    echo "<tr><td><strong>Total Marks</strong></td><td>$total</td></tr>";
    echo "</table>";
}
?>

<br><br>
<a href="marklist.php">Back to Form</a>
</center>
</body>
</html>
