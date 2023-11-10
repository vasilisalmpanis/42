#!/bin/bash

useradd nginx
chown -R nginx:nginx /var/www
mkdir /etc/nginx/ssl
chown -R nginx:nginx /etc/nginx/ssl
openssl req -x509 -nodes -days 365 -newkey rsa:2048 -keyout /etc/nginx/ssl/self-signed.key -out /etc/nginx/ssl/self-signed.crt -subj "/CN=$HOST"
nginx -g 'daemon off;'
