SELECT
    t.request_at AS Day,
    ROUND(
        SUM(CASE WHEN t.status LIKE 'cancelled%' THEN 1 ELSE 0 END) / COUNT(*),
        2
    ) AS `Cancellation Rate`
FROM Trips AS t
JOIN Users AS uc
  ON uc.users_id = t.client_id
 AND uc.banned = 'No'
JOIN Users AS ud
  ON ud.users_id = t.driver_id
 AND ud.banned = 'No'
WHERE t.request_at BETWEEN '2013-10-01' AND '2013-10-03'
GROUP BY t.request_at;