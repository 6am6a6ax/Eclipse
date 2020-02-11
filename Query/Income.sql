SELECT i.date, m.name, i.count, r.first_name, 
r.surname, p.name, pn.row, pn.rack FROM tbl_income i
INNER JOIN tbl_materials m ON i.material_id = m.material_id
INNER JOIN tbl_responsible r ON i.responsible_id = r.responsible_id
INNER JOIN tbl_producers p ON i.producer_id = p.producer_id
INNER JOIN tbl_positions pn ON i.position_id = pn.position_id
WHERE i.income_id = ?