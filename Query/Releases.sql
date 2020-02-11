SELECT r.release_id, r.date, m.name, m.unit, m.price, r.count FROM tbl_releases r
INNER JOIN tbl_materials m ON r.material_id = m.material_id