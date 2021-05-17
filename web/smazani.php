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
echo " <form action='smazani.php' method='post'>
    <table>
    <tr>
        <td>Id pro smazani:</td>
        <td><input type='number' min='1' max='$i' name='delete'></td>
    </tr>
    <tr>
                <td><input type='submit' value='Smazat'></td>
            </tr>
</table>
    </form>
";
include_once "spojeni.php";
if ($_POST) {
    $delete = $_POST['delete'];
    mysqli_query($spojeni, "DELETE FROM Zaci where id='$delete'");
    if(mysqli_query($spojeni,"SELECT * FROM Zaci Where id='$delete'")==NULL) echo "Student byl smazan";
}
include_once "zadek.html";
?>