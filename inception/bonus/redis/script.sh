#!/bin/bash

sed -i 's/^requirepass "12345"$/requirepass "'"$REDIS_PASS"'"/' /etc/redis/redis.conf
redis-server /etc/redis/redis.conf
