SELECT i.date, m.name, i.count, p.row, p.rack FROM tbl_income i
INNER JOIN tbl_materials m ON i.material_id = m.material_id
INNER JOIN tbl_positions p ON i.position_id = p.position_id
WHERE i.material_id = (SELECT material_id FROM tbl_materials WHERE name = ?)