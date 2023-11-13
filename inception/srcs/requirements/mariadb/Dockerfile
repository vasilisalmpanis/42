FROM debian:11.8

RUN apt update
RUN apt-get install -y \
	mariadb-server

COPY / /
ENTRYPOINT [ "/script.sh" ]
