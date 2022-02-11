In 11.sql, write a SQL query to list the titles of the five highest rated movies (in order) that Chadwick Boseman starred in, starting
with the highest rated.

    Your query should output a table with a single column for the title of each movie.
    You may assume that there is only one person in the database with the name Chadwick Boseman.

SELECT title FROM movies JOIN stars ON id = stars.movie_id JOIN ratings ON 
WHERE person_id = (SELECT id FROM people WHERE name = 'Chadwick Boseman')
ORDER BY rating DESC LIMIT 5;


|          title           |
+--------------------------+
| 42                       |
| Ma Rainey's Black Bottom |
| Message from the King    |
| The Kill Hole            |
| Black Panther            |
| Draft Day                |
| Gods of Egypt            |
| Get on Up                |
| Marshall                 |
| 21 Bridges               |
+--------------------------+