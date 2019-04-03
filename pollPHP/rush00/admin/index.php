
<?php
$servername = "localhost";
$username = "root";
$password = "qwerty123456";
$dbname = "shop";

include '../includes/functions/products_sql.php';
include '../includes/functions/users_sql.php';
include '../includes/functions/basket_sql.php';
include '../includes/functions/category_sql.php';
?>

<!DOCTYPE html>
<html>
<head>
	<title>Admin panel</title>
	<link rel="stylesheet" href="../css/admin.css">
</head>
<body>
	<?php
	if ($ifLogin) : ?>
	<header class="mainHead">
		<button id="cat">Categori</button>
		<button id="prd">Product</button>
		<button id="usr">Users</button>
	</header>
<?php endif?>

<?php if (!$ifLogin) :?>
	<section class="login">
		<div class="login-page">
			<div class="form">
				<input type="text" name="login" placeholder="username"/>
				<input type="password" name="pass" placeholder="password"/>
				<button onclick="loginAdm(login, pass)" name="btnLogin">login</button>
			</div>
		</div>
	</section>
<?php endif ?>
</body>


</html>