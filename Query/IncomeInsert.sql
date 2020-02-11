INSERT INTO tbl_income(date, material_id, count, responsible_id, producer_id, position_id) VALUES(
(?),
(SELECT material_id FROM tbl_materials WHERE name = ?),
?,
(SELECT responsible_id FROM tbl_responsible WHERE first_name = ? AND surname = ?),
(SELECT producer_id FROM tbl_producers WHERE name = ?),
(SELECT position_id FROM tbl_positions WHERE row = ? AND rack = ?))