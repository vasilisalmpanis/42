#!/bin/bash

mkdir /run/php
curl -O https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar
chmod +x wp-cli.phar
mv wp-cli.phar /usr/local/bin/wp
cd /var/www/html/
wp core download --allow-root
wp core config --dbname=$DBNAME --dbuser=$DBUSER --dbpass=$DBPASS --dbhost=$DBHOST --allow-root
chown -R www-data:www-data /var/www/html
chmod 600 wp-config.php
wp core install --allow-root --url=http://$HOST:8080/ --title="My site" --admin_user=$WP_ADMIN_USER --admin_password=$WP_ADMIN_PASS --admin_email=$WP_ADMIN_EMAIL
wp --allow-root user create $WP_USER  $WP_EMAIL --role=author
wp --allow-root user update $WP_USER --user_pass=$WP_PASS --display_name="Ron_loves_harry"
wp --allow-root --path=/var/www/html theme install blocksy
wp --allow-root --path=/var/www/html theme activate blocksy
php-fpm7.4 -F
