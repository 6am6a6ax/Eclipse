SELECT name, (i.count * m.price) FROM tbl_materials m
INNER JOIN tbl_income i ON m.material_id = i.material_id
WHERE (i.count * m.price) > ?