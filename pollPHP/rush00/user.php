<?php 
require_once 'header.php';

if (isset($_POST['btnLogin']))
{
	$login = $_POST['login'];
	$pass = hash('whirlpool', $_POST['pass']);
	$id = getUserId($login);
	$ifLogin = logIn($login, $pass);
	if ($ifLogin) 
	{
		session_start();
		$_SESSION['id'] = $id;
		$_SESSION['login'] = $login;
		$_SESSION['pass'] = $pass;
	} else {
		echo '<section class="page"><h3>Can`t Log in</h3><br><a href="user.php">Back</a></section>';
	}
}
if (isset($_POST['btnSingUp'])) {
	$login = $_POST['login'];
	$pass = hash('whirlpool', $_POST['pass']);
	$ifExist = checkIfUserExist($login);
	if ($ifExist) {
		header('Location: user.php');
	} else {
		singUp($login, $pass);
		header('Location: user.php');
	}
}
if (isset($_POST['btnDell'])) {
	$login = $_POST['login'];
	deleteUser($login);
	$_SESSION[id] = "";
	$_SESSION[login] = "";
	$_SESSION[pass] = "";
	session_destroy();
	$ifLogin = false;
	header('Location: user.php');

}
if (isset($_POST['btnLogOut'])) {
	
	$_SESSION[id] = "";
	$_SESSION[login] = "";
	$_SESSION[pass] = "";
	session_destroy();
	$ifLogin = false;
	header('Location: user.php');
}
if (isset($_POST['btnChange'])) {
	$login = $_POST['login'];
	$pass = hash('whirlpool', $_POST['pass']);
	$id = getUserId($login);
	updateUserData($login, $pass, $id);
}
if (isset($_SESSION[login]))
{
	$id = $_SESSION[id];
	$login = $_SESSION[login];
	$pass = $_SESSION[pass];
}
?>


<section id="user">
	<div class="url">
		<?php if (!$ifLogin && !isset($_SESSION[login])):?>
			<div class="login">
				<section class="login">
					<div class="login-page">
						<div class="form">
							<form method="post">
								<h2>LOGIN</h2>
								<input type="text" name="login" placeholder="username"/>
								<input type="password" name="pass" placeholder="password"/>
								<button type="submit" name="btnLogin">login</button>
							</form>
						</div>
					</div>
				</section>	
				<section class="login">
					<div class="login-page">
						<div class="form">
							<form method="post">
								<h2>SING UP</h2>
								<input type="login" name="login" placeholder="username"/>
								<input type="password" name="pass" placeholder="password"/>
								<button type="submit" name="btnSingUp">SingUp</button>
							</form>
						</div>
					</div>
				</section>
			<?php endif;
			if ($ifLogin || $_SESSION[login]):?>
			<?php echo "<h3>Login: " . $login . "</h3>";?>
			<form method="post">
				<input type="text" name="login" style="display: none;" value="<?php echo $login; ?>" />
				<button type="submit" name="btnDell">DEL me</button>
				<br>
				<button type="submit" name="btnLogOut">Log Out</button>
				<br>
			</form>
			<h3>Update info</h3>
			<form method="post">
				<input type="text" name="login" value="<?php echo $login; ?>" />
				<input type="password" name="pass" value="<?php echo $pass; ?>" />
				<button type="submit" name="btnChange">update</button>
			</form>
		<?php endif; ?>
	</div>
</div>
</section>

<?php require_once 'footer.php';