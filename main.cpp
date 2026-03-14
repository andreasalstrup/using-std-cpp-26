#include <iostream>

template <typename... Ts> void hello(Ts... args) {
  std::cout << args...[0] << "\n"; // C++26 pack indexing
}

int main() { hello("Hello C++26"); }
