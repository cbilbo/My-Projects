# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Dockerfile                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cbilbo <cbilbo@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/24 16:05:14 by cbilbo            #+#    #+#              #
#    Updated: 2021/04/28 22:24:40 by cbilbo           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#download debian bister image
FROM debian:buster as server

#update debian system
RUN apt-get -y update && apt-get -y upgrade \
    && apt-get -y install wget vim

#install nginx
RUN apt-get install -y nginx

#install mysql on debian
RUN apt-get install -y mariadb-server

COPY ./srcs/autoindex/autoindex_off /etc/nginx/sites-available/default
COPY ./srcs/autoindex/ /var/www/html/autoindex/
COPY ./srcs/index.php /var/www/html/

#install php's modules
RUN apt-get -y install php7.3-fpm php7.3-common php7.3-mysql \
    php7.3-gmp php7.3-curl php7.3-intl php7.3-mbstring php7.3-xmlrpc \
    php7.3-gd php7.3-xml php7.3-cli php7.3-zip php7.3-soap php7.3-imap

#location of server's files
WORKDIR /var/www/html/

#install phpmyadmin
RUN wget https://files.phpmyadmin.net/phpMyAdmin/5.1.0/phpMyAdmin-5.1.0-all-languages.tar.gz
RUN tar -xf phpMyAdmin-5.1.0-all-languages.tar.gz\
    && rm -rf phpMyAdmin-5.1.0-all-languages.tar.gz
RUN mv phpMyAdmin-5.1.0-all-languages phpmyadmin
RUN rm -rf /var/www/html/phpmyadmin/config.sample.inc.php
COPY ./srcs/config.inc.php /var/www/html/phpmyadmin/config.inc.php

#install wordpress
RUN wget https://ru.wordpress.org/latest-ru_RU.tar.gz
RUN tar -xvzf latest-ru_RU.tar.gz && rm -rf latest-ru_RU.tar.gz
RUN rm -f /var/www/html/wordpress/wp-config-sample.php
COPY ./srcs/wp-config.php /var/www/html/wordpress/wp-config.php

RUN openssl req -x509 -nodes -days 365 -subj "/C=RU/ST=Russia/L=Moscow/O=School21/OU=cbilbo/CN=cbilbo.su" \
    -newkey rsa:2048 -keyout /etc/ssl/nginx-selfsigned.key -out /etc/ssl/nginx-selfsigned.crt;

EXPOSE 80 443

COPY ./srcs/start.sh  /var/www/html/start.sh

RUN chown -R www-data:www-data /var/www/*
RUN chmod -R 755 /var/www/*
CMD bash /var/www/html/start.sh