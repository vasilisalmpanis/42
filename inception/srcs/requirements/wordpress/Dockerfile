FROM debian:11.8

RUN apt update
RUN apt-get install -y \
	curl \
	php php-curl \
	php-fpm \
	php-bcmath \
	php-gd \
	php-soap \
	php-zip \
	php-curl \
	php-mbstring \
	php-mysqlnd \
	php-gd \
	php-xml \
	php-intl \
	php-zip \ 
	php-cgi

RUN rm /etc/php/7.4/fpm/pool.d/www.conf
COPY ./www.conf /etc/php/7.4/fpm/pool.d/
COPY ./script.sh ./scripts/
ENTRYPOINT ["sh", "./scripts/script.sh" ]
