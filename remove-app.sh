#!/usr/bin/env sh

if [ "$1" = "linux" ]; then
    sudo rm -rf /bin/Anime-Fetch
    sudo rm -rf /bin/Anime-Fetch-GUI
    rm -rf ~/.local/share/applications/anime-fetch.desktop
    rm -rf ~/.anime-fetch/
elif [ "$1" = "freebsd" ]; then
    sudo rm -rf /usr/local/sbin/Anime-Fetch
    sudo rm -rf /usr/local/sbin/Anime-Fetch-GUI
    rm -rf ~/.local/share/applications/anime-fetch.desktop
    rm -rf ~/.anime-fetch/ 
else
    echo "./remove_app.sh linux: remove linux versiom of the app"
    echo "./remove_app.sh freebsd : remove FreeBSD versiom of the app"
fi 