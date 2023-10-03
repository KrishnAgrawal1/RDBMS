#!/bin/bash 
docker start nitcbase # if the container instance is not already running

docker exec -it nitcbase /bin/bash # to get a bash shell inside the container
