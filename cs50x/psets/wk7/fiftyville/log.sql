-- Keep a log of any SQL queries you execute as you solve the mystery.

.schema
CREATE TABLE crime_scene_reports (
    id INTEGER,
    year INTEGER,
    month INTEGER,
    day INTEGER,
    street TEXT,
    description TEXT,
    PRIMARY KEY(id)
);
CREATE TABLE interviews (
    id INTEGER,
    name TEXT,
    year INTEGER,
    month INTEGER,
    day INTEGER,
    transcript TEXT,
    PRIMARY KEY(id)
);
CREATE TABLE atm_transactions (
    id INTEGER,
    account_number INTEGER,
    year INTEGER,
    month INTEGER,
    day INTEGER,
    atm_location TEXT,
    transaction_type TEXT,
    amount INTEGER,
    PRIMARY KEY(id)
);
CREATE TABLE bank_accounts (
    account_number INTEGER,
    person_id INTEGER,
    creation_year INTEGER,
    FOREIGN KEY(person_id) REFERENCES people(id)
);
CREATE TABLE airports (
    id INTEGER,
    abbreviation TEXT,
    full_name TEXT,
    city TEXT,
    PRIMARY KEY(id)
);
CREATE TABLE flights (
    id INTEGER,
    origin_airport_id INTEGER,
    destination_airport_id INTEGER,
    year INTEGER,
    month INTEGER,
    day INTEGER,
    hour INTEGER,
    minute INTEGER,
    PRIMARY KEY(id),
    FOREIGN KEY(origin_airport_id) REFERENCES airports(id),
    FOREIGN KEY(destination_airport_id) REFERENCES airports(id)
);
CREATE TABLE passengers (
    flight_id INTEGER,
    passport_number INTEGER,
    seat TEXT,
    FOREIGN KEY(flight_id) REFERENCES flights(id)
);
CREATE TABLE phone_calls (
    id INTEGER,
    caller TEXT,
    receiver TEXT,
    year INTEGER,
    month INTEGER,
    day INTEGER,
    duration INTEGER,
    PRIMARY KEY(id)
);
CREATE TABLE people (
    id INTEGER,
    name TEXT,
    phone_number TEXT,
    passport_number INTEGER,
    license_plate TEXT,
    PRIMARY KEY(id)
);
CREATE TABLE bakery_security_logs (
    id INTEGER,
    year INTEGER,
    month INTEGER,
    day INTEGER,
    hour INTEGER,
    minute INTEGER,
    activity TEXT,
    license_plate TEXT,
    PRIMARY KEY(id)
);
-- Found this overwhelming

SELECT *
FROM crime_scene_reports
    WHERE year = 2021
        AND month = 7
        AND street LIKE "%Humphrey Street%";
-- To get the crimes known details
-- The Theft occured at 10:15am at Humphrey Street Bakery
-- Three of the witnesses that were present were interviewed

SELECT name, transcript
FROM interviews
    WHERE year = 2021
        AND month = 7
        AND day = 28;
-- The Crime scene reports mentions witnesses so I looked up their interview transcripts
/*
1.) Ruth says he saw the thief get into a car and drive away within 10 minutes of the theft.
    Look at the bakery's security footage for this

2.) Eugenes says he recognized the thief because he saw them withdrawing money from an ATM on Leggett Street
    Check out the ATM's transaction log

3.) Raymond saw the thief talking with someone for less than a minute. He heard the thief say that he would be
taking the earliest flight out of Fiftyville tomorrow. Then the thief asked the other caller to purchase that
flight ticket
    Investigate the flights on the day after the theft and the phone_calls made within some time of the theft
*/

SELECT
    people.name, bakery_security_logs.license_plate
FROM
    bakery_security_logs
JOIN
    people ON bakery_security_logs.license_plate = people.license_plate
    WHERE year = 2021
        AND month = 7
        AND day = 28
        AND hour = 10
        AND activity = "exit"
        ORDER BY people.name;
/* License Plate Numbers of cars that exited the bakery within ten minutes of
    the theft
    Query late modified to show the owners of those License Plate Numbers
+---------+---------------+
|  name   | license_plate |
+---------+---------------+
| Vanessa | 5P2BI95       |
| Bruce   | 94KL13X       |
| Barry   | 6P58WS2       |
| Luca    | 4328GD8       |
| Sofia   | G412CB7       |
| Iman    | L93JTIZ       |
| Diana   | 322W7JE       |
| Kelsey  | 0NTHK55       |
| Taylor  | 1106N58       |
+---------+---------------+
*/

SELECT
    people.name, atm_transactions.account_number, atm_transactions.amount
FROM
    atm_transactions
JOIN
    bank_accounts ON atm_transactions.account_number = bank_accounts.account_number
JOIN
    people ON bank_accounts.person_id = people.id
    WHERE year = 2021
        AND day = 28
        AND month = 7
        AND transaction_type = "withdraw"
        AND atm_location = "Leggett Street"
        ORDER BY people.name;
/* Withdrawals at the Leggett Street ATM on the day of the theft
+---------+----------------+--------+
|  name   | account_number | amount |
+---------+----------------+--------+
| Kenny   | 28296815       | 20     |
| Iman    | 25506511       | 20     |
| Benista | 81061156       | 30     |
| Diana   | 26013199       | 35     |
| Luca    | 28500762       | 48     |
| Bruce   | 49610011       | 50     |
| Taylor  | 76054385       | 60     |
| Brooke  | 16153065       | 80     |
+---------+----------------+--------+
*/

SELECT
    p1.name, caller, p2.name, receiver
FROM
    phone_calls
JOIN
    people p1 ON phone_calls.caller = p1.phone_number
JOIN
    people p2 ON phone_calls.receiver = p2.phone_number
    WHERE
        year = 2021
        AND month = 7
        AND day = 28
        AND duration <= 60
        ORDER BY p1.name;
/* Calls shorter than a minute on the day of the theft
+---------+----------------+------------+----------------+
|  name   |     caller     |    name    |    receiver    |
+---------+----------------+------------+----------------+
| Benista | (338) 555-6650 | Anna       | (704) 555-2131 |
| Bruce   | (367) 555-5533 | Robin      | (375) 555-8161 |
| Carina  | (031) 555-6622 | Jacqueline | (910) 555-3251 |
| Diana   | (770) 555-1861 | Philip     | (725) 555-3243 |
| Kathryn | (609) 555-5876 | Luca       | (389) 555-5198 |
| Kelsey  | (499) 555-9472 | Larry      | (892) 555-8872 |
| Kelsey  | (499) 555-9472 | Melissa    | (717) 555-1342 |
| Kenny   | (826) 555-1652 | Doris      | (066) 555-9701 |
| Sofia   | (130) 555-0289 | Jack       | (996) 555-8899 |
| Taylor  | (286) 555-6063 | James      | (676) 555-6554 |
+---------+----------------+------------+----------------+
*/

SELECT *
FROM airports
    WHERE city = "Fiftyville";
-- To get the name and ID of Fiftyville's airport

SELECT
    f.id, f.month, f.day, f.hour, f.minute, a2.city, a2.full_name as arriving, a2.abbreviation
FROM
    flights AS f
JOIN
    airports a1 ON f.origin_airport_id = a1.id
JOIN
    airports a2 ON f.destination_airport_id = a2.id
WHERE
    origin_airport_id = 8
    AND year = 2021
    AND month = 7
    AND (day = 29 OR day = 28)
ORDER BY f.hour, f.minute;
-- To get details of Flights out of Fiftyville the day after the theft
/*
+-------+-----+------+--------+---------------+-----------------------------------------+--------------+
| month | day | hour | minute |     city      |                arriving                 | abbreviation |
+-------+-----+------+--------+---------------+-----------------------------------------+--------------+
| 7     | 29  | 8    | 20     | New York City | LaGuardia Airport                       | LGA          |
| 7     | 29  | 9    | 30     | Chicago       | O'Hare International Airport            | ORD          |
| 7     | 29  | 12   | 15     | San Francisco | San Francisco International Airport     | SFO          |
| 7     | 28  | 13   | 49     | Dallas        | Dallas/Fort Worth International Airport | DFS          |
| 7     | 29  | 15   | 20     | Tokyo         | Tokyo International Airport             | HND          |
| 7     | 29  | 16   | 0      | Boston        | Logan International Airport             | BOS          |
| 7     | 28  | 16   | 16     | New York City | LaGuardia Airport                       | LGA          |
| 7     | 28  | 17   | 20     | Dallas        | Dallas/Fort Worth International Airport | DFS          |
| 7     | 28  | 17   | 50     | Dubai         | Dubai International Airport             | DXB          |
| 7     | 28  | 20   | 16     | New York City | LaGuardia Airport                       | LGA          |
+-------+-----+------+--------+---------------+-----------------------------------------+--------------+

First flight out of Fiftyville is to the LaGuardia Airport in New York City

*/

SELECT *
FROM
    people
JOIN
     bank_accounts ON people.id = bank_accounts.person_id;
-- I ran this Query but I didn't know how to cross-reference it with the data I already Isolated
-- So I backtracked to the other Queries from this point

SELECT
    p.name
FROM
    bakery_security_logs
JOIN
    people AS p ON bakery_security_logs.license_plate = p.license_plate
JOIN
    bank_accounts ON p.id = bank_accounts.person_id
JOIN
    atm_transactions ON bank_accounts.account_number = atm_transactions.account_number
JOIN
    phone_calls ON p.phone_number = phone_calls.caller
WHERE
    bakery_security_logs.year = 2021
        AND bakery_security_logs.month = 7
        AND bakery_security_logs.day = 28
        AND bakery_security_logs.hour = 10
        AND bakery_security_logs.minute BETWEEN 15 AND 25
        AND atm_transactions.atm_location = "Leggett Street"
        AND atm_transactions.transaction_type =  "withdraw"
        AND atm_transactions.year = 2021
        AND atm_transactions.month = 7
        AND atm_transactions.day = 28
        AND phone_calls.year = 2021
        AND phone_calls.month = 7
        AND phone_calls.day = 28
        AND phone_calls.duration <= 60;
-- Attempt to consolidate all the data
-- Took some correcting but I got it to work
/*
+-------+
| name  |       My main Suspects
+-------+
| Bruce |
| Diana |
+-------+
*/

SELECT
    p.name, ps.passport_number, ps.seat
FROM
    passengers AS ps
JOIN
    people AS p ON ps.passport_number = p.passport_number
WHERE
    flight_id = 36;
-- Check the passengers of the Flight to New York
/*
+--------+-----------------+
|  name  | passport_number |
+--------+-----------------+
| Doris  | 7214083635      |
| Sofia  | 1695452385      |
| Bruce  | 5773159633      |    One of the Suspects for the Theft
| Edward | 1540955065      |
| Kelsey | 8294398571      |
| Taylor | 1988161715      |
| Kenny  | 9878712108      |
| Luca   | 8496433585      |
+--------+-----------------+

Therefore, Bruce is the Thief

*/

