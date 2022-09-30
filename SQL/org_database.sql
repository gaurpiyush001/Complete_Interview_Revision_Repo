CREATE DATABASE IF NOT EXISTS ORG;
SHOW DATABASES;
USE ORG; #switching to ORG Databases  

CREATE TABLE Worker (
	WORKER_ID INT NOT NULL PRIMARY KEY AUTO_INCREMENT,
    FIRST_NAME VARCHAR(25),
    LAST_NAME VARCHAR(25),
    SALARY INT(15),
    JOINING_DATE DATETIME,
    DEPARTMENT CHAR(25)
);


INSERT INTO Worker
	VALUES
    (001, 'Moknika', 'Arora', 100000, '14-02-20 09:00:00', 'HR'),
    (002, 'Niharika', 'Arora', 80000, '14-06-11 09:00:00', 'Admin'),
    (003, 'Vishal', 'Arora', 300000, '14-02-20 09:00:00', 'HR'),
    (004, 'Amitabh', 'Arora', 500000, '14-02-20 09:00:00', 'Admin'),
    (005, 'Vivek', 'Arora', 500000, '14-06-11 09:00:00', 'Admin'),
    (006, 'Vipul', 'Arora', 200000, '14-06-11 09:00:00', 'Account'),
    (007, 'Satish', 'Arora', 75000, '14-01-20 09:00:00', 'Account'),
    (008, 'Geetika', 'Arora', 90000, '14-04-11 09:00:00', 'Admin');

INSERT INTO WORKER VALUES (009, 'Piyush', 'Gaur', 10000, '14-04-11 09:00:00', 'DD');

SELECT * FROM Worker;

CREATE TABLE Bonus (
	WORKER_REF_ID INT, 
	BONUS_AMOUNT INT(10),
    BONUS_DATE DATETIME,
    FOREIGN KEY (WORKER_REF_ID)
		REFERENCES Worker(WORKER_ID)
		ON DELETE CASCADE
);

INSERT INTO Bonus (WORKER_REF_ID, BONUS_AMOUNT, BONUS_DATE) VALUES
	(001, 5000, '16-02-20'),
    (002, 3000, '16-06-11'),
    (003, 4000, '16-02-20'),
    (001, 4500, '16-02-20'),
    (002, 3500, '16-06-11');
    
SELECT * FROM Bonus;

CREATE TABLE Title (
	WORKER_REF_ID INT,
    WORKER_TITLE CHAR(25),
    AFFECTED_FROM DATETIME,
    FOREIGN KEY (WORKER_REF_ID) 
		REFERENCES Worker(WORKER_ID)
        ON DELETE CASCADE
);

INSERT INTO Title VALUES
	(001, 'Manager', '2016-02-20 00:00:00'),
    (002, 'Executive', '2016-06-11 00:00:00'),
    (008, 'Executive', '2016-06-11 00:00:00'),
    (005, 'Manager', '2016-06-11 00:00:00'),
    (004, 'Asst. Manager', '2016-06-11 00:00:00'),
    (007, 'Executive', '2016-06-11 00:00:00'),
    (006, 'Lead', '2016-06-11 00:00:00'),
    (003, 'Lead', '2016-06-11 00:00:00');
    
SELECT * FROM Title;

DROP TABLE title;

SELECT FIRST_NAME, SALARY FROM Worker; 

SELECT 44/11; # SQL humesha (Dummy) Table ke ander hi answer dega

SELECT now(); # If we want to know server's time 

# below commands tb use hoti jb mujhe SQL se hi kaam krana ho
SELECT lcase('PIYUSH');
SELECT ucase('piyush');

-- Reduce OR Conditions
SELECT * FROM Worker WHERE DEPARTMENT = 'HR' OR DEPARTMENT = 'ADMIN';
-- IN Keyword (Better way)
SELECT * FROM Worker WHERE DEPARTMENT IN ('HR', 'ADMIN');

-- NOT Logical Operator
SELECT * FROM Worker WHERE DEPARTMENT NOT IN ('HR', 'ADMIN');

-- SORTING
SELECT * FROM Worker ORDER BY SALARY; # default is Ascending(ASC)
# first sort the salary in descending order, If equal then descending dort by F_NAME
SELECT * FROM Worker ORDER BY SALARY DESC, FIRST_NAME DESC; 

-- DISTINCT
# Try to give DISTINCT DEPARTMENT in my Organisation
SELECT DISTINCT(DEPARTMENT) FROM Worker;
-- SELECT DISTINCT(DEPARTMENT),(SALARY) FROM Worker; # ye saarey columns dedega

-- GROUPING OF DATA
# find no. of employees working in different department
-- below command mein grouping huyi hi nhi because Aggregation function hi use nhi kiya
SELECT DEPARTMENT FROM Worker GROUP BY DEPARTMENT; # ye toh same DISTINCT Wala result aagya, So here SQL by default, If we are not aggregating then GROUP BY ko DISTINCT ki tarah treat krta hai 
-- below command mein rearange kr lega khud ko data, bcz aggregation function use huya hai 
SELECT count(DEPARTMENT), DEPARTMENT FROM Worker GROUP BY DEPARTMENT;
 
-- AVG Salary per Department
 select DEPARTMENT, AVG(SALARY) as AVG_SALARY from Worker GROUP BY DEPARTMENT;
 
 -- MIN salary dept
 select DEPARTMENT, MIN(SALARY) as MIN_SALARY from Worker GROUP BY DEPARTMENT;
 
 -- HAVING Keyword (Generally GROUP BY ke saath hi use hota haiu)
 SELECT count(DEPARTMENT), DEPARTMENT FROM Worker GROUP BY DEPARTMENT HAVING COUNT(DEPARTMENT) > 2;
 
 -- LECTURE 10 
 -- Q1. Write an SQL query to fecth "FIRST_NAME" from the worker table using alias name as <WORKER_NAME>
 SELECT FIRST_NAME AS WORKER_NAME FROM WORKER; 
 
-- Q-2. Write an SQL query to fetch “FIRST_NAME” from Worker table in upper case.
SELECT ucase(FIRST_NAME) FROM WORKER; -- mein table se reqiuired cheezey nikalkey post-processing krunga
 
-- Q-3. Write an SQL query to fetch unique values of DEPARTMENT from Worker table.
SELECT distinct DEPARTMENT FROM WORKER;

-- Q-4. Write an SQL query to print the first three characters of  FIRST_NAME from Worker table.
SELECT substring(FIRST_NAME, 1, 3) from WORKER; # IMPORTANT

-- Q-5. Write an SQL query to find the position of the alphabet (‘b’) in the first name column ‘Amitabh’ from Worker table.
SELECT instr(FIRST_NAME, 'b') from WORKER WHERE FIRST_NAME = 'Amitabh';

-- Q-6. Write an SQL query to print the FIRST_NAME from Worker table after removing white spaces from the right side.
SELECT rtrim(FIRST_NAME) from WORKER;

-- Q-7. Write an SQL query to print the DEPARTMENT from Worker table after removing white spaces from the left side
SELECT ltrim(FIRST_NAME) from WORKER;

-- Q-8. Write an SQL query that fetches the unique values of DEPARTMENT from Worker table and prints its length.
SELECT DISTINCT DEPARTMENT, length(DEPARTMENT) FROM WORKER;

-- Q-9. Write an SQL query to print the FIRST_NAME from Worker table after replacing ‘a’ with ‘A’.
SELECT replace(FIRST_NAME, 'a', 'A') FROM WORKER;

-- Q-10. Write an SQL query to print the FIRST_NAME and LAST_NAME from Worker table into a single column COMPLETE_NAME.
-- A space char should separate them.
SELECT concat(FIRST_NAME, ' ', LAST_NAME) as Full_Name from Worker;

-- Q-11. Write an SQL query to print all Worker details from the Worker table order by FIRST_NAME Ascending.
SELECT * FROM WORKER ORDER BY FIRST_NAME;

-- Q-12. Write an SQL query to print all Worker details from the Worker table order by 
-- FIRST_NAME Ascending and DEPARTMENT Descending.
SELECT * FROM WORKER ORDER BY FIRST_NAME, DEPARTMENT DESC;

-- Q-13. Write an SQL query to print details for Workers with the first name as “Vipul” and “Satish” from Worker table.
SELECT * FROM WORKER WHERE FIRST_NAME IN ('Vipul', 'Satish');

-- Q-14. Write an SQL query to print details of workers excluding first names, “Vipul” and “Satish” from Worker table.
SELECT * FROM WORKER WHERE FIRST_NAME NOT IN ('Vipul', 'Satish');

-- Q-15. Write an SQL query to print details of Workers with DEPARTMENT name as “Admin*”.
SELECT * FROM WORKER WHERE DEPARTMENT LIKE 'Admin%';

-- Q-16. Write an SQL query to print details of the Workers whose FIRST_NAME contains ‘a’.
SELECT * FROM WORKER WHERE FIRST_NAME LIKE '%a%';

-- Q-17. Write an SQL query to print details of the Workers whose FIRST_NAME ends with ‘a’.
SELECT * FROM WORKER WHERE FIRST_NAME LIKE '%a';

-- Q-18. Write an SQL query to print details of the Workers whose FIRST_NAME ends with ‘h’ and contains six alphabets.
SELECT * FROM WORKER WHERE FIRST_NAME LIKE '%h' AND length(FIRST_NAME) = 6;
SELECT * FROM WORKER WHERE FIRST_NAME LIKE '_____h';

-- Q-19. Write an SQL query to print details of the Workers whose SALARY lies between 100000 and 500000.
SELECT * FROM WORKER WHERE SALARY BETWEEN 100000 AND 500000;

-- Q-20. Write an SQL query to print details of the Workers who have joined in Feb’2014
SELECT * FROM WORKER WHERE year(JOINING_DATE) = 2014 AND month(JOINING_DATE) = 2;

-- Q-21. Write an SQL query to fetch the count of employees working in the department ‘Admin’.
SELECT count(WORKER_ID) FROM WORKER WHERE DEPARTMENT = 'Admin';

-- Q-22. Write an SQL query to fetch worker full names with salaries >= 50000 and <= 100000.
SELECT CONCAT(FIRST_NAME, ' ', LAST_NAME) AS FULL_NAME FROM WORKER WHERE SALARY BETWEEN 50000 AND 100000;

-- Q-23. Write an SQL query to fetch the no. of workers for each department in the descending order.
select COUNT(WORKER_ID), DEPARTMENT FROM WORKER GROUP BY DEPARTMENT ORDER BY COUNT(WORKER_ID) DESC;

-- Q-24. Write an SQL query to print details of the Workers who are also Managers.
SELECT w.* FROM WORKER AS w, TITLE AS t WHERE w.WORKER_ID=t.WORKER_REF_ID AND t.WORKER_TITLE = 'Manager';

-- Q-25. Write an SQL query to fetch number (more than 1) of same titles in the ORG of different types.
SELECT count(*), WORKER_TITLE FROM TITLE GROUP BY WORKER_TITLE HAVING COUNT(*) > 1;

-- Q-26. Write an SQL query to show only odd rows from a table.
SELECT * FROM WORKER WHERE mod(WORKER_ID,2) <> 0;

-- Q-27. Write an SQL query to show only even rows from a table. 
SELECT * FROM WORKER WHERE mod(WORKER_ID,2) = 0;

-- Q-28. Write an SQL query to clone a new table from another table.
-- IMPORTANT
CREATE TABLE WORKER_CLONE LIKE WORKER;
INSERT INTO WORKER_CLONE SELECT * FROM WORKER;
select * from WORKER_CLONE;
desc WORKER_CLONE;


-- Q-29. Write an SQL query to fetch intersecting records of two tables.


-- Q-30. Write an SQL query to show records from one table that another table does not have.
-- MINUS


-- Q-31. Write an SQL query to show the current date and time.
-- DUAL

-- Q-32. Write an SQL query to show the top n (say 5) records of a table order by descending salary.


-- Q-33. Write an SQL query to determine the nth (say n=5) highest salary from a table.


-- Q-34. Write an SQL query to determine the 5th highest salary without using LIMIT keyword.


 
-- Q-35. Write an SQL query to fetch the list of employees with the same salary.


-- Q-36. Write an SQL query to show the second highest salary from a table using sub-query.


-- Q-37. Write an SQL query to show one row twice in results from a table.


-- Q-38. Write an SQL query to list worker_id who does not get bonus.


-- Q-39. Write an SQL query to fetch the first 50% records from a table.


-- Q-40. Write an SQL query to fetch the departments that have less than 4 people in it.

