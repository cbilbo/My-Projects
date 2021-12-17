#!/bin/bash

cd nginx/
docker build -t nginx_img .
cd ../mysql/
docker build -t mysql_img .
cd ../wordpress/
docker build -t wordpress_img .
cd ../phpmyadmin/
docker build -t phpmyadmin_img .
cd ../ftps/
docker build -t ftps_img .
cd ../grafana/
docker build -t grafana_img .
cd ../influxdb/
docker build -t influxdb_img .
cd ../