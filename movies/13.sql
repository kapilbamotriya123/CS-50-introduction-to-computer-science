SELECT DISTINCT(p2.name)

FROM people p1
JOIN stars s1 ON p1.id = s1.person_id
JOIN movies m ON s1.movie_id = m.id
JOIN stars s2 ON m.id = s2.movie_id
JOIN people p2 ON s2.person_id = p2.id

WHERE p1.name = 'Kevin Bacon' AND p2.name != 'Kevin Bacon';

