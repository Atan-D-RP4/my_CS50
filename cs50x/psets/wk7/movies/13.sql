SELECT DISTINCT(people.name) FROM people
JOIN stars s1 ON s1.person_id = people.id
JOIN movies ON s1.movie_id = movies.id
JOIN stars s2 ON movies.id = s2.movie_id
JOIN people p2 ON s2.person_id = p2.id AND p2.name = "Kevin Bacon" AND p2.birth = 1958
WHERE people.name != "Kevin Bacon";
