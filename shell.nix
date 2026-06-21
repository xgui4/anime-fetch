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
    install -Dm644 "packages/io.github.xgui4.lce_qt_launcher.desktop" "$out/share/applications/io.github.xgui4.lce_qt_launcher.desktop"
    install -Dm644 "packages/lce_inst-mime.xml" "$out/share/mime/packages/io.github.xgui4.lce_qt_launcher.xml"
    install -Dm644 "packages/io.github.xgui4.lce_qt_launcher.metainfo.xml" "$out/share/metainfo/io.github.xgui4.lce_qt_launcher.metainfo.xml"

    # Icons
    install -Dm644 "assets/io.github.xgui4.lce_qt_launcher.png" "$out/share/icons/hicolor/128x128/apps/io.github.xgui4.lce_qt_launcher.png"
    install -Dm644 "assets/lce_inst.png" "$out/share/icons/hicolor/128x128/mimetypes/application-x-lce_inst.png"

    # Data/Assets (Mirroring your /opt logic into Nix share)
    mkdir -p "$out/share/${pname}"
    cp -r data assets "$out/share/${pname}/"

    # Docs
    install -Dm644 "license.md" -t "$out/share/licenses/${pname}/"
    install -Dm644 "readme.md" "code-of-conduct.md" -t "$out/share/doc/${pname}/"
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