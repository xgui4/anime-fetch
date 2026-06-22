{ pkgs ? import <nixpkgs> {} }:

pkgs.python3Packages.buildPythonApplication rec {
  pname = "anime-fetch";
  version = "0.0.0.0";
  format = "cmake"; 

  src = ./.;

  nativeBuildInputs = [
    pkgs.qt6.wrapQtAppsHook
    pkgs.qt6.qtbase
    pkgs.qt6.qtbase.dev
    pkgs.qt6.qttools
    pkgs.bash
    pkgs.coreutils
    pkgs.gnused
  ];

  propagatedBuildInputs = [
    pkgs.qt6.qtbase
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

  meta = with pkgs.lib; {
    description = "A neofetch-inspired utility that fetch your system info with a OS-Tan";
    license = licenses.gpl3;
    platforms = platforms.linux;
    mainProgram = "anime-fetch";
  };
}