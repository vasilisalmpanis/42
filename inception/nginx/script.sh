#!/bin/bash

useradd nginx
chown -R nginx:nginx /var/www
mkdir /etc/nginx/ssl
chown -R nginx:nginx /etc/nginx/ssl
openssl req -x509 -nodes -days 365 -newkey rsa:2048 -keyout /etc/nginx/ssl/self-signed.key -out /etc/nginx/ssl/self-signed.crt -subj "/CN=$HOST"
sed -i "s/server_name python.example/server_name python.$HOST/g" /etc/nginx/nginx.conf
nginx -g 'daemon off;'
