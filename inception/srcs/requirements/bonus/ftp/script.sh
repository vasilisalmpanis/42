#!/bin/bash

mkdir -p /var/run/vsftpd/empty
adduser $FTPUSER --disabled-password
echo "$FTPUSER:$FTPPASS" | /usr/sbin/chpasswd
usermod -g www-data $FTPUSER
while [ -e "/var/www/html/lock" ]; do
    sleep 1
done
chown -R nobody:nogroup /home/ftp
chown -R $FTPUSER:$FTPUSER /home/ftp/files
echo "$FTPUSER" > /etc/vsftpd.userlist
vsftpd
