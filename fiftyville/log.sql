-- Keep a log of any SQL queries you execute as you solve the mystery.
-- First query to see what tables are included:
.tables

-- Second query to take a look at the crime scene report table:
SELECT description
  FROM crime_scene_reports
 WHERE month = 7
   AND day = 28
   AND year = 2021
   AND street = "Humphrey Street";
    /*Theft of the CS50 duck took place at 10:15am at the Humphrey Street bakery.
    Interviews were conducted today with three witnesses who were present at the time –
    each of their interview transcripts mentions the bakery.
    Littering took place at 16:36. No known witnesses.*/

-- Crime scene report mentions interview logs and bakery so the following queries were ran next:
  .schema interviews
  -- to get interview logs:
  SELECT name, transcript
    FROM interviews
  WHERE month = 7 AND day = 28 AND year = 2021 AND transcript LIKE "%bakery%";

/*
|Raymond| As the thief was leaving the bakery, they called someone who talked to them for less than a minute. In the call, I heard the
thief say that they were planning to take the earliest flight out of Fiftyville tomorrow. The thief then asked the person on the other
end of the phone to purchase the flight ticket. |
|Emma| I'm the bakery owner, and someone came in, suspiciously whispering into a phone for about half an hour. They never bought anything.*/
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
  and check which one of those people also left the bakery within 10 minutes of the crime */
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

  -- Current list of suspects (those who withdrew money and left bakery within 10 minutes after crime):
  Bruce
  Diana
  Iman
  Luca

/* Check call, flight and passenger logs to see who where on a call around the time the thief left the bakery, as witness
Raymond overheard a call that lasted less than a minute in which the thief planned to leave with the first
flight the following day*/
.schema phone_calls
.schema airports
.schema flights
.schema passengers

  -- check who made a call of less than 60 s:
  SELECT name
    FROM phone_calls
         JOIN people
           ON phone_calls.caller = people.phone_number
   WHERE month = 7 AND day = 28 AND year = 2021 AND duration < 60;

  -- check who received a call of less than 60 s:
  SELECT name
    FROM phone_calls
         JOIN people
           ON phone_calls.receiver = people.phone_number
   WHERE month = 7 AND day = 28 AND year = 2021 AND duration < 60;
      -- gives list of possible accomplices:
        Jack       |
      | Larry      |
      | Robin      |
      | Melissa    |
      | James      |
      | Philip     |
      | Jacqueline |
      | Doris      |
      | Anna

  -- out of those who made a call, check who is also on the list of people leaving the bakery within 10 min of crime AND having withdrawn money:
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

airports              crime_scene_reports   people
atm_transactions      flights               phone_calls
bakery_security_logs  interviews
bank_accounts         passengers