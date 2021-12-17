CREATE DATABASE wordpress;
CREATE USER 'cbilbo'@'%' IDENTIFIED BY 'cbilbo';
GRANT ALL PRIVILEGES ON wordpress.* TO 'cbilbo'@'%';
FLUSH PRIVILEGES;
