FROM debian:11.8

RUN apt update
RUN apt-get install -y \
	python3 \
	pip \
	python3-venv \
	python3-openssl \
	vim \
	git
RUN git clone https://github.com/vasilisalmpanis/Python-Company-Blog app

COPY ./app/main.py /main.py
WORKDIR /app
COPY ./schript.sh .
ENTRYPOINT [ "sh", "./schript.sh" ]
