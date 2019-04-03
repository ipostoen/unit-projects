SELECT `last_name`, `first_name`, DATE(`birthdate`) AS `birthdate`
FROM `db_ipostoen`.`user_card` WHERE `birthdate` LIKE '1989%'
ORDER BY `last_name`;