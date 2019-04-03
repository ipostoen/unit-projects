SELECT `title` AS 'Title', `summary` AS 'Summary', `prod_year`
FROM `db_ipostoen`.`film`
WHERE `id_genre` = (SELECT `id_genre` FROM `db_ipostoen`.`genre` WHERE `name` = 'erotic')
ORDER BY `prod_year` DESC; 