#!/bin/bash

[ "0" != "$UID" ] && ( echo "Must run as root!" ) && exit

service network-manager $@