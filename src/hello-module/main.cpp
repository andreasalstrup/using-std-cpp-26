//clang++ -std=c++2c --precompile   -Wno-unused-command-line-argument   -x c++-module helloworld.cpp -o helloworld.pcm
//clang++ -std=c++2c -fmodule-file=helloworld=helloworld.pcm helloworld.pcm main.cpp -o app 
import helloworld; // import declaration

int main() { hello(); }
