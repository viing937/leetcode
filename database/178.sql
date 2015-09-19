SELECT
    Score,
    (SELECT COUNT(*) FROM (SELECT DISTINCT Score s FROM Scores) tmp WHERE s >= Score) Rank
FROM Scores
ORDER BY Score DESC
