#!/bin/bash
# This script will be running in backgound and keep updating the ip addresses of server containers on nodes.cfg
while(true)
do
 	rm -f -- /tmp/nodes.cfg
	for OUTPUT in $(sudo docker ps -aqf "ancestor=$1")
	do
        	container_ip=$(sudo docker inspect --format='{{range .NetworkSettings.Networks}}{{.IPAddress}}{{end}}' $OUTPUT)
        	echo $container_ip:1234  >>  /tmp/nodes.cfg
	done
	for OUTPUT in $(sudo docker ps -aqf "ancestor=$1")
	do
	        #echo $OUTPUT:1234  >>  /tmp/nodes.cfg
	        sudo docker cp /tmp/nodes.cfg $OUTPUT:/tmp/nodes.cfg
        	echo $OUTPUT
	done
sleep 10;
done

