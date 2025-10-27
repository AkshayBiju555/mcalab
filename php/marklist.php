<html>
<head>
    <title>Student Marklist</title>
</head>
<body bgcolor="beige">
<center>
<h1>Student Details</h1>

<form method="post" action="">
    Name: <input type="text" name="name" required><br><br>
    
    Age: 
    <select name="age">
        <?php
        for($i=18; $i<=50; $i++){
            echo "<option value='$i'>$i</option>";
        }
        ?>
    </select><br><br>
    Class:
    <select name="class">
        <?php
        for($i=1; $i<=12; $i++){
            echo "<option value='$i'>$i</option>";
        }
        ?>

    </select><br><br>
    Division:
    <select name="class">
        <option>A</option>
        <option>B</option>
        <option>C</option>
        <option>D</option>
    </select><br><br>
    
    Mark 1: <input type="number" name="m1" required><br><br>
    Mark 2: <input type="number" name="m2" required><br><br>
    Mark 3: <input type="number" name="m3" required><br><br>
    
    <input type="submit" name="calculate" value="Calculate Total">
</form>

<?php
if (isset($_POST['calculate'])) {
    $name = $_POST['name'];
    $age = $_POST['age'];
    $m1 = $_POST['m1'];
    $m2 = $_POST['m2'];
    $m3 = $_POST['m3'];
    $total = $m1 + $m2 + $m3;
    
    echo "<h2>Total Marks: $total</h2>";
    
    echo "<form method='post' action='markprogress.php'>
            <input type='hidden' name='name' value='$name'>
            <input type='hidden' name='age' value='$age'>
            <input type='hidden' name='m1' value='$m1'>
            <input type='hidden' name='m2' value='$m2'>
            <input type='hidden' name='m3' value='$m3'>
            <input type='hidden' name='total' value='$total'>
            <input type='submit' name='show' value='See Progress Card'>
          </form>";
}
?>

</center>
</body>
</html>
