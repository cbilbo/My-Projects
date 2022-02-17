# Services
## Description
This project deploys WordPress site using kubernetes in minikube.
## Infrastructure
Project sets up a multi-service cluster using Kubernetes, each service has to run in a dedicated container. 
Containers built from the 3.12 version of Alpine Linux. Each container build their own Docker image using Dockerfile. 
The infrastructure looks like:
- The Kubernetes web dashboard to manage cluster.
- The Load Balancer which manages the external access of services. It is
the only entry point to  cluster. Load Balancer has a single ip.
- A WordPress website listening on port 5050, which works with a MySQL database.
Both services have to run in separate containers. The WordPress website has
several users and an administrator. Wordpress has its own nginx server. The
Load Balancer redirects directly to this service.
- phpMyAdmin, listening on port 5000 and linked with the MySQL database. PhpMyAdmin has its own nginx server.
The Load Balancer redirects directly to this service.
- A container with an nginx server listening on ports 80 and 443. Port 80 is in
http and has a systematic redirection of type 301 to 443, which is in https.
The page displayed does not matter as long as it is not an http error.
This container allows access to a /wordpress route that makes a redirect 307 to IP:WPPORT.
It allows access to /phpmyadmin with a reverse proxy to IP:PMAPORT.
- A FTPS server listening on port 21.
- A Grafana platform, listening on port 3000, linked with an InfluxDB database.
Grafana is monitoring all your containers. There is one dashboard
per service. InfluxDB and grafana are in two distincts containers.

Containers have to restart in case of a crash.
