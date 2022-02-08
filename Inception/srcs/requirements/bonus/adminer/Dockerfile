from alpine:3.14

run apk update && apk upgrade
run apk add bash vim wget openrc
run apk add php8 php8-fpm php8-mysqlnd php8-mysqli php8-curl php8-dom php8-exif php8-fileinfo php8-pecl-imagick php8-mbstring php8-openssl php8-xml php8-zip php8-bcmath php8-gd php8-iconv php8-intl php8-pecl-mcrypt php8-simplexml php8-sodium php8-zlib php8-pecl-ssh2 php8-ftp php8-sockets php8-pecl-memcache

run mkdir -p /var/www/cbilbo.42.fr/adminer/

run adduser -D -H -u 1000 -s /bin/bash www-data -G www-data
run chown -R www-data:www-data /var/www/*
workdir /var/www/cbilbo.42.fr/adminer

run wget https://github.com/vrana/adminer/releases/download/v4.8.1/adminer-4.8.1-mysql.php
run mv adminer-4.8.1-mysql.php index.php
copy conf/www.conf /etc/php8/php-fpm.d/www.conf

workdir /root
copy tools/start.sh ./start.sh

expose 5000

cmd ["bash", "start.sh"]
