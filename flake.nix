{
  description = "A neofetch-inspired utility that fetch your system info with a OS-Tan";

  inputs = {
    nixpkgs.url = "github:NixOS/nixpkgs/nixos-unstable";
    flake-utils.url = "github:numtide/flake-utils";
  };

  outputs = { self, nixpkgs, flake-utils }:
    flake-utils.lib.eachDefaultSystem (system:
      let
        pkgs = nixpkgs.legacyPackages.${system};
      in
      {
        # Wraps your existing package definition
        packages.default = import ./default.nix { inherit pkgs; };

        # Wraps your existing dev shell environment
        devShells.default = import ./shell.nix { inherit pkgs; };
      }
    );
}