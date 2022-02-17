from alpine:3.14

run apk update && apk upgrade
run apk add bash vim nginx openssl openrc
run mkdir -p /run/nginx/ /var/www/cbilbo.42.fr/
run openssl req -x509 -nodes -days 365 -subj "/C=RU/ST=Russia/L=Moscow/O=School21/OU=cbilbo/CN=cbilbo.42.fr" \
	-newkey rsa:4096 -keyout /etc/ssl/certs/cbilbo.42.fr.key -out /etc/ssl/certs/cbilbo.42.fr.crt;

copy conf/nginx.conf /etc/nginx/http.d/default.conf
copy tools/start.sh ./start.sh

expose 443

CMD ["bash", "start.sh"]
