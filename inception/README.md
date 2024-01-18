# Docker Services Infrastructure

## Overview

This project involves setting up a small infrastructure composed of different services using Docker Compose. Each service runs in a dedicated container, and the containers are built from Dockerfiles written for each service. The infrastructure includes NGINX with TLSv1.2 or TLSv1.3, WordPress with php-fpm, MariaDB, and additional services based on the bonus list.
All Services run in Debian containers and have to overide pid 1 with the dedicated service of the container not daemonized so the containers stay active.

## Services

### NGINX Container

- Responsible for serving the website over TLSv1.2 or TLSv1.3.
- Exposes port 443 for HTTPS requests

### WordPress Container

- Contains WordPress and php-fpm. It automatically sets up wordpress with wp cli and connects with mariadb-server through the container network
- Database: MariaDB container.
- Volumes: website files.

### MariaDB Container

- Dedicated MariaDB container.
- Database: Used by the WordPress container.
- Auto-restart: Enabled in case of a crash.

## Volumes

- WordPress Database Volume: `/home/login/data/mysql`
- WordPress Website Files Volume: `/home/login/data/wordpress`
- Full Stack Python App Volume: `/home/login/data/python_blog_data`

## Configuration

- Domain Name: `login.42.fr` (replace "login" with your own login).
- Redirect: `login.42.fr` should redirect to the local IP address pointing to your website.
- Changing /etc/hosts file is mandatory for it to work

## Bonus Features

### Redis Cache Container

- Dedicated container for Redis cache to manage the cache for the WordPress website.

### FTP Server Container

- Container with an FTP server pointing to the volume of the WordPress website.

### Static Website Container

- Container for a Full Stack Python App with its own database for users and blog posts with comments. 

### Adminer Container

- Container for Adminer to manage databases.

### Portainer Container

- Container for Portainer to manage Docker containers.

## Building and Running

Use the provided Makefile to build and run the Docker containers:

```bash
make build   # Build Docker images
make stop    # Stops the containers
make clean   # Stops containers and deletes them and their volumes
make fclean  # Cleans up container and removes all cache from system
make re      # Stops containers and starts them again
```