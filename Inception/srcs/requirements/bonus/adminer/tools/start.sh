#!/bin/bash

openrc
touch /run/openrc/softlevel
rc-update add php-fpm8 default
php-fpm8 -F
