SELECT ROUND(AVG(rating) - 0.005, 2) 
FROM ratings 
WHERE (
    SELECT id 
    FROM movies 
    WHERE year = 2012
);