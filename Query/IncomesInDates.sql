SELECT i.date, m.name, i.count, r.first_name, r.surname, pr.name, p.row, p.rack FROM tbl_income i
INNER JOIN tbl_materials m ON i.material_id = m.material_id
INNER JOIN tbl_responsible r ON i.responsible_id = r.responsible_id
INNER JOIN tbl_producers pr ON i.producer_id = pr.producer_id
INNER JOIN tbl_positions p ON i.position_id = p.position_id
WHERE ? < date AND date < ?