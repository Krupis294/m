<?php
include_once "hlava.html";
include_once "spojeni.php";
mysqli_query($spojeni, "CREATE TABLE IF NOT EXISTS Zaci(id serial primary key , jmeno VARCHAR(20),trida INT(10),nar DATE)");
?>
<form action="novy.php" method="post">
    <table>
        <tr>
            <td>Jmeno:</td>
            <td><input type="text" name="jmeno"></td>
        </tr>
        <tr>
            <td>Trida:</td>
            <td><input type="number" min="1" max="9" name="trida"></td>
        </tr>
        <tr>
            <td>Datum narozeni:</td>
            <td><input type="date" name="nar"></td>
        </tr>
        <tr>
            <td><input type="submit" value="Odeslat"></td>
        </tr>
    </table>
</form>

<?php
include_once "spojeni.php";
if ($_POST) {
    $jmeno = $_POST['jmeno'];
    $trida = $_POST['trida'];
    $nar = $_POST['nar'];
    mysqli_query($spojeni, "INSERT INTO Zaci(jmeno,trida,nar) VALUES('$jmeno','$trida','$nar')");
}
include_once "zadek.html";
?>
