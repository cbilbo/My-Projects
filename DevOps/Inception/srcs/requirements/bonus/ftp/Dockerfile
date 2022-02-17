from alpine:3.14

run apk update && apk upgrade

run apk add bash vim openrc vsftpd

workdir /root

copy conf/vsftpd.conf /etc/vsftpd/vsftpd.conf
copy tools/start.sh ./start.sh

expose 21 21100-21110
cmd bash start.sh
