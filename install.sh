#!/bin/bash

# stop the service
systemctl stop daemonizer.service

echo "";
# copy systemctl file
sudo cp -v daemonizer.service /etc/systemd/system/
echo "";
ls -l /etc/systemd/system/daemonizer.service

echo "";
# copy config
# sudo cp -v daemonizer.cfg /etc/

echo "";
# copy binary
sudo cp -v ../build-daemonizer-Desktop-Debug/daemonizer /usr/bin/
# sudo cp -v ../build-daemonizer-Desktop-Release/daemonizer /usr/bin/

echo "";
# reload systemctl
sudo systemctl daemon-reload

echo "";
# start the servivce
systemctl start daemonizer.service

echo "";
# check install
systemctl status daemonizer.service

