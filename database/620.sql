SELECT id, movie, description, rating
FROM cinema c
WHERE c.id%2=1 AND c.description NOT LIKE '%boring%'
ORDER BY c.rating DESC;
