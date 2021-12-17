FROM alpine:3.12

RUN apk update && apk upgrade
RUN apk add bash vim nginx openrc openssl libc6-compat supervisor wget

RUN mkdir -p /run/nginx/

RUN openssl req -x509 -nodes -days 365 -subj "/C=RU/ST=Russia/L=Moscow/O=School21/OU=cbilbo/CN=cbilbo" \
    -newkey rsa:2048 -keyout /etc/ssl/private/nginx-host.key -out /etc/ssl/certs/nginx-host.crt;

RUN wget https://dl.influxdata.com/telegraf/releases/telegraf-1.18.2_linux_amd64.tar.gz
RUN tar xf telegraf-1.18.2_linux_amd64.tar.gz --strip-components=2 -C /

COPY ./confpack/telegraf.conf /etc/telegraf/telegraf.conf
COPY ./confpack/nginx.conf /etc/nginx/conf.d/default.conf
COPY ./confpack/supervisord.conf /etc/supervisord.conf
COPY ./start.sh /

RUN chmod 777 start.sh

EXPOSE 80 443

CMD bash start.sh