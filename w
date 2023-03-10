CREATE OR REPLACE PROCEDURE insertCustomer(
 f_n varchar,
 l_n varchar,
 address_ varchar,
 email  varchar
)
LANGUAGE plpgsql AS $$
BEGIN 
 INSERT INTO customer(
  first_name,
  last_name,
  address,
  email
 )values(
  f_n,
  l_n,
  address_,
  email
 );
 COMMIT;
END; $$

SELECT *
FROM customer;

CALL insertCustomer('Joe', 'smith','200 main st Oakland CA', 'jsmith@gmail.com')
CALL insertCustomer('luam', 'able','5567 broad st colmbus ,oh', 'ableluam@gmail.com')

CREATE OR REPLACE PROCEDURE insertCar(
 make varchar,
 model varchar,
 color varchar,
 year_  varchar,
 used varchar
 
)
LANGUAGE plpgsql AS $$
BEGIN 
 INSERT INTO car(
  make,
  model ,
  color,
  year_,
  used
 )values(
   make,
  model ,
  color,
  year_,
  used
 );
 COMMIT;
END; $$

SELECT *
FROM car;

CALL insertcar('Nissan', 'Rouge', 'gray', '2012','used')