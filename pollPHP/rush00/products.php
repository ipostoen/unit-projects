<?php require_once 'header.php';
$arr = getAllProduct();
?>

<section class="products">
<?php	if (isset($_POST['btnAddToCart'])) {
				$id = $_SESSION[id];
				$prodId = $_POST['prodId'];
				$amount = 1;
				putProductToBasket ($prodId, $id, $amount);
			}
	 foreach ($arr as $value):
		
	?>
		<div class="wrapProd">
			<div class="topImg">
				<img src="<?php echo $value['img_url'];?>" alt="">
			</div>
			<div class="centerText">
				<h2><?php echo $value['name'];?></h2>
				<h3>Cost: <?php echo $value['price'];?></h3>
			</div>
			<div class="bottomBtn">
				<form method="post">
					<input type="text" name="prodId" style="display: none;" value="<?php echo $value[id_product];?> ">
					<button type="submit" name="btnAddToCart">Add to cart</button>
				</form>
			</div>
		</div>
	<?php endforeach; ?>
	
</section>

<?php require_once 'footer.php';?>