SELECT SUBSTRING(REVERSE(`phone_number`), 1, CHAR_LENGTH(`phone_number` - 1)) AS `rebmunenohp` FROM `db_ipostoen`.`distrib`
WHERE `phone_number` LIKE '05%';