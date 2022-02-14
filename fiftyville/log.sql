-- Keep a log of any SQL queries you execute as you solve the mystery.

-- First query to see what tables are included:
.tables

-- Second query to take a look at the crime scene report table:
SELECT description
  FROM crime_scene_reports
 WHERE month = 7
   AND day = 28
   AND street = "Humphrey Street";

-- List of suspects