<?php
	if (isset($_GET['action']) && isset($_GET['name']))
	{
		$act = $_GET['action'];
		$name = $_GET['name'];

		if ($act == 'set' && isset($_GET['value']))
			setcookie($name, $_GET['value'], time() + 60 * 60 * 24 * 60);
		else if ($act == 'get' && isset($_COOKIE[$name]))
			echo ($_COOKIE[$name] . "\n");
		else if ($act == 'del')
			setcookie($name, '', 0);
	}
?>