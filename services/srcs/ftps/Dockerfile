FROM alpine:3.12

RUN apk update && apk upgrade 

RUN apk add openssh openssl openrc libc6-compat bash wget vsftpd supervisor vim

RUN mkdir -p home/cbilbo/ && chmod -R 777 home/ && mkdir -p /etc/ssl/ && chmod -R 777 /etc/ssl/

RUN wget https://dl.influxdata.com/telegraf/releases/telegraf-1.18.2_linux_amd64.tar.gz
RUN tar xf telegraf-1.18.2_linux_amd64.tar.gz --strip-components=2 -C /

RUN openssl req -x509 -nodes -days 365 -subj "/C=RU/ST=Russia/L=Moscow/O=School21/OU=cbilbo/CN=cbilbo" \
    -newkey rsa:2048 -keyout /etc/ftps.key -out /etc/ftps.crt;

RUN adduser -D -h /home/cbilbo cbilbo && echo "cbilbo:cbilbo" | chpasswd

COPY ./confpack/telegraf.conf /etc/telegraf/
COPY ./confpack/hello.txt /home/cbilbo/hello.txt
COPY ./confpack/vsftpd.conf /etc/vsftpd.conf
COPY ./confpack/supervisord.conf /etc/supervisord.conf
COPY ./start.sh /

EXPOSE 21 20001

CMD bash start.sh