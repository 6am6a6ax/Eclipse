UPDATE tbl_releases SET
date = ?,
material_id = (SELECT material_id FROM tbl_materials WHERE name = ?),
count = ?
WHERE release_id = ?