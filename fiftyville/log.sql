-- First query to see what tables are included:
.tables

-- Second query to take a look at the crime scene report table:
SELECT description
  FROM crime_scene_reports
 WHERE month = 7
   AND day = 28
   AND year = 2021
   AND street = "Humphrey Street";

-- Crime scene report mentions interview logs and bakery so the following queries were ran next:
.schema interviews

SELECT name, transcript
  FROM interviews
 WHERE month = 7 AND day = 28 AND year = 2021 AND transcript LIKE "%bakery%";

.schema bakery_security_logs

-- Thief is definitely one of these as was seen getting into car within this time frame, according to interview transcripts:
SELECT activity, license_plate, hour, minute
  FROM bakery_security_logs
 WHERE month = 7 AND day = 28 AND year = 2021 AND hour = 10 AND minute BETWEEN 15 AND 30;

-- Check when witness Eugene got to the bakery as he saw thief just before that by an ATM on Leggett Street:
.schema people

SELECT activity, hour, minute
  FROM bakery_security_logs
       JOIN people
         ON bakery_security_logs.license_plate = people.license_plate
 WHERE name = "Eugene";

-- Eugene entered at 8:53. Check what activity can be found around the ATM shortly before this time:
.schema atm_transactions

SELECT id, account_number, transaction_type, amount
  FROM atm_transactions
 WHERE month = 7 AND day = 28 AND year = 2021 AND atm_location = "Leggett Street";

/* No timestaps given in atm_transactions.
Look at bank_accounts table next to see if account numbers can be used to see who made withdraws that day
and check which one of those people also left the bakery within 10 minutes of the crime. */
.schema bank_accounts

SELECT name
  FROM people
       JOIN bank_accounts
         ON people.id = bank_accounts.person_id

       JOIN atm_transactions
         ON atm_transactions.account_number = bank_accounts.account_number
 WHERE month = 7 AND day = 28 AND year = 2021 AND atm_location = "Leggett Street" AND transaction_type = "withdraw"

INTERSECT

SELECT name
  FROM bakery_security_logs
       JOIN people
         ON bakery_security_logs.license_plate = people.license_plate
 WHERE month = 7 AND day = 28 AND year = 2021 AND activity = "exit" AND hour = 10 AND minute BETWEEN 15 AND 30;
 /* current list of suspects (those who withdrew money and left bakery within 10 minutes after crime):
    Bruce, Diana, Iman, Luca */

/* Check call logs to see who where on a call around the time the thief left the bakery, as witness Raymond
overheard a call that lasted less than a minute in which the thief planned to leave with the first flight the following day*/
.schema phone_calls

-- out of those who made a call of less than 60 seconds, check who also left the bakery within 10 min of crime AND withdrew money:
SELECT name
  FROM phone_calls
       JOIN people
         ON phone_calls.caller = people.phone_number
 WHERE month = 7 AND day = 28 AND year = 2021 AND duration < 60

INTERSECT

SELECT name
  FROM people
       JOIN bank_accounts
         ON people.id = bank_accounts.person_id

       JOIN atm_transactions
         ON atm_transactions.account_number = bank_accounts.account_number
 WHERE month = 7 AND day = 28 AND year = 2021 AND atm_location = "Leggett Street" AND transaction_type = "withdraw"

INTERSECT

SELECT name
  FROM bakery_security_logs
       JOIN people
         ON bakery_security_logs.license_plate = people.license_plate
 WHERE month = 7 AND day = 28 AND year = 2021 AND activity = "exit" AND hour = 10 AND minute BETWEEN 15 AND 30;
 -- this narrows the list of suspects down to two: Bruce, Diana


-- Check who the two suspects made their calls to:
SELECT name
  FROM phone_calls
       JOIN people
         ON phone_calls.receiver = people.phone_number
 WHERE month = 7 AND day = 28 AND year = 2021 AND duration < 60 AND caller
    IN (SELECT phone_number FROM people WHERE name = "Bruce" OR name = "Diana");
    /* Bruce called Robin and Diana called Philip
        |  name  |
        +--------+
        | Robin  |
        | Philip |
        +--------+ */

-- performed following queries to view flights, airports and passengers tables:
SELECT * FROM passengers; SELECT * FROM airports; SELECT * FROM flights;

-- check flights leaving from Fiftyville the following day, from earliest to latest
SELECT id, destination_airport_id, hour, minute
  FROM flights
 WHERE origin_airport_id =
       (SELECT id
          FROM airports
         WHERE city = "Fiftyville")
   AND month = 7 AND day = 29 AND year = 2021
 ORDER BY hour, minute;
 /* the earliest flight is at 08:20 with flight id 36 to New York City/LaGuardia Airport , which has airport id 4
 as per aiport table */

-- Check if either of the suspects are passengers on first flight:
  -- get Bruce's and Diana's passport numbers:
  SELECT name, passport_number FROM people WHERE name = "Bruce" OR name = "Diana";
/* +-------+-----------------+
  | name  | passport_number |
  +-------+-----------------+
  | Diana | 3592750733      |
  | Bruce | 5773159633      |
  +-------+-----------------+ */

-- Check which passport holder is on the first flight:
SELECT name
  FROM passengers
       JOIN people
         ON passengers.passport_number = people.passport_number
 WHERE flight_id = 36 AND passengers.passport_number
    IN (SELECT passport_number FROM people WHERE name = "Bruce" OR name = "Diana");
    -- only Bruce is on the flight so he is the thief. Since Robin was called by Bruce at the time of the crime, he is likely the accomplice.





