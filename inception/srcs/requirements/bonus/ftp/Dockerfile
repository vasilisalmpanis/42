FROM debian:11.8

RUN apt update

RUN apt-get install -y \
	vim \
	vsftpd \
	iputils-ping \
	telnet

COPY ./script.sh /
COPY ./vsftpd.conf /etc/vsftpd.conf
ENTRYPOINT [ "sh", "script.sh" ]

