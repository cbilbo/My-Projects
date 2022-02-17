#!/bin/bash

openrc
touch /run/openrc/softlevel
if ! [ -d /var/lib/mysql/$MYSQL_DATABASE ]; then
	rc-update add mariadb default
	mysql_install_db --user=root
	rc-service mariadb start
	echo "CREATE DATABASE $MYSQL_DATABASE;" | mariadb
	#if [ -f $MYSQL_DATABASE.sql ]; then
	#	mariadb $MYSQL_DATABASE < $MYSQL_DATABASE.sql
	#fi
	echo "CREATE USER '$MYSQL_USER'@'%' IDENTIFIED BY '$MYSQL_PASSWORD';" | mariadb
	echo "GRANT ALL PRIVILEGES ON $MYSQL_DATABASE.* TO '$MYSQL_USER'@'%';" | mariadb
	echo "FLUSH PRIVILEGES;" | mariadb
	echo "ALTER USER 'root'@'localhost' IDENTIFIED BY '$MYSQL_ROOT_PASSWORD';" | mariadb
	echo "FLUSH PRIVILEGES;" | mariadb -u root -p$MYSQL_ROOT_PASSWORD
	rc-service mariadb stop
fi
mysqld_safe
