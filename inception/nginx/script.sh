#!/bin/bash

useradd nginx
chown -R nginx:nginx /var/www
nginx -g 'daemon off;'
