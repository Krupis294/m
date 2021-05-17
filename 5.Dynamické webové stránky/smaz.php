<?php
include_once 'main.html';
?>
	<main>
	<div class="tabula">
	<h1>Smazání přihlášeného studenta<br><br></h1>
	<form action="smaz.php" method="post" enctype="multipart/form-data">
		<div class="hledani">
			<label for="id">Studenti:</label> <select name="id" id="id">
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
				<input type="submit" value="Odeslat hledání">
		</div>
	</form>
<?php
if($_POST){

	$serversql = "localhost";
	$jmenosql  = "root";
	$heslosql  = "heslo";
	$jmenodb   = "prihlaska";
	$id=$_POST['id'];
	$conn= new mysqli( $serversql, $jmenosql, $heslosql, $jmenodb );
	$conn->select_db( $jmenodb ) or die( "Nemůžu najít databazi" );
	if ( $conn->connect_error ){
		die( "Chyba přiklášení: " . $conn->connect_error );
	}
	$sql = "DELETE FROM uchazec WHERE id=$id";
	if(mysqli_query($conn,$sql)) echo "<br><br><br>Student byl smazán.";
	else echo "<br><br><br>Chyba při mazání uživatele." .$conn->error;
	echo"</main>";
}
?>