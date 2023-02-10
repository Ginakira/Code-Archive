# LeetCode 584 寻找用户推荐人

# Write your MySQL query statement below
SELECT
    name
FROM
    customer
WHERE
    referee_id <> 2 OR referee_id IS NULL
;