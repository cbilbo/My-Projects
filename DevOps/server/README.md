# Server
## installation
Download this repository and `docker build -t server . && docker run -d -p 80:80 -p 443:443 server`
## Description
There is a single docker container with Nginx, Wordpress, PhpMyAdmin and MariaDB. 
Server is used the SSL protocol. It's redirect http to https.
