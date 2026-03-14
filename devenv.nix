{ pkgs, ... }:

{
  languages.cplusplus.enable = true;

  packages = with pkgs; [
    clang_18
    cmake
    gdb
  ];

  env = {
    CXXFLAGS = "-std=c++2c";
  };

  enterShell = ''
      export SHELL=$(getent passwd $USER | cut -d : -f 7)
      clang++ -std=c++2c -dM -E -x c++ /dev/null | grep __cplusplus
      clang++ $CXXFLAGS main.cpp && ./a.out
  '';
}
