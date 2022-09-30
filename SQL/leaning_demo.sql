#In sql, we should write Keyword in CAPS as a norm
CREATE DATABASE temp; #creating database

#create table with specifying database
USE temp;

CREATE TABLE student (
	id INT PRIMARY KEY,
    name VARCHAR(255)
);

INSERT INTO student VALUES(1, 'Piyush');
INSERT INTO student VALUES(2, 'Gaur');
INSERT INTO student VALUES(3, 'gaurav');

TRUNCATE TABLE student;

SHOW TABLES;

select * FROM student;

DROP DATABASE IF EXISTS temp;-- 