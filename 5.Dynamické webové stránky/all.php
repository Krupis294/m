<?php
include_once 'main.html';
?>
<main>
    <div class="tabula">
        <h1>Výpis všech přihlášených studentů<br><br></h1>
        <?php

	$serversql = "localhost";
	$jmenosql  = "root";
	$heslosql  = "heslo";
	$jmenodb   = "prihlaska";
	$conn      = new mysqli( $serversql, $jmenosql, $heslosql, $jmenodb );
	$conn->select_db( $jmenodb ) or die( "Nemůžu najít databazi" );
	if ( $conn->connect_error ) {
		die( "Chyba přiklášení: " . $conn->connect_error );
	}
     $sql = "SELECT * FROM uchazec";
	$result = $conn-> query($sql);

	if($result-> num_rows > 0){
		while ($row = $result -> fetch_assoc()){
			echo"<div name='tabhled'><table>
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
		echo"NIKDO SE ZATÍM NEPŘIHLÁSIL.";
	}
    echo"</main>";
	$conn->close();
    ?>