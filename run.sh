#!/bin/bash
sudo whoami
cd Binary
make
cd ..
sudo docker build --tag docky-ver-1.0 .
sudo docker run -d -p 1337:1337 --name Docky docky-ver-1.0
