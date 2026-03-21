#include <coroutine>
#include <iostream>

// Example: Using suspend_never in promise_type
struct Task {
  struct promise_type {
    Task get_return_object() { return {}; }
    std::suspend_never initial_suspend() { return {}; }  // Starts immediately
    std::suspend_never final_suspend() noexcept {
      return {};
    }  // No suspension at end
    void unhandled_exception() {}
    void return_void() {}
  };
};

int main() {
  std::suspend_never x;
  std::cout << "Coroutines work\n";
}
