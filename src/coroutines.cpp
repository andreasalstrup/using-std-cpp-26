#include <coroutine>
#include <cstdio>
#include <generator>

struct Coroutine {
  struct promise_type {
    Coroutine get_return_object() { return {}; }
    std::suspend_never initial_suspend() { return {}; }  // Starts immediately
    std::suspend_never final_suspend() noexcept {
      return {};
    }  // No suspension at end
    void unhandled_exception() {}
    void return_void() {}
  };
};

auto func() -> Coroutine { co_return; }

auto foo() -> Coroutine { return func(); }

auto gen() -> std::generator<int> {
  co_yield 0;
  co_yield 1;
  co_yield 2;
  co_yield 3;
  co_return;
}

int main() {
  for (auto i : gen()) {
    std::printf("{%d}\n", i);
  }
  return 0;
}
