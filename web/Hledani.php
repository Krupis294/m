<?php
include_once "hlava.html";
?>
<H1>Hledání studenta</H1>
    <table>
        <form method="post" action="Hledani.php">
            <tr>
                <td>Id Studenta:</td>
                <td><input type="text" name="hled"></td>
            </tr>
            <tr>
                <td><input type="submit"></td>
            </tr>
        </form>
    </table>
<?php
if($_POST){
    $hled=$_POST['hled'];
    include_once "spojeni.php";
    $sql=mysqli_query($spojeni,"SELECT * FROM Zaci");
    $i=0;
    echo "<table width='30%'>";
    while($row=mysqli_fetch_assoc($sql)) if($hled==$row['id']) $i++;

    if($i==0) echo"<tr><td>Nikdo takový zde není</td></tr>";
    else{
        echo"<tr>
            <td>Id:</td><td>Jmeno:</td><td>Trida:</td><td>Datum Narozeni:</td>
            </tr>";
        $sql=mysqli_query($spojeni,"SELECT * FROM Zaci");
        while($row=mysqli_fetch_assoc($sql)) {
            if($hled==$row['id']) {
                echo "
            <tr>
            <td>" . $row['id'] . "</td><td>" . $row['jmeno'] . "</td><td>" . $row['trida'] . "</td><td>" . $row['nar'] . "</td>
            </tr>";
            }
        }
    }
}
 echo "</table>";
include_once "zadek.html";
?>
