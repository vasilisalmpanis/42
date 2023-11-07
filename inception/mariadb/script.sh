#!/bin/bash

/etc/init.d/mariadb start
mariadb -e "CREATE DATABASE IF NOT EXISTS $DBNAME;"
mariadb -e "CREATE USER IF NOT EXISTS '$DBUSER'@'$DBHOST' IDENTIFIED BY '$DBPASS';"
mariadb -e "GRANT ALL PRIVILEGES ON $DBNAME.* TO '$DBUSER'@'$DBHOST';"
mariadb -e "FLUSH PRIVILEGES;"
mariadb -e "SHOW DATABASES;"

/bin/bash
