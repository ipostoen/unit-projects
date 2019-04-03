<?php


function checkIfUserExist($login) {
global $servername, $username, $password, $dbname;
$conn = mysqli_connect($servername, $username, $password, $dbname);
if (!$conn) die("Connection failed: " . mysqli_connect_error());

$sql = "SELECT login FROM users WHERE login='$login'";

$result = mysqli_query($conn, $sql);
$ifExist = false;

if (mysqli_num_rows($result) > 0) {
    $ifExist = true;
}
mysqli_close($conn);
return ($ifExist);
}

function singUp ($login, $pass) {
global $servername, $username, $password, $dbname;
$conn = mysqli_connect($servername, $username, $password, $dbname);
if (!$conn) die("Connection failed: " . mysqli_connect_error());

$sql = "INSERT INTO users (login, password) VALUES ('$login', '$pass')";
$res = false;
if (mysqli_query($conn, $sql)) {
    $res = true;
}
mysqli_close($conn);
return ($res);
}

function logIn ($login, $pass) {
global $servername, $username, $password, $dbname;
$conn = mysqli_connect($servername, $username, $password, $dbname);
if (!$conn) die("Connection failed: " . mysqli_connect_error());

$sql = "SELECT * FROM users WHERE login='$login' AND password='$pass'";

$result = mysqli_query($conn, $sql);
$ifExist = false;

if (mysqli_num_rows($result) > 0) {
    $ifExist = true;
} 
mysqli_close($conn);
return ($ifExist);
}

function deleteUser ($login) {
global $servername, $username, $password, $dbname;
$conn = mysqli_connect($servername, $username, $password, $dbname);
if (!$conn) die("Connection failed: " . mysqli_connect_error());
$res = false;

$sql = "DELETE FROM users WHERE login='$login'";

if (mysqli_query($conn, $sql)) {
    $res = true;
}
mysqli_close($conn);
return ($res);
}

function getUserId ($login) {
	global $servername, $username, $password, $dbname;
	$conn = mysqli_connect($servername, $username, $password, $dbname);
	if (!$conn) die("Connection failed: " . mysqli_connect_error());

		$sql = "SELECT uid FROM users WHERE login = '$login'";
		$res = mysqli_query($conn, $sql);
		if (mysqli_num_rows($res) > 0) {
    	$data = mysqli_fetch_assoc($res);
        // echo "id: " . $data["id"]. " -  name:   " . $data["name"]. "<br>";
        $result = $data['uid'];
 
		}
		return ($result);
}

function updateUserData ($login, $pass, $id) {
global $servername, $username, $password, $dbname;
$conn = mysqli_connect($servername, $username, $password, $dbname);
if (!$conn) die("Connection failed: " . mysqli_connect_error());

$sql = "UPDATE users SET login='$login', password='$pass' WHERE uid='$id'";
$res = false;
if (mysqli_query($conn, $sql)) {
    $res = true;
} 
mysqli_close($conn);
return ($res);
}

?>