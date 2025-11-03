-- # Write your MySQL query statement below
-- WITH cte AS (SELECT
--     product_name,
--     store_id,
--     MAX(price) AS maximum_price,
--     MIN(price) AS minimum_price
-- FROM inventory
-- GROUP BY store_id),

-- cte2 AS(SELECT
--     c.product_name,
--     c.store_id,
--     c.maximum_price,
--     c.minimum_price,
--     SUM(CASE WHEN i.price = c.maximum_price THEN quantity ELSE 0 END) AS most_expensive,
--     SUM(CASE WHEN i.price = c.minimum_price THEN quantity ELSE 0 END) AS most_cheapest
-- FROM cte c
-- JOIN inventory i 
-- ON c.store_id = i.store_id
-- GROUP BY i.store_id, c.maximum_price,c.minimum_price),

-- cte3 AS(
-- SELECT
--     c2.store_id,
--     c2.maximum_price,
--     c2.minimum_price,
--     ROUND((c3.most_cheapest / c2.most_expensive), 2) AS imbalance_ratio
-- FROM cte2 c2
-- JOIN cte2 c3
-- ON c2.most_expensive < c3.most_cheapest
-- )

-- SELECT
--     CASE WHEN i.price = c3.maximum_price THEN i.product_name END AS most_exp_product,
--     CASE WHEN i.price = c3.minimum_price THEN i.product_name END AS cheapest_product
-- FROM cte3 c3
-- JOIN inventory i
-- ON i.store_id = c3.store_id

WITH cte AS(SELECT *,
    ROW_NUMBER() OVER(PARTITION BY store_id ORDER BY price DESC) AS exp_rnk,
    ROW_NUMBER() OVER(PARTITION BY store_id ORDER BY price) AS chp_rnk
FROM inventory),

cte2 AS(
SELECT
    store_id,
    MAX(CASE WHEN exp_rnk = 1 THEN product_name ELSE null END) AS most_exp_product,
    MAX(CASE WHEN chp_rnk = 1 THEN product_name ELSE null END) AS cheapest_product,
    SUM(CASE WHEN exp_rnk = 1 THEN quantity ELSE 0 END) AS exp_qty,
    SUM(CASE WHEN chp_rnk = 1 THEN quantity ELSE 0 END) AS chp_qty,
    ROUND(SUM(CASE WHEN chp_rnk = 1 THEN quantity ELSE 0 END) / SUM(CASE WHEN exp_rnk = 1 THEN quantity ELSE 0 END), 2) AS imbalance_ratio
FROM cte
GROUP BY store_id
HAVING COUNT(DISTINCT product_name) >= 3
)

SELECT
     s.*,
     cte2.most_exp_product,
     cte2.cheapest_product,
     cte2.imbalance_ratio
FROM cte2 
LEFT JOIN stores s
ON cte2.store_id = s.store_id
WHERE exp_qty < chp_qty
ORDER BY cte2.imbalance_ratio DESC, s.store_name