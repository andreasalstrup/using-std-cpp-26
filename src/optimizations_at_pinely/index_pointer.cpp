#include <cstdint>
#include <iostream>

static uint64_t INDEX = 0;

template <typename T>
class IndexPointer {
 public:
  IndexPointer(T t)
      : value_{(reinterpret_cast<uint64_t>(new T(t)) << 17) | ++INDEX} {}

  T* operator->() const { return reinterpret_cast<T*>(value_ >> 20 << 3); }
  T& operator*() const { return *reinterpret_cast<T*>(value_ >> 20 << 3); }

  std::size_t index() const {
    return static_cast<std::size_t>(value_ & 0xFFFFF);
  }

 private:
  uint64_t value_;
};

int main() {
  auto idxPtr = IndexPointer<std::string>{"hello"};
  std::cout << idxPtr.index() << std::endl;
  std::cout << *idxPtr << std::endl;
  auto idxPtr2 = IndexPointer<std::string>{"world"};
  std::cout << idxPtr2.index() << std::endl;
  std::cout << *idxPtr2 << std::endl;
}
