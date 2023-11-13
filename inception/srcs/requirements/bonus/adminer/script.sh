#!/bin/bash

useradd adminer
mkdir -p /usr/share/adminer/
chown  -R adminer:adminer /usr/share/adminer/
cd /usr/share/adminer
php -S 0.0.0.0:81 /etc/adminer/conf.php
