-- 1. Create Tables (Schema Design)
CREATE TABLE Products (
    product_id INT PRIMARY KEY,
    name VARCHAR(50),
    price DECIMAL(10,2)
);

CREATE TABLE Orders (
    order_id INT PRIMARY KEY,
    product_id INT,
    customer_name VARCHAR(50),
    order_date DATE,
    FOREIGN KEY (product_id) REFERENCES Products(product_id)
);

-- 2. Insert Data
INSERT INTO Products VALUES (1, 'Laptop', 50000), (2, 'Mouse', 500);
INSERT INTO Orders VALUES (101, 1, 'Rahul', '2023-10-01'), (102, 2, 'Anjali', '2023-10-02');

-- 3. The "Pro" Query (JOIN)
-- This shows which customer bought what and the price
SELECT Orders.customer_name, Products.name, Products.price
FROM Orders
INNER JOIN Products ON Orders.product_id = Products.product_id;
