# LeetCOde 1757 可回收且低脂的产品

# Write your MySQL query statement below
SELECT
    product_id
FROM
    Products
WHERE
    low_fats = 'Y' AND recyclable = 'Y'
;