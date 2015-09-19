SELECT DISTINCT Num FROM (
    SELECT
        Num,
        CASE
            WHEN @prevNum = Num THEN @count := @count+1
            WHEN (@prevNum := Num) IS NOT NULL THEN @count := 1
        END n
    FROM Logs, (SELECT @prevNum := NULL) r, (SELECT @count :=1) c
) a WHERE n >= 3
