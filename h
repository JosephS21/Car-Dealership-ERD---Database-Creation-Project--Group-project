DROP TABLE IF EXISTS customer;
CREATE TABLE customer(
  customer_id SERIAL PRIMARY KEY,
  first_name varchar(55),
  last_name varchar(55),
  address varchar(255),
  email  varchar(255) 
);
INSERT INTO customer(
   first_name,
   last_name,
   address,
   email
 )VALUES(
   'Sam',
   'Smith',
   '2345 main st Dayton ohio',
   'samsmith@gmail.com'
   ),(
    'Jhon',
    'Albert',
    '4545 south blvd Colmbus ohio',
    'jhon2424@gmail.com'
   ),(
    'Bob',
    'Evens',
    '5656 broad dr Akron ohio',
    'evensbob@yahoo.com'
   ),(
     'Robet',
     'Good',
     '6677 heritage st uniontown ohio',
     'good@gmail.com '
   );
SELECT *
FROM customer;
DROP TABLE IF EXISTS car;
CREATE TABLE car(
  car_id SERIAL PRIMARY KEY,
  make varchar(55),
  model varchar(55),
  color varchar(55),
  year_ varchar(55),
  used varchar(55)
 );
INSERT INTO car(
    make,
    model,
    color,
    year_,
    used
)VALUES(
    
    'Honda',
    'CRV',
    'Red',
    '2018',
    'used'
),(
    
    'Toyota',
    'camery',
    'White',
    '2023',
    'new'

),(
    
    'Jeep',
    'wagoneer',
    'Black',
    '2022',
    'used'
    
),(
    
    'Tesla',
    'Modle X',
    'Blue',
    '2019',
    'used'


);
SELECT *
FROM car;
DROP TABLE IF EXISTS sales_person;
CREATE TABLE sales_person(
  sales_person_id SERIAL PRIMARY KEY,
  sales_person_first_name varchar(55),
  sales_person_last_name varchar (55)

);
INSERT INTO sales_person(
   sales_person_first_name,
   sales_person_last_name
)VALUES(
    'Mark',
    'Gooding'
),(
     'Helen',
     'Giller'

);
SELECT *
FROM sales_person 


DROP TABLE IF EXISTS service;
CREATE TABLE service(
  service_id SERIAL PRIMARY KEY,
  service_name varchar(55),
  service_price float,
  machanic_id integer NOT NULL,
  FOREIGN KEY (machanic_id) REFERENCES machanic(machanic_id)
);

INSERT INTO service(
   service_name,
   service_price,
   machanic_id
)VALUES(
   'oil_change',
    80.00,
    2
 ),(
    'Engine light check',
    30.00,
    1
 
 ),(
    'Tyre Condition & Tread Depth Check',
    25.00,
    2
 
 );
SELECT *
FROM service;


DROP TABLE IF EXISTS service_ticket;
CREATE TABLE service_ticket(
  service_ticket_id SERIAL PRIMARY KEY,
  date_serviced timestamp,
  car_id integer NOT NULL,
  customer_id integer NOT NULL,
  service_id integer NOT NULL, 
  machanic_id integer NOT NULL, 
  FOREIGN KEY (car_id) REFERENCES car(car_id),
  FOREIGN KEY (customer_id) REFERENCES customer(customer_id),
  FOREIGN KEY (service_id) REFERENCES service(service_id),
  FOREIGN KEY (machanic_id) REFERENCES machanic(machanic_id)

);
INSERT INTO service_ticket(
   date_serviced,
   car_id,
   customer_id,
   service_id,
   machanic_id 

)VALUES(
   '2023-02-22 12:10:00',
    8,
    6,
    6,
    2
),(
   '2023-10-22 12:01:00',
   5,
   4,
   4,
   1


);

SELECT *
FROM service_ticket;




DROP TABLE IF EXISTS invoice;
CREATE TABLE invoice(
  invoice_id SERIAL PRIMARY KEY,
  date_ timestamp,
  price float,
  customer_id integer NOT NULL,
  sales_person_id integer NOT NULL,
  car_id integer NOT NULL,
  FOREIGN KEY (customer_id) REFERENCES customer(customer_id),
  FOREIGN KEY (sales_person_id) REFERENCES sales_person(sales_person_id),
  FOREIGN KEY (car_id) REFERENCES car(car_id)
);
INSERT INTO invoice(
   date_,
   price,
   customer_id,
   sales_person_id,
   car_id
)values(
   '2023-02-22 10:02:00',
   10000.00,
   6,
   2,
   5
   
   
   
),(
   '2023-12-22 10:02:00',
    20000.00,
    4,
    1,
    2
   
);
SELECT *
FROM invoice;
DROP TABLE IF EXISTS machaic;
CREATE TABLE machanic(
  machanic_id SERIAL PRIMARY KEY,
  machanic_first_name varchar(55),
  machanic_last_name varchar(55)
 );

INSERT INTO machanic(
    machanic_first_name,
    machanic_last_name
)VALUES(
    'Simon',
    'Abreham'

),(
    'Samson',
    'Layne'

);

SELECT *
FROM machanic;
