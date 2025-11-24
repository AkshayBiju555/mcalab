<!DOCTYPE html>
<html>
<head>
    <title>Electricity Bill Generator</title>
</head>
<body bgcolor="#f0f8ff">
<center>
    <h2>Electricity Bill Calculator</h2>

<form method="POST">
    <table cellpadding="5">
        <tr>
            <td>Consumer ID:</td>
            <td><input type="text" name="consumer_id" value="<?php if(isset($_POST['consumer_id'])) echo $_POST['consumer_id']; ?>"></td>
        </tr>
        <tr>
            <td>Enter Units Consumed:</td>
            <td><input type="number" name="units" value="<?php if(isset($_POST['units'])) echo $_POST['units']; ?>"></td>
        </tr>
        <tr>
            <td colspan="2" align="center">
                <input type="submit" name="calculate" value="Calculate Bill">
            </td>
        </tr>
    </table>
</form>

<?php
if (isset($_POST['calculate'])) {
    $consumer_id = $_POST['consumer_id'];
    $units = $_POST['units'];

    // Tariff Calculation
    $bill = 0;
    $remaining = $units;

    if ($remaining > 200) {
        $bill += ($remaining - 200) * 10;
        $remaining = 200;
    }
    if ($remaining > 100) {
        $bill += ($remaining - 100) * 7;
        $remaining = 100;
    }
    if ($remaining > 0) {
        $bill += $remaining * 5;
    }

    $bill += 50; // Fixed charge

    // Display Bill
    echo "<h3>Electricity Bill</h3>";
    echo "<table border='1' cellpadding='5'>
            <tr><th>Consumer ID</th><td>$consumer_id</td></tr>
            <tr><th>Units Consumed</th><td>$units units</td></tr>
            <tr><th>Bill Amount</th><td>₹" . number_format($bill, 2) . "</td></tr>
          </table>";
}
?>

</center>
</body>
</html>
