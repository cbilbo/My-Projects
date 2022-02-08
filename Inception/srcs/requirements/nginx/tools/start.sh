#!/bin/bash
openrc
touch /run/openrc/softlevel
rc-update add nginx default
chmod 777 /var/www/*
nginx -g 'daemon off;'
