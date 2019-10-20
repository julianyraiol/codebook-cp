/* Query a count of the number of cities in CITY having a Population larger than 100000.*/
SELECT COUNT(ID) FROM CITY WHERE POPULATION > 100000

/* Query the total population of all cities in CITY where District is California.*/
SELECT SUM(POPULATION) FROM CITY WHERE DISTRICT = 'California'

/* Consider  and  to be two points on a 2D plane.

 happens to equal the minimum value in Northern Latitude (LAT_N in STATION).
 happens to equal the minimum value in Western Longitude (LONG_W in STATION).
 happens to equal the maximum value in Northern Latitude (LAT_N in STATION).
 happens to equal the maximum value in Western Longitude (LONG_W in STATION).
Query the Manhattan Distance between points  and  and round it to a scale of  decimal place*/

SELECT FORMAT(ABS(MIN(LAT_N) - MAX(LAT_N)) + ABS(MIN(LONG_W) - MAX(LONG_W)), 4)
FROM STATION