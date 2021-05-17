<?php
include_once 'main.html';
?>
<main>
<h1>Přihláška na Vysokou školu</h1>
	<form action="form.php" method="post" enctype="multipart/form-data">
	<table class="tab">
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
		<input type="submit" value="Odeslat přihlášku">
	</form>
	
</main>
<?php
if($_POST){
	echo "<br><br><br><br><br>";
	$serversql = "localhost";
	$jmenosql = "root";
	$heslosql = "heslo";
	$jmenodb = "prihlaska";
	$conn = new mysqli($serversql, $jmenosql, $heslosql, $jmenodb);
	$conn-> select_db($jmenodb) or die("Nemůžu najít databazi");
	$jmeno = $conn->real_escape_string($_POST['jmeno']);
	$prijmeni = $conn->real_escape_string($_POST['prijmeni']);
	$obor = $conn->real_escape_string($_POST['obor']);
	$mail=$conn->real_escape_string($_POST['mail']);
	$forma=$conn->real_escape_string($_POST['typ']);
	$termin=$conn->real_escape_string($_POST['termin']);
	if ( $conn->connect_error ) {
		die( "Chyba přiklášení: " . $conn->connect_error );
	}
	$sql = "CREATE TABLE `uchazec` (
  `id` INT NOT NULL AUTO_INCREMENT,
  `jmeno` VARCHAR(45) NULL,
  `prijmeni` VARCHAR(45) NULL,
  `email` VARCHAR(45) NULL,
  `obor` VARCHAR(45) NULL,
  `forma` VARCHAR(45) NULL,
  `termin` VARCHAR(45) NULL,
  PRIMARY KEY (`id`))";
	$conn->query("$sql");
	$sql = "INSERT INTO uchazec(jmeno,prijmeni,email,obor,forma,termin) VALUES ('$jmeno','$prijmeni','$mail','$obor','$forma','$termin')";
	if(mysqli_query($conn,$sql)) echo "<br><div class=\"konec\">Vaše přihláška byla odeslána</div>";
	else echo " <br>Hodnoty se nepodařilo přidat do databáze ";
}
?>
</body>

