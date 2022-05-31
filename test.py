
SELECT stock, SUM(shares) FROM purchases WHERE user_id = 1 GROUP BY stock;
+-------+-------------+
| stock | SUM(shares) |
+-------+-------------+
| AMZN  | 1           |
| COX   | 5           |
| NFLX  | 4           |
+-------+-------------+
 transaction_id |   type   | stock |  price  | shares |        time         | user_id |
+----------------+----------+-------+---------+--------+---------------------+---------+
| 1              | purchase | NFLX  | 390.38  | 2      | 2022-05-31 08:18:01 | 1       |
| 2              | purchase | AMZN  | 2302.93 | 1      | 2022-05-31 08:35:06 | 1       |
| 3              | purchase | COX   | 69.54   | 2      | 2022-05-31 08:35:38 | 1       |
| 4              | purchase | COX   | 104.31  | 3      | 2022-05-31 08:35:57 | 1       |
+----------------+----------+-------+---------+--------+---------------------+---------+

CREATE TABLE users (id INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL, username TEXT NOT NULL, hash TEXT NOT NULL, cash NUMERIC NOT NULL DEFAULT 10000.00)
CREATE TABLE transactions (transaction_id INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL, type TEXT NOT NULL, stock TEXT NOT NULL, price FLOAT NOT NULL, shares INTEGER NOT NULL, time DATETIME, user_id);
CREATE TABLE purchases (id INTEGER PRIMARY KEY NOT NULL, stock TEXT NOT NULL, price FLOAT NOT NULL, shares INTEGER NOT NULL, time DATETIME);




