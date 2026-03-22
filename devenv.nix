{ pkgs, ... }:
let
  llvm = pkgs.llvmPackages_22;
in
{
  packages = [
    llvm.clang
    llvm.clang-tools
    pkgs.gcc
    pkgs.git
    pkgs.cmake
    pkgs.ninja
    pkgs.gdb
  ];
  env = {
    CC       = "${llvm.clang}/bin/clang";
    CXX      = "${llvm.clang}/bin/clang++";
    CXXFLAGS = "-std=c++2c -stdlib=libstdc++";
    CLANGD   = "${llvm.clang-tools}/bin/clangd";
  };
  enterShell = ''
    export SHELL=$(getent passwd $USER | cut -d : -f 7)
    export PATH="${llvm.clang-tools}/bin:$PATH"

    run() {
      clang++ $CXXFLAGS "$1" -o /tmp/out && /tmp/out
    }

    echo "Compiler:"
    clang++ --version

    echo "C++ standard:"
    clang++ -std=c++2c -dM -E -x c++ /dev/null | grep __cplusplus

    echo "Building src/main.cpp:"
    cmake -B build -G Ninja \
      -DCMAKE_C_COMPILER=$(which clang) \
      -DCMAKE_CXX_COMPILER=$(which clang++) \
      -DCMAKE_EXPORT_COMPILE_COMMANDS=ON

    cmake --build build \
    && ./build/main

    ln -sf build/compile_commands.json .
  '';
}
