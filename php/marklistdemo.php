<html>
    <head>
        <title>
            Student Marklist
        </title>
    </head>
   

    <body bgcolor="beige">
        
        <center>
            <h1>Student details</h1>
        <form method="post" action="markprogress.php">
            <table border ="1">
                <tr>
                    <td>Name</td>
                    <td><input type="text" name="name"></td>
                </tr>
                <tr>
                     <td>Age</td>
                     <td>
                        <select name="age">
                        */<?php
                        for($i=18;$i<=50;$i++)
                        {
                            echo "<option value=$i>".$i."</option>";

                        }
                        ?>
                        </select>
                     </td>
                     <tr>
                        <td>Class</td>
                        <td>
                            <select>
                        <?php
                        for($i=1;$i<=12;$i++)
                        {
                            echo "<option value=$i>".$i."</option>";

                        }
                        ?>
                        </select>
                        Division
                             <select name="DIV" required>
                            <option >SELECT</option>
                            <option>A</option>
                            <option>B</option>
                            <option>C</option>
                            <option>D</option>
                        </select>

                        </td>
                     </tr>
                     <tr>
                        <td>Mark 1</td>
                        <td><input type="number" name="m1" id="m1"></td>
                     </tr>
                     <tr>
                        <td>Mark 2</td>
                        <td><input type="number" name="m2" id="m2"></td>
                     </tr>
                     <tr>
                        <td>Mark 3</td>
                        <td><input type="number" name="m3" id="m3"></td>
                     </tr>
                     <tr ><td colspan="2"><input type="submit" value="calculate"> 
                     
            <input type="reset" value="reset"></td></tr>
            <tr>
                <td>
                    <input type="submit" value="See Progress Card" onclick="marks()"> 
                </td>
            </tr>

               
                
               
            </table>
        </form>
        <script>
            function marks(){
                let x=parseint(document.getElementById("m1").value);
                let x=parseint(document.getElementById("m1").value);
                let x=parseint(document.getElementById("m1").value);

            }
        </script>
        
        </center>
        
    </body>
</html>
