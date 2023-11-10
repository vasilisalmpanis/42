FROM debian:11.8

RUN apt update;

RUN apt-get install -y \
	redis
COPY ./script.sh ./scripts/
COPY ./redis.conf /etc/redis/
ENTRYPOINT ["./scripts/script.sh"]
