
all:
	@echo "Building and running all containers"
	@docker compose -f ./srcs/docker-compose.yaml up -d
build:
	@echo "Building all containers"
	@docker compose -f ./srcs/docker-compose.yaml build
stop:
	@echo "Stoping docker compose containers"
	@docker compose -f ./srcs/docker-compose.yaml down --rmi local
clean:
	@echo "Cleaning up docker"
	@docker system prune -a
	rm -rf ~/data/mysql/*
	rm -rf ~/data/wordpress/*
	rm -rf ~/data/python_blog_data/*
fclean:
	@echo "Pruning all docker data"
	@docker system prune --all --force --volumes
	rm -rf ~/data/mysql/*
	rm -rf ~/data/wordpress/*
	rm -rf ~/data/python_blog_data/*

re:	stop all
	@echo "Restarted all container"

.PHONY: all stop clean fclean build re
