FROM debian:11.8

RUN apt update

RUN apt-get install -y \
	nginx \
	openssl


COPY ./script.sh /scripts/
RUN rm /etc/nginx/nginx.conf
COPY ./nginx.conf /etc/nginx/

ENTRYPOINT [ "/scripts/script.sh" ]
