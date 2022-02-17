from alpine:3.14

run apk update && apk upgrade
run apk add bash vim openrc hugo git

workdir /root
copy ./tools/start.sh ./start.sh
copy ./conf/ /root/
expose 1313
cmd bash start.sh
