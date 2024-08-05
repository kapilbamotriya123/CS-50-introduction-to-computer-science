-- Keep a log of any SQL queries you execute as you solve the mystery.

--I only know the time and place so I will check the crimescene reports of the same street on the same day
SELECT * FROM crime_scene_reports WHERE street = 'Humphrey Street' AND day = 28;
--Theft of the CS50 duck took place at 10:15am at the Humphrey Street bakery. Interviews were conducted today with three witnesses who were present at the time – each of their interview transcripts mentions the bakery.

--check in the interview what's the clue
SELECT * FROM  interviews WHERE interviews.day = 28;
--here there are three interview lets break them down
--1. Sometime within ten minutes of the theft, I saw the thief get into a car in the
--   bakery parking lot and drive away. If you have security footage from the bakery
--   parking lot, you might want to look for cars that left the parking lot in that time frame.

--2. earlier this morning theif was withdrawing some money from atm on Leggett Sreet

--3. As the thief was leaving the bakery, they called someone who talked to them for less than a minute. In the call,
--   I heard the thief say that they were planning to take the earliest flight out of Fiftyville tomorrow. The thief then
--   asked the person on the other end of the phone to purchase the flight ticket

--lets start to dig it down more one by one
--checking people with car's License plate within 10:15 - 10:30 or so
SELECT p1.name FROM people p1
    WHERE license_plate IN
        (SELECT license_plate FROM bakery_security_logs b
            WHERE b.day = 28
            AND b.hour = 10
            AND b.minute < 30
            AND b.minute > 15);

--checking out atm details
-- this give list of the all people who have been to atm Leggett Street on 28
SELECT p2.name FROM people p2
    WHERE id IN
        (SELECT person_id FROM bank_accounts
            WHERE account_number IN
                (SELECT account_number FROM atm_transactions a1
                    WHERE a1.day = 28
                    AND atm_location = 'Leggett Street'));

--checking out third inteview details
--finding the list of people who made calls on 28 and duration less than 60 secs
SELECT p3.name FROM people p3
    WHERE phone_number IN
        (SELECT phone_calls.caller FROM phone_calls
            WHERE day = 28
            AND duration < 60);

--now checking earliest flight details of earliest flight from fiftyville on 29 and then the passenger list in the same flight
SELECT p4.name FROM people p4 WHERE passport_number IN
    (SELECT passport_number FROM passengers
    WHERE flight_id =
        (SELECT id FROM flights
        WHERE flights.day = 29
        AND origin_airport_id =
            (SELECT id FROM airports
            WHERE city = 'Fiftyville')
            ORDER BY flights.hour
            LIMIT 1));

---FINDING THE COMMONG PERONS IN ALL
SELECT * FROM people p1
    WHERE license_plate IN
        (SELECT license_plate FROM bakery_security_logs b
            WHERE b.day = 28
            AND b.hour = 10
            AND b.minute < 30
            AND b.minute > 15)

    AND p1.name IN
        (SELECT p2.name FROM people p2
            WHERE id IN
                (SELECT person_id FROM bank_accounts
                    WHERE account_number IN
                        (SELECT account_number FROM atm_transactions a1
                            WHERE a1.day = 28
                            AND atm_location = 'Leggett Street'))
    AND p2.name IN
        (SELECT p3.name FROM people p3
            WHERE phone_number IN
                (SELECT phone_calls.caller FROM phone_calls
                    WHERE day = 28
                    AND duration < 60)
                    AND p3.name IN
                        (SELECT p4.name FROM people p4 WHERE passport_number IN
                            (SELECT passport_number FROM passengers
                            WHERE flight_id =
                                (SELECT id FROM flights
                                WHERE flights.day = 29
                                AND origin_airport_id =
                                    (SELECT id FROM airports
                                    WHERE city = 'Fiftyville')
                                    ORDER BY flights.hour
                                    LIMIT 1)))));

