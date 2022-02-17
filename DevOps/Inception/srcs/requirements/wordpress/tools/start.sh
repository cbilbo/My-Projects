#!/bin/bash

openrc
touch /run/openrc/softlevel
rc-update add php-fpm8 default
cd /var/www/cbilbo.42.fr/wordpress
wp core download --locale=ru_RU
cp wp-config-sample.php wp-config.php
sed -i -e "s/username_here/$WP_DB_USER/g" /var/www/cbilbo.42.fr/wordpress/wp-config.php;
sed -i -e "s/password_here/$WP_DB_PASSWORD/g" /var/www/cbilbo.42.fr/wordpress/wp-config.php;
sed -i -e "s/localhost/$WP_DB_HOST/g" /var/www/cbilbo.42.fr/wordpress/wp-config.php;
sed -i -e "s/database_name_here/$WP_DB_NAME/g" /var/www/cbilbo.42.fr/wordpress/wp-config.php;
sed -i -e "/WP_DEBUG/a define( 'WP_REDIS_HOST', '$WP_REDIS_HOST');" /var/www/cbilbo.42.fr/wordpress/wp-config.php;
sed -i -e "/WP_DEBUG/a define( 'WP_REDIS_PORT', '$WP_REDIS_PORT');" /var/www/cbilbo.42.fr/wordpress/wp-config.php;
sed -i -e "/WP_DEBUG/a define( 'WP_CACHE', true );" /var/www/cbilbo.42.fr/wordpress/wp-config.php;
sed -i -e "/WP_DEBUG/a define( 'WP_REDIS_KEY_SALT', '$HOST');" /var/www/cbilbo.42.fr/wordpress/wp-config.php;
wp core install --url=localhost --title="cbilbo's Inception" --admin_user="$WP_DB_USER" --admin_password="$WP_DB_PASSWORD" --admin_email="$WP_DB_USER@student.21-school.ru"
wp user create ktulhu ktulhu@mail.ru --user_pass=kuku
wp plugin install redis-cache --activate
wp redis update-dropin
php-fpm8 -F 
