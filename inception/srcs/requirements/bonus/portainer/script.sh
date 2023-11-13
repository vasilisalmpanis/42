#!/bin/bash

wget https://github.com/portainer/portainer/releases/download/2.19.1/portainer-2.19.1-linux-amd64.tar.gz
tar -xvf portainer-2.19.1-linux-amd64.tar.gz
cd portainer
./portainer --bind=":8080"
