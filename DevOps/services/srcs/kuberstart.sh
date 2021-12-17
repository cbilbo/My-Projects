#!/bin/bash
cd ./yamls/

kubectl apply -f metallb.yaml
kubectl apply -f nginx.yaml
kubectl apply -f mysql.yaml
kubectl apply -f wordpress.yaml
kubectl apply -f phpmyadmin.yaml
kubectl apply -f ftps.yaml
kubectl apply -f grafana.yaml
kubectl apply -f influxdb.yaml
cd ../