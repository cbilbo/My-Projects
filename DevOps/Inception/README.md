# Inception
## Installation
Download this repository to virtual machine with Linux (my case is Alpine) and `make`
## Infrastructure
Project is composed of different services, that had to run in a dedicated container.
Containers built from the 3.14 version of Alpine Linux. Each container build their own Docker image using Dockerfile.
The infrastructure looks like: 
- A Docker container that contains NGINX with TLSv1.3.
- A Docker container that contains WordPress + php-fpm only without nginx.
- A Docker container that contains MariaDB only without nginx.
- A Docker container that contains redis cache for WordPress.
- A Docker container that contains Adminer for WordPress.
- A Docker container that create my own static site using gohugo.
- A Docker container that contains FTP server pointing to hte volume of WordPress site.
- A volume that contains your WordPress database.
- A second volume that contains your WordPress website files.
- A docker-network that establishes the connection between your containers.
Containers have to restart in case of a crash.
## Instructions
`make` for deploy services
`make down` for stop services
`make dataclean` for delete data from volumes
`make fclean` for delete all data from project
