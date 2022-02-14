In 12.sql, write a SQL query to list the titles of all movies in which both Johnny Depp and Helena Bonham Carter starred.
    Your query should output a table with a single column for the title of each movie.
    You may assume that there is only one person in the database with the name Johnny Depp.
    You may assume that there is only one person in the database with the name Helena Bonham Carter.


SELECT title FROM movies
JOIN stars ON movies.id = stars.movie_id JOIN people ON stars.person_id = people.id
WHERE person_id = ALL (SELECT id FROM people WHERE name IN ("Johnny Depp", "Helena Bonham Carter"));

SELECT title FROM movies
JOIN stars ON movies.id = stars.movie_id JOIN people ON stars.person_id = people.id
WHERE person_id IN ((SELECT id FROM people WHERE name = "Johnny Depp")
AND person_id IN (SELECT id FROM people WHERE name = "Helena Bonham Carter"));

SELECT title FROM people
JOIN stars ON people.id = stars.person_id
JOIN movies ON stars.movie_id = movies.id
WHERE name = "Johnny Depp" AND name = "Helena Bonham Carter";

SELECT title FROM movies
JOIN stars ON movies.id = stars.movie_id JOIN people ON stars.person_id = people.id
WHERE EXISTS ((SELECT id FROM people WHERE name = "Johnny Depp") AND (SELECT id FROM people WHERE name = "Helena Bonham Carter"));