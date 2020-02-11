INSERT INTO tbl_releases(date, material_id, count) VALUES(
(?),
(SELECT material_id FROM tbl_materials WHERE name = ?),
?)