SELECT m1.title
FROM movies m1
JOIN movies m2
ON m1.id = m2.id WHERE m1.id IN (SELECT movie_id FROM stars WHERE person_id IN (SELECT id FROM people WHERE people.name = 'Bradley Cooper')) AND m2.id IN (SELECT movie_id FROM stars WHERE person_id IN (SELECT id FROM people WHERE people.name = 'Jennifer Lawrence'));

