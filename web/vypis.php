<?php
include_once "hlava.html";
?>
    <h1>Výpis studentů</h1>
<table width='30%'>
    <tr>
        <td>Id:</td><td>Jmeno:</td><td>Trida:</td><td>Datum Narozeni:</td>
    </tr>
    <?php
    include_once "spojeni.php";
    $sql=mysqli_query($spojeni,"SELECT * FROM Zaci");
    while($row=mysqli_fetch_assoc($sql)) {
        echo "
        <tr>
        <td>".$row['id']."</td><td>".$row['jmeno']."</td><td>".$row['trida']."</td><td>".$row['nar']."</td>
        </tr>";

    }
    ?>
</table>
<?php
include_once "zadek.html"
?>

