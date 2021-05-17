<?php
	include_once 'main.html';
?>
	<main>
			<h1>Editace:</h1>
			<form action="edit.php" method="post" enctype="multipart/form-data">
				<table class="tab">
					<div class="hledani">
						<label for="cislo">Editovaný:</label>
						<select name="cislo" id="cislo">
							<?php
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

							$sql = "SELECT * FROM uchazec";
							$result = $conn-> query($sql);
							if($result-> num_rows > 0){
								while ($row = $result -> fetch_assoc()){
									$id=$row['id'];
									echo"<option value=$id>".$row['jmeno']." ".$row['prijmeni']." ".$row['email']." ".$row['obor']." ".$row['forma']." ".$row['termin']." </option>";
								}
							}
							else{
								echo"<br><br><br>NIKDO SE ZATÍM NEPŘIHLÁSIL.";
							}
							?>
						</select>


					<tr><td>Jmeno</td><td><input type="text" name="jmeno" required></td></tr>
					<tr><td>Prijmeni</td><td><input type="text" name="prijmeni" required></td></tr>
					<tr><td>E-mail</td><td><input type="email" name="mail"></td></tr>
					<tr><td>Obor</td><td><select name="obor">
								<?php
								$string=array('Softwarové inženýrství','Aplikovaná informatika','Bezpečnostní technologie','IT v administrativě');
								for ( $i = 0; $i < 4; $i++ )
								{
									echo"<option value='$string[$i]'>$string[$i]</option>";
								}
								?>
							</select></td></tr>
					<tr><td><div class="text"><p>Forma studia</p></div></td></tr>
				</table>
				<div class="forma">
					<input type="radio" name="typ" id="forma_studia0" value="Prezenční" required onchange="this.setCustomValidity(validity.valueMissing ? 'Musíš vybrat alespoň jednu možnost' : '');">
					<label for="forma_studia0">Prezenční</label>
					<input type="radio" name="typ" id="forma_studia1" value="Kombinovaná" >
					<label for="forma_studia1">Kombinovaná</label>
				</div>
				<tr><td><div class="text"><p>Termín zkoušek</p></div></td></tr>
				</table>
				<div class="forma">
					<input type="radio" name="termin" id="termin0" value="14.5.2020" required onchange="this.setCustomValidity(validity.valueMissing ? 'Musíš vybrat alespoň jednu možnost' : '');">
					<label for="termin0">14.5.2020</label>
					<input type="radio" name="termin" id="termin1" value="21.5.2020" >
					<label for="termin1">21.5.2020</label>
				</div>
				<input type="submit" value="Změnit údaje">
			</form>

<?php
if($_POST){
	echo "<br><br><br><br><br>";
	$serversql = "localhost";
	$jmenosql  = "root";
	$heslosql  = "heslo";
	$jmenodb   = "prihlaska";
	$id=$_POST['cislo'];
	$conn= new mysqli( $serversql, $jmenosql, $heslosql, $jmenodb );
	$hledani=$conn->real_escape_string($_POST['obor']);
	$jmeno = $conn->real_escape_string($_POST['jmeno']);
	$prijmeni = $conn->real_escape_string($_POST['prijmeni']);
	$obor = $conn->real_escape_string($_POST['obor']);
	$mail=$conn->real_escape_string($_POST['mail']);
	$forma=$conn->real_escape_string($_POST['typ']);
	$termin=$conn->real_escape_string($_POST['termin']);
	$conn->select_db( $jmenodb ) or die( "Nemůžu najít databazi" );
	if ( $conn->connect_error ){
		die( "Chyba přiklášení: " . $conn->connect_error );
	}
	$sql = "UPDATE uchazec SET jmeno='$jmeno', prijmeni='$prijmeni', email='$mail', obor='$obor', forma='$forma', termin='$termin' WHERE id=$id";
	if(mysqli_query($conn,$sql)) echo "<br><div class=\"konec\">Vaše data byli úspěšně změněny</div>";
	else echo " <br>Data se nepodařili změnit";
	echo"</main>";
}
?>