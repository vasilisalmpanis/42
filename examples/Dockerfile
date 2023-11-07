FROM debian



RUN  apt update 
RUN apt-get install -y \
	build-essential \
	mariadb-server \
	nano \
	php \
	libapache2-mod-php \
	php-mysql \
	wget


EXPOSE 80

CMD [ "/bin/bash" ]
