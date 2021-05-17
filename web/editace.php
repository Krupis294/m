<?php
include_once "hlava.html";
?>
    <h1>Editace studentů</h1>
    <table width='30%'>
        <tr>
            <td>Id:</td>
            <td>Jmeno:</td>
            <td>Trida:</td>
            <td>Datum Narozeni:</td>
        </tr>
<?php
include_once "spojeni.php";
$sql = mysqli_query($spojeni, "SELECT * FROM Zaci");
$i = 0;
while ($row = mysqli_fetch_assoc($sql)) {
    echo "
        <tr>
        <td>" . $row['id'] . "</td><td>" . $row['jmeno'] . "</td><td>" . $row['trida'] . "</td><td>" . $row['nar'] . "</td>
        </tr>";
    $i -= -1;
}

echo "</table>";
echo " <form action='editace.php' method='post'>
    <table>
    <tr>
        <td>Id pro editaci:</td>
        <td><input type='number' min='1' max='$i' name='edit'></td>
    </tr>
</table>
        <table>
            <tr>
                <td>Nove Jmeno:</td>
                <td><input type='text' name='jmeno'></td>
            </tr>
            <tr>
                <td>Nova Trida:</td>
                <td><input type='number' min='1' max='9' name='trida'></td>
            </tr>
            <tr>
                <td>Nove Datum narozeni:</td>
                <td><input type='date' name='nar'></td>
            </tr>
            <tr>
                <td><input type='submit' value='Editovat'></td>
            </tr>
        </table>
    </form>
";
include_once "spojeni.php";
if ($_POST) {
    $edit = $_POST['edit'];
    $jmeno = $_POST['jmeno'];
    $trida = $_POST['trida'];
    $nar = $_POST['nar'];
    mysqli_query($spojeni, "UPDATE Zaci SET jmeno='$jmeno', trida='$trida',nar='$nar' where id='$edit'");
}
include_once "zadek.html";
?>