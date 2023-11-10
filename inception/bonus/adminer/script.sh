#!/bin/bash

cd /var/www/html/
wget https://www.adminer.org/latest.php -O adminer.php
chown -R www-data:www-data adminer.php
chmod 755 adminer.php
php -S 0.0.0.0:8080
