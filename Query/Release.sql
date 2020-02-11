SELECT r.date, m.name, r.count FROM tbl_releases r
INNER JOIN tbl_materials m ON r.material_id = m.material_id
WHERE r.release_id = ?