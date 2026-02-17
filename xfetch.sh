#!/usr/bin/env bash

echo Hostname : "$(cat /etc/hostname)"
echo OS : "$(lsb_release -d -s)"
kitty +icat "/usr/share/pixmaps/$(grep -Po 'LOGO=\K.*' /etc/os-release).png"