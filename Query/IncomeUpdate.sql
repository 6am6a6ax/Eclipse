UPDATE tbl_income SET
date = ?,
material_id = (SELECT material_id FROM tbl_materials WHERE name = ?),
count = ?,
responsible_id = (SELECT responsible_id FROM tbl_responsible WHERE first_name = ? AND surname = ?),
producer_id = (SELECT producer_id FROM tbl_producers WHERE name = ?),
position_id = (SELECT position_id FROM tbl_positions WHERE row = ? AND rack = ?) WHERE income_id = ?