#!/bin/bash

[ "0" != "$UID" ] && ( echo "Must run as root!" ) && exit

./networkmanager_do.sh stop

ifconfig wlp3s0 down
iwconfig wlp3s0 mode monitor
ifconfig wlp3s0 up