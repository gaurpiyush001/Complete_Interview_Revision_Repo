USE TEMP;

CREATE TABLE Customer (
	id INT PRIMARY KEY, # PRIMARY KEY constarint hai toh iska mtlb YE IMPLICIT hai ki id attribute can't be NULL
    cname varchar(255),
    Address varchar(255),
    Gender char(2),
    City varchar(225),
    Pincode integer
);

INSERT INTO Customer VALUES
	(1251, 'Ram Kumar', 'Dilbagh Nagar', 'M', 'Jalandhar', 14402),
    (1300, 'Shayam Singh', 'Lughiana Nagar', 'M', 'Ludhiana', 14402),
    (245, 'Neelabh Shukla', 'Ashok Nagar', 'M', 'Jalandhar', 14402),
    (210, 'Barkha Singh', 'Dilbagh Nagar', 'M', 'Jalandhar', 14402),
    (500, 'Rohan Arora', 'Ludhiana Nagar', 'M', 'Ludhiana', 14402);
    
CREATE TABLE Order_details (
	Order_id integer PRIMARY KEY,
    delivery_date DATE,
    cust_id INT,
    FOREIGN KEY(cust_id) REFERENCES Customer(id) 
);

ALTER TABLE Order_details ADD CONSTRAINT PRIMARY KEY(Order_id);

INSERT INTO Order_details VALUES (1, '2019-03-11', 245);

CREATE TABLE Account (
id int PRIMARY KEY,
name varchar(255) UNIQUE, # UNIQUE Constraint
balance INT,
CONSTRAINT acc_balance_chk CHECK(balance > 1000) # check contraint
);

INSERT INTO Account
	(ID, name, balance) VALUES
    (1, 'A', 10000);
    
select * from Account;
    
INSERT INTO Account
	(ID, name, balance) VALUES
    (2, 'A', 10000);
    
INSERT INTO Account
	(ID, name, balance) VALUES
    (2, 'B', 100);

-- DEFAULT CONSTRAINT
 DROP TABLE Account;
 
 CREATE TABLE Account (
	id int PRIMARY KEY,
	name varchar(255) UNIQUE, # UNIQUE Constraint
	balance INT NOT NULL DEFAULT(0), #default CONSTRAINT, but the default value won't guard your table against explicit NULL's
    -- have good habit of specifying NOT null CONTRAINT
	CONSTRAINT acc_balance_chk CHECK(balance > 1000) # check contraint
 );
 
 INSERT INTO Account (id, name, balance) values (1, 'A', 10000);

