# LeetCode 595 大的国家

# Write your MySQL query statement below
SELECT
    name, population, area
FROM
    World
WHERE
    area >= 3000000 OR population >= 25000000;