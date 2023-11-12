#!/bin/bash

mkdir -p /var/run/vsftpd/empty
adduser $FTPUSER --disabled-password
echo "$FTPUSER:$FTPPASS" | /usr/sbin/chpasswd
chown -R nobody:nogroup /home/ftp
chown -R $FTPUSER:$FTPUSER /home/ftp/files
echo "$FTPUSER" > /etc/vsftpd.userlist
vsftpd
