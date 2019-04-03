<?php require_once 'header.php';?>
<?php if (isset($_POST['emtyCartById'])) {
	$res = false;
	$res = deleteCartProduct($_SESSION[id]);
	
}
?>

<section class="page">
	<div class="head">
		<?php if (!$res) :?>
		<h1>Basket</h1>
		<?php endif ;?>

		<?php if ($res) :?>
			<h1>Thanks for your purchase!</h1>
		<?php endif ;?>
	</div>

<?php
		$arr = getAllProductBasket($_SESSION[id]);

		foreach ($arr as $val) {
			$arr1[] = getAllProductById($val);
		}

?>
	<div class="content">
		<div class="prod">
			<div class="name"><h3>Product name</h3></div>
			<div class="price"><h3>Price</h3></div>
			<div class="cat"><h3>Category</h3></div>
			<div class="img"><h3>Image</h3></div>
		</div>
		<div class="amount"><h3>Amount</h3></div>
	</div>

<hr>
<?php
foreach ($arr1 as $val):
?>
	<div class="content">
		<div class="prod">
			<div class="name"><h3><?php echo $val[name];?></h3></div>
			<div class="price"><h3><?php echo $val[price];?></h3></div>
			<div class="cat"><h3><?php echo $val[category];?></h3></div>
			<div class="img"><img src="<?php echo $val[img];?>" alt=""></div>
		</div>
		<div class="amount"><h3>Amount</h3></div>
	</div>
<?php endforeach;?>




<form method="post">
	<input type="submit" name="emtyCartById" placeholder="Buy" />
</form>

</section>





<?php require_once 'footer.php';?>