all: up

up:
	bash mkd.sh
	docker-compose -f srcs/docker-compose.yml up --build -d

down:
	docker-compose -f srcs/docker-compose.yml down

fclean: dataclean
	bash clean.sh

dataclean:
	rm -rf $HOME/data/mariadb/* $HOME/data/mysite/* $HOME/data/wordpress/* $HOME/data/redis/* $HOME/data/adminer/*
