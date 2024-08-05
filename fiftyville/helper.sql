--for those who entered before 1015 and not exited






























SELECT b1.*
FROM bakery_security_logs b1
LEFT JOIN bakery_security_logs b2
ON b1.license_plate = b2.license_plate
AND b2.activity = 'exit'
AND b2.id < 260
WHERE b1.id < 260
AND b1.activity = 'entrance'
AND b2.license_plate IS NULL;

--this is name of all the people who were in the bakery at the time of accident

SELECT * FROM people
WHERE license_plate in

(SELECT b1.license_plate
FROM bakery_security_logs b1
LEFT JOIN bakery_security_logs b2
ON b1.license_plate = b2.license_plate
AND b2.activity = 'exit'
AND b2.id < 260
WHERE b1.id < 260
AND b1.activity = 'entrance'
AND b2.license_plate IS NULL);
