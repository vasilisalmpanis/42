FROM debian:11.8

RUN apt update
RUN apt-get install -y \
	php-mysqlnd \
	php \
	php-curl \
	wget

COPY ./script.sh /scripts/

ENTRYPOINT [ "./scripts/script.sh" ]

