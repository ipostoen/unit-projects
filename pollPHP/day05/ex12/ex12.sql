SELECT `last_name`, `first_name` FROM `db_ipostoen`.`user_card`
WHERE `last_name` LIKE '%-%' OR `first_name` LIKE '%-%'
ORDER BY `last_name`, `first_name`;