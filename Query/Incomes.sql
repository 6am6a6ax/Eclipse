SELECT i.income_id, i.date, m.name, i.count, m.unit, m.price,
r.first_name, r.surname, r.position, p.name, p.address,
p.phone, pn.row, pn.rack FROM tbl_income i
INNER JOIN tbl_materials m ON i.material_id = m.material_id
INNER JOIN tbl_responsible r ON i.responsible_id = r.responsible_id
INNER JOIN tbl_producers p ON i.producer_id = p.producer_id
INNER JOIN tbl_positions pn ON i.position_id = pn.position_id