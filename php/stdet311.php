<html>
<head>
    <title>Student Marklist</title>
</head>
<body bgcolor="beige">
<center>
<h1>Student Details</h1>

<form method="post" action="details.php">
    Rollno:<input type="number" name="rollno" required><br>
    Name: <input type="text" name="name" required><br><br>
    Gender:<input type="radio" value="Male" name="m">Male
    <input type="radio" value="female" name="m">Female<br><br>
    Class:
    <select name="class1">
        <?php
        for($i=1; $i<=12; $i++){
            echo "<option value='$i'>$i</option>";
        }
        ?>
    </select><br><br>
    Mark 1: <input type="number" name="m1" required><br><br>
    Mark 2: <input type="number" name="m2" required><br><br>
    Mark 3: <input type="number" name="m3" required><br><br>

    <input type="submit" name="submit" value="Submit">
    <input type="reset" name="reset" value="reset">
</form>


</center>
</body>
</html>