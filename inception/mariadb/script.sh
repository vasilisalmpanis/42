#!/bin/bash

cat << EOF > /etc/mysql/my.cnf
[mysqld]
datadir = /var/lib/mysql
bind-address = 0.0.0.0
user = root
port = 3306
general_log = 1
general_log_file = /var/lib/mysql/error.log
EOF
chown -R mysql:mysql /var/lib/mysql
mkdir /run/mysqld
chown -R mysql:mysql /run/mysqld
touch /var/lib/mysql/initialized
mariadb-install-db --user=mysql --data-dir=/var/lib/mysql
/etc/init.d/mariadb start
mariadb -e "CREATE DATABASE IF NOT EXISTS $DBNAME;"
mariadb -e "CREATE USER IF NOT EXISTS '$DBUSER'@'$WPHOST.$WPHOST' IDENTIFIED BY '$DBPASS';"
mariadb -e "GRANT ALL PRIVILEGES ON $DBNAME.* TO '$DBUSER'@'$WPHOST.$WPHOST' IDENTIFIED BY '$DBPASS';"
mariadb -e "FLUSH PRIVILEGES;"
/etc/init.d/mariadb stop
mysqld
