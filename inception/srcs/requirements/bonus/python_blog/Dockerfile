FROM debian:11.8

RUN apt update
RUN apt-get install -y \
	python3 \
	pip \
	python3-venv \
	python3-openssl \
	vim 

WORKDIR /app 
COPY ./app/ .
COPY ./schript.sh .
ENTRYPOINT [ "sh", "./schript.sh" ]
