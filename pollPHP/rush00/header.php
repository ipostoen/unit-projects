<?php
$servername = "localhost";
$username = "root";
$password = "qwerty123456";
$dbname = "shop";

include 'includes/functions/products_sql.php';
include 'includes/functions/users_sql.php';
include 'includes/functions/basket_sql.php';
include 'includes/functions/category_sql.php';
session_start();
if (!isset($_SESSION[login])) {
	$_SESSION[id] = 1;
}
?>
<!DOCTYPE html>
<html>
<head>
	<meta charset="utf-8" />
	<meta http-equiv="X-UA-Compatible" content="IE=edge">
	<title>Electric Bikes</title>
	<meta name="viewport" content="width=device-width, initial-scale=1">
	<link rel="stylesheet" type="text/css" media="screen" href="./css/main.css" />
	<link rel="stylesheet" type="text/css" media="screen" href="./css/menu.css" />
	<link rel="stylesheet" type="text/css" media="screen" href="./css/page.css" />
	<link rel="stylesheet" type="text/css" media="screen" href="./css/user.css" />
	<link rel="stylesheet" type="text/css" media="screen" href="./css/admin.css" />
	<link href="https://fonts.googleapis.com/css?family=Open+Sans" rel="stylesheet">
	<link rel="stylesheet" href="https://use.fontawesome.com/releases/v5.1.0/css/all.css" integrity="sha384-lKuwvrZot6UHsBSfcMvOkWwlCMgc0TaWr+30HWe3a4ltaBwTZhyTEggF5tJv8tbt" crossorigin="anonymous">
	<script src="./scripts/main.js"></script>
</head>
<body>
	<div class="menu">
		<div class="fixedMenu">
			<div class="logo">
				<a href="#"><h2>Electric BIKES</h2></a>
			</div>
			<ul class="cart">
				<li><a href="cart.php"><i class="fas fa-shopping-cart"></i></a></li>
				<li><a href="user.php" id="au"><i class="fas fa-user"></i></a></li>
			</ul>
			<hr>
			<ul class="shopList">
				<?php
				$cat = getAllCategory();
				foreach ($cat as $value):?>
				<li><a href="products.php"><?php echo $value["name"]; ?></a></li>
			<?php endforeach; ?>
		</ul>
		<hr>
		<ul class="menuList">
			<li><a href="#" id="am" onclick="show('main');">Main</a></li>
			<li><a href="#" id="aa" onclick="show('about');">About us</a></li>
			<li><a href="#" id="ac" onclick="show('contacts');">Contacts</a></li>
			<li><a href="#" id="as" onclick="show('support');">Support</a></li>
		</ul>
		<hr>
		<ul class="socialIcons">
			<li><a href="#"><i class="fab fa-facebook-f"></i></a></li>
			<li><a href="#"><i class="fab fa-instagram"></i></a></li>
			<li><a href="#"><i class="fab fa-twitter"></i></a></li>
		</ul>
	</div>
</div>