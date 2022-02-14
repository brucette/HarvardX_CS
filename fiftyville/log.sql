-- Keep a log of any SQL queries you execute as you solve the mystery.
-- First query to see what tables are included:
.tables

airports              crime_scene_reports   people
atm_transactions      flights               phone_calls
bakery_security_logs  interviews
bank_accounts         passengers

-- Second query to take a look at the crime scene report table:
SELECT description
  FROM crime_scene_reports
 WHERE month = 7
   AND day = 28
   AND street = "Humphrey Street";
    /*Theft of the CS50 duck took place at 10:15am at the Humphrey Street bakery.
    Interviews were conducted today with three witnesses who were present at the time –
    each of their interview transcripts mentions the bakery.
    Littering took place at 16:36. No known witnesses.*/

-- Crime scene report mentions interview logs and bakery so the following queries were ran next:
.schema interviews
SELECT name, transcript
  FROM interviews
 WHERE month = 7 AND day = 28 AND transcript LIKE "%bakery%";

/*
|Ruth| Sometime within ten minutes of the theft, I saw the thief get into a car in the bakery parking lot and drive away.
If you have security footage from the bakery parking lot, you might want to look for cars that left the parking lot in that time frame.
                                                         |
|Eugene| I don't know the thief's name, but it was someone I recognized. Earlier this morning, before I arrived at Emma's bakery,
I was walking by the ATM on Leggett Street and saw the thief there withdrawing some money.
                                                                                      |
|Raymond| As the thief was leaving the bakery, they called someone who talked to them for less than a minute. In the call, I heard the
thief say that they were planning to take the earliest flight out of Fiftyville tomorrow. The thief then asked the person on the other
end of the phone to purchase the flight ticket. |

|Emma| I'm the bakery owner, and someone came in, suspiciously whispering into a phone for about half an hour. They never bought anything.*/
.schema bakery_security_logs
/*bakery_security_logs (
    id INTEGER,
    year INTEGER,
    month INTEGER,
    day INTEGER,
    hour INTEGER,
    minute INTEGER,
    activity TEXT,
    license_plate TEXT,
    PRIMARY KEY(id)
);*/
SELECT activity, license_plate
  FROM bakery_security_logs
 WHERE month = 7 AND day = 28 AND hour = 10;
-- List of suspects