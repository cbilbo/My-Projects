#!/bin/bash

openrc
touch /run/openrc/softlevel
rc-update add vsftpd default
cp /etc/hosts ./hosts
sed -i -e  "1 s/localhost/localhost ftp.$FTP_HOST/g" ./hosts
cat hosts > /etc/hosts
rm hosts

adduser -h $FTP_HOMEDIR -D $FTP_USER
echo "$FTP_USER:$FTP_PASSWORD" | chpasswd
mkdir -p $FTP_HOMEDIR
chown -R $FTP_USER:$FTP_USER $FTP_HOMEDIR
chmod 777 $FTP_HOMEDIR

/usr/sbin/vsftpd -opasv_min_port=$MIN_PORT -opasv_max_port=$MAX_PORT -opasv_address=ftp.$FTP_HOST /etc/vsftpd/vsftpd.conf
