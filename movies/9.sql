/*SELECT COUNT(DISTINCT name) FROM people JOIN stars ON people.id = stars.person_id JOIN movies ON stars.movie_id = movies.id
WHERE stars.movie_id IN (SELECT id FROM movies where year = 2004) ORDER BY birth;*/

SELECT DISTINCT name FROM people JOIN stars ON people.id = stars.person_id JOIN movies ON stars.movie_id = movies.id
WHERE year = 2004 ORDER BY birth;