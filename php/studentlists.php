<!--<html>
    <body bgcolor="beige">
        <center>
            <h1><marquee>Welcome Admin</marquee></h1>
            <br><br><br><br><br>
        <h1>Dashboard</h1>
        <a href="admin.php" target="self">Home</a><br>
        <a href="addstudent.php" target="a">add stduent</a><br>
        <a href="managestudent.php" target="a">update and delete student</a><br>
        <a href="update_marks.php" target="a">manage stduent details</a><br>
        <a href="topstudent.php" target="a">view top student</a><br>
        </center>

        

        
    </body>
</html>-->
<?php
session_start();
?>
<!DOCTYPE html>
<html>
<head>
    <title>Admin Dashboard - Welcome</title>
    <style>
        body {
            margin: 0;
            padding: 0;
            font-family: "Poppins", sans-serif;
            background: linear-gradient(135deg, #1a1a2e, #16213e, #0f3460);
            color: white;
            height: 100vh;
        }

        .header {
            text-align: center;
            padding: 15px;
            background: rgba(0, 0, 0, 0.4);
            font-size: 26px;     /* smaller */
            font-weight: bold;
            letter-spacing: 1px;
            border-bottom: 3px solid gold;
        }

        .content {
            text-align: center;
            margin-top: 40px;     /* smaller spacing */
        }

        .card {
            margin: auto;
            width: 40%;           /* smaller width */
            padding: 18px;        /* smaller padding */
            background: rgba(255, 255, 255, 0.1);
            border-radius: 15px;  /* smaller radius */
            box-shadow: 0 0 14px gold;
            border: 1px solid gold;
        }

        .card h2 {
            font-size: 20px;      /* smaller heading */
        }

        .link {
            display: block;
            margin: 10px;         /* smaller spacing */
            padding: 6px;         /* smaller padding */
            font-size: 16px;      /* smaller font */
            text-decoration: none;
            color: gold;
            font-weight: bold;
            border: 1px solid gold;
            border-radius: 8px;
            transition: 0.3s;
        }

        .link:hover {
            background: gold;
            color: black;
            transform: scale(1.05); /* smaller hover effect */
            box-shadow: 0 0 10px gold;
        }

    </style>
</head>
<body>

    <div class="header">
        Student home page
    </div>

    <div class="content">
        <div class="card">
            <h2>Welcome, Student!</h2>

            <a class="link" href="Studenthome.php" target="self">🏠 Home</a>
            
            <a class="link" href="showprogress.php" target="a">📘 Show Student Progress report</a>
            <a class="link" href="topstudent.php" target="a">🏆 View Top Student</a>
            <a class="link" href="studentlogin.php" target="self">🚪 Logout</a>

        </div>
    </div>

</body>
</html>
