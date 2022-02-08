all: up

up:
	bash mkd.sh
	docker-compose -f srcs/docker-compose.yml up --build -d

down:
	docker-compose -f srcs/docker-compose.yml down

fclean: dataclean
	bash clean.sh

dataclean:
	rm -rf ../data/mariadb/* ../data/mysite/* ../data/wordpress/* ../data/redis/* ../data/adminer/*
