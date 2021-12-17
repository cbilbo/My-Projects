FROM alpine:3.12

RUN apk update && apk upgrade 

RUN apk add bash supervisor openrc libc6-compat wget

RUN wget https://dl.influxdata.com/telegraf/releases/telegraf-1.18.2_linux_amd64.tar.gz
RUN tar xf telegraf-1.18.2_linux_amd64.tar.gz --strip-components=2 -C /

RUN wget https://dl.grafana.com/enterprise/release/grafana-enterprise-7.5.4.linux-amd64.tar.gz
RUN tar -zxvf grafana-enterprise-7.5.4.linux-amd64.tar.gz --strip-components=1 -C /

COPY ./confpack/grafana.db /data/grafana.db
COPY ./confpack/telegraf.conf /etc/telegraf/
COPY ./confpack/supervisord.conf /etc/supervisord.conf
COPY ./start.sh /

EXPOSE 3000

CMD bash start.sh