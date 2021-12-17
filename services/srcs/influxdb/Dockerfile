FROM alpine:3.12

RUN apk update && apk upgrade

RUN apk add bash influxdb supervisor openrc libc6-compat wget

RUN wget https://dl.influxdata.com/telegraf/releases/telegraf-1.18.2_linux_amd64.tar.gz
RUN tar xf telegraf-1.18.2_linux_amd64.tar.gz --strip-components=2 -C /

COPY ./confpack/telegraf.conf /etc/telegraf/
COPY ./confpack/supervisord.conf /etc/supervisord.conf
COPY ./start.sh /

EXPOSE 8086

CMD bash start.sh