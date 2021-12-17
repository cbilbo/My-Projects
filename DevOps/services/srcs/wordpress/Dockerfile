FROM alpine:3.12

RUN apk update && apk upgrade
RUN apk add bash libc6-compat nginx openrc vim supervisor wget

RUN apk add php7 php7-fpm php7-mysqli php7-mbstring php7-json php7-session\
			php7-common php7-iconv php7-gd php7-curl php7-xml php7-imap php7-cgi \
			fcgi php7-pdo php7-pdo_mysql php7-soap php7-xmlrpc php7-posix \
			php7-mcrypt php7-gettext php7-ldap php7-ctype php7-dom

RUN mkdir -p /www && chmod -R 777 /www && mkdir -p /run/nginx

RUN wget https://dl.influxdata.com/telegraf/releases/telegraf-1.18.2_linux_amd64.tar.gz
RUN tar xf telegraf-1.18.2_linux_amd64.tar.gz --strip-components=2 -C /

RUN wget https://wordpress.org/latest.tar.gz
RUN tar zxvf latest.tar.gz -C ./www/

COPY ./confpack/telegraf.conf /etc/telegraf/
COPY ./confpack/wp-config.php ./www/wordpress/wp-config.php
COPY ./confpack/nginx.conf /etc/nginx/conf.d/default.conf
COPY ./confpack/supervisord.conf /etc/supervisord.conf
COPY ./start.sh /

CMD bash start.sh