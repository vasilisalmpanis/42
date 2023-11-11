FROM debian:11.8

RUN apt update
RUN apt-get install -y \
	php-mysqlnd \
	php \
	php-curl \
<<<<<<< HEAD
	wget \
	adminer
=======
	wget
>>>>>>> f0b2ea8d3167a385d004c431f05da04ceaf85214

COPY ./script.sh /scripts/

ENTRYPOINT [ "./scripts/script.sh" ]

