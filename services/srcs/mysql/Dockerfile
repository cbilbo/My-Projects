FROM alpine:3.12

VOLUME ["/var/lib/mysql"]

RUN apk update && apk upgrade 

RUN apk add bash supervisor mysql mysql-client openrc libc6-compat vim

RUN apk add php7 php7-fpm php7-mysqli php7-mbstring php7-json php7-session\
			php7-common php7-iconv php7-gd php7-curl php7-xml php7-imap php7-cgi \
			fcgi php7-pdo php7-pdo_mysql php7-soap php7-xmlrpc php7-posix \
			php7-mcrypt php7-gettext php7-ldap php7-ctype php7-dom

RUN wget https://dl.influxdata.com/telegraf/releases/telegraf-1.18.2_linux_amd64.tar.gz
RUN tar xf telegraf-1.18.2_linux_amd64.tar.gz --strip-components=2 -C /

COPY ./confpack/telegraf.conf /etc/telegraf/
COPY ./confpack/supervisord.conf /etc/
COPY ./confpack/my.cnf /etc/
COPY ./confpack/wordpress_create_user.sql /
COPY ./confpack/wordpress.sql /
COPY ./start.sh /

EXPOSE 3306

CMD bash start.sh