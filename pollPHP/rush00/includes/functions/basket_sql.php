<?php

function getAllProductBasket($userId) {
global $servername, $username, $password, $dbname;
$conn = mysqli_connect($servername, $username, $password, $dbname);
if (!$conn) die("Connection failed: " . mysqli_connect_error());

$sql = "SELECT * FROM cart WHERE userId=$userId";

$result = mysqli_query($conn, $sql);

if (mysqli_num_rows($result) > 0) {
    while($data = mysqli_fetch_assoc($result)) {
        // echo "id: " . $data["id"]. " -  Name: " . $data["id_product"]. "<br>";
        $array[] = $data[id_product];
    }
}
mysqli_close($conn);
return ($array);
}

function putProductToBasket ($product_id, $user_id,  $amount) {
global $servername, $username, $password, $dbname;
$conn = mysqli_connect($servername, $username, $password, $dbname);

if (!$conn) die("Connection failed: " . mysqli_connect_error());
$sql = "INSERT INTO cart (id_product, userId, amount)
VALUES ($product_id, $user_id, $amount)";
$res = false;
if (mysqli_query($conn, $sql)) {
    $res = true;
}
mysqli_close($conn);
return ($res);
}

function deleteCartProduct ($id) {
global $servername, $username, $password, $dbname;
$conn = mysqli_connect($servername, $username, $password, $dbname);
if (!$conn) die("Connection failed: " . mysqli_connect_error());

$sql = "DELETE FROM cart WHERE userId='$id'";
$res = false;
if (mysqli_query($conn, $sql)) {
    $res = true;
}
mysqli_close($conn);
return ($res);
}

function updateBasketProduct ($id, $user_id, $product_id, $count) {
global $servername, $username, $password, $dbname;
$conn = mysqli_connect($servername, $username, $password, $dbname);
if (!$conn) die("Connection failed: " . mysqli_connect_error());

$sql = "UPDATE basket SET user_id=$user_id, product_id=$product_id, count=$count WHERE id='$id'";
$res = false;
if (mysqli_query($conn, $sql)) {
    $res = true;
}
mysqli_close($conn);
return ($res);
}
?>