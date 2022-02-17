from alpine:3.14

run apk update && apk upgrade
run apk add bash vim wget openrc
run apk add php8 php8-fpm php8-mysqlnd php8-mysqli php8-curl php8-dom php8-exif php8-fileinfo php8-pecl-imagick php8-mbstring php8-openssl php8-xml php8-zip php8-bcmath php8-gd php8-iconv php8-intl php8-pecl-mcrypt php8-simplexml php8-sodium php8-zlib php8-pecl-ssh2 php8-ftp php8-sockets php8-pecl-memcache php8-phar php8-pecl-redis php8-ctype

run mv /usr/bin/php8 /usr/bin/php

run mkdir -p /var/www/cbilbo.42.fr/wordpress/
run mkdir -p /var/lib/redis

run adduser -D -H -u 1000 -s /bin/bash www-data -G www-data
run chown -R www-data:www-data /var/www/*
workdir /var/www/cbilbo.42.fr/wordpress/

#run wget https://ru.wordpress.org/latest-ru_RU.tar.gz
#run tar zxvf latest-ru_RU.tar.gz -C .
#run mv wordpress/* ./
#run rm -rf latest-ru_RU.tar.gz wordpress
#copy conf/wp-config.php ./wp-config.php
copy conf/www.conf /etc/php8/php-fpm.d/www.conf

workdir /root
copy tools/start.sh ./start.sh
run wget https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar
run chmod +x wp-cli.phar
run mv wp-cli.phar /usr/bin/wp

expose 9000

cmd ["bash", "start.sh"]
