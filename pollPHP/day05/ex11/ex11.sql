SELECT upper(`last_name`) AS `NAME`, `first_name`, `price` FROM `db_ipostoen`.`user_card`
JOIN `member` ON `db_ipostoen`.`member`.`id_user_card` = `db_ipostoen`.`user_card`.`id_user`
JOIN `subscription` ON `db_ipostoen`.`member`.`id_sub` = `db_ipostoen`.`subscription`.`id_sub`
WHERE `price` >= 42
ORDER BY `last_name`, `first_name`;