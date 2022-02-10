In 7.sql, write a SQL query to list all movies released in 2010 and their ratings, in descending order by rating.
For movies with the same rating, order them alphabetically by title.
Your query should output a table with two columns, one for the title of each movie and one for the rating of each movie.

/* This prints movie and its rating, by rating descending order:*/
SELECT title, rating FROM movies JOIN ratings ON id = movie_id ORDER BY rating DESC, title ASC;