FROM debian:11.8

RUN apt update
RUN apt-get install -y \ 
	vim \
	curl \
	wget \
	iputils-ping \
	telnet

COPY ./script.sh /
ENTRYPOINT [ "/script.sh" ]
	
