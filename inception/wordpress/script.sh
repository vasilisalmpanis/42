#!/bin/bash
rm -f /var/www/html/lock
mkdir /run/php
curl -O https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar
chmod +x wp-cli.phar
mv wp-cli.phar /usr/local/bin/wp
cd /var/www/html/
if ! wp core --allow-root is-installed ; then
	wp core download --allow-root
	wp core config --dbname=$DBNAME --dbuser=$DBUSER --dbpass=$DBPASS --dbhost=$DBHOST --allow-root
	chown -R www-data:www-data /var/www/html
	chmod 600 wp-config.php
	wp core install --allow-root --url=$HOST --title="My site" --admin_user=$WP_ADMIN_USER --admin_password=$WP_ADMIN_PASS --admin_email=$WP_ADMIN_EMAIL
	sed -i "41i define( 'WP_REDIS_HOST', 'redis' );" /var/www/html/wp-config.php
	sed -i "42i define( 'WP_REDIS_PORT', '6379' );" /var/www/html/wp-config.php
	sed -i "43i define( 'WP_REDIS_PASSWORD', '$REDIS_PASS');" /var/www/html/wp-config.php
	wp --allow-root user create $WP_USER  $WP_EMAIL --role=author
	wp --allow-root user update $WP_USER --user_pass=$WP_PASS --display_name="Ron_loves_harry"
	wp --allow-root --path=/var/www/html theme install generatepress 
	wp --allow-root --path=/var/www/html theme activate generatepress
else
	echo "core already downloaded"
fi
wp --allow-root plugin install redis-cache  --activate --path=/var/www/html
wp --allow-root plugin update --all --path=/var/www/html
wp --allow-root --path=/var/www/html redis enable
touch /var/www/html/lock
php-fpm7.4 -F
