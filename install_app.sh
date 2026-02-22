#!/usr/bin/env sh

if [ "$1" = "-r"  ] || [ "$1" = "--remove" ]; then
    sudo rm -rf /bin/Anime-Fetch
    rm -rf ~/.anime-fetch/; 
else 
    if [ -f "$HOME/.anime-fetch/" ]; then
        sudo rm -rf /bin/Anime-Fetch
        rm -rf ~/.anime-fetch/; 
    fi 
    sudo ln -s "$PWD"/build/cli/Anime-Fetch /bin/Anime-Fetch
    cp -r assets/ ~/.anime-fetch/
fi