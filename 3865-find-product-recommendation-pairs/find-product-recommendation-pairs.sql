# Write your MySQL query statement below
WITH cte AS (
SELECT 
    p1.product_id AS product1_id,
    p2.product_id AS product2_id
FROM ProductPurchases p1
JOIN ProductPurchases p2
ON p1.user_id = p2.user_id
AND p1.product_id < p2.product_id
),

cte1 AS(
    SELECT
        t.product1_id,
        t.product2_id,
        p.category AS product1_category
    FROM cte AS t
    LEFT JOIN ProductInfo AS p
    ON t.product1_id = p.product_id
),

cte2 AS(
    SELECT 
        t.product1_id,
        t.product2_id,
        t.product1_category,
        p.category AS product2_category
    FROM cte1 AS t
    LEFT JOIN ProductInfo AS p
    ON t.product2_id = p.product_id
)

SELECT *,
    COUNT(*) AS customer_count
FROM cte2
GROUP BY product1_id, product2_id
HAVING count(*) >= 3
ORDER BY customer_count DESC, product1_id, product2_id

