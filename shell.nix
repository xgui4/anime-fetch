{ pkgs ? import <nixpkgs> {} }:

pkgs.mkShell rec {
  pname = "anime-fetch";
  version = "0.0.0.0";
  format = "cmake";

  src = ./.;
  
  buildInputs = with pkgs; [
    qt6.qtbase
    qt6.qtwayland
    libGL
  ];

  postInstall = ''
    # Desktop Entry & Mime
    install -Dm644 "packages/anime-fetch-gui.desktop" "$out/share/applications/anime-fetch-gui.desktop"

    # Docs
    install -Dm644 "LICENSE.md" -t "$out/share/licenses/${pname}/"
    install -Dm644 "README.md" "code-of-conduct.md" -t "$out/share/doc/${pname}/"
  '';

  dontCheckRuntimeDeps = true;
  dontWrapQtApps = true;
  preFixup = ''
    makeWrapperArgs+=("''${qtWrapperArgs[@]}")
  '';

  shellHook = ''    
    # NixOS Graphics & Qt Fixes
    export LD_LIBRARY_PATH="${pkgs.lib.makeLibraryPath [ pkgs.libGL pkgs.stdenv.cc.cc ]}:$LD_LIBRARY_PATH"
    export QT_PLUGIN_PATH="${pkgs.qt6.qtbase}/${pkgs.qt6.qtbase.qtPluginPrefix}"
    export QT_QPA_PLATFORM_PLUGIN_PATH="${pkgs.qt6.qtbase}/lib/qt-6/plugins/platforms"
  '';
}