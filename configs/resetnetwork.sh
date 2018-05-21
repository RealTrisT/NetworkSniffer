#!/bin/bash

[ "0" != "$UID" ] && ( echo "Must run as root!" ) && exit

ifconfig wlp3s0 down
iwconfig wlp3s0 mode managed
ifconfig wlp3s0 up

service network-manager restart