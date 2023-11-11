#!/bin/bash

<<<<<<< HEAD
useradd adminer
mkdir -p /usr/share/adminer/
chown  -R adminer:adminer /usr/share/adminer/
cd /usr/share/adminer
php -S 0.0.0.0:81 /etc/adminer/conf.php
=======
cd /var/www/html/
wget https://www.adminer.org/latest.php -O adminer.php
chown -R www-data:www-data adminer.php
chmod 755 adminer.php
php -S 0.0.0.0:8080
>>>>>>> f0b2ea8d3167a385d004c431f05da04ceaf85214
