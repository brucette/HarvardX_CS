In 8.sql, write a SQL query to list the names of all people who starred in Toy Story.

    Your query should output a table with a single column for the name of each person.
    You may assume that there is only one movie in the database with the title Toy Story.

/* gets name of star                                          gives Toy STory's ID */
SELECT name FROM people JOIN stars, movies ON people.id = stars.person_id WHERE movies.id = (SELECT id FROM movies WHERE title = "Toy Story");
