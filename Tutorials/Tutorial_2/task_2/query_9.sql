USE PHARMA_DB_TASK2;

WITH boundaries AS (
    SELECT clinical_trial_start_date AS dt FROM CLINICAL_TRIAL
    UNION
    SELECT clinical_trial_completion_date AS dt FROM CLINICAL_TRIAL
),
ordered_boundaries AS (
    SELECT
        dt AS period_start,
        LEAD(dt) OVER (ORDER BY dt) AS period_end
    FROM boundaries
),
active_trials AS (
    SELECT
        ob.period_start,
        ob.period_end,
        c.clinical_trial_title
    FROM ordered_boundaries ob
    JOIN CLINICAL_TRIAL c
      ON ob.period_end IS NOT NULL
     AND c.clinical_trial_start_date <= ob.period_start
     AND c.clinical_trial_completion_date >= ob.period_end
),
period_counts AS (
    SELECT
        period_start,
        period_end,
        COUNT(DISTINCT clinical_trial_title) AS active_trial_count
    FROM active_trials
    GROUP BY period_start, period_end
),
max_count AS (
    SELECT MAX(active_trial_count) AS mx
    FROM period_counts
)
SELECT
    pc.period_start,
    pc.period_end,
    pc.active_trial_count,
    GROUP_CONCAT(DISTINCT s.drug_name ORDER BY s.drug_name SEPARATOR ', ') AS studied_drugs
FROM period_counts pc
JOIN max_count mc
  ON pc.active_trial_count = mc.mx
JOIN active_trials a
  ON a.period_start = pc.period_start
 AND a.period_end = pc.period_end
JOIN STUDIES s
  ON s.clinical_trial_title = a.clinical_trial_title
GROUP BY pc.period_start, pc.period_end, pc.active_trial_count
ORDER BY pc.period_start;