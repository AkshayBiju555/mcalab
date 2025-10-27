<html>
    <head>
        <title>php form</title>
    </head>
    <body>
        <h1>Registration form</h1>
        <form>
            select a number
            <select>
                <?php
                for($i=1;$i<=100;$i++)
                {
                    //echo "<option value='$i'>$i</option>";
                    //echo "<option>$i</option>";
                    echo "<option>".$i."</option>";
                }
                ?>
            </select>
        </form>
    </body>
</html>