from alpine:3.14
run apk update && apk upgrade
run apk add bash vim openrc redis

run mkdir -p /var/lib/redis && chmod 777 /var/lib/redis

workdir /root
copy tools/start.sh ./start.sh
copy conf/redis.conf ./redis.conf

expose 6379

cmd bash start.sh
