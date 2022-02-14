/*SELECT DISTINCT name FROM people JOIN directors ON people.id = directors.person_id JOIN ratings ON directors.movie_id = ratings.movie_id
WHERE directors.movie_id IN (SELECT movie_id FROM ratings WHERE rating >= 9.0);*/

SELECT DISTINCT name FROM people JOIN directors ON people.id = directors.person_id JOIN ratings ON directors.movie_id = ratings.movie_id
WHERE rating >= 9.0;