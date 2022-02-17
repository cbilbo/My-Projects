from alpine:3.14

run apk update && apk upgrade

run apk add bash vim openrc mariadb mariadb-client

workdir /root
copy conf/my.cnf /etc/my.cnf
copy tools/start.sh ./start.sh
#copy conf/wordpress.sql ./wordpress.sql

expose 3306

cmd ["bash", "start.sh"]
