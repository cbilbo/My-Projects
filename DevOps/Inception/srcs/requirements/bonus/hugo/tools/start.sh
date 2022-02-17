#!/bin/bash

openrc
touch /run/openrc/softlevel
if ! [ -d /root/mysite/public]; then
	rm -rf mysite
	hugo new site mysite
	cd mysite/themes
	git init
	git clone https://github.com/shenoybr/hugo-goa
	cd ../
	cp /root/config.toml ./
	cp -r /root/content ./
	cp -r /root/static ./
	hugo -D
fi
hugo server -D
