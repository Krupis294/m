<?php
include_once 'main.html';
?>
	<main>
	<div class="tabula">
	<h1>Hledání přihlášených studentů<br><br></h1>
    <form action="hled.php" method="post" enctype="multipart/form-data">
        <div class="hledani">
            <label for="obor">Obor</label> <select name="obor" id="obor">
                <?php
                $string=array('Softwarové inženýrství','Aplikovaná informatika','Bezpečnostní technologie','IT v administrativě');
        for ( $i = 0; $i < 4; $i++ )
        {
           echo"<option value='$string[$i]'>$string[$i]</option>";
        }
        ?>
			</select>
                <input type="submit" value="Odeslat hledání">
        </div>
    </form>
    <?php
if($_POST){

	$serversql = "localhost";
	$jmenosql  = "root";
	$heslosql  = "heslo";
	$jmenodb   = "prihlaska";
	$conn= new mysqli( $serversql, $jmenosql, $heslosql, $jmenodb );
	$hledani=$conn->real_escape_string($_POST['obor']);
	$conn->select_db( $jmenodb ) or die( "Nemůžu najít databazi" );
	if ( $conn->connect_error ){
		die( "Chyba přiklášení: " . $conn->connect_error );
	}
	$sql = "SELECT * FROM uchazec where obor='$hledani'";
	$result = $conn-> query($sql);
	if($result-> num_rows > 0){
		while ($row = $result -> fetch_assoc()){
			echo"<br><br><br><div name='tabhled'><table>
		<tr>
		<th>ID</th>
		<th>Jméno</th>
		<th>Příjmení</th>
		<th>Email</th>
		<th>Obor</th>
		<th>Forma Studia</th>
		<th>Termín</th>
		</tr>
		<tr id='tabmez'><td>".$row["id"]."</td><td>".$row["jmeno"]."</td><td>".$row["prijmeni"]."</td><td>".$row["email"]."</td><td>".$row["obor"]."</td><td>".$row["forma"]."</td><td>".$row["termin"]."</td></tr>";
		}
		echo "</div></table>";
	}
	else{
		echo"<br><br><br>NIKDO SE ZATÍM NEPŘIHLÁSIL.";
	}
	echo"</main>";
	}
   ?>