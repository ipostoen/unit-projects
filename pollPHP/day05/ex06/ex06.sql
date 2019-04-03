SELECT `title`, `summary`
FROM `db_ipostoen`.`film`
WHERE lower(`summary`) LIKE '%vincent%'
ORDER BY `id_film` ASC;