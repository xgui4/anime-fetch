#!/usr/bin/env sh

if [ "$1" = "linux" ]; then
    if [ "$2" = "-r"  ] || [ "$2" = "--remove" ]; then
        sudo rm -rf /bin/Anime-Fetch
        rm -rf ~/.anime-fetch/; 
    else 
        if [ -f "$HOME/.anime-fetch/" ]; then
            sudo rm -rf /bin/Anime-Fetch-GUI
            sudo rm -rf /bin/Anime-Fetch
            rm -rf ~/.local/share/applications/anime-fetch.desktop
            rm -rf ~/.anime-fetch/; 
        fi      
        cp pkg/anime-fetch-linux.desktop ~/.local/share/applications/anime-fetch.desktop
        sudo ln -s "$PWD"/build/gui/Anime-Fetch-GUI /bin/Anime-Fetch-GUI
        sudo ln -s "$PWD"/build/cli/Anime-Fetch /bin/Anime-Fetch
        cp -r assets/ ~/.anime-fetch/
    fi
fi
if [ "$1" = "freebsd" ]; then
    if [ "$2" = "-r"  ] || [ "$2" = "--remove" ]; then
        sudo rm -rf /usr/local/sbin/Anime-Fetch
        sudo rm -rf /usr/local/sbin/Anime-Fetch-GUI
        rm -rf ~/.anime-fetch/; 
    else 
        if [ -f "$HOME/.anime-fetch/" ]; then
            sudo rm -rf /usr/local/sbin/Anime-Fetch
            sudo rm -rf /usr/local/sbin/Anime-Fetch-GUI
            rm -rf ~/.anime-fetch/; 
        fi 
        cp pkg/anime-fetch-bsd.desktop ~/.local/share/applications/anime-fetch.desktop
        sudo ln -s "$PWD"/build/cli/Anime-Fetch /usr/local/sbin/Anime-Fetch
        sudo ln -s "$PWD"/build/gui/Anime-Fetch-GUI /usr/local/sbin/Anime-Fetch-GUI
        cp -r assets/ ~/.anime-fetch/
    fi
else
    echo "./install_app.sh linux -r : remove linux versiom of the app"
    echo "./install_app.sh linux : install the linux versiom of the app"
    echo "./install_app.sh freebsd -r : remove FreeBSD versiom of the app"
    echo "./install_app.sh freebsd : install the FreeBSD versiom of the app"
fi
